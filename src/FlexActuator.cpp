#include "FlexActuator.h"

FlexActuator::FlexActuator(byte pipesNum) {
	_pipesNum = pipesNum;
	_pipes = new FlexPipePtr[_pipesNum];
	for (auto i = 0; i < _pipesNum; i++)
		_pipes[i] = new FlexPipe();
}

FlexActuator::~FlexActuator() {
	for (auto i = 0; i < _pipesNum; i++)
		delete _pipes[i];
	delete[] _pipes;
}

void FlexActuator::attachValves(const byte valvePins[]) {
	for (auto i = 0; i < _pipesNum; i++) {
		_valves[i] = valvePins[i];
		pinMode(_valves[i], OUTPUT);
		digitalWrite(_valves[i], LOW);
	}
}

void FlexActuator::attachSensors(const byte sensorPins[]) {
	for (auto i = 0; i < _pipesNum; i++)
		_sensors[i] = sensorPins[i];
}

byte FlexActuator::pipesNum() {
	return _pipesNum;
}

bool FlexActuator::checkNum(byte n) {
	return n >= 0 && n < _pipesNum;
}

void FlexActuator::inflate() {
	openAll();
	// TODO: close valves after some time
}

void FlexActuator::deflate() {
	// TODO
}

void FlexActuator::openAll() {
	for (auto i = 0; i < _pipesNum; i++)
		_pipes[i]->open();
}

void FlexActuator::closeAll() {
	for (auto i = 0; i < _pipesNum; i++)
		_pipes[i]->close();
}

const FlexPipe *FlexActuator::operator[](byte n) const {
	if (n < _pipesNum)
		return _pipes[n];

	return nullptr;
}
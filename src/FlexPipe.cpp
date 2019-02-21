#include "FlexPipe.h"

FlexPipe::FlexPipe() : _valvePin(0), _sensorPin(0) {}

FlexPipe::~FlexPipe() {}

void FlexPipe::attach(byte valvePin)
{
	_valvePin = valvePin;
	pinMode(_valvePin, OUTPUT);
	digitalWrite(_valvePin, LOW);
}

void FlexPipe::attach(byte valvePin, byte sensorPin)
{
	attach(valvePin);
	_sensorPin = sensorPin;
}

void FlexPipe::open()
{
	if (_valvePin)
		digitalWrite(_valvePin, HIGH);
}

void FlexPipe::close()
{
	if (_valvePin)
		digitalWrite(_valvePin, LOW);
}

void FlexPipe::toggle()
{
	if (_valvePin)
		digitalWrite(_valvePin, !digitalRead(_valvePin));
}

bool FlexPipe::state()
{
	if (_valvePin)
		return digitalRead(_valvePin);

	return false;
}

float FlexPipe::pressure()
{
	if (_sensorPin)
		return float(analogRead(_sensorPin)) * 8. / 1023.;

	return -1.;
}

int FlexPipe::_pressure()
{
	if (_sensorPin)
		return analogRead(_sensorPin);

	return -1;
}

FlexPipe::operator bool()
{
	return state();
}

bool FlexPipe::operator!()
{
	return !state();
}

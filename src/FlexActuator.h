#ifndef FlexActuator_h
#define FlexActuator_h

#include <Arduino.h>
#include "FlexPipe.h"

class FlexActuator {
public:
	/**
	 * \brief Constructor
	 */
	FlexActuator(byte pipesNum);

	/**
	 * \brief Destructor
	 */
	~FlexActuator();

	void attachValves(const byte valvePins[]);
	void attachSensors(const byte sensorPins[]);

	byte pipesNum();
	bool checkNum(byte n);

	void openAll();
	void closeAll();

	void inflate();
	void deflate();

	const FlexPipe *operator[](byte n) const;

private:
	byte _pipesNum;
	FlexPipe **_pipes;

	byte *_valves;
	byte *_sensors;
};

#endif // FlexActuator_h

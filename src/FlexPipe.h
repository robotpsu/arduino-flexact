#ifndef FlexPipe_h
#define FlexPipe_h

#include <Arduino.h>

class FlexPipe;
typedef FlexPipe* FlexPipePtr;

/**
 * \brief Flexible pipe control class.
 */
class FlexPipe {
public:
	/**
	 * \brief Default constructor.
	 */
	FlexPipe();
	/**
	 * \brief Destructor.
	 * \details Does nothing.
	 */
	~FlexPipe();

	void attach(byte valvePin);
	void attach(byte valvePin, byte sensorPin);

	void open();
	void close();
	void toggle();

	/**
	 * \brief Get valve state.
	 * \return
	 *   - \c true (\c HIGH) - opened;
	 *   - \c false (\c LOW) - closed.
	 */
	bool state();
	/**
	 * \brief Get pressure from sensor in bars.
	 * \return Pressure in bars.
	 */
	float pressure();

	explicit operator bool();
	bool operator!();

private:
	byte _valvePin;
	byte _sensorPin;

	int _pressure();
};

#endif // FlexPipe_h

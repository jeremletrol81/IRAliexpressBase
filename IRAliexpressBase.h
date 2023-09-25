#ifndef IRAliexpressBase_H
#define IRAliexpressBase_H

#include <Arduino.h>

class IRAliexpressBase
{
public:
	void init(uint8_t data_pin, uint16_t delay_burst = 560, uint16_t delay_lead = 9000, uint16_t delay_space = 4500, uint16_t delay_0 = 560, uint16_t delay_1 = 1690);
	void begin(uint16_t address);
	void send(uint8_t code);

private:
	struct Config {
		uint8_t data_pin;
		uint16_t delay_burst;
		uint16_t delay_lead;
		uint16_t delay_space;
		uint16_t delay_0;
		uint16_t delay_1;
	} config;

	uint16_t address = 0x0000;

	void send_0();
	void send_1();
	void send_byte(uint8_t c);
};
#endif 
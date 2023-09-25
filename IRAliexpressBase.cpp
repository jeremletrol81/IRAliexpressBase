#include "IRAliexpressBase.h"

void IRAliexpressBase::init(uint8_t data_pin, uint16_t delay_burst, uint16_t delay_lead, uint16_t delay_space, uint16_t delay_0, uint16_t delay_1)
{
    config.data_pin = data_pin;
    config.delay_burst = delay_burst;
    config.delay_lead = delay_lead;
    config.delay_space = delay_space;
    config.delay_0 = delay_0;
    config.delay_1 = delay_1;
}

void IRAliexpressBase::begin(uint16_t address)
{
    this->address = address;
}

void IRAliexpressBase::send_0()
{
    digitalWrite(config.data_pin, LOW);
    delayMicroseconds(config.delay_burst);
    digitalWrite(config.data_pin, HIGH);
    delayMicroseconds(config.delay_0);
}

void IRAliexpressBase::send_1()
{
    digitalWrite(config.data_pin, LOW);
    delayMicroseconds(config.delay_burst);
    digitalWrite(config.data_pin, HIGH);
    delayMicroseconds(config.delay_1);
}

void IRAliexpressBase::send_byte(uint8_t c)
{
  for (int bits = 0; bits < 8; bits++)
  {
    if (c & (1 << bits))
    {
      send_1();
    }
    else
    {
      send_0();
    }
  }
}

void IRAliexpressBase::send(uint8_t code)
{
    pinMode(config.data_pin, OUTPUT);

    digitalWrite(config.data_pin, LOW);
    delayMicroseconds(config.delay_lead);
    digitalWrite(config.data_pin, HIGH);
    delayMicroseconds(config.delay_space);

    send_byte(address & 0xFF);
    send_byte(address >> 8);

    send_byte(code);
    send_byte(~code);

    digitalWrite(config.data_pin, LOW);
    delayMicroseconds(config.delay_burst);

    digitalWrite(config.data_pin, HIGH);
    delayMicroseconds(config.delay_space);

    pinMode(config.data_pin, INPUT);
}

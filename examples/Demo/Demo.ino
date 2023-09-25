#include <IRAliexpressBase.h>

#define OUTPUT_PIN 9

IRAliexpressBase ir;

void setup()
{
  ir.init(OUTPUT_PIN);
  ir.begin(0xEF00);
}

void loop()
{
  ir.send(0x3);  // ON
  delay(2000);
  ir.send(0x2);  // OFF
  delay(2000);
} 
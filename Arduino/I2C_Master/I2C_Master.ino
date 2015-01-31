#include <Wire.h>

byte incomingByte = 0;

void setup()
{
  Serial.begin(9600);
  Wire.begin(2); // join i2c bus (address optional for master)
  Serial.print("Enabled!");
  Wire.write("Hello world");
}

void loop()
{
  if (Serial.available() > 0)
  {
    Wire.write("Message: ");
    incomingByte = Serial.read();
    Wire.write(incomingByte);
    Serial.write(incomingByte);
  }
}




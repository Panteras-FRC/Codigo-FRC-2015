#include <Wire.h>

int incomingByte = 0;

void setup()
{
  Serial.begin(9600);
  Wire.begin(2); // join i2c bus (address optional for master)
  Serial.print("Enabled!");
  Wire.beginTransmission(2); // transmit to device #4
  Wire.write("Hello world");
  Wire.endTransmission();    // stop transmitting
}

byte x = 0;

void loop()
{
  if (Serial.available() > 0)
  {
    Wire.beginTransmission(2); // transmit to device #4
    Wire.write("Message: ");
    incomingByte = Serial.read();
    Wire.write("I received: ");
    Wire.write(incomingByte);
    Wire.endTransmission();    // stop transmitting
  }
  Wire.write("H");
  
  delay(500);
}




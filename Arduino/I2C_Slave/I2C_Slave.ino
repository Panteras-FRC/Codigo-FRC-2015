#include <Wire.h>
#define LIDARLite_ADDRESS 0x62 // Default I2C Address of LIDAR-Lite.
#define RegisterMeasure 0x00 // Register to write to initiate ranging.
#define MeasureValue 0x04 // Value to initiate ranging.
#define RegisterHighLowB 0x8f // Register to get both High and Low bytes in 1 call.

int reading, readingLo, readingHi = 0;
const byte SlaveDeviceId = 2;

void setup()
{
  Wire.begin(SlaveDeviceId);
  Wire.onReceive(receiveCallback);
  Wire.onRequest(requestCallback);
  Serial.begin(9600);
}

void loop()
{
  sensorRead();
}

// aCount is the number of bytes received.
void receiveCallback(int aCount)
{
  if(aCount == 4)
  {
    char receivedValue = Wire.read() << 8;
    receivedValue |= Wire.read();
    Serial.println(receivedValue);
  }
  else
  {
    Serial.print("Unexpected number of bytes received: ");
    Serial.println(aCount);
  }
}

void requestCallback(){
  Serial.println("data requested");
  Wire.write(reading);
}

void sensorRead(){
  Wire.beginTransmission((int)LIDARLite_ADDRESS); // transmit to LIDAR-Lite
  Wire.write((int)RegisterMeasure); // sets register pointer to (0x00)
  Wire.write((int)MeasureValue); // sets register pointer to (0x00)
  Wire.endTransmission(); // stop transmitting
  delay(20); // Wait 20ms for transmit
  Wire.beginTransmission((int)LIDARLite_ADDRESS); // transmit to LIDAR-Lite
  Wire.write((int)RegisterHighLowB); // sets register pointer to (0x8f)
  Wire.endTransmission(); // stop transmitting
  delay(20); // Wait 20ms for transmit
  Wire.requestFrom((int)LIDARLite_ADDRESS, 2); // request 2 bytes from LIDAR-Lite
  if(2 <= Wire.available()){ // if two bytes were received
    readingHi = Wire.read(); // receive high byte (overwrites previous reading)
    readingLo = Wire.read(); // receive low byte as lower 8 bits
    reading = (readingHi << 8) + readingLo;
    Serial.println(reading); // print the reading
  }
}

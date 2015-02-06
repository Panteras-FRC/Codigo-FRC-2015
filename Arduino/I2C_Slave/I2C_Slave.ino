#include <Wire.h>
#define SlaveDeviceId 0x64 // ID Arduino

int Red, Green, Blue;

void setup()
{
  Wire.begin(SlaveDeviceId);
  Wire.onReceive(receiveCallback);
  Wire.onRequest(requestCallback);
  Serial.begin(9600);
  Serial.println("Enabled!");
}

void loop()
{
}

// aCount is the number of bytes received.
void receiveCallback(int aCount)
{
  int registerValue = Wire.read();
  switch (registerValue){
  case 0x0:
    Red = Wire.read();
    Green = Wire.read();
    Blue = Wire.read();
    Serial.println(Red);
    Serial.println(Green);
    Serial.println(Blue);
    break;
  case 0x01:
    char message;
    for(int i = 0; i <= (aCount-1); i++){
      message = message + Wire.read();
    }
    Serial.println(message);
    break;
  default:
    break;
  }
}

void requestCallback(){
  Serial.println("Data Requested");
}




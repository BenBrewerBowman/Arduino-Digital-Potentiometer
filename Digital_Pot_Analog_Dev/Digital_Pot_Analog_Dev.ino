/*
 * Arduino digital potentiometer control for: AD5171BRJZ5-R2, Analog Devices Inc., 5kOhm. 
 * (May work with other potentiometers by same manufacturer, untested.)
 * 
 * Fluctuates potentiometer from no resistance to full resistance, waits half a second, and then back down. Goes up and down indefinitely.
 * 
 * digitalpotwrite values:
 * 0   =  no voltage
 * 64  =  half voltage
 * 128 =  full voltage
 */

#include <SPI.h>

#define PotWiperVoltageIn A15   //Analog input for reading VIN                      
#define CS 53                   //MOSI pin (53 on Arduino Mega, will change depending on controller)
                   
int address = 0x00;             //Adress of slave

void setup()
{
  Serial.begin(9600);
 
  pinMode (CS, OUTPUT);
  SPI.begin();
}


void loop()
{
  float Voltage = 0;

  // Increment potentiometer up to full resistance
  for (int i = 0; i <= 128; i++) {
    digitalPotWrite(i);                                           //Tell dig pot what resistance
    delay(20);
    Voltage = map(analogRead(PotWiperVoltageIn), 0, 1023, 0, 5);  //Read voltage into analog input
    Serial.println(Voltage);
  } 
  delay(500);

  // Decrement potentiometer down to zero resistance
  for (int i = 128; i >= 0; i--) {
    digitalPotWrite(i);                                           //Tell dig pot what resistance
    delay(20);
    Voltage = map(analogRead(PotWiperVoltageIn), 0, 1023, 0, 5);  //Read voltage into analog input
    Serial.println(Voltage);
  }
  delay(500);
}


// Send data to digital potentiometer
int digitalPotWrite(int value)
{
digitalWrite(CS, LOW);    //MOSI LOW, signals data transfer
SPI.transfer(address);    //Slave Select 
SPI.transfer(value);      //Sends potentiometer value
digitalWrite(CS, HIGH);   //MOSI HIGH, end of data transfer
}

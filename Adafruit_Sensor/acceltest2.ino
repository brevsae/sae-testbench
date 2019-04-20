#include "SparkFunLIS3DH.h"
#include "Wire.h"
#include "SPI.h"
#include "PushButton.h"
//LIS3DH myIMU; //Default constructor is I2C, addr 0x19.
#define accelSen1 10;

#define killPin 5;

  float maxaccel = 8;
  int PKILL = 5;
  PushButton killSwitch(killPin);


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  delay(1000); //relax...
  Serial.println("Processor came out of reset.\n");
 
 
 
  myIMU.begin();
  
}


void loop()
{
  delay(250);
    
    //for 1 sensor
   myIMU.settings.accelRange = 8;
  float gx1 = myIMU.readFloatAccelX();
  float gy1 = myIMU.readFloatAccelY();
  float gz1 = myIMU.readFloatAccelZ();
 
  
  if (gx1 > maxAccel || gy1 > maxAccel || gz1 > maxAccel || killSwitch.isPressed())
  { //check if any readings are above 6g or if the killswitch is manually pressed
  Serial.println("SHUTTING DOWN 1");
  digitalWrite(killSwitch, HIGH); 
    return PKILL;
  }
    
  if (isnan(gx) || isnan(gy) || isnan(gz))
    { //check if any reads failed and exited early
    Serial.print("Failed to read from Sensor");
    }   
   
  
  //Get all parameters
  Serial.print("\nAccelerometer:\n");
  Serial.print(" X = ");
  Serial.println(myIMU.readFloatAccelX(), 8);
  Serial.print(" Y = ");
  Serial.println(myIMU.readFloatAccelY(), 8);
  Serial.print(" Z = ");
  Serial.println(myIMU.readFloatAccelZ(), 8);
  Serial.println("----------------------------------------------------------------") //end of sensor 1 readings

 
  
















}

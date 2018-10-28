// Example testing sketch for various DHT humidity/temperature sensors
//Original version written by ladyada to the public domain

#include "DHT.h"
#include "Pushbutton.h"

#define tempSen1 2     // what digital pin we're connected to
#define tempSen2 3
#define tempSen3 4

#define killPin 5 
#define onPin 8

// Uncomment whatever type you're using!
#define DHTType11 DHT11   // DHT 11
#define DHTType22 DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your tempSen1 is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(tempSen1, DHTType11);
DHT dht1(tempSen2, DHTType22);
DHT dht2(tempSen3, DHTType22);

Pushbutton killSwitch(killPin);

int PKILL = 5;
float TEMPLIMIT = 30.0;

void setup() {
  Serial.begin(9600);
  Serial.println("Formula SAE promises no cell will reach 1000000 C!");

// Running 2 begin functions is causing trouble!
  //dht.begin();
  digitalWrite(onPin, HIGH);
  dht.begin();
//  delay(1000);
//  dht1.begin();
//  delay(1000);
//  dht2.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  /**///Print out left (non-Emanuel first)!
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float hleft = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t1 = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float fleft = dht.readTemperature(true);
  if (t1 > TEMPLIMIT /*|| killSwitch.isPressed()*/){
    Serial.println("SHUTTING DOWN 1");
    digitalWrite(onPin, LOW);
    digitalWrite(killPin, HIGH);
    return PKILL;
  }
  // Check if any reads failed and exit early (to try again).
  if (isnan(hleft) || isnan(t1) || isnan(fleft)) {
    Serial.println("Failed to read from tempSen1 sensor!"); 
    //digitalWrite(onPin, LOW);
    //digitalWrite(killPin, HIGH);
    //return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hifleft = dht.computeHeatIndex(fleft, hleft);
  // Compute heat index in Celsius (isFahreheit = false)
  float hicleft = dht.computeHeatIndex(t1, hleft, false);

  Serial.print("Left Humidity: ");
  Serial.print(hleft);
  Serial.print(" %\t");
  Serial.print("Left Temperature: ");
  Serial.print(t1);
  Serial.print(" *C ");
  Serial.print(fleft);
  Serial.print(" *F\t");
  Serial.print("Left Heat index: ");
  Serial.print(hicleft);
  Serial.print(" *C ");
  Serial.print(hifleft);
  Serial.println(" *F");

  ///new sensor being read
  Serial.println("------------------------------------------");

   hleft = dht1.readHumidity();
  // Read temperature as Celsius (the default)
   float t2 = dht1.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
   fleft = dht1.readTemperature(true);
  if (t2 > TEMPLIMIT /*|| killSwitch.isPressed()*/){
    Serial.println("SHUTTING DOWN2");
    digitalWrite(onPin, LOW);
    digitalWrite(killPin, HIGH);
    return PKILL;
  }
  // Check if any reads failed and exit early (to try again).
  if (isnan(hleft) || isnan(t2) || isnan(fleft)) {
    Serial.println("Failed to read from tempSen2 sensor!");
    //digitalWrite(onPin, LOW);
   // digitalWrite(killPin, HIGH);
    //return;
  }

  // Compute heat index in Fahrenheit (the default)
   hifleft = dht1.computeHeatIndex(fleft, hleft);
  // Compute heat index in Celsius (isFahreheit = false)
   hicleft = dht1.computeHeatIndex(t2, hleft, false);

  Serial.print("Left Humidity: ");
  Serial.print(hleft);
  Serial.print(" %\t");
  Serial.print("Left Temperature: ");
  Serial.print(t2);
  Serial.print(" *C ");
  Serial.print(fleft);
  Serial.print(" *F\t");
  Serial.print("Left Heat index: ");
  Serial.print(hicleft);
  Serial.print(" *C ");
  Serial.print(hifleft);
  Serial.println(" *F");

  //new sensor being read
  Serial.println("------------------------------------------");


/**/
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht2.readHumidity();
  // Read temperature as Celsius (the default)
  float t3 = dht2.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht2.readTemperature(true);

  if (t3 > TEMPLIMIT /*|| killSwitch.isPressed()*/){
    Serial.println("SHUTTING DOWN 3");
     digitalWrite(onPin, LOW);
    digitalWrite(killPin, HIGH);
    return PKILL;
  }
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t3) || isnan(f)) {
    Serial.println("Failed to read from tempSen3 sensor!");
    //digitalWrite(onPin, LOW);
    //digitalWrite(killPin, HIGH);
    //return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht2.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht2.computeHeatIndex(t3, h, false);

  Serial.print("Right Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Right Temperature: ");
  Serial.print(t3);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Right Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");


  Serial.println("---------------DONE------------------"); 
  if (isnan(t1) && isnan(t2) && isnan(t3)) {
    Serial.println("Failed to read from all Temperature Sensors! Emergency Shut Down! ");
    digitalWrite(onPin, LOW);
    digitalWrite(killPin, HIGH);
    //return;
  }

}

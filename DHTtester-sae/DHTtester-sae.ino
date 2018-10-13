// Example testing sketch for various DHT humidity/temperature sensors
//Original version written by ladyada to the public domain

#include "DHT.h"
#define DHTPIN 2     // what digital pin we're connected to

#define tempSen 4
// Uncomment whatever type you're using!
#define DHTTYPE11 DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE11);
DHT dhte(tempSen, DHTTYPE);
int PKILL = 5;
float TEMPLIMIT = 30.0;

void setup() {
  Serial.begin(9600);
  Serial.println("Formula SAE promises no cell will reach 1000000 C!");

// Running 2 begin functions is causing trouble!
  //dht.begin();
  dhte.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  /**///Print out left (non-Emanuel first)!
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float hleft = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float tleft = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float fleft = dht.readTemperature(true);
  if (tleft > TEMPLIMIT){
    Serial.println("SHUTTING DOWN");
    return PKILL;
  } 
  // Check if any reads failed and exit early (to try again).
  if (isnan(hleft) || isnan(tleft) || isnan(fleft)) {
    Serial.println("Failed to read from DHTPIN sensor!");
    //return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hifleft = dht.computeHeatIndex(fleft, hleft);
  // Compute heat index in Celsius (isFahreheit = false)
  float hicleft = dht.computeHeatIndex(tleft, hleft, false);

  Serial.print("Left Humidity: ");
  Serial.print(hleft);
  Serial.print(" %\t");
  Serial.print("Left Temperature: ");
  Serial.print(tleft);
  Serial.print(" *C ");
  Serial.print(fleft);
  Serial.print(" *F\t");
  Serial.print("Left Heat index: ");
  Serial.print(hicleft);
  Serial.print(" *C ");
  Serial.print(hifleft);
  Serial.println(" *F");

  
/**/
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dhte.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dhte.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dhte.readTemperature(true);
  
  if (t > TEMPLIMIT){
    Serial.println("SHUTTING DOWN");
    return PKILL;
  }
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from tempSen sensor!");
    //return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dhte.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dhte.computeHeatIndex(t, h, false);

  Serial.print("Right Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Right Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Right Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
}
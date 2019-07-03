#include "Adafruit_Si7021.h"
#include "HardwareSerial.h"
#include <dht.h>
Adafruit_Si7021 sensor = Adafruit_Si7021();
dht DHT;

#define DHT11_PIN 7
void setup() {
  Serial.begin(9600);

  // wait for serial port to open
//  while (!Serial) {
    delay(10);
  //}

  Serial.println("Si7021 and DHT11 test!");
  
  if (!sensor.begin()) {
    Serial.println("Did not find Si7021 sensor!");
    while (true)
      ;
  }

  //Serial.print("Found model ");
  switch(sensor.getModel()) {
    case SI_Engineering_Samples:
      //Serial.print("SI engineering samples"); break;
    case SI_7013:
      //Serial.print("Si7013"); break;
    case SI_7020:
      //Serial.print("Si7020"); break;
    case SI_7021:
      //Serial.print("Si7021"); break;
    case SI_UNKNOWN:
    default:;
      //Serial.print("Unknown");
  }
  //Serial.print(" Rev(");
  //Serial.print(sensor.getRevision());
  //Serial.print(")");
  //Serial.print(" Serial #"); Serial.print(sensor.sernum_a, HEX); Serial.println(sensor.sernum_b, HEX);
}

void loop() {

  //SI7021
  Serial.print("SI7021 Humidity = ");
  Serial.print(sensor.readHumidity(), 2);
  Serial.print("\tTemperature = ");
  Serial.print(sensor.readTemperature(), 2);
  Serial.print("\n");

  //DHT
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("DHT11 Humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("\tTemperature = ");
  Serial.print(DHT.temperature);
  Serial.print("\n");
  delay(8000);
}

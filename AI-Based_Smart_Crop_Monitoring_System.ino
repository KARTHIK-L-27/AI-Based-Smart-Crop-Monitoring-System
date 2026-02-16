#include <ESP8266WiFi.h>
#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int soil = A0;
int relay = D5;

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  dht.begin();
}

void loop() {
  int soilValue = analogRead(soil);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.print("Soil: ");
  Serial.print(soilValue);
  Serial.print(" Temp: ");
  Serial.print(temp);
  Serial.print(" Humidity: ");
  Serial.println(hum);

  if (soilValue < 400) {
    digitalWrite(relay, HIGH);  // Irrigation ON
  } else {
    digitalWrite(relay, LOW);
  }

  delay(5000);
}

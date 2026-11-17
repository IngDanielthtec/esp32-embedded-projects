
#include <stdint.h>
#include "DHT.h"

#define IN1_PIN 5
#define IN2_PIN 4

#define DHTPIN 22
#define DHTTYPE DHT22


DHT dhtSensor(DHTPIN, DHTTYPE);

//Variables
float humedad = 0.0;
float temperatura = 0.0;

void setup() 
{
  //Config GPIO
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);

  //Relays inactivos
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, HIGH);

  Serial.begin(115200);

  //Inicializar el sensor
  dhtSensor.begin();
}

void loop() 
{
  delay(2000);
  humedad = dhtSensor.readHumidity();
  temperatura = dhtSensor.readTemperature();

  Serial.printf("Sensor DTH22 \r\n");
  Serial.printf("Temperatura: %.2f \r\n", temperatura);
  Serial.printf("Humedad Rl.: %.2f \r\n\r\n", humedad);

  if(temperatura > 32)
  {
    Serial.printf("Sensor Exesiva Alerta! \r\n\r\n");
    //Relays activos
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, LOW);
  }
  else
  {
    Serial.printf("Sensor Normal! \r\n\r\n");
    //Relays apagados
    digitalWrite(IN1_PIN, HIGH);
    digitalWrite(IN2_PIN, HIGH);
  }
}


#include "max6675.h"

#define MAX_SO   19
#define MAX_SCK  18
#define MAX_CS   5

MAX6675 moduloMax(MAX_SCK, MAX_CS, MAX_SO);

//Variables
float tempF = 0.0;
float tempC = 0.0;


void setup() 
{
  // UART0
  Serial.begin(9600);

}

void loop() 
{
  //Leer temeratura C y F
  tempC = moduloMax.readCelsius(); 
  tempF = moduloMax.readFahrenheit(); 

  Serial.printf(">> Sistama de monitero de temperatura << \n");
  Serial.printf("Temp. Actual: %.2f C  ---  %.2f F \n\n", tempC, tempF);

  //Tarae imprimir a travez de una pantalla (OLED o LCD)

  delay(1000);
}

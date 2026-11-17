
/*
Datos del sensor de humeda de suelo
-----------------------------------

V_A0 = 0........3.3V
ADC  = 0....2048...4095
hmd  = 100%..50%...0%

valorEscalado = map(ADC, 0, 4095, 100, 0);

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
*/


#include <stdint.h>

//Macros
#define ADC1_CH7_SENSOR_HMD 35
//Parametros del ADC
//#define ADC_VREF        3.3
//#define ADC_RESOLUCION  4096.0

//Prototipos de funciones
long map(long x, long in_min, long in_max, long out_min, long out_max);

//Variables
uint16_t valorADC = 0; //0...4095
uint16_t valorHumedad = 0; // 0....100%

void setup() 
{
  Serial.begin(115200);

  //Set ADC
  analogSetWidth(12); //Resolucion 12 bits

}

void loop() 
{
  valorADC = analogRead(ADC1_CH7_SENSOR_HMD); //Leemos el valor crudo del sensor
  valorHumedad = map(valorADC, 0, 4095, 100, 0); //Escalamos el valor a humedad de suelo

  Serial.printf("Higrometro: %u %% \n", valorHumedad);

  delay(2000);
}

//Desarrollo de funciones
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}




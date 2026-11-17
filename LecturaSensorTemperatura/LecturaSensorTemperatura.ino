/*
RELACION PARA EL SENSOR MCP9700A / MCP9701A ( -40 .... 150 °C )
(Factor de escala es: °C/10mV)

-40°c -> ???
-3°c  -> 470mV
-2°c  -> 480mV
-1°c  -> 490mV
0°c   -> 500mV -> 0.5V
1°c   -> 510mV
2°c   -> 520mV
3°c   -> 530mV
4°c   -> 540mV
10°c   -> 600mV
20°c   -> 700mV
30°c   -> 800mV
40°c   -> 900mV
50°c   -> 1000mV -> 1v
60°c   -> 1100mV -> 1.1v
70°c   -> 1200mV -> 1.2v
80°c   -> 1300mV -> 1.3v
90°c   -> 1400mV -> 1.4v
100°c  -> 1500mV -> 1.5v
110°c  -> 1600mV -> 1.6v
120°c  -> 1700mV -> 1.7v
130°c  -> 1800mV -> 1.8v
140°c  -> 1900mV -> 1.9v
150°c  -> 2000mV -> 2.0v

Formula para convertir el voltaje a temperatura

temp = (voutSensor - 0.5V) / 0.01V;

*/


#include <stdint.h>

#define ADC1_CH4_SENSOR  32
#define ADC_VREF        3.3
#define ADC_RESOLUCION  4096.0


//Variables
float voutSensor = 0.0;
float temperatura = 0.0;

void setup() 
{
  Serial.begin(115200);

  //Set Resolucion
  analogSetWidth(12);
}

void loop() 
{
  voutSensor = (analogRead(ADC1_CH4_SENSOR) * (ADC_VREF/ADC_RESOLUCION));
  temperatura = (voutSensor - 0.5) / 0.01; // tempLM35 = voutSensor / 0.01;
  //temperatura = voutSensor / 0.01;


  Serial.printf("Vout Sensor: %.2f V \n", voutSensor);
  Serial.printf("Temperatura: %.2f C \n\n", temperatura);

  delay(2000);
}

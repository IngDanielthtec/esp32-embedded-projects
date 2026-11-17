
#include <Servo.h>
#include <stdint.h>

#define SERVO_PIN 13

Servo microServo; //Creamos un objeto para menejo de nuestro servo


void setup() 
{
  //UART0
  Serial.print(115200);

  //Inicializar servo (configurar el pin de control)
  microServo.attach(SERVO_PIN);
}

void loop() 
{
  for(int16_t angulo = 0; angulo <= 180; angulo++)
  {
    microServo.write(angulo); 
    delay(50);
  }

  for(int16_t angulo = 180; angulo >= 0; angulo--)
  {
    microServo.write(angulo); 
    delay(50);
  }
  
}



#include <stdint.h>

//Pines PWM para control de motores
#define MT_A_PIN_PWM 4
#define MT_B_PIN_PWM 2

//Pines de control de direccion de motores
#define IN1   21
#define IN2   19
#define IN3   18
#define IN4   5

//Parametros de PWM
#define PWM_CHANNEL0 0
#define PWM_CHANNEL1 1
#define PWM_FREQ     5000 // 5Khz
#define PWM_RES      8    // 0...255 (0...100%)

//Prototipos de funcion
void PWM_SetDutyCyle (uint8_t channel, uint8_t dutyCycle);


//Variables
char datoRx;
uint8_t valor = 0;

void setup() 
{
  //Config UARt0
  Serial.begin(115200);

  //Config GPIO
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //Config LEDC PWM
  ledcSetup(PWM_CHANNEL0, PWM_FREQ, PWM_RES);
  ledcSetup(PWM_CHANNEL1, PWM_FREQ, PWM_RES);

  //Vincular canales PWM con pines
  ledcAttachPin(MT_A_PIN_PWM, PWM_CHANNEL0);
  ledcAttachPin(MT_B_PIN_PWM, PWM_CHANNEL1);

  //Estado inicial de los motores
  //Motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  PWM_SetDutyCyle (PWM_CHANNEL0, 0); // 0% duty cycle
  //Motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  PWM_SetDutyCyle (PWM_CHANNEL1, 0); // 0% duty cycle
  Serial.printf("Motores inciados Ok!\r\n");
}

void loop() 
{
  if(Serial.available() > 0)
  {
    //Leer dato
    datoRx = Serial.read();

    //Evaluar dato recibido
    switch(datoRx)
    {
      case 'A': //Giro adelante
      Serial.printf("Motores Adelante!\r\n");
      //Motor A
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      //Motor B
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;

      case 'T': //Giro atras
      Serial.printf("Motores Atras!\r\n");
      //Motor A
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      //Motor B
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;

      case 'S': //Motores Pare
      Serial.printf("Motores Pare!\r\n");
      //Motor A
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      PWM_SetDutyCyle (PWM_CHANNEL0, 0); // 0% duty cycle
      //Motor B
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      PWM_SetDutyCyle (PWM_CHANNEL1, 0); // 0% duty cycle
      valor = 0;
      break;

      case 'P':
      Serial.printf("Motores Incremento de velocidad!\r\n");
      valor++; //incrementar en 1 a la variable

      if(valor == 1)
      {
        PWM_SetDutyCyle (PWM_CHANNEL0, 30); //Motor A PWM
        PWM_SetDutyCyle (PWM_CHANNEL1, 30); //Motor B PWM
      }
      else if(valor == 2)
      {
        PWM_SetDutyCyle (PWM_CHANNEL0, 50); //Motor A PWM
        PWM_SetDutyCyle (PWM_CHANNEL1, 50); //Motor B PWM
      }
      else if(valor == 3)
      {
        PWM_SetDutyCyle (PWM_CHANNEL0, 70); //Motor A PWM
        PWM_SetDutyCyle (PWM_CHANNEL1, 70); //Motor B PWM
      }
      else if(valor == 4)
      {
        PWM_SetDutyCyle (PWM_CHANNEL0, 100); //Motor A PWM
        PWM_SetDutyCyle (PWM_CHANNEL1, 100); //Motor B PWM

        //Reset valor
        valor = 0;
      }
      break;
    }
  }
}

//Desarrollo de funciones
void PWM_SetDutyCyle (uint8_t channel, uint8_t dutyCycle)
{
  uint8_t dataPWM = 0;

  dataPWM = (uint8_t)map(dutyCycle, 0, 100, 0, 255); // map(valEntrada, input_min, input_max, out_min, out_max); 

  ledcWrite(channel, dataPWM);
}

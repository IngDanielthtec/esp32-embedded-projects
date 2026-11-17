
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
}

void loop() 
{
  //Motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  //Set PWM
  PWM_SetDutyCyle(PWM_CHANNEL0, 40); // Motor A PWM = 0...100%
  PWM_SetDutyCyle(PWM_CHANNEL1, 40); // Motor B PWM = 0...100%
  delay(3000);

  PWM_SetDutyCyle(PWM_CHANNEL0, 60); // Motor A PWM = 0...100%
  PWM_SetDutyCyle(PWM_CHANNEL1, 60); // Motor B PWM = 0...100%
  delay(3000);

  PWM_SetDutyCyle(PWM_CHANNEL0, 80); // Motor A PWM = 0...100%
  PWM_SetDutyCyle(PWM_CHANNEL1, 80); // Motor B PWM = 0...100%
  delay(3000);

  PWM_SetDutyCyle(PWM_CHANNEL0, 100); // Motor A PWM = 0...100%
  PWM_SetDutyCyle(PWM_CHANNEL1, 100); // Motor B PWM = 0...100%
  delay(3000);
}

//Desarrollo de funciones
void PWM_SetDutyCyle (uint8_t channel, uint8_t dutyCycle)
{
  uint8_t dataPWM = 0;

  dataPWM = (uint8_t)map(dutyCycle, 0, 100, 0, 255);

  ledcWrite(channel, dataPWM);
}

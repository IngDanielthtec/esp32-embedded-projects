
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN   4
#define DHTTYPE  DHT22

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x3F, 16, 2);


float temperatura = 0.0;
float humedadRelativa = 0.0;

void setup() {

  Serial.begin(115200);

  //Inicializa la configuracion del sensor
  dht.begin();

  lcd.init(); // LCD Init - Default I2C0 y lo pines
  lcd.backlight(); // Enciende la luz de fondo de la pantalla LCD
}

void loop() 
{
  humedadRelativa = dht.readHumidity();
  temperatura     = dht.readTemperature();

  lcd.clear();
  lcd.setCursor(0, 0);  // setCursor(columna, fila);  -> columna(0...15), fila(0..1)
  lcd.print("T:");
  lcd.print(temperatura);
  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(humedadRelativa);

  delay(2000);
}

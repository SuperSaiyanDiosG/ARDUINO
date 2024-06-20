#include <NewPing.h> //Librería para el sensor ultrasónico
#include <LiquidCrystal.h> //Librería para la pantalla LCD

const int trigPin = 9; //Pin conectado al trigger del sensor ultrasónico
const int echoPin = 10; //Pin conectado al echo del sensor ultrasónico
const int maxDistance = 200; //Distancia máxima a detectar (en cm)
const int servoPin = 11; //Pin conectado al servo motor
const int ledRojoPin = 12; //Pin del LED rojo
const int ledVerdePin = 13; //Pin del LED verde

NewPing sonar(trigPin, echoPin, maxDistance); //Creación del objeto NewPing
LiquidCrystal lcd(13, 12, 7, 6, 5, 4); //Creación del objeto LiquidCrystal

void setup() {
  lcd.begin(16, 2); //Inicializar la pantalla LCD
  pinMode(ledRojoPin, OUTPUT); //Configurar el pin del LED rojo como salida
  pinMode(ledVerdePin, OUTPUT); //Configurar el pin del LED verde como salida
  pinMode(servoPin, OUTPUT); //Configurar el pin del servo motor como salida
}

void loop() {
  int distance = sonar.ping_cm(); //Medir la distancia al objeto
  
  if (distance <= maxDistance) { //Si el objeto está dentro de la distancia máxima
    lcd.print("Objeto detectado!"); //Mostrar mensaje en la pantalla LCD
    lcd.setCursor(0, 1); //Mover el cursor a la segunda línea
    lcd.print("Distancia: "); //Mostrar texto "Distancia: "
    lcd.print(distance); //Mostrar la distancia en cm
    lcd.print(" cm"); //Mostrar la unidad de medida (cm)
    digitalWrite(ledRojoPin, HIGH); //Encender el LED rojo
    digitalWrite(ledVerdePin, LOW); //Apagar el LED verde
    servoMotor.attach(servoPin); //Conectar el servo motor al pin
    servoMotor.write(90); //Girar el servo motor a 90 grados (activar la alarma)
  } else { //Si no se detecta ningún objeto
    lcd.clear(); //Limpiar la pantalla LCD
    lcd.print("Sin objetos detectados"); //Mostrar mensaje en la pantalla LCD
    digitalWrite(ledRojoPin, LOW); //Apagar el LED rojo
    digitalWrite(ledVerdePin, HIGH); //Encender el LED verde
    servoMotor.write(0); //Girar el servo motor a 0 grados (desactivar la alarma)
  }
  delay(500); //Esperar 500 milisegundos
}


/*Cómo hacer un semáforo con Arduino
Existen diferentes maneras de hacer un semáforo con Arduino, pero la idea básica es la misma: utilizar LEDs para representar las luces roja, amarilla y verde, y programar la placa Arduino para que las encienda y apague en la secuencia correcta.

Materiales necesarios:

Arduino Uno R3
Protoboard
3 LEDs (rojo, amarillo y verde)
3 resistencias de 220 Ω
Cables dupont
Cable USB para Arduino
Pasos a seguir:

Conectar los componentes:

Conecte los LEDs a la protoboard de la siguiente manera:
LED rojo: pin 13
LED amarillo: pin 12
LED verde: pin 11
Conecte las resistencias de 220 Ω a cada LED, una entre el LED y la protoboard, y la otra entre el LED y el pin de Arduino correspondiente.
Conecte el cable USB a la placa Arduino y al ordenador.
Programar la placa Arduino:

Abra el IDE de Arduino y cree un nuevo proyecto.
Copie y pegue el siguiente código en el IDE:
Ejecutar el programa:
Una vez que el código se haya subido a la placa Arduino, el semáforo debería empezar a funcionar automáticamente.
Recursos adicionales:

Semáforo con ARDUINO en 5 MINUTOS: Impresionante - YouTube
SEMÁFORO con ARDUINO (Tinkercad) 🚥
Semáforo con Arduino
Cómo hacer un Semáforo con arduino
🚦 Semáforo con ARDUINO en 5 MINUTOS: Impresionante 🤖
Consejos:

Puede modificar el código para cambiar la duración de las luces.
Puede agregar un botón para que los peatones puedan solicitar el paso.
Puede utilizar LEDs RGB para tener más opciones de colores.
Espero que esta información te sea útil. Si tienes alguna otra pregunta, no dudes en contactarme.*/

const int rojo = 13;
const int amarillo = 12;
const int verde = 11;

void setup() {
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
}

void loop() {
  // Enciende el LED verde durante 3 segundos
  digitalWrite(rojo, LOW);
  digitalWrite(amarillo, LOW);
  digitalWrite(verde, HIGH);
  delay(3000);

  // Apaga el LED verde y enciende el LED amarillo durante 1 segundo
  digitalWrite(verde, LOW);
  digitalWrite(rojo, LOW);
  digitalWrite(amarillo, HIGH);
  delay(1000);

  // Apaga el LED amarillo y enciende el LED rojo durante 5 segundos
  digitalWrite(amarillo, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(rojo, HIGH);
  delay(5000);
}

/*Descripción del proyecto:

Este proyecto consiste en encender un LED cuando un objeto se encuentra dentro de un rango de distancia específico utilizando un sensor ultrasónico y una placa Arduino.

Componentes necesarios:

Placa Arduino Uno o similar
Sensor ultrasónico HC-SR04
LED
Resistencia de 10kΩ
Cables dupont
Protoboard
Esquema de conexión:

Conecte el pin Vcc del sensor ultrasónico al pin 5V de Arduino.
Conecte el pin GND del sensor ultrasónico al pin GND de Arduino.
Conecte el pin Trig del sensor ultrasónico al pin 9 de Arduino.
Conecte el pin Echo del sensor ultrasónico al pin 10 de Arduino.
Conecte la pata larga del LED a uno de los pines digitales de Arduino (por ejemplo, pin 13).
Conecte una resistencia de 10kΩ entre la pata larga del LED y el pin digital de Arduino.
Conecte la pata corta del LED al pin GND de Arduino.

Explicación del código:

La biblioteca NewPing se utiliza para trabajar con el sensor ultrasónico HC-SR04.
La función sonar.ping_cm() se utiliza para medir la distancia en centímetros entre el sensor y el objeto más cercano.
Si la distancia es menor o igual a 50 cm, el LED se enciende. De lo contrario, el LED se apaga.
Variaciones del proyecto:

Puede cambiar el rango de distancia en el que se enciende el LED modificando el valor de la variable distance_threshold.
Puede utilizar un sensor ultrasónico de diferente rango de distancia.
Puede conectar varios LEDs a la placa Arduino para indicar diferentes distancias.
Puede utilizar el sensor ultrasónico para controlar otros dispositivos, como un motor o un relé.
Recursos adicionales:

Sensor ultrasónico HC-SR04 [se quitó una URL no válida]
Biblioteca NewPing [se quitó una URL no válida]
Ejemplos de proyectos con sensor ultrasónico [se quitó una URL no válida]
Tiendas donde puedes comprar los componentes:

Puedes encontrar los componentes necesarios para este proyecto en tiendas online como AliExpress, Banggood o Amazon.
También puedes encontrarlos en tiendas de electrónica física en tu localidad.
Precio del proyecto:

El precio del proyecto variará dependiendo de la tienda donde compres los componentes. Sin embargo, debería ser un proyecto relativamente económico, con un costo total de alrededor de $10 a $20.

Dificultad del proyecto:

Este proyecto es adecuado para principiantes en Arduino. No se requieren conocimientos previos de electrónica o programación.

Tiempo de realización:

El proyecto se puede completar en aproximadamente 30 minutos a 1 hora.*/

#include <NewPing.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_PIN 13

NewPing sonar(TRIG_PIN, ECHO_PIN, 4000); // Define el sensor ultrasónico con pines Trig y Echo, y la velocidad del sonido en cm/s

int distancia = 0; // Variable para almacenar la distancia medida

void setup() {
  pinMode(LED_PIN, OUTPUT); // Configura el pin del LED como salida
  Serial.begin(9600); // Inicia la comunicación serial
}

void loop() {
  distancia = sonar.ping_cm(); // Mide la distancia en cm

  if (distancia <= 10) { // Si la distancia es menor o igual a 10 cm
    digitalWrite(LED_PIN, HIGH); // Enciende el LED
  } else {
    digitalWrite(LED_PIN, LOW); // Apaga el LED
  }

  Serial.print("Distancia: "); // Imprime la distancia en la consola serial
  Serial.println(distancia); // Imprime la distancia en la consola serial

  delay(100); // Retrasa la ejecución del bucle por 100 milisegundos
}


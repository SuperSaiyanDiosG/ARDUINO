/*
Proyecto de Arduino con un motor eléctrico, un LED y comunicación serial
Descripción del proyecto:

Este proyecto consiste en controlar un motor eléctrico, un LED y enviar y recibir datos a través del puerto serie de Arduino. El usuario podrá interactuar con el sistema enviando comandos desde un ordenador a través del puerto serie.

Componentes necesarios:

Placa Arduino Uno
Motor eléctrico de corriente continua
Leds
Cables
Resistencias
Protoboard
Esquema de conexión:

[Imagen de un esquema de conexión de un proyecto de Arduino con un motor eléctrico, un LED y comunicación serial]

Código Arduino:*/

const int ledPin = 13;
const int motorPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    switch (command) {
      case 'A':
        digitalWrite(ledPin, HIGH);
        break;
      case 'a':
        digitalWrite(ledPin, LOW);
        break;
      case 'M':
        analogWrite(motorPin, 255);
        break;
      case 'm':
        analogWrite(motorPin, 0);
        break;
      default:
        Serial.println("SISTEMA ON/OFF");
    }
  }
}
/*Explicación del código:

El código primero define algunos pines como entradas y salidas.
Luego, inicializa el puerto serie a una velocidad de baudios de 9600.
En la función loop(), se verifica si hay datos disponibles en el puerto serie.
Si hay datos disponibles, se lee el primer carácter y se almacena en la variable command.
Según el valor de command, se controla el LED o el motor.
Si el comando no es válido, se imprime un mensaje en el puerto serie.
Ejecución del proyecto:

Cargue el código Arduino en la placa Arduino.
Conecte los componentes según el esquema de conexión.
Abra el monitor serial de Arduino IDE.
En el monitor serial, escriba los siguientes comandos para controlar el LED y el motor:
A: enciende el LED
a: apaga el LED
M: enciende el motor a máxima velocidad
m: apaga el motor
Variaciones del proyecto:

Puede agregar más comandos para controlar otras funciones, como la dirección del motor o la intensidad del LED.
Puede usar un sensor para obtener información del entorno y enviar esa información al ordenador a través del puerto serie.
Puede usar una interfaz gráfica en el ordenador para interactuar con el sistema.*/
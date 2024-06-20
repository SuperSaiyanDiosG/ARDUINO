/*
Para encender y apagar un LED con Arduino y el teclado de tu PC, puedes utilizar la comunicación serial. Esto te permite enviar comandos desde el teclado a la placa Arduino, la cual controlará el LED en consecuencia.

Componentes necesarios:

Placa Arduino Uno o similar
LED
Resistencia de 220 Ω
Cables jumper
Computadora
Conexiones:

Conecta el LED al pin 13 de la placa Arduino mediante la resistencia de 220 Ω. La resistencia limita la corriente que fluye a través del LED y lo protege de daños.
Conecta el cable TX de la placa Arduino al pin RX del convertidor USB a serie.
Conecta el cable RX de la placa Arduino al pin TX del convertidor USB a serie.
Conecta el convertidor USB a serie al puerto USB de tu computadora.*/

int ledPin = 13; // Define el pin al que está conectado el LED

void setup() {
  pinMode(ledPin, OUTPUT); // Configura el pin como salida
  Serial.begin(9600); // Inicializa la comunicación serial a 9600 baudios
}

void loop() {
  if (Serial.available()) { // Si hay datos disponibles en el puerto serie
    char tecla = Serial.read(); // Lee el siguiente byte del puerto serie
    
    if (tecla == '1') { // Si la tecla presionada es '1'
      digitalWrite(ledPin, HIGH); // Enciende el LED
      Serial.println("LED encendido"); // Envía un mensaje de confirmación al puerto serie
    } else if (tecla == '2') { // Si la tecla presionada es '2'
      digitalWrite(ledPin, LOW); // Apaga el LED
      Serial.println("LED apagado"); // Envía un mensaje de confirmación al puerto serie
    }
  }
}

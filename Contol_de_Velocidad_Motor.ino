/* Modulación de ancho de pulso (PWM)

La modulación de ancho de pulso (PWM) es una técnica que se utiliza para controlar la potencia suministrada a un motor. Esto se hace variando el ancho de los pulsos de voltaje que se envían al motor. Cuanto más ancho sea el pulso, más potencia se suministrará al motor y, por lo tanto, más rápido girará.

Para controlar la velocidad de un motor con PWM, necesitarás un controlador de motor que admita PWM. Un controlador de motor popular es el L298N, que puede controlar dos motores de CC.

Componentes necesarios:

Arduino Uno
Controlador de motor L298N
Motor de CC
Cables
Fuente de alimentación
Conexiones:

Conecta el pin 12 del Arduino al pin IN1 del L298N.
Conecta el pin 13 del Arduino al pin IN2 del L298N.
Conecta el pin 5V del Arduino al pin VCC del L298N.
Conecta el pin GND del Arduino al pin GND del L298N.
Conecta el terminal positivo del motor de CC al pin OUT1 del L298N.
Conecta el terminal negativo del motor de CC al pin OUT2 del L298N.
Conecta la fuente de alimentación al L298N.*/

int motorPin = 9; // Pin de salida PWM conectado al controlador del motor

void setup() {
  pinMode(motorPin, OUTPUT); // Configurar el pin del motor como salida
}

void loop() {
  for (int i = 0; i < 256; i++) { // Ciclo de 0 a 255
    analogWrite(motorPin, i); // Enviar señal PWM con ciclo de trabajo variable
    delay(10); // Esperar 10 milisegundos
  }

  for (int i = 255; i > 0; i--) { // Ciclo de 255 a 0
    analogWrite(motorPin, i);
    delay(10);
  }
}


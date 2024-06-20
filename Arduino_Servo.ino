#include <Servo.h> // Incluir la biblioteca Servo
#include <Joystick.h> // Incluir la biblioteca Joystick

// Definir el pin del servo
const int servoPin = 9;

// Crear un objeto Servo para controlar el servo
Servo servoMotor;

// Crear un objeto Joystick para leer las entradas del joystick
Joystick joystick;

void setup() {
  // Inicializar el servo motor
  servoMotor.attach(servoPin);

  // Inicializar el joystick
  joystick.begin();
}

void loop() {
  // Leer la posición del joystick en el eje X
  int posicionX = joystick.readX();

  // Mapear la posición del joystick a un ángulo para el servo
  int anguloServo = map(posicionX, -127, 127, 0, 180);

  // Mover el servo al ángulo calculado
  servoMotor.write(anguloServo);

  delay(10); // Retardo para evitar sobrecargar el servo
}


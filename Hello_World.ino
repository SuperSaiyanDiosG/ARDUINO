/*El programa "Hola Mundo" es un clásico en la programación, y es una excelente manera de comenzar a aprender a usar Arduino. Este programa simple enciende y apaga el LED integrado en la placa Arduino, y también muestra el mensaje "Hola Mundo" en el monitor serial.

Materiales necesarios:

Placa Arduino Uno
Cable USB
Computadora
Pasos:

Descarga e instala el IDE de Arduino:

El IDE de Arduino es un software gratuito que te permite escribir y subir código a tu placa Arduino. Puedes descargarlo desde el sitio web oficial de Arduino: https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE

Conecta tu placa Arduino a tu computadora:

Usa el cable USB para conectar tu placa Arduino a tu computadora.

Abre el IDE de Arduino:

Una vez que tu placa Arduino esté conectada, abre el IDE de Arduino.

Escribe el siguiente código:*/

const int led = 13; // Define el pin del LED

void setup() {
  pinMode(led, OUTPUT); // Configura el pin del LED como salida
  Serial.begin(9600); // Inicializa la comunicación serial
}

void loop() {
  digitalWrite(led, HIGH);   // Enciende el LED
  delay(5000);               // Espera 1 segundo
  digitalWrite(led, LOW);    // Apaga el LED
  delay(3000);               // Espera 1 segundo
  Serial.println("Hola Mundo!"); // Imprime "Hola Mundo!" en el monitor serial
}
/*Sube el código a tu placa Arduino:

Para subir el código a tu placa Arduino, haz clic en el botón "Subir" (una flecha hacia arriba) en la barra de herramientas del IDE de Arduino.

Abre el monitor serial:

Para ver el mensaje "Hola Mundo!", abre el monitor serial. En el IDE de Arduino, haz clic en "Herramientas" > "Monitor serial".

Observa el LED y el monitor serial:

El LED debería encenderse y apagarse cada segundo, y el mensaje "Hola Mundo!" debería aparecer en el monitor serial.

Explicación del código:

La línea const int led = 13; define una constante llamada led que almacena el número de pin al que está conectado el LED.
La función setup() se ejecuta una vez al inicio del programa. En esta función, configuramos el pin del LED como salida utilizando la función pinMode(). También inicializamos la comunicación serial con la función Serial.begin().
La función loop() se ejecuta repetidamente en un bucle infinito. En esta función, encendemos el LED con la función digitalWrite(led, HIGH), esperamos un segundo con la función delay(1000), apagamos el LED con la función digitalWrite(led, LOW), esperamos otro segundo con delay(1000) e imprimimos el mensaje "Hola Mundo!" en el monitor serial con la función Serial.println().*/
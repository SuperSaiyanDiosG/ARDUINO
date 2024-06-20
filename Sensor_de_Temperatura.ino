/*Introducción

Los sensores de temperatura son componentes electrónicos que se utilizan para medir la temperatura de un entorno. Son ampliamente utilizados en diversas aplicaciones, como sistemas de control ambiental, monitoreo industrial y proyectos de electrónica para aficionados.

En este proyecto, construiremos un simple sensor de temperatura utilizando un Arduino y un sensor DS18B20. El sensor DS18B20 es un sensor de temperatura digital de bajo costo y fácil uso que se comunica con el Arduino a través de un bus 1-Wire.

Materiales necesarios

Una placa Arduino Uno o similar
Un sensor de temperatura DS18B20
Cables para jumper
Una computadora con Arduino IDE instalado
Esquema de conexión

Conecte el pin VCC del sensor DS18B20 al pin de 5V del Arduino.
Conecte el pin GND del sensor DS18B20 al pin GND del Arduino.
Conecte el pin DQ del sensor DS18B20 al pin de datos del bus 1-Wire del Arduino (generalmente, el pin 10).


Proyecto de sensor de temperatura con Arduino
Introducción

Los sensores de temperatura son componentes electrónicos que se utilizan para medir la temperatura de un entorno. Son ampliamente utilizados en diversas aplicaciones, como sistemas de control ambiental, monitoreo industrial y proyectos de electrónica para aficionados.

En este proyecto, construiremos un simple sensor de temperatura utilizando un Arduino y un sensor DS18B20. El sensor DS18B20 es un sensor de temperatura digital de bajo costo y fácil uso que se comunica con el Arduino a través de un bus 1-Wire.

Materiales necesarios

Una placa Arduino Uno o similar
Un sensor de temperatura DS18B20
Cables para jumper
Una computadora con Arduino IDE instalado
Esquema de conexión

Conecte el pin VCC del sensor DS18B20 al pin de 5V del Arduino.
Conecte el pin GND del sensor DS18B20 al pin GND del Arduino.
Conecte el pin DQ del sensor DS18B20 al pin de datos del bus 1-Wire del Arduino (generalmente, el pin 10).
Código Arduino

C++
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 10

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures(); // Solicita temperaturas a todos los sensores
  delay(500);

  for (size_t i = 0; i < sensors.getDeviceCount(); i++) {
    DeviceAddress deviceAddress = sensors.getDeviceAddress(i);
    sensors.requestTemperature(deviceAddress);
    float temperature = sensors.getTemperatureC(deviceAddress);

    if (sensors.validTemperature(deviceAddress)) {
      Serial.print("Sensor ID: ");
      Serial.print(deviceAddress);
      Serial.print(" Temperatura: ");
      Serial.print(temperature);
      Serial.println(" °C");
    } else {
      Serial.print("Sensor ID: ");
      Serial.print(deviceAddress);
      Serial.println(" No se pudo leer la temperatura");
    }
  }
}
Usa el código con precaución.
content_copy
Explicación del código

El código anterior incluye las bibliotecas OneWire y DallasTemperature, que son necesarias para trabajar con el sensor DS18B20. La función setup() inicializa el bus 1-Wire y la biblioteca DallasTemperature. La función loop() solicita temperaturas a todos los sensores conectados al bus y luego imprime los valores de temperatura en la consola serial.

Ejecución del proyecto

Cargue el código Arduino en su placa Arduino.
Abra el monitor serial en el Arduino IDE.
Observe cómo se muestran los valores de temperatura en la consola serial.
Ampliación del proyecto

Puede ampliar este proyecto de varias maneras:

Agregar una pantalla LCD para mostrar los valores de temperatura en tiempo real.
Registrar los valores de temperatura en un archivo de texto.
Utilizar los valores de temperatura para controlar un dispositivo, como un ventilador o un calentador.
Recursos adicionales

Biblioteca OneWire para Arduino
Biblioteca DallasTemperature para Arduino [se quitó una URL no válida]
Tutorial sobre sensores de temperatura DS18B20 con Arduino [se quitó una URL no válida]
Tiendas donde puedes comprar los materiales

Puedes encontrar el sensor DS18B20 en tiendas de electrónica en línea como AliExpress, Amazon y DigiKey. El precio típico del sensor es de entre $0.77 y $6.90.
También puedes comprar un kit de proyecto de sensor de temperatura Arduino que incluye todos los componentes necesarios para completar el proyecto. Estos kits suelen costar entre $10 y $20.
Espero que esta información te sea útil para realizar tu proyecto de sensor de temperatura con Arduino.

Fuentes*/

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 10

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures(); // Solicita temperaturas a todos los sensores
  delay(500);

  for (size_t i = 0; i < sensors.getDeviceCount(); i++) {
    DeviceAddress deviceAddress = sensors.getDeviceAddress(i);
    sensors.requestTemperature(deviceAddress);
    float temperature = sensors.getTemperatureC(deviceAddress);

    if (sensors.validTemperature(deviceAddress)) {
      Serial.print("Sensor ID: ");
      Serial.print(deviceAddress);
      Serial.print(" Temperatura: ");
      Serial.print(temperature);
      Serial.println(" °C");
    } else {
      Serial.print("Sensor ID: ");
      Serial.print(deviceAddress);
      Serial.println(" No se pudo leer la temperatura");
    }
  }
}

/**
   -->  CURSO BASICO DE ROBOTICA CON ARDUINO  <--
   -->           MATERIAL DE APOYO            <--

   Potenciado por:
   Geek Factory - "Dale vuelo a tus proyectos"
   www.geekfactory.mx

   CONSULTA EL ARCHIVO LICENCIA.TXT PARA CONOCER MÁS SOBRE LOS DERECHOS DE DISTRIBUCIÓN DE ESTE
   MATERIAL. PUBLICADO BAJO LICENCIA ATTRIBUTION-NONCOMMERCIAL-SHAREALIKE 4.0 INTERNATIONAL
   (CC BY-NC-SA 4.0).

   PRÁCTICA ULTRASONICO: Medición de distancia sin retardos.

   Este programa muestra como leer el sensor ultrasónico sin utilizar la función delay, de forma
   que nuestro microcontrolador esté disponible para realizar otras tareas.
*/
#include <Ultrasonic.h>
#include "pines.h"

/**
    Objeto que permite el control del sensor ultrasónico
*/
Ultrasonic ultrasonico(PIN_SENSOR_ULTRASONICO);

/**
    Función setup: se ejecuta una vez cuando encendemos el arduino
*/
void setup() {
  // iniciar puerto y mostrar mensaje
  Serial.begin(115200);
  Serial.println(F("----------------------------------------------------"));
  Serial.println(F("               ROBOT SUMO - ULTRASONICO             "));
  Serial.println(F("              https://www.geekfactory.mx            "));
  Serial.println(F("----------------------------------------------------"));
}

/**
    Función loop: se ejecuta continuamente mientras el arduino permanece encendido
*/
void loop() {
  // variable para almacenar el tiempo de la ultima lectura de sensor
  static uint32_t ultimotiempo = 0;
  // distancia medida por el sensor
  int32_t distancia;
  // obtener el tiempo en milisegundos
  uint32_t ahora = millis();

  // ver si han pasado 5 segundos
  if (ahora - ultimotiempo >= 5000) {
    // almacenar el tiempo en milisegundos
    ultimotiempo = ahora;
    // leer la distancia
    distancia = ultrasonico.read();
    // imprimir en monitor serial
    Serial.print(F("Distancia: "));
    Serial.println(distancia);
  }
}

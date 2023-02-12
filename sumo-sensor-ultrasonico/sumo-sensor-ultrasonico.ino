#include <Ultrasonic.h>
#include <GBOT.h>

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

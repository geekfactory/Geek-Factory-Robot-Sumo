/**
   -->  CURSO BASICO DE ROBOTICA CON ARDUINO  <--
   -->           MATERIAL DE APOYO            <--

   Potenciado por:
   Geek Factory - "Dale vuelo a tus proyectos"
   www.geekfactory.mx

   CONSULTA EL ARCHIVO LICENCIA.TXT PARA CONOCER MÁS SOBRE LOS DERECHOS DE DISTRIBUCIÓN DE ESTE
   MATERIAL. PUBLICADO BAJO LICENCIA ATTRIBUTION-NONCOMMERCIAL-SHAREALIKE 4.0 INTERNATIONAL
   (CC BY-NC-SA 4.0).

   PRÁCTICA FINAL: Robot sumo completo

   Este programa implementa un robot sumo que utiliza un único sensor ultrasónico para buscar
   y atacar (empujar) al contrincante. También mantiene al robot dentro del dojo mediante los
   sensores de detección de linea.
*/

#include <Ultrasonic.h>
#include <GFMotor.h>
#include <GFButton.h>
#include <GFLed.h>
#include "gsumo.h"
#include "pines.h"
#include "conf.h"

/**
   LED indicador de estado
*/
GFLed ledEstado(PIN_LED_ESTATUS);

/**
    Boton de inicio del robot
*/
GFButton botonInicio(PIN_BOTON_INICIO);

/**
    Objeto que permite el control del sensor ultrasónico
*/
Ultrasonic ultrasonico(PIN_SENSOR_ULTRASONICO);

/**
   Objetos para el control de motores izquierdo y derecho
*/
GFMotor motorIzq(PIN_MOTOR_IZQ_1, PIN_MOTOR_IZQ_2, PIN_MOTOR_IZQ_PWM);
GFMotor motorDer(PIN_MOTOR_DER_1, PIN_MOTOR_DER_2, PIN_MOTOR_DER_PWM);

/**
    Función setup: se ejecuta una vez cuando encendemos el arduino
*/
void setup() {
  // iniciar puerto y mostrar mensaje
  Serial.begin(115200);
  Serial.println(F("----------------------------------------------------"));
  Serial.println(F("                  ROBOT SUMO SENCILLO               "));
  Serial.println(F("              https://www.geekfactory.mx            "));
  Serial.println(F("----------------------------------------------------"));

  // inicializar motores
  motorIzq.begin();
  motorDer.begin();

  // configurar como entrada pines sensores de linea
  pinMode(PIN_SENSOR_LINEA_IZQ, INPUT);
  pinMode(PIN_SENSOR_LINEA_DER, INPUT);

  botonInicio.setDebounceTime(100);
}

/**
    Función loop: se ejecuta continuamente mientras el arduino permanece encendido
*/
void loop() {
  // parpadeo de LED
  ledEstado.process();
  // procesar logica de sumo
  sumo_procesa();
  // realizar otras operaciones dentro de loop en caso de ser necesario
}

/**
   Implementación del automata finito del robot de sumo
*/
void sumo_procesa() {
  // variables de control de tiempo
  static uint32_t tultimaop, tultimoestado;
  // variable de estado para automata finito
  static enum gsumo_estados estado = E_ESPERA;
  // variable para almacenar direccion de giro
  static enum gsumo_direcciones ultimolado = E_IZQUIERDA;
  // obtener tiempo actual para operaciones basadas en tiempos
  uint32_t tmillis = millis();
  // variable para distancia medida por el sensor
  int32_t distancia;

  // evaluar estado del robot
  switch (estado) {
    case E_ESPERA:
      // boton de inicio
      if (botonInicio.isPressed()) {
        Serial.println(F("Iniciar"));
        estado = E_COM_BUSCAR;
      }
      break;

    // iniciar busqueda del oponente
    case E_COM_BUSCAR:
      // decidir hacia que lado girar
      if (ultimolado == E_IZQUIERDA) {
        Serial.println(F("Busqueda DER"));
        motorIzq.setSpeed(CONF_VEL_BUSQUEDA);
        motorDer.setSpeed(-CONF_VEL_BUSQUEDA);
        ultimolado = E_DERECHA;
      } else if (ultimolado == E_DERECHA) {
        Serial.println(F("Busqueda IZQ"));
        motorIzq.setSpeed(-CONF_VEL_BUSQUEDA);
        motorDer.setSpeed(CONF_VEL_BUSQUEDA);
        ultimolado = E_IZQUIERDA;
      }
      // afectar variables de tiempo y pasar al estado buscar
      tultimoestado = tmillis;
      tultimaop = tmillis;
      estado = E_BUSCAR;
      break;

    // leer el sensor hasta encontrar al otro robot o hasta que se agote el tiempo de giro en este sentido
    case E_BUSCAR:
      // medir la distancia cada CONF_TIE_MUESTREO milisegundos mientras el robot está girando para buscar al oponente
      if (tmillis - tultimaop >= CONF_TIE_MUESTREO) {
        tultimaop = tmillis;
        // leer la distancia, si se detecta algo cerca lo atacamos
        distancia = ultrasonico.read();  // Serial.println(distancia);
        if (distancia <= CONF_DIST_ATAQUE) {
          estado = E_COM_ATACAR;
          break;
        }
      }
      // evaluar si termina la busqueda por tiempo en esta direccion e iniciar la busqueda en el otro sentido
      if (tmillis - tultimoestado >= CONF_TIE_BUSQUEDA) {
        estado = E_COM_BUSCAR;
      }
      break;

    case E_COM_ATACAR:
      // el robot avanza hacia adelante con velocidad de ataque en todos los motores
      Serial.println(F("Atacar!"));
      motorIzq.setSpeed(CONF_VEL_ATAQUE);
      motorDer.setSpeed(CONF_VEL_ATAQUE);
      tultimaop = tmillis;
      estado = E_ATACAR;
      break;

    case E_ATACAR:
      // medir la distancia cada CONF_TIE_MUESTREO milisegundos para asegurarnos que aún tenemos al oponente enfrente
      if (tmillis - tultimaop >= CONF_TIE_MUESTREO) {
        tultimaop = tmillis;
        // leer la distancia, si ya no se detecta al oponente, buscamos de nuevo
        distancia = ultrasonico.read();  // Serial.println(distancia);
        if (distancia > CONF_DIST_ATAQUE && distancia < 300) {
          estado = E_COM_BUSCAR;
        }
      }
      // revisar sensores de linea mientras vamos avanzando, si detectmos linea entonces cambiamos a reversa
      if (digitalRead(PIN_SENSOR_LINEA_IZQ) == CONF_NIVEL_LINEA || digitalRead(PIN_SENSOR_LINEA_DER) == CONF_NIVEL_LINEA) {
        estado = E_COM_REVERSA;
      }
      break;

    case E_COM_REVERSA:
      Serial.println(F("Reversa"));
      motorIzq.setSpeed(-CONF_VEL_REVERSA);
      motorDer.setSpeed(-CONF_VEL_REVERSA);
      tultimoestado = tmillis;
      estado = E_REVERSA;
      break;

    case E_REVERSA:
      // evaluar tiempo maximo en reversa
      if (tmillis - tultimoestado >= CONF_TIE_REVERSA) {
        estado = E_COM_BUSCAR;
      }
      break;
  }
}

/**
   -->  CURSO BASICO DE ROBOTICA CON ARDUINO  <--
   -->           MATERIAL DE APOYO            <--

   Potenciado por:
   Geek Factory - "Dale vuelo a tus proyectos"
   www.geekfactory.mx

   CONSULTA EL ARCHIVO LICENCIA.TXT PARA CONOCER MÁS SOBRE LOS DERECHOS DE DISTRIBUCIÓN DE ESTE
   MATERIAL. PUBLICADO BAJO LICENCIA ATTRIBUTION-NONCOMMERCIAL-SHAREALIKE 4.0 INTERNATIONAL
   (CC BY-NC-SA 4.0).
*/

#ifndef PINES_H
#define PINES_H

/**
   Pin para el led indicador de estado
*/
#define PIN_LED_ESTATUS A4

/**
   Pin para boton de inicio
*/
#define PIN_BOTON_INICIO A5

/**
   Pin donde se conecta el sensor ultrasonico
*/
#define PIN_SENSOR_ULTRASONICO 4

/**
   Pin donde se conecta el sensor de linea izquierdo
*/
#define PIN_SENSOR_LINEA_IZQ A0

/**
   Pin donde se conecta el sensor de linea derecha
*/
#define PIN_SENSOR_LINEA_DER A1

/**
   Pin 1 para el control de direccion motor izquierdo
*/
#define PIN_MOTOR_IZQ_1 8

/**
   Pin 2 para el control de direccion motor izquierdo
*/
#define PIN_MOTOR_IZQ_2 9

/**
   Pin de control de velocidad (PWM) motor izquierdo
*/
#define PIN_MOTOR_IZQ_PWM 10

/**
   Pin de control de velocidad (PWM) motor derecho
*/
#define PIN_MOTOR_DER_PWM 11

/**
   Pin 1 para el control de direccion motor derecho
*/
#define PIN_MOTOR_DER_1 12

/**
   Pin 2 para el control de direccion motor derecho
*/
#define PIN_MOTOR_DER_2 13

#endif

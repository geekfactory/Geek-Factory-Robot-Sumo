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

#ifndef CONF_H
#define CONF_H

/**
  Distancia de detección del oponente en centimetros
*/
#define CONF_DIST_ATAQUE 40

/**
  Intervalo de medicion del sensor ultrasónico y de toma de decisiones.
*/
#define CONF_TIE_MUESTREO 100

/**
  Tiempo maximo que el robot girará en una determinada dirección para
  buscar un oponente antes de cambiar el sentido de giro.
*/
#define CONF_TIE_BUSQUEDA 2500

/**
  Tiempo que dura el movimiento en reversa al detectar la orilla
*/
#define CONF_TIE_REVERSA 600

/**
  Velocidad de los motores al girar para buscar oponente
*/
#define CONF_VEL_BUSQUEDA 80

/**
  Velocidad de los motores al detectar y empujar al otro robot
*/
#define CONF_VEL_ATAQUE 100

/**
  Velocidad de los motores en reversa
*/
#define CONF_VEL_REVERSA 100

/**
  Nivel en los pines de entrada cuando se detecta el contorno del dojo
*/
#define CONF_NIVEL_LINEA HIGH

#endif

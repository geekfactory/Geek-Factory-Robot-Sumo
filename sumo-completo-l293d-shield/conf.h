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

#ifndef CONF_H
#define CONF_H

/**
  Distancia de detección del oponente en centimetros
*/
#define CONF_DIST_ATAQUE 30

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
#define CONF_TIE_REVERSA 1500

/**
  Velocidad de los motores al girar para buscar oponente
*/
#define CONF_VEL_BUSQUEDA 150

/**
  Velocidad de los motores al detectar y empujar al otro robot
*/
#define CONF_VEL_ATAQUE 255

/**
  Velocidad de los motores en reversa
*/
#define CONF_VEL_REVERSA 255

/**
  Nivel en los pines de entrada cuando se detecta el contorno del dojo
*/
#define CONF_NIVEL_LINEA HIGH

#endif

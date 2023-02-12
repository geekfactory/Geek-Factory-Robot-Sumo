#ifndef CONF_H
#define CONF_H

/**
  Distancia de detección del oponente en centimetros
*/
#define CONF_DIST_ATAQUE 40

/**
  Intervalo tras el cual el sensor ultrasónico realiza mediciones y
  se toman decisiones.
*/
#define CONF_TIE_MUESTREO 100

/**
  Tiempo maximo que el robot girará en una determinada dirección
  para buscar un oponente antes de cambiar el sentido de giro.
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
  Velocidad de los motores cuando se encuentra otro robot
*/
#define CONF_VEL_ATAQUE 100

/**
  Velocidad de los motores en reversa
*/
#define CONF_VEL_REVERSA 100

/**
  Nivel en los pines cuando se detecta el contorno
*/
#define CONF_NIVEL_LINEA HIGH

#endif

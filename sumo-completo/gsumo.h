#ifndef GSUMO_H
#define GSUMO_H

/**
   Definición de los estados del automata finito del robot
*/
enum gsumo_estados {
  /**
     ESPERA: El robot esta esperando a que se presione un boton para comenzar su funcionamiento.
  */
  E_ESPERA,

  /**
     COMIENZA A BUSCAR: Estado transitorio en el que el robot decide si debe girar a la derecha
     o a la izquierda para buscar al oponente y activa sus motores en la dirección que
     corresponda.
  */
  E_COM_BUSCAR,

  /**
    BUSCAR: Mientras el roboy gira, este mide la distancia para encontrar al otro robot. Una
    vez que lo encuentra para al siguiente estado para comenzar a empujar.
  */
  E_BUSCAR,

  /**
     Estado transitorio en el que el robot activa sus motores en linea recta y se prepara para
     empujar al oponente.
  */
  E_COM_ATACAR,

  /**
     Mientras empuja, el robot mide distancia para asegurarse que sigue teniendo al oponente
     enfrente. Seguirá empujando hasta llegar a la orilla o hasta que no detecte al contrincante.
  */
  E_ATACAR,

  /**
     Estado transitorio en el que el robot se prepara para retroceder y activa sus motores
     en reversa.
  */
  E_COM_REVERSA,

  /**
     El robot retrocede por cierto tiempo para intentar regresar al centro del dojo
  */
  E_REVERSA,
};

/**
   Definicion de direcciones para movimiento del robot
*/
enum gsumo_direcciones {
  E_IZQUIERDA,
  E_DERECHA,
};

#endif

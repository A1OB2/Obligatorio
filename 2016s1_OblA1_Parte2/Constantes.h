#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <iostream>
using namespace std;

 ///////////////////////////
// ---------------------- //
// DEFINICIONES DE TIPOS  //
// ---------------------- //////////////////////////////

#include "TipoRetorno.h"

enum _estadoArtefacto {
  OFF, ON
};
typedef enum _estadoArtefacto EstadoArtefacto;

enum _estadoAlarma {
  DESACTIVADA, ACTIVADA
};
typedef enum _estadoAlarma EstadoAlarma;

enum _estadoSensor {
  NORMAL, ENALARMA
};
typedef enum _estadoSensor EstadoSensor;



#endif

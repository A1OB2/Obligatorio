#ifndef ESTADISTICAPRUEBA_H
#define ESTADISTICAPRUEBA_H

#include "TipoRetorno.h"

class EstadisticaPrueba  
{
public:
	EstadisticaPrueba();
	virtual ~EstadisticaPrueba();

	int getCantidadCorrectas()const;
	int getCantidadIncorrectas()const;
	int getCantidadNoImplementadas()const;

	void resetearResultados();

	void actualizarEstadisticas(TipoRetorno nroRetorno, TipoRetorno nroRetornoEsperado);
private:
	int cantCorrectas, cantIncorrectas, cantNoImplementadas;

};

#endif
#ifndef INTERFAZ_DEL_SISTEMA_IMP_H
#define INTERFAZ_DEL_SISTEMA_IMP_H

#include "InterfazDelSistema.h"
#include "CasaInteligente.h"

class InterfazDelSistemaImp  : public InterfazDelSistema
{
public:
	InterfazDelSistemaImp(unsigned int CANT_SENSORES, unsigned int MAX_ESTADOS);
	~InterfazDelSistemaImp();

	TipoRetorno AgregarLuz(unsigned int nroLuz, char* nombre);
	TipoRetorno AgregarArtefacto(unsigned int nroArt, char* nombre);
	TipoRetorno CambiarEstadoLuz(unsigned int nroLuz, unsigned int porcentaje);
	TipoRetorno CambiarEstadoArtefacto(unsigned int nroArt, EstadoArtefacto nuevoEstado);
	TipoRetorno CambiarEstadoAlarma(EstadoAlarma nuevoEstado);
	TipoRetorno ImprimirEstadoCasa() const;
	TipoRetorno CrearCondicion(unsigned int nroCondicion, void (*seCumpleCondicion)(int), void (*seDejaDeCumplirCondicion)(int));
	TipoRetorno AgregarSensorACondicion(unsigned int nroCondicion, unsigned int nroSensor, EstadoSensor estado);
	TipoRetorno CambiarEstadoSensor(unsigned int nroSensor, EstadoSensor estado);
	
	TipoRetorno InicioEscena(unsigned int nroEscena, char* nombre);
	TipoRetorno FinEscena();
	TipoRetorno EjecutarEscena(unsigned int nroEscena);
	TipoRetorno ImprimirEscenas() const;
	TipoRetorno ImprimirEscena(unsigned int nroEscena) const;
	TipoRetorno ImprimirEscenasRaras() const;

	TipoRetorno GuardarEstadoActual();
	TipoRetorno VolverAlEstadoAnterior();

private:

		InterfazDelSistemaImp() { assert(false); } // Constructor por defecto.

		// Definir atributo/s

};

#endif

#ifndef INTERFAZ_DEL_SISTEMA_PROXY_H
#define INTERFAZ_DEL_SISTEMA_PROXY_H

#include "Constantes.h"
#include "InterfazDelSistema.h"
#include <assert.h>

class InterfazDelSistemaProxy  : public InterfazDelSistema
{
public:
	
	InterfazDelSistemaProxy(InterfazDelSistema*);
	virtual ~InterfazDelSistemaProxy();

	void Comentar();
	void Descomentar();

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

	InterfazDelSistemaProxy() { assert(false); }

	InterfazDelSistema* interfaz;
	bool comentado;
};

#endif

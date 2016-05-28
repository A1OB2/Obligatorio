#ifndef INTERFAZ_DEL_SISTEMA_H
#define INTERFAZ_DEL_SISTEMA_H

#include "Constantes.h"

/*	
	Todos los métodos retornan un enumerado correspondiente a si la operación 
	se pudo realizar correctamente, hubo un error o no fue implementada.
   

	NOTA:
			Ver la especificación completa de los diferentes comandos en 
			la letra del obligatorio.

*/

class InterfazDelSistema abstract
{
	
	public:

		virtual ~InterfazDelSistema() {};

		virtual TipoRetorno AgregarLuz(unsigned int nroLuz, char* nombre) abstract;
		virtual TipoRetorno AgregarArtefacto(unsigned int nroArt, char* nombre) abstract;
		virtual TipoRetorno CambiarEstadoLuz(unsigned int nroLuz, unsigned int porcentaje) abstract;
		virtual TipoRetorno CambiarEstadoArtefacto(unsigned int nroArt, EstadoArtefacto nuevoEstado) abstract;
		virtual TipoRetorno CambiarEstadoAlarma(EstadoAlarma nuevoEstado) abstract;
		virtual TipoRetorno ImprimirEstadoCasa() const abstract;
		virtual TipoRetorno CrearCondicion(unsigned int nroCondicion, void (*seCumpleCondicion)(int), void (*seDejaDeCumplirCondicion)(int)) abstract;
		virtual TipoRetorno AgregarSensorACondicion(unsigned int nroCondicion, unsigned int nroSensor, EstadoSensor estado) abstract;
		virtual TipoRetorno CambiarEstadoSensor(unsigned int nroSensor, EstadoSensor estado) abstract;
		
		virtual TipoRetorno InicioEscena(unsigned int nroEscena, char* nombre) abstract;
		virtual TipoRetorno FinEscena() abstract;
		virtual TipoRetorno EjecutarEscena(unsigned int nroEscena) abstract;
		virtual TipoRetorno ImprimirEscenas() const abstract;
		virtual TipoRetorno ImprimirEscena(unsigned int nroEscena) const abstract;
		virtual TipoRetorno ImprimirEscenasRaras() const abstract;

		virtual TipoRetorno GuardarEstadoActual() abstract;
		virtual TipoRetorno VolverAlEstadoAnterior() abstract;
};

#endif 
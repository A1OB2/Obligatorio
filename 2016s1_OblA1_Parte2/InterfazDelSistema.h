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

		// PRE: no se esta grabando una escena, no hay una luz con ese nombre o numero
		// POS: Agrega una luz con el numero nroLuz y el nombre nombre a la casa
		virtual TipoRetorno AgregarLuz(unsigned int nroLuz, char* nombre) abstract;

		// PRE: no se esta grabando una escena, no hay un artefacto con ese numero o nombre
		// POS: Agrega un artefacto con el numero nroArt y el nombre nombre a la casa
		virtual TipoRetorno AgregarArtefacto(unsigned int nroArt, char* nombre) abstract;

		// PRE: hay una luz con ese numero, elporcentaje esta entre 0 y 100
		// POS: Cambia la intensidad de la luz con numero nroLuz a porcentaje
		virtual TipoRetorno CambiarEstadoLuz(unsigned int nroLuz, unsigned int porcentaje) abstract;

		// PRE: hay un artefacto con ese numero
		// POS: Cambia el estado del artefacto con nroArt a nuevoEstado
		virtual TipoRetorno CambiarEstadoArtefacto(unsigned int nroArt, EstadoArtefacto nuevoEstado) abstract;

		// PRE: la alarma se encuentra en otro estado, todos los sensores entan en estado normal
		// POS: Cambia el estado de la alarma a nuevoEstado
		virtual TipoRetorno CambiarEstadoAlarma(EstadoAlarma nuevoEstado) abstract;

		// PRE: no se esta grabando una escena
		// POS: Muestra la casa en pantalla
		virtual TipoRetorno ImprimirEstadoCasa() const abstract;

		// PRE: no se esta grabando una escena, no existe una condicion con ese numero
		// POS: Crea la condicion con numero nroCondicion y con las funciones que se pasan por parametro
		virtual TipoRetorno CrearCondicion(unsigned int nroCondicion, void (*seCumpleCondicion)(int), void (*seDejaDeCumplirCondicion)(int)) abstract;

		// PRE: no se esta grabando una escena, existe una condicion con ese numero, existe un sensor con ese numero
		// POS: Agrega el sensor con numero nroSensor a la condicion con numero nroSensor y con el estado estado
		virtual TipoRetorno AgregarSensorACondicion(unsigned int nroCondicion, unsigned int nroSensor, EstadoSensor estado) abstract;

		// PRE: no se esta grabando una escena, existe un sensor con ese numero
		// POS: Cambia el estado del sensor con numero nroSensor a estado
		virtual TipoRetorno CambiarEstadoSensor(unsigned int nroSensor, EstadoSensor estado) abstract;
		
		// PRE: no se esta grabando una escena, no existe una escena con numero nroEscena o nombre nombre
		// POS: Inicia una escena 
		virtual TipoRetorno InicioEscena(unsigned int nroEscena, char* nombre) abstract;

		// PRE: Hay una escena en curso
		// POS: Finaliza la escena en curso
		virtual TipoRetorno FinEscena() abstract;

		// PRE: Existe la escena con numero nroEscena
		// POS: Ejecuta la escena con numero nroEscena
		virtual TipoRetorno EjecutarEscena(unsigned int nroEscena) abstract;

		// PRE: no se esta grabando una escena
		// POS: Muestra en pantalla todas las escenas en orden
		virtual TipoRetorno ImprimirEscenas() const abstract;

		// PRE: Existe la escena con numero nroEscena,no se esta grabando una escena
		// POS: Muestra en pantalla la escena con numero nroEscena
		virtual TipoRetorno ImprimirEscena(unsigned int nroEscena) const abstract;

		// PRE: no se esta grabando una escena
		// POS: Muestra en pantalla todas las escenas consideradas como raras
		virtual TipoRetorno ImprimirEscenasRaras() const abstract;

		// PRE: no se esta grabando una escena
		// POS: Guarda el estado actual de la casa
		virtual TipoRetorno GuardarEstadoActual() abstract;

		// PRE: no se esta grabando una escena, hay estados guardados
		// POS: Vuelve al estado anterior de la casa
		virtual TipoRetorno VolverAlEstadoAnterior() abstract;
};

#endif 
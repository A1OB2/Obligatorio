#ifndef CASAINTELIGENTE_H
#define CASAINTELIGENTE_H

class Alarma;
class Artefacto;
class Dispositivo;
class Luz;
class Sensor;
class Cambio;
class Escena;
class Condicion;

#include "Constantes.h"
#include <assert.h>
#include "Cadena.h"

#include "Referencia.h"
#include "Asociacion.h"
#include "ListaImp.h"
#include "ListaOrdImp.h"
#include "ABB.h"
#include "ABBImp.h"

#include "Alarma.h"
#include "Artefacto.h"
#include "Luz.h"
#include "Sensor.h"
#include "Dispositivo.h"
#include "Cambio.h"
#include "Escena.h"
#include "Condicion.h"

class CasaInteligente {
public:

	// Constructor por defecto
	CasaInteligente();

	CasaInteligente(unsigned int CANT_SENSORES);

	// Constructor copia
	CasaInteligente(const CasaInteligente *casa);

	// Destructor
	virtual ~CasaInteligente();

	// Operador de asignacion
	CasaInteligente &operator=(const CasaInteligente &casa);

	// Operador de comparacion ==
	bool operator==(const CasaInteligente &casa) const;

	// Operador de comparacion <
	bool operator<(const CasaInteligente &casa) const;

	// VER Ver la especificación completa de los diferentes comandos en 
	// la letra del obligatorio.


	// PRE: no se esta grabando una escena, no hay una luz con ese nombre o numero
	// POS: Agrega una luz con el numero nroLuz y el nombre nombre a la casa
	TipoRetorno AgregarLuz(unsigned int nroLuz, Cadena nombre);

	// PRE: no se esta grabando una escena, no hay un artefacto con ese numero o nombre
	// POS: Agrega un artefacto con el numero nroArt y el nombre nombre a la casa
	TipoRetorno AgregarArtefacto(unsigned int nroArt, Cadena nombre);

	// PRE: hay una luz con ese numero, elporcentaje esta entre 0 y 100
	// POS: Cambia la intensidad de la luz con numero nroLuz a porcentaje
	TipoRetorno CambiarEstadoLuz(unsigned int nroLuz, unsigned int porcentaje);

	// PRE: hay un artefacto con ese numero
	// POS: Cambia el estado del artefacto con nroArt a nuevoEstado
	TipoRetorno CambiarEstadoArtefacto(unsigned int nroArt, EstadoArtefacto nuevoEstado);

	// PRE: la alarma se encuentra en otro estado, todos los sensores entan en estado normal
	// POS: Cambia el estado de la alarma a nuevoEstado
	TipoRetorno CambiarEstadoAlarma(EstadoAlarma nuevoEstado);

	// PRE: no se esta grabando una escena
	// POS: Muestra la casa en pantalla
	TipoRetorno ImprimirEstadoCasa() const;

	// PRE: no se esta grabando una escena, no existe una condicion con ese numero
	// POS: Crea la condicion con numero nroCondicion y con las funciones que se pasan por parametro
	TipoRetorno CrearCondicion(unsigned int nroCondicion, void(*seCumpleCondicion)(int), void(*seDejaDeCumplirCondicion)(int));

	// PRE: no se esta grabando una escena, existe una condicion con ese numero, existe un sensor con ese numero
	// POS: Agrega el sensor con numero nroSensor a la condicion con numero nroSensor y con el estado estado
	TipoRetorno AgregarSensorACondicion(unsigned int nroCondicion, unsigned int nroSensor, EstadoSensor estado);

	// PRE: no se esta grabando una escena, existe un sensor con ese numero
	// POS: Cambia el estado del sensor con numero nroSensor a estado
	TipoRetorno CambiarEstadoSensor(unsigned int nroSensor, EstadoSensor estado);


	// PRE: no se esta grabando una escena, no existe una escena con numero nroEscena o nombre nombre
	// POS: Inicia una escena 
	TipoRetorno InicioEscena(unsigned int nroEscena, Cadena nombre);

	// PRE: Hay una escena en curso
	// POS: Finaliza la escena en curso
	TipoRetorno FinEscena();

	// PRE: Existe la escena con numero nroEscena
	// POS: Ejecuta la escena con numero nroEscena
	TipoRetorno EjecutarEscena(unsigned int nroEscena);

	// PRE: no se esta grabando una escena
	// POS: Muestra en pantalla todas las escenas en orden
	TipoRetorno ImprimirEscenas() const;

	// PRE: Existe la escena con numero nroEscena,no se esta grabando una escena
	// POS: Muestra en pantalla la escena con numero nroEscena
	TipoRetorno ImprimirEscena(unsigned int nroEscena) const;

	// PRE: -
	// POS: Muestra en pantalla aquellas escenas consideradas como 'raras'
	TipoRetorno ImprimirEscenasRaras() const;
	
	// PRE: no se esta grabando una escena
	// POS: Muestra en pantalla todas las escenas consideradas como raras
	bool isEnEscena();

private:
	ABB<Asociacion<int, Referencia<Luz>>> * lucesNumero;
	ABB<Asociacion<Cadena, Referencia<Luz>>> * lucesNombre;
	ABB<Asociacion<int, Referencia<Artefacto>>> * artefactosNumero;
	ABB<Asociacion<Cadena, Referencia<Artefacto>>> * artefactosNombre;
	ABB<Asociacion<int, Referencia<Sensor>>> * sensores;
	ABB<Asociacion<int, Referencia<Escena>>> * escenasNumero;
	ABB<Asociacion<Cadena, Referencia<Escena>>> * escenasNombre;
	ABB<Asociacion<int, Referencia<Condicion>>> * condiciones;
	Referencia<Alarma> * alarma;
	bool enEscena;
	Referencia<Escena> * escenaActual;

	//aux methods
	template<class T, class U>
	void llenarArbol(ABB<Asociacion<U, Referencia<T>>>* & llenar, ABB<Asociacion<U, Referencia<T>>>* sacar);
};

#endif
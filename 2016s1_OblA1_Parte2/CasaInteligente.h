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

#include "Alarma.h"
#include "Artefacto.h"
#include "Luz.h"
#include "Sensor.h"
#include "Dispositivo.h"
#include "Cambio.h"
#include "Escena.h"
#include "Condicion.h"


class CasaInteligente 
{
public:
	
	// Constructor por defecto
	CasaInteligente();

	CasaInteligente(unsigned int CANT_SENSORES);
	
	// Constructor copia
	CasaInteligente(const CasaInteligente &casa);

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
	TipoRetorno AgregarLuz(unsigned int nroLuz, Cadena nombre);
	TipoRetorno AgregarArtefacto(unsigned int nroArt, Cadena nombre);
	TipoRetorno CambiarEstadoLuz(unsigned int nroLuz, unsigned int porcentaje);
	TipoRetorno CambiarEstadoArtefacto(unsigned int nroArt, EstadoArtefacto nuevoEstado);
	TipoRetorno CambiarEstadoAlarma(EstadoAlarma nuevoEstado);
	TipoRetorno ImprimirEstadoCasa() const;
	TipoRetorno CrearCondicion(unsigned int nroCondicion, void (*seCumpleCondicion)(int), void (*seDejaDeCumplirCondicion)(int));
	TipoRetorno AgregarSensorACondicion(unsigned int nroCondicion, unsigned int nroSensor, EstadoSensor estado);
	TipoRetorno CambiarEstadoSensor(unsigned int nroSensor, EstadoSensor estado);
	
	TipoRetorno InicioEscena(unsigned int nroEscena, Cadena nombre);
	TipoRetorno FinEscena();
	TipoRetorno EjecutarEscena(unsigned int nroEscena);
	TipoRetorno ImprimirEscenas() const;
	TipoRetorno ImprimirEscena(unsigned int nroEscena) const;
	TipoRetorno ImprimirEscenasRaras() const;

private:

};

#endif
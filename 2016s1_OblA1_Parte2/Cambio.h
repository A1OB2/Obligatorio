#ifndef CAMBIO_H
#define CAMBIO_H

class Alarma;
class Artefacto;
class Dispositivo;
class Luz;
class Sensor;
class Cambio;
class Escena;
class CasaInteligente;

#include <iostream>
using namespace std;
#include <assert.h>
#include "Cadena.h"
#include "Dispositivo.h"
#include "CasaInteligente.h"

class Cambio;
ostream &operator<<(ostream& out, const Cambio &c);

class Cambio {
public:
	// Constructores
	Cambio();
	Cambio(const Dispositivo &d);

	// Constructor copia
	Cambio(const Cambio &c);

	// Destructor
	virtual ~Cambio();

	// Operador de asignacion
	Cambio &operator=(const Cambio &c);

	// Operador de comparacion ==. 
	bool operator==(const Cambio &c) const;

	// Operador de comparacion <. assert(false)
	bool operator<(const Cambio &c) const;

	// PRE: -
	// POS: Retorna el dispositivo del cambio
	Dispositivo * getDispositivo();

	// PRE: -
	// POS: Retorna el tipo de dispositivo del cambio
	TipoDispositivo getTipo();


	// PRE: -
	// POS: Muestra el cambio en pantalla
	void Imprimir() const;

	// PRE: -
	// POS: Ejecuta el cambio en la casa
	void Ejecutar(CasaInteligente *casa);

private:
	Dispositivo * disp;
	TipoDispositivo tipo;
};

#endif
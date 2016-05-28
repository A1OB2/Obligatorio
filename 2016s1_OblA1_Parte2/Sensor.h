#ifndef SENSOR_H
#define SENSOR_H

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
#include "Constantes.h"
#include "Dispositivo.h"
#include "CasaInteligente.h"

class Sensor;
ostream &operator<<(ostream& out, const Sensor &s);

class Sensor : public Dispositivo {
public:
	// Constructores
	Sensor();
	Sensor(unsigned int nro);

	// Constructor copia
	Sensor(const Sensor &s);

	// Destructor
	virtual ~Sensor();

	// Operador de asignacion
	Sensor &operator=(const Sensor &s);

	// Operador de comparacion ==. Compara el nro
	bool operator==(const Sensor &s) const;

	unsigned int GetNro() const;

	void SetEstado(EstadoSensor estado);
	EstadoSensor GetEstado() const;

	void Imprimir(ostream& out) const;

private:

};


#endif
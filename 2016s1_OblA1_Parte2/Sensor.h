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

	bool operator<(const Sensor &s) const;

	bool operator>(const Sensor &s) const;

	// PRE: -
	// POS: Devuelve el numero del sensor
	unsigned int GetNro() const;

	// PRE: -
	// POS: Cambia el estado de sensor por estado
	void SetEstado(EstadoSensor estado);

	// PRE: -
	// POS: Devuelve el estado actual del sensor
	EstadoSensor GetEstado() const;

	// PRE: -
	// POS: Muestra el sensor en la pantalla
	void Imprimir(ostream& out) const;

	// PRE: -
	// POS: Muestra el sensor en la pantalla como un cambio
	void ImprimirCambio() const;

	// PRE: -
	// POS: Ejecuta el cambio con el sensor en la casa
	void Ejecutar(CasaInteligente *casa);

	// PRE: -
	// POS: Devuelve un puntero a un dispositivo de tipo sensor que no comparte memoria con this
	Dispositivo* Clon() const;

private:
	unsigned int nro;
	EstadoSensor estado;
};


#endif
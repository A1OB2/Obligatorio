#ifndef CONDICION_H
#define CONDICION_H

#include <iostream>
using namespace std;
#include <assert.h>
#include "Cadena.h"
#include "ListaImp.h"
#include "Referencia.h"
#include "Sensor.h"

class Condicion;
ostream &operator<<(ostream& out, const Condicion &c);

class Condicion {
public:
	// Constructores
	Condicion();
	Condicion(unsigned int nro, void(*seCumpleCondicion)(int), void(*seDejaDeCumplirCondicion)(int));

	// Constructor copia
	Condicion(const Condicion &c);

	// Destructor
	virtual ~Condicion();

	// Operador de asignacion
	Condicion &operator=(const Condicion &c);

	// Operador de comparacion ==. assert(false)
	bool operator==(const Condicion &c) const;

	// Operador de comparacion <. assert(false)
	bool operator<(const Condicion &c) const;


	// PRE: -
	// POS: Muestra la condicion en pantalla
	void Imprimir() const;


	// PRE: -
	// POS: Agrega un sensor a la condicion
	void AgregarSensor(unsigned int nroSensor, EstadoSensor estado);

	// PRE: -
	// POS: Dada una lista de sensores evalua si se cumple la condicion y actua acorde
	void Evaluar(NodoLista<Asociacion<int, Referencia<Sensor>>> *l);

private:
	Lista<Asociacion<int, Referencia<Sensor>>> * sensores;
	bool cumpliendo;
	int numero;
	void(*pcumple) (int);
	void(*pnocumple) (int);
};

#endif
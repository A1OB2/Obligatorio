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
	Condicion(unsigned int nro, void (*seCumpleCondicion)(int), void (*seDejaDeCumplirCondicion)(int));

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

	void Imprimir() const;
	
	void AgregarSensor(unsigned int nroSensor, EstadoSensor estado);

	void Evaluar(CasaInteligente *casa);

private:
	template<class T, class U>
	void setABB(ABB<Asociacion<U, Referencia<T>>> *& a, NodoLista<Asociacion<U, Referencia<T>>>* l);
	ABB<Asociacion<int, Referencia<Sensor>>> * sensores;
	bool cumpliendo;
	int numero;
	void(*pcumple) (int);
	void(*pnocumple) (int);
};

#endif
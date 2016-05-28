#ifndef COLA_H
#define COLA_H

#include <iostream>
using namespace std;
#include <assert.h>

template <class T>
class Cola abstract {

public:

	virtual ~Cola() {}
	
	// Inserta un elemento al fondo
	virtual void Encolar(const T &e) abstract;

	// Returna el elemento del principio
	virtual T& Principio() const abstract;

	// Extrae el elemento del principio y lo retorna
	virtual T Decolar() abstract;

	// Vacia toda la cola
	virtual void Vaciar() abstract;

	// Retorna la cantidad de elementos de la cola
	virtual unsigned int Largo() const abstract;

	// Retorna true si la cola esta vacia
	virtual bool EsVacia() const abstract;

	virtual Cola<T> &operator=(const Cola<T> &c) abstract;

	virtual void Imprimir() const abstract;

protected:
	Cola() {}
	Cola(const Cola<T> &c) {}

};


#endif
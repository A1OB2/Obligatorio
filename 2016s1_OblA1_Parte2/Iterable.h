#ifndef ITERABLE_H
#define ITERABLE_H

#include "Iterador.h"

#include <iostream>
using namespace std;

template <class T>
class Iterable abstract
{
	friend ostream& operator<< <>(ostream& out, const Iterable<T>& iterable);

public:
	virtual ~Iterable(){}

	// Retorna un nuevo iterador sobre la estructura
	// Postcondicion: El iterador se encuentra reiniciado

	virtual Iterador<T> GetIterador() const abstract; 
};

template <class T>
ostream& operator<< <>(ostream& out, const Iterable<T>& iterable)
{
	for (Iterador<T> &it = iterable.GetIterador(); !it.EsFin(); )
	{
		out << it->Elemento();
		it.Resto();
		if (!it.EsFin())
			out << ", ";
	}
	return out;
}

#endif
#ifndef ABBIMP_H
#define ABBIMP_H

#include <iostream>
using namespace std;

#include "ABB.h"
#include "NodoABB.h"

template <class T>
class ABBImp : public ABB<T> {
public:

	ABBImp();
	ABBImp(const ABBImp<T> &a);
	ABB<T> &operator=(const ABBImp<T> &a);

	virtual ~ABBImp();

	void Vaciar();

	void Insertar(T &e);

	bool EsVacio() const; 

	const T& Maximo() const;

	const T& Minimo() const;

	bool Existe(const T &e) const;

	const T& Recuperar(const T &e) const;

	void Borrar(const T &e);

	void PreOrder(void (*f)(const T&, void *), void *ptr) const;

	void InOrder(void (*f)(const T&, void *), void *ptr) const;
	
	void PosOrder(void (*f) (const T&, void *), void *ptr) const;

protected:

};

#include "ABBImp.cpp"

#endif
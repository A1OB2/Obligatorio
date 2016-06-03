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

	//void insert(T *d);

	bool EsVacio() const; 

	const T& Maximo() const;

	const T& Minimo() const;

	bool Existe(const T &e) const;

	const T& Recuperar(const T &e) const;

	void Borrar(const T &e);

	void PreOrder(void (*f)(const T&, void *), void *ptr) const;

	void InOrder(void (*f)(const T&, void *), void *ptr) const;
	
	void PosOrder(void (*f) (const T&, void *), void *ptr) const;
	
	void imprimir();

	NodoABB<T> * getRaiz() const;

	void aNodoLista(NodoLista<T> * & l);

	T traer(T e);

protected:
	NodoABB<T> * raiz;

private:
	void insertar(NodoABB<T>* & a, T x);
	bool menorQueTodos(NodoABB<T>* a, T x);
	bool mayorQueTodos(NodoABB<T>* a, T x);
	void imprimir(NodoABB<T> *a);
	void toNodoLista(NodoABB<T> * a,NodoLista<T> * & l);
	void insertarOrdenado(NodoLista<T> * & l, T & e);
	T traer(NodoABB<T> * a,T e);
};

#include "ABBImp.cpp"

#endif
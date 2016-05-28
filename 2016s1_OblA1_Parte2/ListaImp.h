#ifndef LISTAIMP_H
#define LISTAIMP_H

#include <assert.h>
#include "Lista.h"
#include "IteradorListaImp.h"
#include "NodoLista.h"

template <class T>
class IteradorListaImp;

template <class T>
class ListaImp: public Lista<T> {
	friend class IteradorListaImp<T>; 
	friend ostream &operator<< <>(ostream& o, const ListaImp<T> & l);
public:

	// Constructor por defecto
	ListaImp();

	// Constructor copia
	ListaImp(const Lista<T> &l);
	ListaImp(const ListaImp<T> &l);

	// Operador de asignacion
	Lista<T> &operator=(const Lista<T> &l);
	Lista<T> &operator=(const ListaImp<T> &l);


	// Para ver la documentacion del resto de las funciones ver la especificacion
	virtual ~ListaImp();

	void AgregarPpio(const T &e);
	void AgregarFin(const T &e);
	void AgregarPos(const T &e, unsigned int pos);
	void BorrarPpio();	
	void BorrarFin();
	void BorrarPos(unsigned int pos);
	void Borrar(const T &e);
	T& ElementoPpio() const;
	T& ElementoFin() const;
	T& ElementoPos(unsigned int pos) const;
	T& Recuperar(const T&) const; 
	bool Existe(const T &e) const;	

	void Vaciar();

	unsigned int Largo() const;

	bool EsVacia() const;
	bool EsLlena() const;

	Iterador<T> GetIterador() const;

protected:

};

#include "ListaImp.cpp"

#endif
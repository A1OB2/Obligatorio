#ifndef LISTAORDIMP_H
#define LISTAORDIMP_H

#include <assert.h>
#include "ListaOrd.h"
#include "IteradorListaOrdImp.h"
#include "NodoLista.h"

template <class T>
class IteradorListaOrdImp;

template <class T>
class ListaOrdImp: public ListaOrd<T> {
	friend class IteradorListaOrdImp<T>; 
	friend ostream &operator<< <>(ostream& o, const ListaOrdImp<T> & l);
public:

	// Constructor por defecto
	ListaOrdImp();

	// Constructor copia
	ListaOrdImp(const ListaOrd<T> &l);
	ListaOrdImp(const ListaOrdImp<T> &l);

	// Operador de asignacion
	ListaOrd<T> &operator=(const ListaOrd<T> &l);
	ListaOrd<T> &operator=(const ListaOrdImp<T> &l);

	// Para ver la documentacion del resto de las funciones ver la especificacion
	virtual ~ListaOrdImp();

	void AgregarOrd(const T &e);
	void BorrarPpio();	
	void BorrarFin();
	void BorrarPos(unsigned int pos);
	void Borrar(const T &e);	
	const T& ElementoPpio() const;
	const T& ElementoFin() const;
	const T& ElementoPos(unsigned int pos) const; 	//Funcion que se debe implementar para poder usar el iterador
	const T& Recuperar(const T&) const; 
	bool Existe(const T &e) const;	

	void Vaciar();

	unsigned int Largo() const;

	bool EsVacia() const;
	bool EsLlena() const;

	Iterador<T> GetIterador() const;

protected:

	// Atributos

};

#include "ListaOrdImp.cpp"

#endif
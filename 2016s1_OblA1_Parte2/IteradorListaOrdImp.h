#pragma once

#ifndef ITERADORLISTAORDIMP_H
#define ITERADORLISTAORDIMP_H

#include "Iterador.h"
#include "ListaOrdImp.h"

template <class T>
class ListaOrdImp;

template <class T>
class IteradorListaOrdImp : public Iterador<T> {
private:
	const ListaOrdImp<T> *lista;
	unsigned int actual;

public:
	IteradorListaOrdImp();
	IteradorListaOrdImp(const ListaOrdImp<T> &l);
	IteradorListaOrdImp(const IteradorListaOrdImp<T> &it);
		
	Iterador<T> &operator=(const IteradorListaOrdImp<T> &it);
	Iterador<T> *Clon() const;

	virtual ~IteradorListaOrdImp();

	const T &Elemento() const;
	void Resto();
	bool EsFin() const;
	void Principio();
};

#include "IteradorListaOrdImp.cpp"

#endif
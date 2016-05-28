#include "IteradorListaOrdImp.h"

#ifndef ITERADORLISTAORDIMP_CPP
#define ITERADORLISTAORDIMP_CPP

template <class T>
IteradorListaOrdImp<T>::IteradorListaOrdImp() {
	lista = NULL;
	actual = 0;
}

template <class T>
IteradorListaOrdImp<T>::IteradorListaOrdImp(const ListaOrdImp<T> &l) {
	lista = &l;
	actual = 0;
}

template <class T>
IteradorListaOrdImp<T>::IteradorListaOrdImp(const IteradorListaOrdImp<T> &it) {
	lista = it.lista;
	actual = it.actual;
}
	
template <class T>
Iterador<T> &IteradorListaOrdImp<T>::operator=(const IteradorListaOrdImp<T> &it) {
	if (this != &it) {
		lista = it.lista;
		actual = it.actual;
	}
	return *this;
}

template <class T>
Iterador<T> *IteradorListaOrdImp<T>::Clon() const {
	IteradorListaOrdImp<T> *it = new IteradorListaOrdImp<T>(*this);
	return it;
}

template <class T>
IteradorListaOrdImp<T>::~IteradorListaOrdImp() {
}

template <class T>
const T &IteradorListaOrdImp<T>::Elemento() const {
	return lista->ElementoPos(actual);
}

template <class T>
void IteradorListaOrdImp<T>::Resto() {
	actual++;
}

template <class T>
bool IteradorListaOrdImp<T>::EsFin() const {
	return actual >= lista->Largo();
}

template <class T>
void IteradorListaOrdImp<T>::Principio() {
	actual = 0;
}


#endif
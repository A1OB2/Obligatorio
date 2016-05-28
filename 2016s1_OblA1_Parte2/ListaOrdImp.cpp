#include "ListaOrdImp.h"

#ifndef LISTAORDIMP_CPP
#define LISTAORDIMP_CPP

template <class T>
ostream &operator<< <>(ostream& out, const ListaOrdImp<T> &l) {
	for (Iterador<T> &i = l.GetIterador(); !i.EsFin();) {
		out << i++ << " ";
	}
	return out;
}

template <class T>
ListaOrdImp<T>::ListaOrdImp(){
	//NO IMPLEMENTADO
}

template <class T>
ListaOrdImp<T>::ListaOrdImp(const ListaOrd<T> &l) {
	//NO IMPLEMENTADO
}

template <class T>
ListaOrdImp<T>::ListaOrdImp(const ListaOrdImp<T> &l) {
	//NO IMPLEMENTADO
}

template <class T>
ListaOrd<T> &ListaOrdImp<T>::operator=(const ListaOrd<T> &l) { 
	if (this != &l) {
		//NO IMPLEMENTADO
	}
	return *this;
}

template <class T>
ListaOrd<T> &ListaOrdImp<T>::operator=(const ListaOrdImp<T> &l) { 
	if (this != &l) {
		//NO IMPLEMENTADO
	}
	return *this;
}

template <class T>
ListaOrdImp<T>::~ListaOrdImp(){
	//NO IMPLEMENTADO
}

template <class T>
void ListaOrdImp<T>::AgregarOrd(const T &e) {
	//NO IMPLEMENTADO
}

template <class T>
void ListaOrdImp<T>::BorrarPpio() {
	//NO IMPLEMENTADO
}

template <class T>
void ListaOrdImp<T>::BorrarFin() {
	//NO IMPLEMENTADO
}

template <class T>
void ListaOrdImp<T>::BorrarPos(unsigned int pos) {
	//NO IMPLEMENTADO
}

template <class T>
void ListaOrdImp<T>::Borrar(const T &e) {
	//NO IMPLEMENTADO
}

template <class T>
const T& ListaOrdImp<T>::ElementoPpio() const {
	//NO IMPLEMENTADO
	return *(new T()); 
}

template <class T>
const T& ListaOrdImp<T>::ElementoFin() const {
	//NO IMPLEMENTADO
	return *(new T()); 
}

template <class T>
const T& ListaOrdImp<T>::ElementoPos(unsigned int pos) const {
	//NO IMPLEMENTADO
	return *(new T()); 
}

template <class T>
const T& ListaOrdImp<T>::Recuperar(const T &e) const {
	//NO IMPLEMENTADO
	return *(new T()); 
}

template <class T>
bool ListaOrdImp<T>::Existe(const T &e) const {
	//NO IMPLEMENTADO	
	return false;
}

template <class T>
void ListaOrdImp<T>::Vaciar() {
	//NO IMPLEMENTADO	
}

template <class T>
unsigned int ListaOrdImp<T>::Largo()const { 
	//NO IMPLEMENTADO	
	return 0; 
}

template <class T>
bool ListaOrdImp<T>::EsVacia()const { 
	//NO IMPLEMENTADO	
	return false; 
}

template <class T>
bool ListaOrdImp<T>::EsLlena()const { 
	return false; 
}

template <class T>
Iterador<T> ListaOrdImp<T>::GetIterador() const {
	return IteradorListaOrdImp<T>(*this);
}

#endif
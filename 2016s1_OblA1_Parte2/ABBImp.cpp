#include "ABBImp.h"

#ifndef AVLIMP_CPP
#define AVLIMP_CPP

template <class T>
ABBImp<T>::ABBImp() {
	//NO IMPLEMENTADO
}

template <class T>
ABBImp<T>::ABBImp(const ABBImp<T> &a) {
	//NO IMPLEMENTADO
}

template <class T>
ABB<T> &ABBImp<T>::operator=(const ABBImp<T> &a) {
	//NO IMPLEMENTADO
}

template <class T>
ABBImp<T>::~ABBImp() {
	//NO IMPLEMENTADO
}

template <class T>
void ABBImp<T>::Vaciar() {
	//NO IMPLEMENTADO
}

template <class T>
void ABBImp<T>::Insertar(T &e) {
	//NO IMPLEMENTADO
}

template <class T>
bool ABBImp<T>::EsVacio() const {
	//NO IMPLEMENTADO
	return false;
} 

template <class T>
const T& ABBImp<T>::Maximo() const {
	//NO IMPLEMENTADO
	return *(new T()); 
}

template <class T>
const T& ABBImp<T>::Minimo() const {
	//NO IMPLEMENTADO
	return *(new T()); 
}

template <class T>
bool ABBImp<T>::Existe(const T &e) const {
	//NO IMPLEMENTADO
	return false;
}

template <class T>
const T& ABBImp<T>::Recuperar(const T &e) const {
	//NO IMPLEMENTADO
	return *(new T()); 
}

template <class T>
void ABBImp<T>::Borrar(const T &e) {
	//NO IMPLEMENTADO
}

template <class T>
void ABBImp<T>::PreOrder(void (*f)(const T&, void *), void *ptr) const {
	//NO IMPLEMENTADO
}

template <class T>
void ABBImp<T>::InOrder(void (*f)(const T&, void *), void *ptr) const {
	//NO IMPLEMENTADO
}

template <class T>
void ABBImp<T>::PosOrder(void (*f) (const T&, void *), void *ptr) const {
	//NO IMPLEMENTADO
}




#endif
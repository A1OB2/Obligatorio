#include "ABBImp.h"

#ifndef AVLIMP_CPP
#define AVLIMP_CPP



template <class T>
ABBImp<T>::ABBImp() {
	this->raiz = NULL;
}

template <class T>
ABBImp<T>::ABBImp(const ABBImp<T> &a) {
	this = new ABBImp<T>();
	this->raiz = copyOf(a.raiz);
}

template<class T>
void ABBImp<T>::copyOf(const NodoABB<T>* a) {
	NodoABB<T> * ret = NULL;
	if (a != NULL) {
		ret = new NodoABB<T>(a->dato);
		ret->hDer = copyOf(a->hDer);
		ret->hIzq = copyOf(a->hIzq);
	}

	return ret;
}

template <class T>
ABB<T> &ABBImp<T>::operator=(const ABBImp<T> &a) {
	if (this != &a) {
		this->Vaciar();
		this->raiz = copyOf(a->raiz);
	}
	return *this;
}

template <class T>
ABBImp<T>::~ABBImp() {
	//NO IMPLEMENTADO
}

template <class T>
void ABBImp<T>::Vaciar() {
		vaciar(raiz);
}

template<class T>
void ABBImp<T>::vaciar(NodoABB<T>* a) {
	if (a != NULL) {
		vaciar(a->hIzq);
		vaciar(a->hDer);
		//delete a->hIzq;
		//delete a->hDer;
		delete a;
	}
}

template <class T>
bool ABBImp<T>::Insertar(T &e) {
	return insertar(this->raiz, e);
}


template<class T>
T ABBImp<T>::fetch(T e) {
	return traer(raiz, e);
}
template<class T>
T ABBImp<T>::traer(NodoABB<T>* a, T e) {
	if (a == NULL) return T();
	if (a->dato == e) return a->dato;
	if (a->dato > e) {
		return traer(a->hIzq, e);
	} else {
		return traer(a->hDer, e);
	}
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
bool ABBImp<T>::Existe( T &e) {
	return existe(this->raiz,e);
}

template <class T>
const T& ABBImp<T>::Recuperar(const T &e) const {
	return *(new T());
}

template <class T>
void ABBImp<T>::Borrar(const T &e) {
	//NO IMPLEMENTADO
}

template <class T>
void ABBImp<T>::PreOrder(void(*f)(const T&, void *), void *ptr) const {
	//NO IMPLEMENTADO
}

template <class T>
void ABBImp<T>::InOrder(void(*f)(const T&, void *), void *ptr) const {
	//NO IMPLEMENTADO
}

template <class T>
void ABBImp<T>::PosOrder(void(*f) (const T&, void *), void *ptr) const {
	//NO IMPLEMENTADO
}
//own method

////Auxiliares
template <class T>
bool ABBImp<T>::insertar(NodoABB<T>* & a, T x) {
	if (a == NULL) {
		a = new NodoABB<T>(x);
		return true;
	} else if (a->dato < x) {
		return insertar(a->hDer, x);
	} else if (a->dato > x) {
		return insertar(a->hIzq, x);
	} else if (a->dato == x) {
		return false;
	}
	return false;
}

template<class T>
bool ABBImp<T>::existe(NodoABB<T>*& a, T x) {
	if (a == NULL)return false;
	if (a->dato == x)return true;
	if (a->dato < x) return existe(a->hDer, x);
	return existe(a->hIzq, x);
}

template<class T>
bool ABBImp<T>::allAnd(bool(*f)(T)) {
	return allAnd(raiz, f);
}

template<class T>
bool ABBImp<T>::allAnd(NodoABB<T> *a, bool (*f)(T)) {
	if (a == NULL) return true;
	return f(a->dato) && allAnd(a->hIzq,f) && allAnd(a->hDer,f);
}

template<class T>
bool ABBImp<T>::allOr(bool(*f)(T)) {
	return allOr(raiz, f);
}

template<class T>
bool ABBImp<T>::allOr(NodoABB<T> *a, bool(*f)(T)) {
	if (a == NULL) return false;
	return f(a->dato) || allAnd(a->hIzq,f) || allAnd(a->hDer,f);
}



template <class T>
void ABBImp<T>::aNodoLista(NodoLista<T> * & l) {
	toNodoLista(raiz, l);
}

template<class T>
void ABBImp<T>::toNodoLista(NodoABB<T>* a, NodoLista<T>*& l) {
	if (a != NULL) {
		insertarOrdenado(l, a->dato);
		toNodoLista(a->hDer, l);
		toNodoLista(a->hIzq, l);
	}
}

template<class T>
void ABBImp<T>::insertarOrdenado(NodoLista<T>*& l, T & e) {
	if (l == NULL) {
		l = new NodoLista<T>(e);
	} else if (e < l->dato) {
		NodoLista<T> * aux = l;
		l = new NodoLista<T>(e);
		aux->ant = l;
		l->sig = aux;
	} else {
		insertarOrdenado(l->sig, e);
	}
}
#endif
#include "ABBImp.h"

#ifndef AVLIMP_CPP
#define AVLIMP_CPP

////Auxiliares
//template <class T>
//bool mayorQueTodos(NodoABB<T>* a, T x) {
//	return a == NULL ? true : a->dato > x && mayorQueTodos(a->izq, x) && mayorQueTodos(a->der, x);
//}
//
//template <class T>
//bool menorQueTodos(NodoABB<T>* a, T x) {
//	return a == NULL ? true : a->dato < x && menorQueTodos(a->izq, x) && menorQueTodos(a->der, x);
//}
//
//template <class T>
//void insertar(NodoABB<T>* & a, T x) {
//	if (a == NULL) {
//		a = new NodoABB(x);
//	} else {
//		if (a->dato < x) {
//			if (menorQueTodos(a->izq, x) && mayorQueTodos(a->der, x)) {
//				nodoAB * aux = a;
//				a = new NodoABB(x);
//				a->der = aux->der;
//				aux->der = NULL;
//				a->izq = aux;
//			} else insertar(a->der, x);
//		} else if (a->dato > x) {
//			if (menorQueTodos(a->hDer, x) && mayorQueTodos(a->der, x)) {
//				nodoAB * aux = a;
//				a = new NodoABB(x);
//				a->izq = aux->izq;
//				aux->izq = NULL;
//				a->der = aux;
//			} else insertar(a->izq, x);
//		}
//	}
//}
//


template <class T>
ABBImp<T>::ABBImp() {
	this->raiz = NULL;
}

template <class T>
ABBImp<T>::ABBImp(const ABBImp<T> &a) {
	raiz = NULL;
	*this = a;
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
	//NO IMPLEMENTADO
}

template <class T>
void ABBImp<T>::Insertar(T &e) {
	//No imp
}


//template <class T>
//void ABBImp<T>::insert(T * d) {
//	insertar(raiz, d);
//}


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
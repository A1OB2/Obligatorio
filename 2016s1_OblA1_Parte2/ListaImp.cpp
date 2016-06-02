#include "ListaImp.h"

#ifndef LISTAIMP_CPP
#define LISTAIMP_CPP

template <class T>
ostream &operator<< <>(ostream& out, const ListaImp<T> &l) {
	for (Iterador<T> &i = l.GetIterador(); !i.EsFin();) {
		out << i++ << " ";
	}
	return out;
}

template <class T>
ListaImp<T>::ListaImp(){
	lista = new NodoLista<T>();
}

template <class T>
ListaImp<T>::ListaImp(const Lista<T> &l) {
	assert(false);
}

template <class T>
ListaImp<T>::ListaImp(const ListaImp<T> &l) {
	assert(false);
}

template <class T>
Lista<T> &ListaImp<T>::operator=(const Lista<T> &l) { 
	if (this != &l) {
		//NO IMPLEMENTADO
	}
	return *this;
}

template <class T>
Lista<T> &ListaImp<T>::operator=(const ListaImp<T> &l) { 
	if (this != &l) {
		//NO IMPLEMENTADO
	}
	return *this;
}

template <class T>
ListaImp<T>::~ListaImp(){
	//NO IMPLEMENTADO
}

template <class T>
void ListaImp<T>::AgregarPpio(const T &e) {
	NodoLista<T> * aux = this->lista;
	lista = new NodoLista<T>(e);
	lista->sig = aux;

}

template <class T>
void ListaImp<T>::AgregarFin(const T &e) {
	//NO IMPLEMENTADO
}

template <class T>
void ListaImp<T>::AgregarPos(const T &e, unsigned int pos) {
	//NO IMPLEMENTADO
}

template <class T>
void ListaImp<T>::BorrarPpio() {
	//NO IMPLEMENTADO
}

template <class T>
void ListaImp<T>::BorrarFin() {
	//NO IMPLEMENTADO
}

template <class T>
void ListaImp<T>::BorrarPos(unsigned int pos) {
	//NO IMPLEMENTADO
}

template <class T>
void ListaImp<T>::Borrar(const T &e) {
	//NO IMPLEMENTADO
}

template <class T>
T& ListaImp<T>::ElementoPpio() const {
	//NO IMPLEMENTADO
	return *(new T()); 
}

template <class T>
T& ListaImp<T>::ElementoFin() const {
	//NO IMPLEMENTADO
	return *(new T()); 
}

template <class T>
T& ListaImp<T>::ElementoPos(unsigned int pos) const {
	//NO IMPLEMENTADO
	return *(new T()); 
}

template <class T>
T& ListaImp<T>::Recuperar(const T &e) const {
	//NO IMPLEMENTADO
	return *(new T()); 
}

template <class T>
bool ListaImp<T>::Existe(const T &e) const {
	//NO IMPLEMENTADO	
	return false;
}

template <class T>
void ListaImp<T>::Vaciar() {
	//NO IMPLEMENTADO	
}

template <class T>
unsigned int ListaImp<T>::Largo()const { 
	//NO IMPLEMENTADO	
	return 0; 
}

template <class T>
bool ListaImp<T>::EsVacia()const { 
	//NO IMPLEMENTADO	
	return false; 
}

template <class T>
bool ListaImp<T>::EsLlena()const { 
	return false; 
}

template <class T>
Iterador<T> ListaImp<T>::GetIterador() const {
	return IteradorListaImp<T>(*this);
}

template<class T>
void ListaImp<T>::imprimir() {
	imprimir(lista);
}

template<class T>
void ListaImp<T>::imprimir(NodoLista<T> *l) {
	if (l != NULL) {
		int i = l->dato.GetDominio();
		auto estado = l->dato.GetRangoInseguro().GetDato();//.GetRangoInseguro().GetDato().GetEstado();
		cout << i << ":" << estado << endl;
	}
}

#endif
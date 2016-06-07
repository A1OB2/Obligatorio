#include "Escena.h"

#ifndef ESCENA_CPP
#define ESCENA_CPP

ostream &operator<<(ostream& out, const Escena &e) {
	e.Imprimir(out);
	return out;
}

Escena::Escena() {
	this->numero = 0;
	this->nombre = "";
	this->cambios = new ABBImp<Asociacion<int, Referencia<Cambio>>>();
}

Escena::Escena(unsigned int nro, Cadena nombre) {
	this->numero = nro;
	this->nombre = nombre;
	this->cambios = new ABBImp<Asociacion<int, Referencia<Cambio>>>();
}

Escena::Escena(const Escena &e) {
	this->numero = e.numero;
	this->nombre = e.nombre;
	NodoLista < Asociacion < int, Referencia<Cambio>>> * lCambios = NULL;
	e.cambios->aNodoLista(lCambios);
	setABB(this->cambios, lCambios);
}

Escena & Escena::operator=(const Escena &e) {
	if (this != &e) {
		// NO IMPLEMENTADA
	}
	return *this;
}

Escena::~Escena() {
	// NO IMPLEMENTADA
}

bool Escena::operator==(const Escena &e) const {
	// NO IMPLEMENTADA
	return false;
}

void Escena::Imprimir(ostream& out) const {
	// NO IMPLEMENTADA
}

unsigned int Escena::GetNro() const {
	// NO IMPLEMENTADA
	return 0;
}

Cadena Escena::GetNombre() const {
	// NO IMPLEMENTADA
	return "";
}

void Escena::ImprimirCambios() const {
	// NO IMPLEMENTADA
}

void Escena::Ejecutar(CasaInteligente *casa) const {
	// NO IMPLEMENTADA
}

void Escena::AgregarCambio(const Cambio &c) {
	// NO IMPLEMENTADA
}

bool Escena::EsRara() const {
	// NO IMPLEMENTADA
	return false;
}
	//aux

	template<class T, class U>
	 void Escena::setABB(ABB<Asociacion<U, Referencia<T>>>*& a, NodoLista<Asociacion<U, Referencia<T>>>* l){
		 a = new ABBImp<Asociacion<U, Referencia<T>>>();
		 while (l != NULL) {
			 a->Insertar(l->dato);
			 l = l->sig;
		 }
	}
#endif


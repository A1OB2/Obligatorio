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
	this->cambios = new ListaImp<Referencia<Cambio>>();
}

Escena::Escena(unsigned int nro, Cadena nombre) {
	this->numero = nro;
	this->nombre = nombre;
	this->cambios = new ListaImp<Referencia<Cambio>>();
}

Escena::Escena(const Escena &e) {
	this->numero = e.numero;
	this->nombre = e.nombre;
	Iterador<Referencia<Cambio>> it = e.cambios->GetIterador();
	cambios = new ListaImp<Referencia<Cambio>>();
	while (!it.EsFin()) {
		cambios->AgregarPpio(Referencia<Cambio>(it.ElementoInseguro()));
		it.Resto();
	}
	it.Principio();
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
#endif


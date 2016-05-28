#include "Escena.h"

#ifndef ESCENA_CPP
#define ESCENA_CPP

ostream &operator<<(ostream& out, const Escena &e) {
	e.Imprimir(out);
	return out;
}

Escena::Escena() {
	// NO IMPLEMENTADA
}

Escena::Escena(unsigned int nro, Cadena nombre) {
	// NO IMPLEMENTADA
}

Escena::Escena(const Escena &e) {
	// NO IMPLEMENTADA
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


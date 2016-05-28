#include "Luz.h"

#ifndef LUZ_CPP
#define LUZ_CPP

ostream &operator<<(ostream& out, const Luz &l) {
	l.Imprimir();
	return out;
}

Luz::Luz() {
	// NO IMPLEMENTADA
}

Luz::Luz(unsigned int nro, Cadena nombre) {
	// NO IMPLEMENTADA
}

Luz::Luz(const Luz &l) {
	// NO IMPLEMENTADA
}

Luz & Luz::operator=(const Luz &l) {
	if (this != &l) {
		// NO IMPLEMENTADA
	}
	return *this;
}

Luz::~Luz() {
	// NO IMPLEMENTADA
}

bool Luz::operator==(const Luz &l) const {
	// NO IMPLEMENTADA
	return false;
}

unsigned int Luz::GetNro() const {
	// NO IMPLEMENTADA
	return 0;
}

Cadena Luz::GetNombre() const {
	// NO IMPLEMENTADA
	return "";
}

void Luz::SetIntensidad(unsigned int intensidad) {
	// NO IMPLEMENTADA
}

unsigned int Luz::GetIntensidad() const {
	// NO IMPLEMENTADA
	return 0;
}

void Luz::Imprimir() const {
	// NO IMPLEMENTADA
}

void Luz::ImprimirCambio() const {
	// NO IMPLEMENTADA
}

void Luz::Ejecutar(CasaInteligente *casa) {
	// NO IMPLEMENTADA
}

Dispositivo* Luz::Clon() const {
	return new Luz(*this);
}

#endif


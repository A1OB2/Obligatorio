#include "Condicion.h"

#ifndef CONDICION_CPP
#define CONDICION_CPP

ostream &operator<<(ostream& out, const Condicion &c) {
	c.Imprimir();
	return out;
}

Condicion::Condicion() {
	// NO IMPLEMENTADA
}

Condicion::Condicion(unsigned int nro, void (*seCumpleCondicion)(int), void (*seDejaDeCumplirCondicion)(int)) {
	// NO IMPLEMENTADA
}

Condicion::Condicion(const Condicion &c) {
	// NO IMPLEMENTADA
}

Condicion & Condicion::operator=(const Condicion &c) {
	if (this != &c) {
		// NO IMPLEMENTADA
	}
	return *this;
}

Condicion::~Condicion() {
	// NO IMPLEMENTADA
}

bool Condicion::operator==(const Condicion &c) const {
	// NO IMPLEMENTADA
	return false;
}

bool Condicion::operator<(const Condicion &c) const {
	// NO IMPLEMENTADA
	return false;
}

void Condicion::Imprimir() const {
	// NO IMPLEMENTADA
}

void Condicion::AgregarSensor(unsigned int nroSensor, EstadoSensor estado) {
	// NO IMPLEMENTADA
}

void Condicion::Evaluar(CasaInteligente *casa) {
	// NO IMPLEMENTADA
}

#endif


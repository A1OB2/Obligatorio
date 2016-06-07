#include "Cambio.h"

#ifndef CAMBIO_CPP
#define CAMBIO_CPP

ostream &operator<<(ostream& out, const Cambio &c) {
	c.Imprimir();
	return out;
}

Cambio::Cambio() {
	/*
	lo dejo vacío porque no se pueden instanciar clases abstractas (Dispositivo)
	*/
}

Cambio::Cambio(const Dispositivo &d) {
	this->disp = d.Clon();
}

Cambio::Cambio(const Cambio &c) {
	// NO IMPLEMENTADA
}

Cambio & Cambio::operator=(const Cambio &c) {
	if (this != &c) {
		// NO IMPLEMENTADA
	}
	return *this;
}

Cambio::~Cambio() {
	// NO IMPLEMENTADA
}

bool Cambio::operator==(const Cambio &c) const {
	// NO IMPLEMENTADA
	return false;
}

bool Cambio::operator<(const Cambio &c) const {
	// NO IMPLEMENTADA
	return false;
}

void Cambio::Imprimir() const {
	// NO IMPLEMENTADA
}

void Cambio::Ejecutar(CasaInteligente *casa) {
	// NO IMPLEMENTADA
}

#endif


#include "Artefacto.h"

#ifndef ARTEFACTO_CPP
#define ARTEFACTO_CPP

ostream &operator<<(ostream& out, const Artefacto &a) {
	a.Imprimir();
	return out;
}

Artefacto::Artefacto() {
	// NO IMPLEMENTADA
}

Artefacto::Artefacto(unsigned int nro, Cadena nombre) {
	// NO IMPLEMENTADA
}

Artefacto::Artefacto(const Artefacto &a) {
	// NO IMPLEMENTADA
}

Artefacto & Artefacto::operator=(const Artefacto &a) {
	if (this != &a) {
		// NO IMPLEMENTADA
	}
	return *this;
}

Artefacto::~Artefacto() {
	// NO IMPLEMENTADA
}

bool Artefacto::operator==(const Artefacto &a) const {
	// NO IMPLEMENTADA
	return false;
}

unsigned int Artefacto::GetNro() const {
	// NO IMPLEMENTADA
	return 0;
}

Cadena Artefacto::GetNombre() const {
	// NO IMPLEMENTADA
	return "";
}

void Artefacto::SetEstado(EstadoArtefacto estado) {
	// NO IMPLEMENTADA
}

EstadoArtefacto Artefacto::GetEstado() const {
	// NO IMPLEMENTADA
	return OFF;
}

void Artefacto::Imprimir() const  {
	// NO IMPLEMENTADA
}

void Artefacto::ImprimirCambio() const  {
	// NO IMPLEMENTADA
}

void Artefacto::Ejecutar(CasaInteligente *casa) {
	// NO IMPLEMENTADA
}

Dispositivo* Artefacto::Clon() const {
	return new Artefacto(*this);
}

#endif


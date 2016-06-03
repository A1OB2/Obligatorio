#include "Artefacto.h"

#ifndef ARTEFACTO_CPP
#define ARTEFACTO_CPP

ostream &operator<<(ostream& out, const Artefacto &a) {
	a.Imprimir();
	return out;
}

Artefacto::Artefacto() {
	this->nombre = "";
	this->numero = 0;
	estado = OFF;
}

Artefacto::Artefacto(unsigned int nro, Cadena nombre) {
	this->numero = nro;
	this->nombre = nombre;
	estado = OFF;
}

Artefacto::Artefacto(const Artefacto &a) {
	this->estado = a.estado;
	this->nombre = a.nombre;
	this->numero = a.numero;
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
	return this->numero;
}

Cadena Artefacto::GetNombre() const {
	// NO IMPLEMENTADA
	return this->nombre;
}

void Artefacto::SetEstado(EstadoArtefacto estado) {
	this->estado = estado;
}

EstadoArtefacto Artefacto::GetEstado() const {
	return this->estado;
}

void Artefacto::Imprimir() const  {
	cout << numero << ": " << nombre << (estado == OFF ? ": OFF" : ": ON") << endl;
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


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
	this->estado = OFF;
}

Artefacto::Artefacto(unsigned int nro, Cadena nombre) {
	this->numero = nro;
	this->nombre = nombre;
	this->estado = OFF;
}

Artefacto::Artefacto(const Artefacto &a) {
	this->numero = a.numero;
	this->nombre = a.nombre;
	this->estado = a.estado;
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
	return this->nombre;
}

void Artefacto::SetEstado(EstadoArtefacto estado) {
	this->estado = estado;
}

EstadoArtefacto Artefacto::GetEstado() const {
	return this->estado;
}

void Artefacto::Imprimir() const  {
	cout << this->GetNro() << ": " << this->GetNombre() << endl;
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


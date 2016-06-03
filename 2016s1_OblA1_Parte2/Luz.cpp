#include "Luz.h"

#ifndef LUZ_CPP
#define LUZ_CPP

ostream &operator<<(ostream& out, const Luz &l) {
	l.Imprimir();
	return out;
}

Luz::Luz() {
	this->nroLuz = 0;
	this->nombre = "";
	this->intensidad = 0;
}

Luz::Luz(unsigned int nro, Cadena nombre) {
	this->nroLuz = nro;
	this->nombre = nombre;
	this->intensidad = 0;
}

Luz::Luz(const Luz &l) {
	this->nroLuz = l.nroLuz;
	this->nombre = l.nombre;
	this->intensidad = l.intensidad;
}

Luz & Luz::operator=(const Luz &l) {
	if (this != &l) {
		// NO IMPLEMENTADA
	}
	return *this;
}

Luz::~Luz() {
	//delete this->nombre;
}

bool Luz::operator==(const Luz &l) const {
	// NO IMPLEMENTADA
	return false;
}

bool Luz::operator<(const Luz & l) const {
	return nroLuz<l.GetNro();
}

bool Luz::operator>(const Luz & l) const {
	return nroLuz>l.GetNro();
}

unsigned int Luz::GetNro() const {
	return this->nroLuz;
}

Cadena Luz::GetNombre() const {
	return this->nombre;
}

void Luz::SetIntensidad(unsigned int intensidad) {
	this->intensidad = intensidad;
}

unsigned int Luz::GetIntensidad() const {
	return this->intensidad;
}

void Luz::Imprimir() const {
	cout << this->GetNro() << ": " << this->GetNombre() << endl;
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


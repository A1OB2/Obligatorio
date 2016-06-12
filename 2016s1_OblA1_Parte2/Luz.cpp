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
}

bool Luz::operator==(const Luz &l) const {
	return this->nombre == l.nombre
		&& this->nroLuz == l.nroLuz
		&& this->intensidad == l.intensidad;
}

bool Luz::operator<(const Luz & l) const {
	return nroLuz < l.GetNro();
}

bool Luz::operator>(const Luz & l) const {
	return nroLuz > l.GetNro();
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
	cout << nroLuz << ": " << nombre << ": " << intensidad << "%" << endl;
}

void Luz::ImprimirCambio() const {
	// NO IMPLEMENTADA
}

void Luz::Ejecutar(CasaInteligente *casa) {
	casa->CambiarEstadoLuz(this->nroLuz, this->intensidad);
}

Dispositivo* Luz::Clon() const {
	return new Luz(*this);
}

#endif


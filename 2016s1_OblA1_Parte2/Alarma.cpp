#include "Alarma.h"

#ifndef ALARMA_CPP
#define ALARMA_CPP

ostream &operator<<(ostream& out, const Alarma &a) {
	a.Imprimir();
	return out;
}

Alarma::Alarma() {
	// NO IMPLEMENTADA
}

Alarma::Alarma(const Alarma &a) {
	// NO IMPLEMENTADA
}

Alarma & Alarma::operator=(const Alarma &a) {
	if (this != &a) {
		// NO IMPLEMENTADA
	}
	return *this;
}

Alarma::~Alarma() {
	// NO IMPLEMENTADA
}

bool Alarma::operator==(const Alarma &a) const {
	// NO IMPLEMENTADA
	return false;
}

unsigned int Alarma::GetNro() const {
	// NO IMPLEMENTADA
	return 0;
}

Cadena Alarma::GetNombre() const {
	// NO IMPLEMENTADA
	return "";
}

void Alarma::SetEstado(EstadoAlarma estado) {
	// NO IMPLEMENTADA
}

EstadoAlarma Alarma::GetEstado() const {
	// NO IMPLEMENTADA
	return DESACTIVADA;
}

void Alarma::Imprimir() const  {
	// NO IMPLEMENTADA
}

void Alarma::ImprimirCambio() const  {
	// NO IMPLEMENTADA
}

void Alarma::Ejecutar(CasaInteligente *casa) {
	// NO IMPLEMENTADA
}

Dispositivo* Alarma::Clon() const {
	return new Alarma(*this);
}

#endif


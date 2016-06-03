#include "Alarma.h"

#ifndef ALARMA_CPP
#define ALARMA_CPP

ostream &operator<<(ostream& out, const Alarma &a) {
	a.Imprimir();
	return out;
}

Alarma::Alarma() {
	nro = 0;
	estado = DESACTIVADA;
}

Alarma::Alarma(const Alarma &a) {
	nro = a.GetNro();
	estado = a.GetEstado();
}

Alarma & Alarma::operator=(const Alarma &a) {
	if (this != &a) {
		// NO IMPLEMENTADA
	}
	return *this;
}

Alarma::~Alarma() {
	
}

bool Alarma::operator==(const Alarma &a) const {
	return false;
}

unsigned int Alarma::GetNro() const {
	// NO IMPLEMENTADA
	return 0;
}

Cadena Alarma::GetNombre() const {
	return nombre;
}

void Alarma::SetEstado(EstadoAlarma estado) {
	this->estado = estado;
}

EstadoAlarma Alarma::GetEstado() const {
	return this->estado;
}

void Alarma::Imprimir() const  {
	cout << "- Alarma " << (estado==ACTIVADA?"ACTIVADA":"DESACTIVADA") << endl;
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


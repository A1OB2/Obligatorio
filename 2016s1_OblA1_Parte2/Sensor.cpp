#include "Sensor.h"

#ifndef SENSOR_CPP
#define SENSOR_CPP

ostream &operator<<(ostream& out, const Sensor &s) {
	s.Imprimir(out);
	return out;
}

Sensor::Sensor() {
	nro = 0;
	estado = NORMAL;
}

Sensor::Sensor(unsigned int nro) {
	this->nro = nro;
	estado = NORMAL;
}

Sensor::Sensor(const Sensor &s) {
	// NO IMPLEMENTADA
}

Sensor & Sensor::operator=(const Sensor &s) {
	if (this != &s) {
		// NO IMPLEMENTADA
	}
	return *this;
}

Sensor::~Sensor() {
	// NO IMPLEMENTADA
}

bool Sensor::operator==(const Sensor &s) const {
	// NO IMPLEMENTADA
	return false;
}

bool Sensor::operator<(const Sensor & s) const {
	return this->nro < s.GetNro();
}

bool Sensor::operator>(const Sensor & s) const {
	return this->nro > s.GetNro();
}

unsigned int Sensor::GetNro() const {
	// NO IMPLEMENTADA
	return 0;
}

void Sensor::SetEstado(EstadoSensor estado) {
	// NO IMPLEMENTADA
}

EstadoSensor Sensor::GetEstado() const {
	// NO IMPLEMENTADA
	return NORMAL;
}

void Sensor::Imprimir(ostream& out) const  {
	// NO IMPLEMENTADA
}

void Sensor::ImprimirCambio() const {
	//Falta hacer
}

void Sensor::Ejecutar(CasaInteligente * casa) {
	//Faltahacer
}

Dispositivo * Sensor::Clon() const {
	//A hacer
	return NULL;
}


#endif


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
	nro = s.nro;
	estado = s.estado;
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
	return nro;
}

void Sensor::SetEstado(EstadoSensor estado) {
	this->estado = estado;
}

EstadoSensor Sensor::GetEstado() const {
	return estado;
}

void Sensor::Imprimir(ostream& out) const  {
	out << nro << ": " << (estado==NORMAL?"NORMAL":"ENALARMA") << endl;
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


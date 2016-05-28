#include "Sensor.h"

#ifndef SENSOR_CPP
#define SENSOR_CPP

ostream &operator<<(ostream& out, const Sensor &s) {
	s.Imprimir(out);
	return out;
}

Sensor::Sensor() {
	// NO IMPLEMENTADA
}

Sensor::Sensor(unsigned int nro) {
	// NO IMPLEMENTADA
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


#endif


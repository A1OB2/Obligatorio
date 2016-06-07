#include "Condicion.h"

#ifndef CONDICION_CPP
#define CONDICION_CPP

ostream &operator<<(ostream& out, const Condicion &c) {
	c.Imprimir();
	return out;
}

Condicion::Condicion() {
	sensores = new ABBImp<Asociacion<int, Referencia<Sensor>>>();
	cumpliendo = false;
	numero = 0;
}

Condicion::Condicion(unsigned int nro, void (*seCumpleCondicion)(int), void (*seDejaDeCumplirCondicion)(int)) {
	this->numero = nro;
	this->pcumple = seCumpleCondicion;
	this->pnocumple = seDejaDeCumplirCondicion;
}

Condicion::Condicion(const Condicion &c) {
	this->numero = c.numero;
	this->pcumple = c.pcumple;
	this->pnocumple = c.pnocumple;
	NodoLista < Asociacion < int, Referencia<Sensor>>> * lSensores = NULL;
	c.sensores->aNodoLista(lSensores);
	setABB(this->sensores, lSensores);
}

Condicion & Condicion::operator=(const Condicion &c) {
	if (this != &c) {
		// NO IMPLEMENTADA
	}
	return *this;
}

Condicion::~Condicion() {
	// NO IMPLEMENTADA
}

bool Condicion::operator==(const Condicion &c) const {
	// NO IMPLEMENTADA
	return false;
}

bool Condicion::operator<(const Condicion &c) const {
	// NO IMPLEMENTADA
	return false;
}

void Condicion::Imprimir() const {
	// NO IMPLEMENTADA
}

void Condicion::AgregarSensor(unsigned int nroSensor, EstadoSensor estado) {
	// NO IMPLEMENTADA
}

void Condicion::Evaluar(CasaInteligente *casa) {
	// NO IMPLEMENTADA
}

template<class T, class U>
void Condicion::setABB(ABB<Asociacion<U, Referencia<T>>>*& a, NodoLista<Asociacion<U, Referencia<T>>>* l) {
	a = new ABBImp<Asociacion<U, Referencia<T>>>();
	while (l != NULL) {
		a->Insertar(l->dato);
		l = l->sig;
	}
}

#endif


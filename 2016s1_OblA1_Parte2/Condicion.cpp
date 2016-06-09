#include "Condicion.h"

#ifndef CONDICION_CPP
#define CONDICION_CPP

ostream &operator<<(ostream& out, const Condicion &c) {
	c.Imprimir();
	return out;
}

Condicion::Condicion() {
	cumpliendo = false;
	numero = 0;
	this->sensores = new ListaImp<Asociacion<int,Referencia<Sensor>>>();
}

Condicion::Condicion(unsigned int nro, void (*seCumpleCondicion)(int), void (*seDejaDeCumplirCondicion)(int)) {
	cumpliendo = false;
	this->numero = nro;
	this->pcumple = seCumpleCondicion;
	this->pnocumple = seDejaDeCumplirCondicion;
	this->sensores = new ListaImp<Asociacion<int, Referencia<Sensor>>>();
}

Condicion::Condicion(const Condicion &c) {
	this->numero = c.numero;
	this->pcumple = c.pcumple;
	this->pnocumple = c.pnocumple;
	this->cumpliendo = c.cumpliendo;
	Iterador<Asociacion<int, Referencia<Sensor>>> it = c.sensores->GetIterador();
	sensores = new ListaImp<Asociacion<int, Referencia<Sensor>>>();
	while (!it.EsFin()) {
		sensores->AgregarPpio(Asociacion<int, Referencia<Sensor>>(it.ElementoInseguro()));
		it.Resto();
	}
	it.Principio();
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
	bool encontro = false;
	Iterador<Asociacion<int, Referencia<Sensor>>> it = sensores->GetIterador();
	while (!it.EsFin()) {
		Asociacion<int, Referencia<Sensor>> e = it.ElementoInseguro();
		if (e.GetDominio() == nroSensor) {
			e.GetRangoInseguro().GetDato().SetEstado(estado);
			encontro = true;
		}
		it.Resto();
	}
	if (!encontro) {
		Sensor s = Sensor(nroSensor);
		s.SetEstado(estado);
		Referencia<Sensor> r = Referencia<Sensor>(s);
		Asociacion<int, Referencia<Sensor>> a = Asociacion<int, Referencia<Sensor>>(nroSensor, r);
		this->sensores->AgregarPpio(a);
	}
}

void Condicion::Evaluar(NodoLista<Asociacion<int, Referencia<Sensor>>> *l) {
	Iterador<Asociacion<int, Referencia<Sensor>>> it = sensores->GetIterador();
	bool cumpleAhora = true;
	while (l != NULL) {
		while (!it.EsFin()) {
			Sensor d = l->dato.GetRangoInseguro().GetDato();
			Asociacion<int, Referencia<Sensor>> e = it.ElementoInseguro();
			if (e.GetDominio() == d.GetNro()) {
				if (d.GetEstado() != e.GetRangoInseguro().GetDato().GetEstado()) {
					cumpleAhora = false;
					break;
				}
			}
			it.Resto();
		}
		if (!cumpleAhora) break;
		it.Principio();
		l = l->sig;
	}
	if (cumpleAhora && !cumpliendo)
		pcumple(this->numero);
	else if (!cumpleAhora && cumpliendo)
		pnocumple(this->numero);
	cumpliendo = cumpleAhora;
}

#endif


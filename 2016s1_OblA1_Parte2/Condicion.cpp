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
	this->numero = nro;
	this->pcumple = seCumpleCondicion;
	this->pnocumple = seDejaDeCumplirCondicion;
	this->sensores = new ListaImp<Asociacion<int, Referencia<Sensor>>>();
}

Condicion::Condicion(const Condicion &c) {
	this->numero = c.numero;
	this->pcumple = c.pcumple;
	this->pnocumple = c.pnocumple;
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
	bool estaba = false;
	Iterador<Asociacion<int, Referencia<Sensor>>> it = sensores->GetIterador();
	while (!it.EsFin()) {
		Asociacion<int, Referencia<Sensor>> e = it.ElementoInseguro();
		if (e.GetDominio() == nroSensor) {
			e.GetRangoInseguro().GetDato().SetEstado(estado);
			estaba = true;
			break;
		}
		it.Resto();
	}
	if (!estaba) {
		Sensor s(nroSensor);
		s.SetEstado(estado);
		Referencia<Sensor> r(s);
		Asociacion<int, Referencia<Sensor>> a(nroSensor,r);
		sensores->AgregarPpio(a);
	}
}

void Condicion::Evaluar(CasaInteligente *casa) {
	// NO IMPLEMENTADA
}

Sensor Condicion::getandexistSensor(Sensor s){
	Sensor ret;
	bool cumpleAhora = true;
	if (s.GetEstado() == ENALARMA) cumpleAhora = false;
	bool estaba = false;
	Iterador<Asociacion<int, Referencia<Sensor>>> it = sensores->GetIterador();
	while (!it.EsFin()) {
		Asociacion<int, Referencia<Sensor>> e = it.ElementoInseguro();
		if (e.GetRangoInseguro().GetDato().GetEstado() == ENALARMA) cumpleAhora = false;
		if (e.GetDominio() == s.GetNro()) {
			ret = e.GetRangoInseguro().GetDato();
			estaba = true;
		}
		if (estaba && cumpleAhora) break;
		it.Resto();
	}
	if (cumpleAhora && !cumpliendo) pcumple(this->numero);
	else if (!cumpleAhora && cumpliendo) pnocumple(this->numero);
	cumpliendo = cumpleAhora;
	if (estaba) return ret;
	else return NULL;
}

#endif


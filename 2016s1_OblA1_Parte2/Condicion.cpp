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
	bool estaba = false;
	EstadoSensor valorCorrecto;
	bool cumpleAhora = true;
	if (estado == ENALARMA) 
		cumpleAhora = false;
	Iterador<Asociacion<int, Referencia<Sensor>>> it = sensores->GetIterador();
	while (!it.EsFin()) {
		Asociacion<int, Referencia<Sensor>> e = it.ElementoInseguro();
		if (e.GetRangoInseguro().GetDato().GetEstado() == ENALARMA) cumpleAhora = false;
		if (e.GetDominio() == nroSensor) {
			e.GetRangoInseguro().GetDato().SetEstado(estado);
			estaba = true;
		}
		if (estaba && cumpleAhora) break;
		it.Resto();
	}
	if (cumpleAhora && !cumpliendo && !sensores->EsVacia()) {
		cumpliendo = cumpleAhora;
		pcumple(this->numero);
	}
	else if (!cumpleAhora && cumpliendo) {
		pnocumple(this->numero);
		cumpliendo = cumpleAhora;
	}
	//bool estabaVacia = sensores->EsVacia();
	if (!estaba) {
		Sensor s(nroSensor);
		s.SetEstado(estado);
		Referencia<Sensor> r(s);
		Asociacion<int, Referencia<Sensor>> a(nroSensor,r);
		sensores->AgregarPpio(a);
	}
	/*if(!estabaVacia)
		trigger();*/
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
	//trigger();
	if (estaba) return ret;
	else return NULL;
}

void Condicion::trigger() {
	bool cumpleAhora = true;
	Iterador<Asociacion<int, Referencia<Sensor>>> it = sensores->GetIterador();
	EstadoSensor valorCorrecto = it.ElementoInseguro().GetRangoInseguro().GetDato().GetEstado();
	while (!it.EsFin()) {
		if (it.ElementoInseguro().GetRangoInseguro().GetDato().GetEstado() != valorCorrecto) {
			cumpleAhora = false;
		}
		it.Resto();
	}

	if (cumpleAhora && !cumpliendo) 
		pcumple(this->numero);
	else if (!cumpleAhora && cumpliendo) 
		pnocumple(this->numero);
	cumpliendo = cumpleAhora;

}

#endif


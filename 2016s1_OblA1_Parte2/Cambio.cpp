#include "Cambio.h"

#ifndef CAMBIO_CPP
#define CAMBIO_CPP

ostream &operator<<(ostream& out, const Cambio &c) {
	c.Imprimir();
	return out;
}

Cambio::Cambio() {
	/*
	lo dejo vacío porque no se pueden instanciar clases abstractas (Dispositivo)
	*/
}

Cambio::Cambio(const Dispositivo &d) {
	string type = typeid(d).name();
	if (type == "class Luz") {
		this->tipo = LUZ;
	} else if(type == "class Artefacto"){
		this->tipo = ARTEFACTO;
	} else {
		this->tipo = ALARMA;
	}
	this->disp = d.Clon();
}

Cambio::Cambio(const Cambio &c) {
	disp = c.disp->Clon();
	tipo = c.tipo;
}

Cambio & Cambio::operator=(const Cambio &c) {
	if (this != &c) {
		// NO IMPLEMENTADA
	}
	return *this;
}

Cambio::~Cambio() {
	// NO IMPLEMENTADA
}

bool Cambio::operator==(const Cambio &c) const {
	// NO IMPLEMENTADA
	return false;
}

bool Cambio::operator<(const Cambio &c) const {
	// NO IMPLEMENTADA
	return false;
}

Dispositivo * Cambio::getDispositivo() {
	return this->disp;
}

TipoDispositivo Cambio::getTipo() {
	return this->tipo;
}

void Cambio::Imprimir() const {
	// NO IMPLEMENTADA
}

void Cambio::Ejecutar(CasaInteligente *casa) {
	auto type = this->tipo;
	if (type == LUZ) {
		Luz *l = dynamic_cast<Luz*>(this->disp);
		casa->CambiarEstadoLuz(l->GetNro(), l->GetIntensidad());
	} else if (type == ARTEFACTO) {
		Artefacto * a = dynamic_cast<Artefacto*>(this->disp);
		casa->CambiarEstadoArtefacto(a->GetNro(), a->GetEstado());
	} else if(type == ALARMA){
		Alarma *a = dynamic_cast<Alarma*>(this->disp);
		casa->CambiarEstadoAlarma(a->GetEstado());
	}
}

#endif


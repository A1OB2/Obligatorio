#include "Escena.h"

#ifndef ESCENA_CPP
#define ESCENA_CPP

ostream &operator<<(ostream& out, const Escena &e) {
	e.Imprimir(out);
	return out;
}

Escena::Escena() {
	this->numero = 0;
	this->nombre = "";
	lucesNumero = new ABBImp<Asociacion<int, Referencia<Luz>>>();
	lucesNombre = new ABBImp<Asociacion<Cadena, Referencia<Luz>>>();
	artefactosNumero = new ABBImp<Asociacion<int, Referencia<Artefacto>>>();
	artefactosNombre = new ABBImp<Asociacion<Cadena, Referencia<Artefacto>>>();
	alarma = new Referencia<Alarma>(Alarma());
	sensores = new ABBImp<Asociacion<int, Referencia<Sensor>>>();
}

Escena::Escena(unsigned int nro, Cadena nombre) {
	this->numero = nro;
	this->nombre = nombre;
	lucesNumero = new ABBImp<Asociacion<int, Referencia<Luz>>>();
	lucesNombre = new ABBImp<Asociacion<Cadena, Referencia<Luz>>>();
	artefactosNumero = new ABBImp<Asociacion<int, Referencia<Artefacto>>>();
	artefactosNombre = new ABBImp<Asociacion<Cadena, Referencia<Artefacto>>>();
	alarma = new Referencia<Alarma>(Alarma());
	sensores = new ABBImp<Asociacion<int, Referencia<Sensor>>>();
}

Escena::Escena(const Escena &e) {
	this->numero = e.numero;
	this->nombre = e.nombre;
	this->alarma = new Referencia<Alarma>(Alarma(e.alarma->GetDato()));
	NodoLista < Asociacion < Cadena, Referencia<Luz>>> * lLuces = NULL;
	e.lucesNombre->aNodoLista(lLuces);
	setABB(this->lucesNombre, lLuces);
	NodoLista < Asociacion < int, Referencia<Luz>>> * lLucesNumero = NULL;
	e.lucesNumero->aNodoLista(lLucesNumero);
	setABB(this->lucesNumero, lLucesNumero);
	NodoLista < Asociacion < Cadena, Referencia<Artefacto>>> * lArtefactos = NULL;
	e.artefactosNombre->aNodoLista(lArtefactos);
	setABB(this->artefactosNombre, lArtefactos);
	NodoLista < Asociacion < int, Referencia<Artefacto>>> * lArtefactosNumero = NULL;
	e.artefactosNumero->aNodoLista(lArtefactosNumero);
	setABB(this->artefactosNumero, lArtefactosNumero);
	NodoLista < Asociacion <int, Referencia<Sensor>>> * lSensores = NULL;
	e.sensores->aNodoLista(lSensores);
	setABB(this->sensores, lSensores);

}

Escena & Escena::operator=(const Escena &e) {
	if (this != &e) {
		// NO IMPLEMENTADA
	}
	return *this;
}

Escena::~Escena() {
	// NO IMPLEMENTADA
}

bool Escena::operator==(const Escena &e) const {
	// NO IMPLEMENTADA
	return false;
}

void Escena::Imprimir(ostream& out) const {
	// NO IMPLEMENTADA
}

unsigned int Escena::GetNro() const {
	// NO IMPLEMENTADA
	return 0;
}

Cadena Escena::GetNombre() const {
	// NO IMPLEMENTADA
	return "";
}

void Escena::ImprimirCambios() const {
	// NO IMPLEMENTADA
}

void Escena::Ejecutar(CasaInteligente *casa) const {
	// NO IMPLEMENTADA
}

void Escena::AgregarCambio(const Cambio &c) {
	// NO IMPLEMENTADA
}

bool Escena::EsRara() const {
	// NO IMPLEMENTADA
	return false;
}
	//aux

	template<class T, class U>
	 void Escena::setABB(ABB<Asociacion<U, Referencia<T>>>*& a, NodoLista<Asociacion<U, Referencia<T>>>* l){
		 a = new ABBImp<Asociacion<U, Referencia<T>>>();
		 while (l != NULL) {
			 a->Insertar(l->dato);
			 l = l->sig;
		 }
	}
#endif


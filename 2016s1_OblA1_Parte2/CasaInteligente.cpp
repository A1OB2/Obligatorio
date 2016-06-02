#include "CasaInteligente.h"

#ifndef CASAINTELIGENTE_CPP
#define CASAINTELIGENTE_CPP

CasaInteligente::CasaInteligente() {
	luces = new ABBImp<Asociacion<int, Referencia<Luz>>>();
	artefactos = new ABBImp<Asociacion<int, Referencia<Artefacto>>>();
	escenas = new ListaImp<Asociacion<int, Referencia<Escena>>>();
	alarma = new Referencia<Alarma>(Alarma());
	sensores = new ListaImp<Asociacion<int, Referencia<Sensor>>>();
}

CasaInteligente::CasaInteligente(unsigned int CANT_SENSORES) {
	luces = new ABBImp<Asociacion<int, Referencia<Luz>>>();
	artefactos = new ABBImp<Asociacion<int, Referencia<Artefacto>>>();
	escenas = new ListaImp<Asociacion<int, Referencia<Escena>>>();
	alarma = new Referencia<Alarma>(Alarma());
	sensores = new ListaImp<Asociacion<int, Referencia<Sensor>>>();
	for (int i = 1; i <= CANT_SENSORES; i++) {
		Sensor s(i);
		Referencia<Sensor> r(s);
		Asociacion<int, Referencia<Sensor>> a(i, r);
		sensores->AgregarPpio(a);
	}
}

CasaInteligente::CasaInteligente(const CasaInteligente &casa) 
{
	// NO IMPLEMENTADA
}

CasaInteligente::~CasaInteligente()
{
	// NO IMPLEMENTADA
}

CasaInteligente &CasaInteligente::operator=(const CasaInteligente &casa) 
{
	if (this != &casa) {
		// NO IMPLEMENTADA
	}
	return *this;
}

bool CasaInteligente::operator==(const CasaInteligente &casa) const {
	// NO IMPLEMENTADA
	return false;
}

bool CasaInteligente::operator<(const CasaInteligente &casa) const {
	// NO IMPLEMENTADA
	return false;
}

TipoRetorno CasaInteligente::AgregarLuz(unsigned int nroLuz, Cadena nombre)
{
	TipoRetorno retorno = OK;
	Luz newLuz = Luz(nroLuz, nombre);
	Asociacion<int, Referencia<Luz>> asoc = Asociacion<int, Referencia<Luz>>(nroLuz, Referencia<Luz>(newLuz));
	ErrorRepetido e = this->puedoInsertar(luces, asoc);
	if (e == E_NOMBRE) {
		cout << "Ya	existe	una	luz	con	el	mismo	nombre.	" << endl;
		retorno = ERROR;
	}
	else if (e == E_NUMERO) {
		cout << "ERROR:	Ya	existe	una	luz	con	el	mismo	numero.	" << endl;
		retorno = ERROR;
	}
	else retorno = OK;

	if(retorno == OK) luces->Insertar(asoc);
	return retorno;
}

TipoRetorno CasaInteligente::AgregarArtefacto(unsigned int nroArt, Cadena nombre)
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::CambiarEstadoLuz(unsigned int nroLuz, unsigned int porcentaje)
{
	if (porcentaje < 100) {
		Luz newLuz = Luz(nroLuz, NULL);
		Asociacion<int, Referencia<Luz>> asoc = Asociacion<int, Referencia<Luz>>(nroLuz, Referencia<Luz>(newLuz));
		if (this->numeroRepetido(luces->getRaiz(), asoc)) {
			luces->Recuperar(asoc).GetRangoInseguro().GetDato().SetIntensidad(porcentaje);
			return OK;
		}
		else {
			cout << "No existe una luz con ese numero";
			return ERROR;
		}
	}
	else {
		cout << "El porcentaje debe ser igual o menor a 100";
		return ERROR;
	}
}

TipoRetorno CasaInteligente::CambiarEstadoArtefacto(unsigned int nroArt, EstadoArtefacto nuevoEstado)
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::CambiarEstadoAlarma(EstadoAlarma nuevoEstado)
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::ImprimirEstadoCasa() const
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::CrearCondicion(unsigned int nroCondicion, void (*seCumpleCondicion)(int), void (*seDejaDeCumplirCondicion)(int))
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::AgregarSensorACondicion(unsigned int nroCondicion, unsigned int nroSensor, EstadoSensor estado)
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::CambiarEstadoSensor(unsigned int nroSensor, EstadoSensor estado)
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::InicioEscena(unsigned int nroEscena, Cadena nombre)
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::FinEscena()
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::EjecutarEscena(unsigned int nroEscena)
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::ImprimirEscenas() const
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::ImprimirEscena(unsigned int nroEscena) const
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::ImprimirEscenasRaras() const
{
	return NO_IMPLEMENTADA;
}

//aux methods
template <class T>
bool CasaInteligente::nombreRepetido(NodoABB<Asociacion<int, Referencia<T>>>* a, Asociacion<int, Referencia<T>> e) {
	if (a == NULL) return false;
	return a->dato.GetRangoInseguro() == e.GetRangoInseguro() || nombreRepetido(a->hIzq, e) || nombreRepetido(a->hDer, e);
}

template <class T>
bool CasaInteligente::numeroRepetido(NodoABB<Asociacion<int, Referencia<T>>>* a, Asociacion<int, Referencia<T>> e) {
	if (a == NULL) return false;
	return a->dato.GetDominio() == e.GetDominio() || numeroRepetido(a->hIzq, e) || numeroRepetido(a->hDer, e);
}


template <class T>
ErrorRepetido CasaInteligente::puedoInsertar(ABB<Asociacion<int, Referencia<T>>>* & a, Asociacion<int, Referencia<T>> x) {
	if (nombreRepetido(a->getRaiz(), x)) {
		return E_NOMBRE;
	}
	else if (numeroRepetido(a->getRaiz(), x)) {
		return E_NUMERO;
	}
	else {
		return BIEN;
	}
}

#endif

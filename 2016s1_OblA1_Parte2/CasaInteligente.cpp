#include "CasaInteligente.h"



#ifndef CASAINTELIGENTE_CPP
#define CASAINTELIGENTE_CPP

CasaInteligente::CasaInteligente(){
	luces = new ABBImp<Asociacion<int, Referencia<Luz>>>();
	artefactos = new ABBImp<Asociacion<int,Referencia<Artefacto>>>();
	escenas = new ABBImp<Asociacion<int, Referencia<Escena>>>();
	alarma = new Referencia<Alarma>(Alarma());
	sensores = new ABBImp<Asociacion<int, Referencia<Sensor>>>();
}

CasaInteligente::CasaInteligente(unsigned int CANT_SENSORES){
	luces = new ABBImp<Asociacion<int,Referencia<Luz>>>();
	artefactos = new ABBImp<Asociacion<int, Referencia<Artefacto>>>();
	escenas = new ABBImp<Asociacion<int, Referencia<Escena>>>();
	alarma = new Referencia<Alarma>(Alarma());
	sensores = new ABBImp<Asociacion<int, Referencia<Sensor>>>();
	for (unsigned int i = 1; i <= CANT_SENSORES; i++) {
		Sensor s(i);
		Referencia<Sensor> r(s);
		Asociacion<int,Referencia<Sensor>> a(i,r);
		sensores->Insertar(a);
	}
}

CasaInteligente::CasaInteligente(const CasaInteligente &casa) {
	assert(false);
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
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::AgregarArtefacto(unsigned int nroArt, Cadena nombre)
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::CambiarEstadoLuz(unsigned int nroLuz, unsigned int porcentaje)
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::CambiarEstadoArtefacto(unsigned int nroArt, EstadoArtefacto nuevoEstado)
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::CambiarEstadoAlarma(EstadoAlarma nuevoEstado)
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::ImprimirEstadoCasa() const{

	cout << this->alarma ->GetDato();//La referencia se interponia con la alarma. No se imprimia
	cout << "-Sensores:" << endl;
	NodoLista <Asociacion<int, Referencia<Sensor>>> * lSensores = NULL;
	sensores->aNodoLista(lSensores);
	while (lSensores != NULL) {
		cout << lSensores->dato;
		lSensores = lSensores->sig;
	}
	cout << "-Luces:" << endl;
	NodoLista<Asociacion<int, Referencia<Luz>>> * lLuces = NULL;
	luces->aNodoLista(lLuces);
	if (lLuces == NULL) cout << "--No hay luces--" << endl;
	while (lLuces != NULL) {
		cout << lLuces->dato;
		lLuces = lLuces->sig;
	}
	cout << "-Artefactos:" << endl;
	NodoLista<Asociacion<int, Referencia<Artefacto>>> * lArtefactos = NULL;
	artefactos->aNodoLista(lArtefactos);
	if (lArtefactos == NULL) cout << "--No hay artefactos--" << endl;
	while (lLuces != NULL) {
		cout << lArtefactos->dato;
		lArtefactos = lArtefactos->sig;
	}

	return OK;
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


//Auxiliares

#endif

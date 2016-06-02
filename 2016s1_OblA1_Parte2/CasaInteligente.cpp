#include "CasaInteligente.h"



#ifndef CASAINTELIGENTE_CPP
#define CASAINTELIGENTE_CPP

CasaInteligente::CasaInteligente(){
	luces = new ABBImp<Asociacion<int, Referencia<Luz>>>();
	artefactos = new ABBImp<Asociacion<int,Referencia<Artefacto>>>();
	escenas = new ListaImp<Asociacion<int, Referencia<Escena>>>();
	alarma = new Referencia<Alarma>(Alarma());
	sensores = new ListaImp<Asociacion<int, Referencia<Sensor>>>();
}

CasaInteligente::CasaInteligente(unsigned int CANT_SENSORES){
	luces = new ABBImp<Asociacion<int,Referencia<Luz>>>();
	artefactos = new ABBImp<Asociacion<int, Referencia<Artefacto>>>();
	escenas = new ListaImp<Asociacion<int, Referencia<Escena>>>();
	alarma = new Referencia<Alarma>(Alarma());
	sensores = new ListaImp<Asociacion<int, Referencia<Sensor>>>();
	for (int i = 1; i <= CANT_SENSORES; i++) {
		Sensor s(i);
		Referencia<Sensor> r(s);
		Asociacion<int,Referencia<Sensor>> a(i,r);
		sensores->AgregarPpio(a);
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
	//EstadoAlarma e = //alarma->GetDato().GetEstado();
	/*auto estado = e;*/
	cout << "-Alarma "<< DESACTIVADA << endl;
	cout << "-Sensores:" << endl;
	//auto h = OFF;
	//cout << typeid(h).name() << endl;
	//if (h == 1) {
	//	cout << "OFF ES 1" << endl;
	//}else if (h == 0) {
	//	cout << "OFF ES 0" << endl;
	//}
	sensores->imprimir();
	//luces->imprimir();
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


//Auxiliares

#endif

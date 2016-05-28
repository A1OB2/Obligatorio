#include "CasaInteligente.h"

#ifndef CASAINTELIGENTE_CPP
#define CASAINTELIGENTE_CPP

CasaInteligente::CasaInteligente()
{
	// NO IMPLEMENTADA
}

CasaInteligente::CasaInteligente(unsigned int CANT_SENSORES)
{
	// NO IMPLEMENTADA
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

#endif

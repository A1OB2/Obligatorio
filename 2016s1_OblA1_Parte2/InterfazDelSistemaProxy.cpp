#include "InterfazDelSistemaProxy.h"

#ifndef INTERFAZ_DEL_SISTEMA_PROXY_CPP
#define INTERFAZ_DEL_SISTEMA_PROXY_CPP
#include "InterfazDelSistemaImp.h"

// Inicialización de los atributos
InterfazDelSistemaProxy::InterfazDelSistemaProxy(InterfazDelSistema* interfaz)
{
	this->interfaz = interfaz;
	this->comentado = false;
}

// Eliminación de los objetos creados con "new"
InterfazDelSistemaProxy::~InterfazDelSistemaProxy()
{	
	delete interfaz;
}

void InterfazDelSistemaProxy::Comentar() {
	this->comentado = true;
}

void InterfazDelSistemaProxy::Descomentar() {
	this->comentado = false;
}

TipoRetorno InterfazDelSistemaProxy::AgregarLuz(unsigned int nroLuz, char* nombre)
{
	if (!comentado)
		return this->interfaz->AgregarLuz(nroLuz, nombre);
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::AgregarArtefacto(unsigned int nroArt, char* nombre)
{
	if (!comentado)
		return this->interfaz->AgregarArtefacto(nroArt, nombre);
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::CambiarEstadoLuz(unsigned int nroLuz, unsigned int porcentaje)
{
	if (!comentado)
		return this->interfaz->CambiarEstadoLuz(nroLuz, porcentaje);
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::CambiarEstadoArtefacto(unsigned int nroArt, EstadoArtefacto nuevoEstado)
{
	if (!comentado)
		return this->interfaz->CambiarEstadoArtefacto(nroArt, nuevoEstado);
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::CambiarEstadoAlarma(EstadoAlarma nuevoEstado)
{
	if (!comentado)
		return this->interfaz->CambiarEstadoAlarma(nuevoEstado);
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::ImprimirEstadoCasa() const
{
	if (!comentado)
		return this->interfaz->ImprimirEstadoCasa();
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::CrearCondicion(unsigned int nroCondicion, void (*seCumpleCondicion)(int), void (*seDejaDeCumplirCondicion)(int))
{
	if (!comentado)
		return this->interfaz->CrearCondicion(nroCondicion, seCumpleCondicion, seDejaDeCumplirCondicion);
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::AgregarSensorACondicion(unsigned int nroCondicion, unsigned int nroSensor, EstadoSensor estado)
{
	if (!comentado)
		return this->interfaz->AgregarSensorACondicion(nroCondicion, nroSensor, estado);
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::CambiarEstadoSensor(unsigned int nroSensor, EstadoSensor estado)
{
	if (!comentado)
		return this->interfaz->CambiarEstadoSensor(nroSensor, estado);
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::InicioEscena(unsigned int nroEscena, char* nombre)
{
	if (!comentado)
		return this->interfaz->InicioEscena(nroEscena, nombre);
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::FinEscena()
{
	if (!comentado)
		return this->interfaz->FinEscena();
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::EjecutarEscena(unsigned int nroEscena)
{
	if (!comentado)
		return this->interfaz->EjecutarEscena(nroEscena);
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::ImprimirEscenas() const
{
	if (!comentado)
		return this->interfaz->ImprimirEscenas();
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::ImprimirEscena(unsigned int nroEscena) const
{
	if (!comentado)
		return this->interfaz->ImprimirEscena(nroEscena);
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::ImprimirEscenasRaras() const
{
	if (!comentado)
		return this->interfaz->ImprimirEscenasRaras();
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::GuardarEstadoActual()
{
	if (!comentado)
		return this->interfaz->GuardarEstadoActual();
	return COMENTADA;
}

TipoRetorno InterfazDelSistemaProxy::VolverAlEstadoAnterior()
{
	if (!comentado)
		return this->interfaz->VolverAlEstadoAnterior();
	return COMENTADA;
}

#endif
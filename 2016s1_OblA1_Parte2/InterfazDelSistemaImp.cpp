#include "InterfazDelSistemaImp.h"

#ifndef INTERFAZ_DEL_SISTEMA_IMP_CPP
#define INTERFAZ_DEL_SISTEMA_IMP_CPP

// Inicialización de los atributos
InterfazDelSistemaImp::InterfazDelSistemaImp(unsigned int CANT_SENSORES, unsigned int MAX_ESTADOS) {
	this->casa = new CasaInteligente(CANT_SENSORES);
	this->listaCasas = new CasaInteligente*[MAX_ESTADOS];
	this->nroEstados = MAX_ESTADOS;
	this->posicion = 0;
}

InterfazDelSistemaImp::~InterfazDelSistemaImp() {
	delete casa;
	//delete this;
}

TipoRetorno InterfazDelSistemaImp::AgregarLuz(unsigned int nroLuz, char* nombre) {
	return this->casa->AgregarLuz(nroLuz, nombre);
}

TipoRetorno InterfazDelSistemaImp::AgregarArtefacto(unsigned int nroArt, char* nombre) {
	return this->casa->AgregarArtefacto(nroArt, nombre);
}

TipoRetorno InterfazDelSistemaImp::CambiarEstadoLuz(unsigned int nroLuz, unsigned int porcentaje) {
	return this->casa->CambiarEstadoLuz(nroLuz, porcentaje);;
}

TipoRetorno InterfazDelSistemaImp::CambiarEstadoArtefacto(unsigned int nroArt, EstadoArtefacto nuevoEstado) {
	return casa->CambiarEstadoArtefacto(nroArt, nuevoEstado);
}

TipoRetorno InterfazDelSistemaImp::CambiarEstadoAlarma(EstadoAlarma nuevoEstado) {
	return casa->CambiarEstadoAlarma(nuevoEstado);
}

TipoRetorno InterfazDelSistemaImp::ImprimirEstadoCasa() const {

	return casa->ImprimirEstadoCasa();
}

TipoRetorno InterfazDelSistemaImp::CrearCondicion(unsigned int nroCondicion, void(*seCumpleCondicion)(int), void(*seDejaDeCumplirCondicion)(int)) {
	return casa->CrearCondicion(nroCondicion, seCumpleCondicion, seDejaDeCumplirCondicion);
}

TipoRetorno InterfazDelSistemaImp::AgregarSensorACondicion(unsigned int nroCondicion, unsigned int nroSensor, EstadoSensor estado) {
	return casa->AgregarSensorACondicion(nroCondicion, nroSensor, estado);
}

TipoRetorno InterfazDelSistemaImp::CambiarEstadoSensor(unsigned int nroSensor, EstadoSensor estado) {
	return casa->CambiarEstadoSensor(nroSensor, estado);
}

TipoRetorno InterfazDelSistemaImp::InicioEscena(unsigned int nroEscena, char* nombre) {
	return casa->InicioEscena(nroEscena, nombre);
}

TipoRetorno InterfazDelSistemaImp::FinEscena() {
	return casa->FinEscena();
}

TipoRetorno InterfazDelSistemaImp::EjecutarEscena(unsigned int nroEscena) {
	return casa->EjecutarEscena(nroEscena);
}

TipoRetorno InterfazDelSistemaImp::ImprimirEscenas() const {
	return casa->ImprimirEscenas();
}

TipoRetorno InterfazDelSistemaImp::ImprimirEscena(unsigned int nroEscena) const {
	return casa->ImprimirEscena(nroEscena);
}

TipoRetorno InterfazDelSistemaImp::ImprimirEscenasRaras() const {
	return casa->ImprimirEscenasRaras();
}

TipoRetorno InterfazDelSistemaImp::GuardarEstadoActual() {
	if (!casa->isEnEscena()) {
		if (posicion != nroEstados) {
			CasaInteligente * c = new CasaInteligente(casa);
			listaCasas[posicion] = c;
			posicion++;
		} else {
			//Nunca lo probaron, no hay ninguna prueba de esto
			delete listaCasas[0];//Borro el primero para recuperar memoria
			for (int i = 1; i < posicion; i++) {
				listaCasas[i - 1] = listaCasas[i];
			}
			CasaInteligente * c = new CasaInteligente(casa);
			listaCasas[posicion - 1] = c;
		}
		return OK;

	}
	cout << "ERROR: Fue iniciada la grabacion de una escena" << endl;
	return ERROR;
}

TipoRetorno InterfazDelSistemaImp::VolverAlEstadoAnterior() {
	if (posicion != 0) {
		if (posicion < nroEstados)
			delete listaCasas[posicion];
		casa = listaCasas[--posicion];
		return OK;
	} else {
		cout << "ERROR: No quedan estados guardados" << endl;
		return ERROR;
	}
}

#endif
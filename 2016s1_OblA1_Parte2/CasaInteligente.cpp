#include "CasaInteligente.h"



#ifndef CASAINTELIGENTE_CPP
#define CASAINTELIGENTE_CPP


CasaInteligente::CasaInteligente() {
	lucesNumero = new ABBImp<Asociacion<int, Referencia<Luz>>>();
	lucesNombre = new ABBImp<Asociacion<Cadena, Referencia<Luz>>>();
	artefactosNumero = new ABBImp<Asociacion<int, Referencia<Artefacto>>>();
	artefactosNombre = new ABBImp<Asociacion<Cadena, Referencia<Artefacto>>>();
	escenasNumero = new ABBImp<Asociacion<int, Referencia<Escena>>>();
	escenasNombre = new ABBImp<Asociacion<Cadena, Referencia<Escena>>>();
	alarma = new Referencia<Alarma>(Alarma());
	sensores = new ABBImp<Asociacion<int, Referencia<Sensor>>>();
	enEscena = false;
	escenaActual = new Referencia<Escena>(Escena());
}

CasaInteligente::CasaInteligente(unsigned int CANT_SENSORES) {
	lucesNumero = new ABBImp<Asociacion<int, Referencia<Luz>>>();
	lucesNombre = new ABBImp<Asociacion<Cadena, Referencia<Luz>>>();
	artefactosNumero = new ABBImp<Asociacion<int, Referencia<Artefacto>>>();
	artefactosNombre = new ABBImp<Asociacion<Cadena, Referencia<Artefacto>>>();
	escenasNumero = new ABBImp<Asociacion<int, Referencia<Escena>>>();
	escenasNombre = new ABBImp<Asociacion<Cadena, Referencia<Escena>>>();
	alarma = new Referencia<Alarma>(Alarma());
	sensores = new ABBImp<Asociacion<int, Referencia<Sensor>>>();
	enEscena = false;
	escenaActual = new Referencia<Escena>(Escena());
	for (unsigned int i = 1; i <= CANT_SENSORES; i++) {
		Sensor s(i);
		Referencia<Sensor> r(s);
		Asociacion<int, Referencia<Sensor>> a(i, r);
		sensores->Insertar(a);
	}
}

CasaInteligente::CasaInteligente(const CasaInteligente &casa) {
	assert(false);
}

CasaInteligente::~CasaInteligente() {
	// NO IMPLEMENTADA->>>HACER
}

CasaInteligente &CasaInteligente::operator=(const CasaInteligente &casa) {
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

bool CasaInteligente::isEnEscena() {
	return this->enEscena;
}

TipoRetorno CasaInteligente::AgregarLuz(unsigned int nroLuz, Cadena nombre) {
	if (!enEscena) {
		Asociacion<int, Referencia<Luz>> asocNro = Asociacion<int, Referencia<Luz>>(nroLuz, Referencia<Luz>(Luz(nroLuz, nombre)));
		Asociacion<Cadena, Referencia<Luz>> asocNombre = Asociacion<Cadena, Referencia<Luz>>(nombre, Referencia<Luz>(Luz(nroLuz, nombre)));
		if (!lucesNumero->Insertar(asocNro)) {
			cout << "ERROR:	Ya	existe	una	luz	con	el	mismo	numero.	" << endl;
			return ERROR;
		}
		else if (!lucesNombre->Insertar(asocNombre)) {
			cout << "ERROR: Ya	existe	una	luz	con	el	mismo	nombre.	" << endl;
			return ERROR;
		}
		else {
			return OK;
		}
	}
	else {
		return ERROR;
	}
}

TipoRetorno CasaInteligente::AgregarArtefacto(unsigned int nroArt, Cadena nombre) {
	if (!enEscena) {
		Asociacion<int, Referencia<Artefacto>> asocNro = Asociacion<int, Referencia<Artefacto>>(nroArt, Referencia<Artefacto>(Artefacto(nroArt, nombre)));
		Asociacion<Cadena, Referencia<Artefacto>> asocNombre = Asociacion<Cadena, Referencia<Artefacto>>(nombre, Referencia<Artefacto>(Artefacto(nroArt, nombre)));
		if (!artefactosNumero->Insertar(asocNro)) {
			cout << "ERROR:	Ya	existe	un artefacto	con	el	mismo	numero.	" << endl;
			return ERROR;
		}
		else if (!artefactosNombre->Insertar(asocNombre)) {
			cout << "ERROR: Ya	existe	un artefacto	con	el	mismo	nombre.	" << endl;
			return ERROR;
		}
		else {
			return OK;
		}
	}
	else {
		return ERROR;
	}
}

TipoRetorno CasaInteligente::CambiarEstadoLuz(unsigned int nroLuz, unsigned int porcentaje) {
		//unos bypass te dan error y otros como este te lo agregan a la escena
		if (porcentaje <= 100) {
			if (!enEscena) {
				Asociacion<int, Referencia<Luz>> e = lucesNumero->traer(Asociacion<int, Referencia<Luz>>(nroLuz, Referencia<Luz>(Luz())));
				if (e == Asociacion<int, Referencia<Luz>>()) {
					cout << "ERROR: No existe una luz con ese numero." << endl;
					return ERROR;
				}
				e.GetRango().GetDato().SetIntensidad(porcentaje);
				return OK;
			}
			else {
				cout << "estoy dentro de una escena" << endl;
			}
		}
		else {
			cout << "ERROR: El porcentaje debe ser igual o menor a 100" << endl;
			return ERROR;
		}
}

TipoRetorno CasaInteligente::CambiarEstadoArtefacto(unsigned int nroArt, EstadoArtefacto nuevoEstado) {
	Asociacion<int, Referencia<Artefacto>> e = artefactosNumero->traer(Asociacion<int, Referencia<Artefacto>>(nroArt, Referencia<Artefacto>(Artefacto())));
	if (e == Asociacion<int, Referencia<Artefacto>>()) {
		cout << "ERROR: No existe un artefacto con ese numero." << endl;
		return ERROR;
	}
	e.GetRango().GetDato().SetEstado(nuevoEstado);
	return OK;
}

TipoRetorno CasaInteligente::CambiarEstadoAlarma(EstadoAlarma nuevoEstado) {
	if (this->alarma->GetDato().GetEstado() == nuevoEstado) {
		cout << "ERROR:	La	alarma	ya	se	encuentra	en	el	nuevo	estado." << endl;
		return ERROR;
	}
	else if (this->puedoCambiarAlarma(sensores->getRaiz()) || nuevoEstado == DESACTIVADA) {
		this->alarma->GetDato().SetEstado(nuevoEstado);
		return OK;
	}
	else {
		cout << "ERROR:	No	se	puede	activar,	hay	uno	o	mas	sensores	ENALARMA." << endl;
		return ERROR;
	}
}

TipoRetorno CasaInteligente::ImprimirEstadoCasa() const {
	if (!enEscena) {
		cout << this->alarma->GetDato();//La referencia se interponia con la alarma. No se imprimia
		cout << "- Sensores:" << endl;
		NodoLista <Asociacion<int, Referencia<Sensor>>> * lSensores = NULL;
		sensores->aNodoLista(lSensores);
		while (lSensores != NULL) {
			cout << lSensores->dato;
			lSensores = lSensores->sig;
		}
		cout << "- Luces:" << endl;
		NodoLista<Asociacion<int, Referencia<Luz>>> * lLuces = NULL;
		lucesNumero->aNodoLista(lLuces);
		if (lLuces == NULL) cout << "--No hay luces--" << endl;
		while (lLuces != NULL) {
			cout << lLuces->dato;
			lLuces = lLuces->sig;
		}
		cout << "- Artefactos:" << endl;
		NodoLista<Asociacion<int, Referencia<Artefacto>>> * lArtefactos = NULL;
		artefactosNumero->aNodoLista(lArtefactos);
		if (lArtefactos == NULL) cout << "--No hay artefactos--" << endl;
		while (lArtefactos != NULL) {
			cout << lArtefactos->dato;
			lArtefactos = lArtefactos->sig;
		}

		return OK;
	}
	else {
		return ERROR;
	}
}

TipoRetorno CasaInteligente::CrearCondicion(unsigned int nroCondicion, void(*seCumpleCondicion)(int), void(*seDejaDeCumplirCondicion)(int)) {
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::AgregarSensorACondicion(unsigned int nroCondicion, unsigned int nroSensor, EstadoSensor estado) {
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::CambiarEstadoSensor(unsigned int nroSensor, EstadoSensor estado) {
	if (!enEscena) {
		Asociacion<int, Referencia<Sensor>> e = sensores->traer(Asociacion<int, Referencia<Sensor>>(nroSensor, Referencia<Sensor>(Sensor())));
		if (e == Asociacion<int, Referencia<Sensor>>()) {
			cout << "ERROR: No existe un sensor con ese numero." << endl;
			return ERROR;
		}
		e.GetRango().GetDato().SetEstado(estado);
		return OK;
	}
	else {
		return ERROR;
	}
}

TipoRetorno CasaInteligente::InicioEscena(unsigned int nroEscena, Cadena nombre) {
	if (!this->enEscena) {
		if (escenasNombre->traer(Asociacion<Cadena, Referencia<Escena>>(nombre, Referencia<Escena>(Escena())))
			!= Asociacion<Cadena, Referencia<Escena>>()) {
			cout << "ERROR:	Ya	existe	una	escena	con	el	mismo	nombre." << endl;
			return ERROR;
		}
		else if (escenasNumero->traer(Asociacion<int, Referencia<Escena>>(nroEscena, Referencia<Escena>(Escena())))
			!= Asociacion<int, Referencia<Escena>>()) {
			cout << "ERROR:	Ya	existe	una	escena	con	el	mismo	numero." << endl;
			return ERROR;
		}else {
			this->enEscena = true;
			this->escenaActual = new Referencia<Escena>(Escena(nroEscena, nombre));
			return OK;
		}
		
	}else {
		cout << "ERROR:	Fue	iniciada	la	grabacion	de	una	escena	" << endl;
		return ERROR;
	}
}

TipoRetorno CasaInteligente::FinEscena() {
	enEscena = false;
	escenasNombre->Insertar(Asociacion<Cadena, Referencia<Escena>>(escenaActual->GetDato().GetNombre(), Referencia<Escena>(escenaActual->GetDato())));
	escenasNumero->Insertar(Asociacion<int, Referencia<Escena>>(escenaActual->GetDato().GetNro(), Referencia<Escena>(escenaActual->GetDato())));
	escenaActual = NULL;
	return OK;
}

TipoRetorno CasaInteligente::EjecutarEscena(unsigned int nroEscena) {
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::ImprimirEscenas() const {
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::ImprimirEscena(unsigned int nroEscena) const {
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::ImprimirEscenasRaras() const {
	return NO_IMPLEMENTADA;
}

//aux

bool CasaInteligente::puedoCambiarAlarma(NodoABB<Asociacion<int, Referencia<Sensor>>>* sens)
{
	if (sens == NULL) return true;
	else if (sens->dato.GetRangoInseguro().GetDato().GetEstado() == NORMAL) 
		return true && puedoCambiarAlarma(sens->hDer) && puedoCambiarAlarma(sens->hIzq);
	else if (sens->dato.GetRangoInseguro().GetDato().GetEstado() == ENALARMA) return false;
}

#endif

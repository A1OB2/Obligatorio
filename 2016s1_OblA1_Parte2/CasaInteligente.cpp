#include "CasaInteligente.h"



#ifndef CASAINTELIGENTE_CPP
#define CASAINTELIGENTE_CPP


CasaInteligente::CasaInteligente(){
	lucesNumero = new ABBImp<Asociacion<int, Referencia<Luz>>>();
	lucesNombre = new ABBImp<Asociacion<Cadena, Referencia<Luz>>>();
	artefactosNumero = new ABBImp<Asociacion<int,Referencia<Artefacto>>>();
	artefactosNombre = new ABBImp<Asociacion<Cadena, Referencia<Artefacto>>>();
	escenas = new ABBImp<Asociacion<int, Referencia<Escena>>>();
	alarma = new Referencia<Alarma>(Alarma());
	sensores = new ABBImp<Asociacion<int, Referencia<Sensor>>>();
}

CasaInteligente::CasaInteligente(unsigned int CANT_SENSORES){
	lucesNumero = new ABBImp<Asociacion<int, Referencia<Luz>>>();
	lucesNombre = new ABBImp<Asociacion<Cadena, Referencia<Luz>>>();
	artefactosNumero = new ABBImp<Asociacion<int, Referencia<Artefacto>>>();
	artefactosNombre = new ABBImp<Asociacion<Cadena, Referencia<Artefacto>>>();
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

CasaInteligente::~CasaInteligente(){
	// NO IMPLEMENTADA->>>HACER
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

TipoRetorno CasaInteligente::AgregarLuz(unsigned int nroLuz, Cadena nombre){
	Asociacion<int, Referencia<Luz>> asocNro = Asociacion<int, Referencia<Luz>>(nroLuz, Referencia<Luz>(Luz(nroLuz, nombre)));
	Asociacion<Cadena, Referencia<Luz>> asocNombre = Asociacion<Cadena, Referencia<Luz>>(nombre, Referencia<Luz>(Luz(nroLuz, nombre)));
	if (!lucesNumero->Insertar(asocNro)) {
		cout << "ERROR:	Ya	existe	una	luz	con	el	mismo	numero.	" << endl;
		return ERROR;
	} else if (!lucesNombre->Insertar(asocNombre)) {
		cout << "ERROR: Ya	existe	una	luz	con	el	mismo	nombre.	" << endl;
		return ERROR;
	}else{
		return OK;
	}
	/*TipoRetorno retorno;
	Asociacion<int, Referencia<Luz>> asoc = Asociacion<int, Referencia<Luz>>(nroLuz, Referencia<Luz>(Luz(nroLuz, nombre)));
	ErrorRepetido e = this->puedoInsertar(luces, asoc);
	switch (e) {
		case E_NOMBRE:
			cout << "ERROR: Ya	existe	una	luz	con	el	mismo	nombre.	" << endl;
			retorno = ERROR;
		break;
		case E_NUMERO:
			cout << "ERROR:	Ya	existe	una	luz	con	el	mismo	numero.	" << endl;
			retorno = ERROR;
		break;
		default:
			luces->Insertar(asoc);
			retorno = OK;
		break;
	}
	return retorno;*/
}

TipoRetorno CasaInteligente::AgregarArtefacto(unsigned int nroArt, Cadena nombre){
	Asociacion<int, Referencia<Artefacto>> asocNro = Asociacion<int, Referencia<Artefacto>>(nroArt, Referencia<Artefacto>(Artefacto(nroArt, nombre)));
	Asociacion<Cadena, Referencia<Artefacto>> asocNombre = Asociacion<Cadena, Referencia<Artefacto>>(nombre, Referencia<Artefacto>(Artefacto(nroArt, nombre)));
	if (!artefactosNumero->Insertar(asocNro)) {
		cout << "ERROR:	Ya	existe	un artefacto	con	el	mismo	numero.	" << endl;
		return ERROR;
	} else if (!artefactosNombre->Insertar(asocNombre)) {
		cout << "ERROR: Ya	existe	un artefacto	con	el	mismo	nombre.	" << endl;
		return ERROR;
	} else {
		return OK;
	}
	/*TipoRetorno retorno;
	Asociacion<int, Referencia<Artefacto>> asoc = Asociacion<int, Referencia<Artefacto>>(nroArt, Referencia<Artefacto>(Artefacto(nroArt, nombre)));
	ErrorRepetido e = this->puedoInsertar(artefactos, asoc);
	switch (e) {
	case E_NOMBRE:
		cout << "ERROR: Ya	existe	una	luz	con	el	mismo	nombre.	" << endl;
		retorno = ERROR;
	break;
	case E_NUMERO:
		cout << "ERROR:	Ya	existe	una	luz	con	el	mismo	numero.	" << endl;
		retorno = ERROR;
	break;
	default:
		artefactos->Insertar(asoc);
		cout << "OK" << endl;
		asoc.GetRango().GetDato().Imprimir();
		retorno = OK;
	break;
	}
	return retorno;*/
}

TipoRetorno CasaInteligente::CambiarEstadoLuz(unsigned int nroLuz, unsigned int porcentaje){
	if (porcentaje <= 100) {
		Asociacion<int, Referencia<Luz>> e = lucesNumero->traer(Asociacion<int, Referencia<Luz>>(nroLuz, Referencia<Luz>(Luz())));
		if (e == Asociacion<int, Referencia<Luz>>()) {
			cout << "ERROR: No existe una luz con ese numero." << endl;
			return ERROR;
		}
		e.GetRango().GetDato().SetIntensidad(porcentaje);
		return OK;
		/*Luz newLuz = Luz(nroLuz, "");
		Asociacion<int, Referencia<Luz>> asoc = Asociacion<int, Referencia<Luz>>(nroLuz, Referencia<Luz>(newLuz));
		if (this->numeroRepetido(lucesNumero->getRaiz(), asoc)) {
			this->getNodoConNum(lucesNumero->getRaiz(), nroLuz)->dato.GetRangoInseguro().GetDato().SetIntensidad(porcentaje);
			return OK;
		}else {
			cout << "ERROR: No existe una luz con ese numero" << endl;
			return ERROR;
		}*/
	}else {
		cout << "ERROR: El porcentaje debe ser igual o menor a 100" << endl;
		return ERROR;
	}
}

TipoRetorno CasaInteligente::CambiarEstadoArtefacto(unsigned int nroArt, EstadoArtefacto nuevoEstado){
	Asociacion<int, Referencia<Artefacto>> e = artefactosNumero->traer(Asociacion<int, Referencia<Artefacto>>(nroArt, Referencia<Artefacto>(Artefacto())));
	if (e == Asociacion<int, Referencia<Artefacto>>()) {
		cout << "ERROR: No existe un artefacto con ese numero." <<endl;
		return ERROR;
	}
	e.GetRango().GetDato().SetEstado(nuevoEstado);
	return OK;
}

TipoRetorno CasaInteligente::CambiarEstadoAlarma(EstadoAlarma nuevoEstado){
	this->alarma->GetDato().SetEstado(nuevoEstado);
	return OK;
}

TipoRetorno CasaInteligente::ImprimirEstadoCasa() const {

	cout << this->alarma ->GetDato();//La referencia se interponia con la alarma. No se imprimia
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

TipoRetorno CasaInteligente::CrearCondicion(unsigned int nroCondicion, void (*seCumpleCondicion)(int), void (*seDejaDeCumplirCondicion)(int))
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::AgregarSensorACondicion(unsigned int nroCondicion, unsigned int nroSensor, EstadoSensor estado)
{
	return NO_IMPLEMENTADA;
}

TipoRetorno CasaInteligente::CambiarEstadoSensor(unsigned int nroSensor, EstadoSensor estado){
	Asociacion<int, Referencia<Sensor>> e = sensores->traer(Asociacion<int, Referencia<Sensor>>(nroSensor, Referencia<Sensor>(Sensor())));
	if (e == Asociacion<int, Referencia<Sensor>>()) {
		cout << "ERROR: No existe un sensor con ese numero." << endl;
		return ERROR;
	}
	e.GetRango().GetDato().SetEstado(estado);
	return OK;
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

template<class T>
NodoABB<Asociacion<int, Referencia<T>>>* CasaInteligente::getNodoConNum(NodoABB<Asociacion<int, Referencia<T>>>* a, int num)
{
	if (a != NULL) {
		if (a->dato.GetDominio() == num) return a;
		else {
			NodoABB<Asociacion<int, Referencia<T>>> * derecha = getNodoConNum(a->hDer, num);
			if (derecha != NULL) return derecha;
			else {
				NodoABB<Asociacion<int, Referencia<T>>> * izquierda = getNodoConNum(a->hIzq, num);
				if (izquierda != NULL) return izquierda;
				else return NULL;
			}
		
		}
	}
	else return a;
}

template <class T>
ErrorRepetido CasaInteligente::puedoInsertar(ABB<Asociacion<int, Referencia<T>>>* a, Asociacion<int, Referencia<T>> x) {
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

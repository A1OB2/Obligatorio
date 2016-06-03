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
	TipoRetorno retorno;
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
	return retorno;
}

TipoRetorno CasaInteligente::AgregarArtefacto(unsigned int nroArt, Cadena nombre)
{
	TipoRetorno retorno;
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
		retorno = OK;
	break;
	}
	return retorno;
}

TipoRetorno CasaInteligente::CambiarEstadoLuz(unsigned int nroLuz, unsigned int porcentaje)
{
	if (porcentaje <= 100) {
		Luz newLuz = Luz(nroLuz, "");
		Asociacion<int, Referencia<Luz>> asoc = Asociacion<int, Referencia<Luz>>(nroLuz, Referencia<Luz>(newLuz));
		if (this->numeroRepetido(luces->getRaiz(), asoc)) {
			this->getNodoConNum(luces->getRaiz(), nroLuz)->dato.GetRangoInseguro().GetDato().SetIntensidad(porcentaje);
			return OK;
		}
		else {
			cout << "ERROR: No existe una luz con ese numero" << endl;
			return ERROR;
		}
	}
	else {
		cout << "ERROR: El porcentaje debe ser igual o menor a 100" << endl;
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

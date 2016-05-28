#include "Asociacion.h"

#ifndef ASOCIACION_CPP
#define ASOCIACION_CPP

template <class Dominio, class Rango>
ostream &operator<<(ostream& out, const Asociacion<Dominio, Rango> &o) {
	out << o.r;
	return out;
}

template <class Dominio, class Rango>
Asociacion<Dominio, Rango>::Asociacion() {
}

template <class Dominio, class Rango>
Asociacion<Dominio, Rango>::Asociacion(const Dominio &d) {
	this->d = d;
}

template <class Dominio, class Rango>
Asociacion<Dominio, Rango>::Asociacion(const Dominio &d, const Rango &r) {
	this->d = d;
	this->r = r;
}

template <class Dominio, class Rango>
Asociacion<Dominio, Rango>::Asociacion(const Asociacion<Dominio, Rango> &o) {
	this->d = o.d;
	this->r = o.r;
}

template <class Dominio, class Rango>
Asociacion<Dominio, Rango>::~Asociacion() {
}

template <class Dominio, class Rango>
Asociacion<Dominio, Rango> &Asociacion<Dominio, Rango>::operator=(const Asociacion<Dominio, Rango> &o) {
	if (this != &o) {
		this->d = o.d;
		this->r = o.r;
	}
	return *this;
}

template <class Dominio, class Rango>
const Dominio &Asociacion<Dominio, Rango>::GetDominio() const {
	return d;
}

//template <class Dominio, class Rango>
//void Asociacion<Dominio, Rango>::SetDominio(const Dominio &d) {
//	this->d = d;
//}

template <class Dominio, class Rango>
const Rango &Asociacion<Dominio, Rango>::GetRango() const {
	return r;
}

template <class Dominio, class Rango>
Rango &Asociacion<Dominio, Rango>::GetRangoInseguro() const {
	return const_cast<Rango &>(r); // le quito el const al retorno
}

template <class Dominio, class Rango>
void Asociacion<Dominio, Rango>::SetRango(const Rango &r) {
	this->r = r;
}

template <class Dominio, class Rango>
bool Asociacion<Dominio, Rango>::operator==(const Asociacion<Dominio, Rango> &o) const {
	return d == o.d;
}

template <class Dominio, class Rango>
bool Asociacion<Dominio, Rango>::operator!=(const Asociacion<Dominio, Rango> &o) const {
	return d != o.d;
}

template <class Dominio, class Rango>
bool Asociacion<Dominio, Rango>::operator<(const Asociacion<Dominio, Rango> &o) const {
	return d < o.d;
}

template <class Dominio, class Rango>
bool Asociacion<Dominio, Rango>::operator>(const Asociacion<Dominio, Rango> &o) const {
	return d > o.d;
}

template <class Dominio, class Rango>
bool Asociacion<Dominio, Rango>::operator<=(const Asociacion<Dominio, Rango> &o) const {
	return d <= o.d;
}

template <class Dominio, class Rango>
bool Asociacion<Dominio, Rango>::operator>=(const Asociacion<Dominio, Rango> &o) const {
	return d >= o.d;
}


#endif
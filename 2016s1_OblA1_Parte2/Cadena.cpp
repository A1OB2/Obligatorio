#include "Cadena.h"

#ifndef CADENA_CPP
#define CADENA_CPP

/****************************************************/
ostream &operator<<(ostream &os, const Cadena &cad){
	if(cad.s)
		os << cad.s;
	return os;
}

istream &operator>>(istream &is, Cadena &cad){
	char aux[200];
	is>>aux;
	cad = aux;
	return is;
}

/****************************************************/
Cadena::Cadena(char *cad, bool ignoreCase) {
	size_t len = strlen(cad)+1;
	s = new char[len];
	strcpy_s(s, len, cad);
	this->ignoreCase = ignoreCase;
}
/****************************************************/
Cadena::Cadena(){
	s = new char[1];
	s[0] = '\0';
	this->ignoreCase = true;
}
/****************************************************/   
Cadena::Cadena(const Cadena &c) {
	s = NULL;
	*this = c;
}
/****************************************************/
Cadena::~Cadena() {
	if(s)
		delete[] s;
}
/****************************************************/
Cadena &Cadena::operator=(const Cadena &c) {
	if(this != &c) {
		delete [] s;

		size_t len = strlen(c.s)+1;
		s = new char[len];
		strcpy_s(s, len, c.s);

		this->ignoreCase = c.ignoreCase;
	}
	return *this;
}
/****************************************************/
Cadena Cadena::operator+(const Cadena &c) const {
	size_t len = strlen(s)+strlen(c.s)+1;
	char *sNew = new char[len];
	strcpy_s(sNew, len, s);
	strcat_s(sNew, len, c.s);
	Cadena cNew(sNew, ignoreCase);
	delete [] sNew;

	return cNew;
}
/****************************************************/
bool Cadena::operator==(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) == 0;
	else
		return strcmp(s, c.s) == 0;
}
/****************************************************/
bool Cadena::operator!=(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) != 0;
	else
		return strcmp(s, c.s) != 0;
}
/****************************************************/
bool Cadena::operator<(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) < 0;
	else
		return strcmp(s, c.s) < 0;
}
/****************************************************/
bool Cadena::operator>(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) > 0;
	else
		return strcmp(s, c.s) > 0;
}
/****************************************************/
bool Cadena::operator<=(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) <= 0;
	else
		return strcmp(s, c.s) <= 0;
}
/****************************************************/
bool Cadena::operator>=(const Cadena &c) const {
	if (ignoreCase) 
		return _stricmp(s, c.s) >= 0;
	else
		return strcmp(s, c.s) >= 0;
}
/****************************************************/
char *Cadena::GetNewCharPtr() const {
	size_t len = strlen(s)+1;
	char *ret = new char[len];
	strcpy_s(ret, len, s);
	return ret;
}
/****************************************************/

unsigned int Cadena::Length() const {
	return strlen(s);
}

bool Cadena::Contains(const Cadena &substr) const {
	if (substr.Length() == 0)
		return true;
	char * s2 = substr.s;
	unsigned int j, j2;

	unsigned int largoS = strlen(s);
	unsigned int largoS2 = strlen(s2);
	if (!ignoreCase) {
		for (unsigned int i = 0; i < largoS; i++) {
			if (i + largoS2 > largoS + 1)
				return false;
			if (s[i] == s2[0]) {
				j = i;
				j2 = 0;
				while (j2 < largoS2 && s[j] == s2[j2]) {
					j++;
					j2++;
				}
				if (j2 == largoS2)
					return true;
			}
		}
	}
	else {
		for (unsigned int i = 0; i < largoS; i++) {
			if (i + largoS2 > largoS + 1)
				return false;
			if (toupper(s[i]) == toupper(s2[0])) {
				j = i;
				j2 = 0;
				while (j2 < largoS2 && toupper(s[j]) == toupper(s2[j2])) {
					j++;
					j2++;
				}
				if (j2 == largoS2)
					return true;
			}
		}
	}
	return false;
}

char Cadena::operator[] (const unsigned int index)
{
	assert (index < Length());
	return s[index];
}


#endif
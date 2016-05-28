#ifndef LUZ_H
#define LUZ_H

class Alarma;
class Artefacto;
class Dispositivo;
class Luz;
class Sensor;
class Cambio;
class Escena;
class CasaInteligente;

#include <iostream>
using namespace std;
#include <assert.h>
#include "Cadena.h"
#include "Dispositivo.h"
#include "CasaInteligente.h"

class Luz;
ostream &operator<<(ostream& out, const Luz &l);

class Luz : public Dispositivo {
public:
	// Constructores
	Luz();
	Luz(unsigned int nro, Cadena nombre);

	// Constructor copia
	Luz(const Luz &l);

	// Destructor
	virtual ~Luz();

	// Operador de asignacion
	Luz &operator=(const Luz &l);

	// Operador de comparacion ==. Compara el nro
	bool operator==(const Luz &l) const;

	unsigned int GetNro() const;
	Cadena GetNombre() const;

	void SetIntensidad(unsigned int intensidad);
	unsigned int GetIntensidad() const; 

	void Imprimir() const;

	void ImprimirCambio() const;
	void Ejecutar(CasaInteligente *casa);
	Dispositivo* Clon() const;

private:

};


#endif
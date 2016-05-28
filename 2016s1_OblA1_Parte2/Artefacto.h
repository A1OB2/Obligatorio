#ifndef ARTEFACTO_H
#define ARTEFACTO_H

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
#include "Constantes.h"
#include "Dispositivo.h"
#include "CasaInteligente.h"

class Artefacto;
ostream &operator<<(ostream& out, const Artefacto &a);

class Artefacto : public Dispositivo {
public:
	// Constructores
	Artefacto();
	Artefacto(unsigned int nro, Cadena nombre);

	// Constructor copia
	Artefacto(const Artefacto &a);

	// Destructor
	virtual ~Artefacto();

	// Operador de asignacion
	Artefacto &operator=(const Artefacto &a);

	// Operador de comparacion ==. Compara el nro
	bool operator==(const Artefacto &a) const;

	unsigned int GetNro() const;
	Cadena GetNombre() const;

	void SetEstado(EstadoArtefacto estado);
	EstadoArtefacto GetEstado() const;

	void Imprimir() const;

	void ImprimirCambio() const;
	void Ejecutar(CasaInteligente *casa);
	Dispositivo* Clon() const;

private:

};

#endif
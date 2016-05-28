#ifndef ESCENA_H
#define ESCENA_H

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
#include "ListaImp.h"
#include "Referencia.h"
#include "Cambio.h"
#include "CasaInteligente.h"

class Escena;
ostream &operator<<(ostream& out, const Escena &e);

class Escena {
public:
	// Constructores
	Escena();
	Escena(unsigned int nro, Cadena nombre);

	// Constructor copia
	Escena(const Escena &e);

	// Destructor
	virtual ~Escena();

	// Operador de asignacion
	Escena &operator=(const Escena &e);

	// Operador de comparacion ==. Compara el nro
	bool operator==(const Escena &e) const;

	void Imprimir(ostream& out) const;

	unsigned int GetNro() const;
	Cadena GetNombre() const;

	void ImprimirCambios() const;
	void Ejecutar(CasaInteligente *casa) const;

	void AgregarCambio(const Cambio &c);

	bool EsRara() const;

private:

};


#endif
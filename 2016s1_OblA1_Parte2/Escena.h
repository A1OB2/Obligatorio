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

	// PRE: -
	// POS: Muestra la escena en pantalla
	void Imprimir(ostream& out) const;

	// PRE: -
	// POS: Retorna el numero de la escena
	unsigned int GetNro() const;

	// PRE: -
	// POS: Retorna el nombre de la escena
	Cadena GetNombre() const;

	// PRE: -
	// POS: Muestra en pantalla los cambios que efectua la escena en orden de ingreso
	void ImprimirCambios() const;

	// PRE: -
	// POS: Ejecuta los cambios de la escena a casa
	void Ejecutar(CasaInteligente *casa) const;

	// PRE: -
	// POS: Agrega un cambio a la escena
	void AgregarCambio(const Cambio &c);

	// PRE: -
	// POS: Retorna true si la escena es considerada 'rara'
	bool EsRara() const;

private:
	int numero;
	Cadena nombre;
	Lista<Referencia<Cambio>> * cambios;
};


#endif
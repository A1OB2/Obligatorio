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


	// PRE: -
	// POS: Retorna el numero del artefacto
	unsigned int GetNro() const;

	// PRE: -
	// POS:Retorna el nombre del artefacto
	Cadena GetNombre() const;

	// PRE: -
	// POS: Setea el estado del artefacto en estado
	void SetEstado(EstadoArtefacto estado);

	// PRE: -
	// POS: Retorna el estado del artefacto
	EstadoArtefacto GetEstado() const;

	// PRE: -
	// POS: Muestra el artefacto en pantalla
	void Imprimir() const;

	// PRE: -
	// POS: Muestra el artefacto en pantalla como un cambio
	void ImprimirCambio() const;

	// PRE: -
	// POS: Cambia el estado del artefacto con el mismo nombre y/o el mismo numero
	//		en la casa al estado de este
	void Ejecutar(CasaInteligente *casa);

	// PRE: -
	// POS: Devuelve un dispositivo de tipo artefacto que no comparte memoria con this
	Dispositivo* Clon() const;

private:
	EstadoArtefacto estado;
	int numero;
	Cadena nombre;
};

#endif
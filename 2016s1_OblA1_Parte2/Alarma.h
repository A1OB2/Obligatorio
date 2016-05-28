#ifndef ALARMA_H
#define ALARMA_H

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

class Alarma;
ostream &operator<<(ostream& out, const Alarma &a);

class Alarma : public Dispositivo {
public:
	// Constructores
	Alarma();

	// Constructor copia
	Alarma(const Alarma &a);

	// Destructor
	virtual ~Alarma();

	// Operador de asignacion
	Alarma &operator=(const Alarma &a);

	// Operador de comparacion ==. Compara el estado
	bool operator==(const Alarma &a) const;

	unsigned int GetNro() const;
	Cadena GetNombre() const;

	void SetEstado(EstadoAlarma estado);
	EstadoAlarma GetEstado() const;

	void Imprimir() const;

	void ImprimirCambio() const;
	void Ejecutar(CasaInteligente *casa);
	Dispositivo* Clon() const;

private:

};

#endif
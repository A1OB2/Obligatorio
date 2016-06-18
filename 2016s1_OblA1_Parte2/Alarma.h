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

	// PRE: -
	// POS: Retorna el numero de la alarma
	unsigned int GetNro() const;

	// PRE: -
	// POS: Retorna el nombre de la alarma
	Cadena GetNombre() const;

	// PRE: -
	// POS: Pone el estado de la alarma en estado
	void SetEstado(EstadoAlarma estado);

	// PRE: -
	// POS: Retorna el estado en el cual esta la alarma
	EstadoAlarma GetEstado() const;

	// PRE: -
	// POS: Muestra la alarma en pantalla
	void Imprimir() const;


	// PRE: -
	// POS: Muestra la alarma como un cambio en pantalla
	void ImprimirCambio() const;

	// PRE: -
	// POS: Ejecuta un cambio de tipo alarma en la casa
	void Ejecutar(CasaInteligente *casa);

	// PRE: -
	// POS: Retorna un dispositivo de tipo alarma que no comparte memoria con this
	Dispositivo* Clon() const;

private:
	unsigned int nro;
	EstadoAlarma estado;
	Cadena nombre;
};

#endif
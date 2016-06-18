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
	bool operator<(const Luz &l) const;
	bool operator>(const Luz &l) const;

	// PRE: -
	// POS: Retorna el numero de la luz
	unsigned int GetNro() const;

	// PRE: -
	// POS: Retorna el nombre de la luz
	Cadena GetNombre() const;

	// PRE: -
	// POS: Cambia la intensidad de la luz por intensidad
	void SetIntensidad(unsigned int intensidad);

	// PRE: -
	// POS: Retorna la intensidad actual de la luz
	unsigned int GetIntensidad() const; 

	// PRE: -
	// POS: Muestra la luz en pantalla
	void Imprimir() const;

	// PRE: -
	// POS: Muestra la luz en pantalla como un cambio
	void ImprimirCambio() const;

	// PRE: -
	// POS: Ejecuta el cambio con esta luz en casa
	void Ejecutar(CasaInteligente *casa);

	// PRE: -
	// POS: Devuelve un puntero a un dispositivo de tipo luz que no comparte memoria
	Dispositivo* Clon() const;

private:
	unsigned int nroLuz;
	Cadena nombre;
	unsigned int intensidad;
};


#endif
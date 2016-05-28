#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

class Alarma;
class Artefacto;
class Dispositivo;
class Luz;
class Sensor;
class Cambio;
class Escena;
class CasaInteligente;

class Dispositivo abstract {
public:
	// Destructor
	virtual ~Dispositivo() {}

	virtual void ImprimirCambio() const abstract;
	virtual void Ejecutar(CasaInteligente *casa) abstract;
	virtual Dispositivo* Clon() const abstract;

	// PRE: -
	// POS: Operador de asignacion
	virtual Dispositivo &operator=(const Dispositivo &d) {
		if (this != &d) {
			assert(false);
		}
		return *this;
	}


protected:

	Dispositivo() { }
	Dispositivo(const Dispositivo &d) { assert(false); }
};


#endif
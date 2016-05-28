#ifndef PRUEBASCORRECCION_H
#define PRUEBASCORRECCION_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "InterfazDelSistemaImp.h"

class PruebasCorreccion : public Prueba  
{

public:
	PruebasCorreccion(ConductorPrueba* conductor);
	virtual ~PruebasCorreccion();
	virtual void correrPruebaConcreta();

protected:
	virtual char* getNombre()const;

private:
};

#endif
#ifndef PRUEBASEJEMPLODEUSO_H
#define PRUEBASEJEMPLODEUSO_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "InterfazDelSistemaImp.h"

class PruebasEjemploDeUso : public Prueba  
{

public:
	PruebasEjemploDeUso(ConductorPrueba* conductor);
	virtual ~PruebasEjemploDeUso();
	virtual void correrPruebaConcreta();

protected:
	virtual char* getNombre()const;

private:

};

#endif
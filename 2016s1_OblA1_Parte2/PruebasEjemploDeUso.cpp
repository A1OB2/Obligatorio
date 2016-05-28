#include "PruebasEjemploDeUso.h"

PruebasEjemploDeUso::PruebasEjemploDeUso(ConductorPrueba* conductor)
:Prueba(conductor)
{
	
}

PruebasEjemploDeUso::~PruebasEjemploDeUso()
{
	
}
char* PruebasEjemploDeUso::getNombre()const
{
	return "PruebasEjemploDeUso";
}


void PruebasEjemploDeUso::correrPruebaConcreta()
{

}


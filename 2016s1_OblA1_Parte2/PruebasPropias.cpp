#include "PruebasPropias.h"

PruebasPropias::PruebasPropias(ConductorPrueba* conductor)
:Prueba(conductor)
{
}

PruebasPropias::~PruebasPropias()
{
}

char* PruebasPropias::getNombre()const
{
	return "PruebasPropias";
}

void cumploCond(int nro) {
	cout << "Se cumple cond: " << nro << endl;
}

void noCumploCond(int nro) {
	cout << "Se deja de cumplir cond: " << nro << endl;
}


void PruebasPropias::correrPruebaConcreta()
{
	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(10, 0);
	interfaz->AgregarLuz(1,"Luz 1");
	interfaz->AgregarLuz(2,"Luz 2");
	interfaz->CambiarEstadoLuz(1, 50);
	interfaz->ImprimirEstadoCasa();

	delete interfaz;
}

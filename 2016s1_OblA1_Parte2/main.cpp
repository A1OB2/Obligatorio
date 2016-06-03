#include "ConductorPruebaObl2.h"

// NO MODIFICAR ACA. HACER LAS PRUEBAS EN EL ARCHIVO PRUEBASPROPIAS.CPP
void main()
{
	ConductorPrueba* prueba = new ConductorPruebaObl2();
	prueba->correrPrueba();
	delete prueba;

	/*ABB<Luz> * a = new ABBImp<Luz>();
	Luz  l = Luz(10, "luz 1");
	Luz l1 = Luz(8, "Luz 3");
	Luz l2 = Luz(11, "Luz 2");
	a->Insertar(l);
	a->Insertar(l2);
	a->Insertar(l1);
	NodoLista<Luz> * li = NULL;
	a->aNodoLista(li);*/


	system("pause");

}


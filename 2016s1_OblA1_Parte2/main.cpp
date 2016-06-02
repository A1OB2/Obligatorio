#include "ConductorPruebaObl2.h"

// NO MODIFICAR ACA. HACER LAS PRUEBAS EN EL ARCHIVO PRUEBASPROPIAS.CPP
void main()
{
	ConductorPrueba* prueba = new ConductorPruebaObl2();
	prueba->correrPrueba();
	delete prueba;

	//Lista<int> * lista = new ListaImp<int>();
	//lista->AgregarPpio(1);
	//lista->AgregarPpio(2);
	//lista->AgregarPpio(3);
	//lista->AgregarPpio(-80);
	//lista->AgregarPpio(5);

	//Iterador<int> it = lista->GetIterador();
	//it.Principio();
	////while (!it.EsFin()) {
	////	int elementoActual = it.ElementoInseguro();
	////	//hago lo que quiera con Elementoactual
	////	it.Resto();
	////}
	//ABB<int> * arbol = new ABBImp<int>();
	//int dato = 1;
	//arbol->Insertar(dato);

	system("pause");

}


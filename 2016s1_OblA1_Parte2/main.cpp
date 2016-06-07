#include "ConductorPruebaObl2.h"
#include "ManejadorArchivos.h"
#include <iostream>
#include <fstream>
using namespace std;

// NO MODIFICAR ACA. HACER LAS PRUEBAS EN EL ARCHIVO PRUEBASPROPIAS.CPP
void main()
{
	ConductorPrueba* prueba = new ConductorPruebaObl2();
	prueba->correrPrueba();
	delete prueba;


	char* rutaLectura = "../SalidaDeLasPruebas/PruebasEjemploDeUso/PruebasEjemploDeUso.txt";
	char* rutaCorreccion = "../PruebasEjemploDeUso.txt";
	char* rutaEscritura = "../SalidaDeLasPruebas/PruebasEjemploDeUso/PruebasEjemploDeUsoResultado.txt";
	ManejadorArchivos* m = new ManejadorArchivos(rutaLectura, rutaCorreccion, rutaEscritura);

	// Comparar
	// - Parametro 1: si se le pasa true muestra el resultado de todas las salidas incluso cuando dan OK
	// - Parametro 2: si se le pasa true solamente muestra las pruebas que no están correctas
	m->Comparar(false, false); 

	//system("pause");
	system("pause");

}


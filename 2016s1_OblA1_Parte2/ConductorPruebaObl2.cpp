#include "ConductorPruebaObl2.h"

ConductorPruebaObl2::ConductorPruebaObl2()
{
	// Empezar aqui a instanciar los archivos de prueba

	pruebasEjemploDeUso = new PruebasEjemploDeUso(this);

	pruebasPropias = new PruebasPropias(this);

	pruebasCorreccion = new PruebasCorreccion(this);

	/* Ej:
	
	miPrueba = new MiPrueba(this);

	Recordar que el constructor de la prueba recibe el Conductor

	*/

	// Terminar aqui
}

ConductorPruebaObl2::~ConductorPruebaObl2()
{
	// Empezar aqui a borrar los archivos de prueba

	delete pruebasEjemploDeUso;

	delete pruebasPropias;

	delete pruebasCorreccion;

	/* Ej:
	
	delete miPrueba;

	*/

	// Terminar aqui
}

void ConductorPruebaObl2::correrPruebaConcreta()
{
	// Empezar aqui a llamar los metodos de prueba

	pruebasEjemploDeUso->correrPrueba();

	pruebasPropias->correrPrueba();

	pruebasCorreccion->correrPrueba();

	/* Ej:
	
	miPrueba->correrPrueba();

	*/

	// Terminar aqui
}

char* ConductorPruebaObl2::getNombre()const
{
	return "SalidaDeLasPruebas";
}

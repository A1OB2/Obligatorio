#include "Prueba.h"


Prueba::Prueba(ConductorPrueba* conductor)
{
	conductorPrueba = conductor;
}

Prueba::~Prueba()
{
}

void Prueba::ver(TipoRetorno retorno, TipoRetorno retornoEsperado, char* comentario)
{
	getEstadisticaPrueba().actualizarEstadisticas(retorno,retornoEsperado);
	
	conductorPrueba->ver(retorno,retornoEsperado,comentario);
}

EstadisticaPrueba& Prueba::getEstadisticaPrueba()
{
	return estadisticaPrueba;
}

ManejadorImpresionPrueba Prueba::getManejadorImpresion()
{
	return ManejadorImpresionPrueba::getInstancia();
}

ManejadorSalidaPrueba Prueba::getManejadorSalida()
{
	return ManejadorSalidaPrueba::getInstancia();
}

void Prueba::correrPrueba()
{
	char* nombrePrueba = getNombre();
	unsigned int largo = strlen(nombrePrueba) + 5;
	char* nombreArchivo = new char[largo];
	strcpy_s(nombreArchivo, largo, nombrePrueba);
	strcat_s(nombreArchivo, largo, ".txt");

	ManejadorSalidaPrueba msp = getManejadorSalida();
	msp.crearDirectorio(nombrePrueba);
	msp.setSalidaArchivo(nombreArchivo);

	delete [] nombreArchivo;

	correrPruebaConcreta();
	
	ManejadorImpresionPrueba mip = getManejadorImpresion();
	mip.imprimirTotalResultados(getEstadisticaPrueba());

	msp.cambiarDirectorio("..");
}
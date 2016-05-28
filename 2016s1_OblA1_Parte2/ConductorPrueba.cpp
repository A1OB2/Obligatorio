#include "ConductorPrueba.h"

ConductorPrueba::ConductorPrueba()
{
}

ConductorPrueba::~ConductorPrueba()
{
}

void ConductorPrueba::correrPrueba()
{
	ManejadorSalidaPrueba msp = getManejadorSalida();
	msp.crearDirectorio(getNombre());

	correrPruebaConcreta();
	
	msp.setSalidaArchivo("Resultados Totales.txt");
	ManejadorImpresionPrueba mip = getManejadorImpresion();
	mip.imprimirTotalResultados(getEstadisticaGlobal());
	msp.setSalidaPantalla();
}

void ConductorPrueba::ver(TipoRetorno retorno, TipoRetorno retornoEsperado, char* comentario)
{
	getManejadorImpresion().imprimirResultado(retorno,retornoEsperado,comentario);

	getEstadisticaGlobal().actualizarEstadisticas(retorno,retornoEsperado);
}

EstadisticaPrueba& ConductorPrueba::getEstadisticaGlobal()
{
	return estadisticaGlobal;
}

ManejadorImpresionPrueba ConductorPrueba::getManejadorImpresion()
{
	return ManejadorImpresionPrueba::getInstancia();
}

ManejadorSalidaPrueba ConductorPrueba::getManejadorSalida()
{
	return ManejadorSalidaPrueba::getInstancia();
}
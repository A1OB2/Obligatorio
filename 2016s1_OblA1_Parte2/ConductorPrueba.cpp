#include "ConductorPrueba.h"

ConductorPrueba::ConductorPrueba()
{
	nroPrueba = 0;
}

ConductorPrueba::~ConductorPrueba()
{
}

void ConductorPrueba::correrPrueba(bool paraParseo)
{
	ManejadorSalidaPrueba msp = getManejadorSalida();
	msp.crearDirectorio(getNombre());

	correrPruebaConcreta();
	
	//msp.setSalidaArchivo("Resultados Totales.txt");
	//ManejadorImpresionPrueba mip = getManejadorImpresion();
	//mip.imprimirTotalResultados(getEstadisticaGlobal(), paraParseo);
	msp.setSalidaPantalla();
}

void ConductorPrueba::ver(TipoRetorno retorno, TipoRetorno retornoEsperado, char* comentario)
{
	getManejadorImpresion().imprimirResultado(retorno,retornoEsperado,comentario, false);

	getEstadisticaGlobal().actualizarEstadisticas(retorno,retornoEsperado);
}

void ConductorPrueba::ver2(TipoRetorno retorno, TipoRetorno retornoEsperado, char* comentario)
{
	this->finPrueba();
	getManejadorImpresion().imprimirResultado(retorno, retornoEsperado, comentario, true);
	this->inicioPrueba();

	getEstadisticaGlobal().actualizarEstadisticas(retorno,retornoEsperado);
}

void ConductorPrueba::inicioPrueba() {
	//cout << "#" << this->nroPrueba << "{--" << endl;
}

void ConductorPrueba::finPrueba() {
	cout << endl << "-!-" << this->nroPrueba << "::";
	this->nroPrueba++;
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
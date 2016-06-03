#pragma once
#include "Asociacion.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <assert.h>
#include <iomanip>
using namespace std;

class ManejadorArchivos {
public:
	ManejadorArchivos(char* rutaL, char* rutaC, char* rutaS);
	~ManejadorArchivos() {}

	//Compara los dos archivos y escribe el resultado en rutaEscritura
	void Comparar(bool mostrarSalidas, bool soloMostrarErrores);

private:
	ManejadorArchivos() {};

	string rutaL, rutaC, rutaS;

	int pCorrectas;
	int pIncorrectas;
	int pNI;
	int pComentadas;

	bool Prefijo(string linea, string pref) const;
	Asociacion<string, string> ObtenerPalabraReservada(string linea) const;
	void ImprimirInicio(ofstream &salida, string) const;
	void ImprimirFin(ofstream &salida, string) const;
	void ImprimirComparacion(ofstream &salida, int nroPrueba, string obtenido, string esperado, string retO, string retE, string com, bool mostrarSalidas, bool soloMostrarErrores);
	void ImprimirEsperadoVsRecibido(ofstream &salida, string &esp, string &obt) const;
	void ImprimirEstadisticas(ofstream &salida) const;
	bool MismaImpresion(string &esp, string &obt) const;
	bool esIniSeccion(string & linea) const;
	bool esFinSeccion(string & linea) const;
	bool esFinDePrueba(string & linea) const;
	int obtenerNumeroDePrueba(string & linea) const;
	bool AvanzarHastaProximaPrueba(ifstream &archivo, int &nroPrueba, string &textoRes, string &contenidoFin, bool imprimirIniFin, ofstream &salida) const;
};
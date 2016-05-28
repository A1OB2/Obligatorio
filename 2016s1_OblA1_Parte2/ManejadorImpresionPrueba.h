#ifndef MANEJADORIMPRESIONPRUEBA_H
#define MANEJADORIMPRESIONPRUEBA_H

#include <iostream>
using namespace std;
#include "TipoRetorno.h"
#include "EstadisticaPrueba.h"

class ManejadorImpresionPrueba  
{
public:
	ManejadorImpresionPrueba();
	virtual ~ManejadorImpresionPrueba();

	void imprimirResultado(TipoRetorno retorno, TipoRetorno retornoEsperado, char* comentario)const;
	void imprimirTotalResultados(const EstadisticaPrueba& estadistica)const;

	static ManejadorImpresionPrueba getInstancia();
protected:
	void imprimirComentario(char* comentario)const;
	void imprimirRetorno(TipoRetorno retorno, TipoRetorno retornoEsperado)const;

private:
	static ManejadorImpresionPrueba* instanciaManejador;
	char* getStringRetorno(TipoRetorno retorno)const;

};

#endif
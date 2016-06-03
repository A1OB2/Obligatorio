#ifndef MANEJADORIMPRESIONPRUEBA_H
#define MANEJADORIMPRESIONPRUEBA_H

#include <iostream>
using namespace std;
#include "TipoRetorno.h"
#include "EstadisticaPrueba.h"

class ManejadorImpresionPrueba  
{
public:
	ManejadorImpresionPrueba(bool paraParseo = true);
	virtual ~ManejadorImpresionPrueba();

	void imprimirResultado(TipoRetorno retorno, TipoRetorno retornoEsperado, char* comentario, bool paraParseo)const;
	void imprimirTotalResultados(const EstadisticaPrueba& estadistica, bool paraParseo)const;

	void iniciarSeccion(char* seccion);
	void cerrarSeccion(char* seccion);

	static ManejadorImpresionPrueba getInstancia();
protected:
	void imprimirComentario(char* comentario)const;
	void imprimirRetorno(TipoRetorno retorno, TipoRetorno retornoEsperado)const;

private:
	static ManejadorImpresionPrueba* instanciaManejador;
	char* getStringRetorno(TipoRetorno retorno)const;
};

#endif
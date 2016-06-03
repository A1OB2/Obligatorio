#include "ManejadorImpresionPrueba.h"

ManejadorImpresionPrueba* ManejadorImpresionPrueba::instanciaManejador = NULL;

ManejadorImpresionPrueba::ManejadorImpresionPrueba(bool paraParseo)
{
}

ManejadorImpresionPrueba::~ManejadorImpresionPrueba()
{

}

ManejadorImpresionPrueba ManejadorImpresionPrueba::getInstancia()
{
	//if ( instanciaManejador == NULL )
	//	instanciaManejador = new ManejadorImpresionPrueba();

	return ManejadorImpresionPrueba();
}

void ManejadorImpresionPrueba::imprimirResultado(TipoRetorno retorno, TipoRetorno retornoEsperado, char* comentario, bool paraParseo) const
{
	if (paraParseo)
	{
		cout << "" << getStringRetorno(retornoEsperado);
		cout << "-" << getStringRetorno(retorno);
		cout << "-" << comentario;
		cout << endl;
	}else{
		cout << endl;
		cout << "----------------------------- Testeo --------------------------------" << endl;

		imprimirComentario(comentario);

		imprimirRetorno(retorno, retornoEsperado);

		cout << "---------------------------------------------------------------------" << endl << endl;
	}
}

void ManejadorImpresionPrueba::imprimirComentario(char* comentario)const
{
	if ( comentario != "" )
	{
		cout << "\n  Comentario: " << comentario << endl;
		cout << endl;
	}
}

void ManejadorImpresionPrueba::iniciarSeccion(char* seccion) 
{
	cout << "-!-Ini::" << seccion << endl;

	/*
	cout << "\n\n";
	cout << "*********************************************************************\n\n";
	cout << "********************** INICIO "<< seccion << "***********************\n";
	cout << "*********************************************************************\n\n";
	*/
}

void ManejadorImpresionPrueba::cerrarSeccion(char* seccion)
{
	cout << "-!-Fin::" << seccion << endl;

	/*
	cout << "\n\n";
	cout << "*********************************************************************\n\n";
	cout << "********************** FIN " << seccion << "***********************\n";
	cout << "*********************************************************************\n\n";
	*/
}

void ManejadorImpresionPrueba::imprimirRetorno(TipoRetorno retorno, TipoRetorno retornoEsperado)const
{
	cout << "  Retorno de la app.: "<< retorno <<" ->\t"<< getStringRetorno(retorno) << endl;
	
	if ( retorno == retornoEsperado )
	{
		cout << "\t\t.........OK........."<<endl;
	}
	else
	{
		cout << "  Se esperaba.......: "<< retornoEsperado <<" ->\t" << getStringRetorno(retornoEsperado) << endl;
	}
}

char* ManejadorImpresionPrueba::getStringRetorno(TipoRetorno retorno)const
{
	switch( retorno )
	{
		case OK: 
			return "OK";
		case ERROR: 
			return "ERROR";
		case NO_IMPLEMENTADA:
			return "NO_IMPLEMENTADA";
		case COMENTADA:
			return "COMENTADA";
		default:
			return "BASURA";
	}
}

void ManejadorImpresionPrueba::imprimirTotalResultados(const EstadisticaPrueba& estadistica, bool paraParseo)const
{
	if (!paraParseo)
	{
		cout << endl;
		cout << "  +------------------------------+" << endl;
		cout << "    RESULTADO DE LOS RETORNOS (NO CHEQUEA SI LAS SALIDAS SON CORRECTAS O NO!)" << endl;
		cout << "    PARA CHEQUEAR SI ES CORRECTO HAY REVISAR TODOS LOS LISTADOS Y VER SI IMPRIME LO QUE DEBERIA" << endl;
		cout << endl;
		//cout << "    Pruebas que retornan TipoRetorno correcto:   " << estadistica.getCantidadCorrectas() << endl;
		cout << "    Pruebas que retornan TipoRetorno incorrecto: " << estadistica.getCantidadIncorrectas() << endl;
		cout << "    Pruebas que retornan NO_IMPLEMENTADA:        " << estadistica.getCantidadNoImplementadas() << endl;
		cout << "    Pruebas que retornan COMENTADA:              " << estadistica.getCantidadComentadas() << endl;
		cout << "  +------------------------------+" << endl;
		cout << endl;
	}
}

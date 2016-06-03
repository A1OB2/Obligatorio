#ifndef PRUEBASEJEMPLODEUSO_H
#define PRUEBASEJEMPLODEUSO_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "InterfazDelSistemaImp.h"
#include "InterfazDelSistemaProxy.h"

class PruebasEjemploDeUso : public Prueba  
{

public:
	PruebasEjemploDeUso(ConductorPrueba* conductor);
	virtual ~PruebasEjemploDeUso();
	virtual void correrPruebaConcreta();

protected:
	virtual char* getNombre()const;

private:
	ManejadorImpresionPrueba mImpresion;
	InterfazDelSistemaProxy* interfaz;

	void PruebasOK();	
	void PruebasError();
	void PruebasOkOpcional();
	void PruebasErrorOpcional();

	void pruebaOKTipo1();
	void pruebaOKCondiciones();
	void pruebaOkEscenas();
	void pruebaOkImprimirEscenasRaras();

	
	void pruebaERROR1();
	void pruebaERROR2();
	void pruebaERROR3();
	void pruebaERROR4();
	void pruebaERROR5();
	void pruebaERROR6();
	void pruebaERROR7();
	void pruebaERROR8();
	void pruebaERROR9();
	void pruebaERROR10();
	void pruebaERROR11();
	void pruebaERROR12();
	void pruebaERROR13();
	void pruebaERROR14();


	void cargarDatos();
	void inicializarCondiciones();
	void inicializarEscenas();
};

#endif
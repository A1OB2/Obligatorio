#include "PruebasPropias.h"

PruebasPropias::PruebasPropias(ConductorPrueba* conductor)
:Prueba(conductor)
{
}

PruebasPropias::~PruebasPropias()
{
}

char* PruebasPropias::getNombre()const
{
	return "PruebasPropias";
}

void cumploCond(int nro) {
	cout << "Se cumple cond: " << nro << endl;
}

void noCumploCond(int nro) {
	cout << "Se deja de cumplir cond: " << nro << endl;
}


void PruebasPropias::correrPruebaConcreta(){
	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(10,0);
	interfaz->AgregarLuz(1,"Luz 1");
	interfaz->AgregarLuz(2,"Luz 2");
	interfaz->AgregarLuz(1, "Luz 2");
	interfaz->CambiarEstadoLuz(1, 101);
	interfaz->AgregarLuz(3, "Luz 3");
	interfaz->AgregarArtefacto(1, "Artefacto 1");
	interfaz->AgregarArtefacto(2, "Artefacto 2");
	interfaz->ImprimirEstadoCasa();
	interfaz->CambiarEstadoArtefacto(1, ON);
	interfaz->CambiarEstadoArtefacto(5, ON);
	interfaz->CambiarEstadoAlarma(ACTIVADA);
	interfaz->CambiarEstadoSensor(2, ENALARMA);
	interfaz->CambiarEstadoSensor(12, ENALARMA);
	interfaz->ImprimirEstadoCasa();

	delete interfaz;
}

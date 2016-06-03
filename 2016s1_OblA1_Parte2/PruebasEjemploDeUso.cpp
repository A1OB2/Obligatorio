
/* IMPORTANTE:
	PARA COMENTAR PRUEBAS UTILIZAR EL COMANDO interfaz->Comentar(); ANTES DE LA(S) PRUEBA(S) A COMENTAR
	PARA DESCOMENTAR PRUEBAS UTILIZAR EL COMANDO interfaz->Descomentar(); DESPUES DE LA(S) PRUEBA(S) 
*/

#include "PruebasEjemploDeUso.h"

PruebasEjemploDeUso::PruebasEjemploDeUso(ConductorPrueba* conductor)
:Prueba(conductor)
{
	
}

PruebasEjemploDeUso::~PruebasEjemploDeUso()
{
	
}
char* PruebasEjemploDeUso::getNombre()const
{
	return "PruebasEjemploDeUso";
}

void cumploCondicionEjemploDeUso(int nro) {
	cout << "Se cumple cond: " << nro << endl;
}

void noCumploCondicionEjemploDeUso(int nro) {
	cout << "Se deja de cumplir cond: " << nro << endl;
}

void PruebasEjemploDeUso::correrPruebaConcreta()
{
	PruebasOK();
	PruebasError();
	PruebasOkOpcional();
	PruebasErrorOpcional();
}

void PruebasEjemploDeUso::PruebasOK()
{	
	pruebaOKTipo1();
	pruebaOKCondiciones();
	pruebaOkEscenas();
	pruebaOkImprimirEscenasRaras();
};

void PruebasEjemploDeUso::PruebasError()
{	
	pruebaERROR1();
	pruebaERROR2();
	pruebaERROR3();
	pruebaERROR4();
	pruebaERROR5();
	pruebaERROR6();
	pruebaERROR7();
	pruebaERROR8();
	pruebaERROR9();
	pruebaERROR10();
	pruebaERROR11();
	pruebaERROR12();
	pruebaERROR13();
	pruebaERROR14();

};

void PruebasEjemploDeUso::pruebaOKTipo1()
{
	this->mImpresion.iniciarSeccion("PRUEBAS TIPO 1");

	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(10, 0));	

	ver2(interfaz->ImprimirEstadoCasa(),OK, "Imprime el estado de la casa");

	ver2(interfaz->AgregarLuz(1,"Luz 1"),OK, "Se agrega la luz 1");
	ver2(interfaz->AgregarLuz(2,"Luz 2"),OK, "Se agrega la luz 2");
	ver2(interfaz->AgregarLuz(3,"Luz 3"),OK, "Se agrega la luz 3");

	ver2(interfaz->AgregarArtefacto(1,"Art1"),OK, "Se agrega el artefacto Art1");
	ver2(interfaz->AgregarArtefacto(2,"Art2"),OK, "Se agrega el artefacto Art2");
	ver2(interfaz->AgregarArtefacto(3,"Art3"),OK, "Se agrega el artefacto Art3");

	ver2(interfaz->CambiarEstadoLuz(1,50),OK, "Se cambia la intensidad de la luz 1 a 50%");
	ver2(interfaz->CambiarEstadoLuz(2,80),OK, "Se cambia la intensidad de la luz 2 a 80%");

	ver2(interfaz->CambiarEstadoArtefacto(1,ON),OK, "Se cambia el estado del artefacto 1 a ON");
	ver2(interfaz->CambiarEstadoArtefacto(1,OFF),OK, "Se cambia el estado del artefacto 1 a OFF");

	ver2(interfaz->CambiarEstadoAlarma(ACTIVADA),OK, "Se cambia el estado de la alarma a ACTIVADA");
	ver2(interfaz->CambiarEstadoAlarma(DESACTIVADA),OK, "Se cambia el estado de la alarma a DESACTIVADA");
	
	ver2(interfaz->ImprimirEstadoCasa(),OK, "Imprime el estado de la casa");

	ver2(interfaz->CambiarEstadoSensor(5,ENALARMA),OK, "Cambia al sensor 5 a ENALARMA");
	ver2(interfaz->CambiarEstadoSensor(3,ENALARMA),OK, "Cambia al sensor 3 a ENALARMA");

	ver2(interfaz->ImprimirEstadoCasa(),OK, "Imprime el estado de la casa");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS TIPO 1");
};


void PruebasEjemploDeUso::pruebaOKCondiciones()
{
	this->mImpresion.iniciarSeccion("PRUEBAS Condiciones");

	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(10, 0));
	cargarDatos();

	ver2(interfaz->CrearCondicion(1,cumploCondicionEjemploDeUso,noCumploCondicionEjemploDeUso),OK, "Crea la condición 1");
	ver2(interfaz->CrearCondicion(2,cumploCondicionEjemploDeUso,noCumploCondicionEjemploDeUso),OK, "Crea la condición 2");
		
	ver2(interfaz->AgregarSensorACondicion(1,1,NORMAL),OK, "Agrega a la condición 1 el sensor 1 con el valor NORMAL.");

	ver2(interfaz->AgregarSensorACondicion(2,3,ENALARMA),OK, "Agrega a la condición 2 el sensor 3 con el valor ENALARMA.");

	ver2(interfaz->ImprimirEstadoCasa(),OK, "Imprime el estado de la casa");

	ver2(interfaz->CambiarEstadoSensor(1,ENALARMA),OK, "Cambia al sensor 1 a ENALARMA, como la condicion no se cumplio aun no pasa nada");
	ver2(interfaz->CambiarEstadoSensor(1,NORMAL),OK, "Cambia al sensor 1 a NORMAL, dejando de cumplir la condición 1");
	ver2(interfaz->CambiarEstadoSensor(1,ENALARMA),OK, "Cambia al sensor 1 a ENALARMA, pasando a cumplir la condición 1");
	ver2(interfaz->CambiarEstadoSensor(3,ENALARMA),OK, "Cambia al sensor 3 a ENALARMA pasando a cumplir la condición 2");
	ver2(interfaz->CambiarEstadoSensor(3,NORMAL),OK, "Cambia al sensor 3 a NORMAL, dejando de cumplir la condición 2");

	ver2(interfaz->ImprimirEstadoCasa(),OK, "Imprime el estado de la casa");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS Condiciones");
};


void PruebasEjemploDeUso::pruebaOkEscenas()
{
	this->mImpresion.iniciarSeccion("PRUEBAS Escenas");

	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(5, 0));
	cargarDatos();

	ver2(interfaz->ImprimirEstadoCasa(),OK, "Imprime el estado de la casa");

	ver2(interfaz->InicioEscena(1, "Escena 1"), OK, "Crea la escena 1");
	ver2(interfaz->CambiarEstadoLuz(1,50), OK, "Guarda el cambio de estado en la escena");
	ver2(interfaz->CambiarEstadoLuz(2,70), OK, "Guarda el cambio de estado en la escena");
	ver2(interfaz->FinEscena(), OK, "Finaliza la escena 1");

	ver2(interfaz->InicioEscena(2, "Escena 2"), OK, "Crea la escena 2");
	ver2(interfaz->CambiarEstadoArtefacto(1,ON), OK, "Guarda el cambio de estado en la escena");
	ver2(interfaz->FinEscena(), OK, "Finaliza la escena 2");

	ver2(interfaz->ImprimirEstadoCasa(),OK, "Imprime el estado de la casa");

	ver2(interfaz->EjecutarEscena(1),OK, "Ejecuta la escena 1");
	ver2(interfaz->EjecutarEscena(2),OK, "Ejecuta la escena 1");

	ver2(interfaz->ImprimirEstadoCasa(),OK, "Imprime el estado de la casa");
	ver2(interfaz->ImprimirEscenas(),OK, "Imprime las escenas 1 y 2");
	ver2(interfaz->ImprimirEscena(1),OK, "Imprime la escena 1");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS Escenas");
};


void PruebasEjemploDeUso::pruebaOkImprimirEscenasRaras()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ImprimirEscenasRaras");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(5, 0));
	cargarDatos();
	inicializarCondiciones();
	inicializarEscenas();
	interfaz->InicioEscena(3,"Escena 3");
	interfaz->CambiarEstadoArtefacto(1,ON);
	interfaz->CambiarEstadoArtefacto(1,OFF);
	interfaz->CambiarEstadoArtefacto(1,ON);
	interfaz->FinEscena();
	ver2(interfaz->ImprimirEscenasRaras(),OK, "Imprime las escenas raras (en este caso, la escena 3)");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ImprimirEscenasRaras");
};


void PruebasEjemploDeUso::pruebaERROR1()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR AgregarLuz");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(10, 0));
	
	interfaz->AgregarLuz(1,"Luz 1");
	interfaz->AgregarLuz(3,"Luz 3");
	ver2(interfaz->AgregarLuz(1,"Luz 2"), ERROR, "Ya existe una luz con ese número");
	ver2(interfaz->AgregarLuz(3,"Luz 2"), ERROR, "Ya existe una luz con ese número");
	ver2(interfaz->AgregarLuz(2,"Luz 3"), ERROR, "Ya existe una luz con ese nombre");
	ver2(interfaz->AgregarLuz(4,"Luz 3"), ERROR, "Ya existe una luz con ese nombre");
	interfaz->InicioEscena(1,"Escena1");
	ver2(interfaz->AgregarLuz(2,"Luz 2"), ERROR, "Fue iniciada la grabación de una escena");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR AgregarLuz");
};

void PruebasEjemploDeUso::pruebaERROR2()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR AgregarArtefacto");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(10, 0));
		
	
	interfaz->AgregarArtefacto(1,"Art1");
	interfaz->AgregarArtefacto(2,"Art2");
	ver2(interfaz->AgregarArtefacto(1,"Art3"), ERROR, "Ya existe un artefacto con ese número");
	ver2(interfaz->AgregarArtefacto(2,"Art4"), ERROR, "Ya existe un artefacto con ese número");
	ver2(interfaz->AgregarArtefacto(3,"Art1"), ERROR, "Ya existe una artefacto con ese nombre");
	ver2(interfaz->AgregarArtefacto(4,"Art2"), ERROR, "Ya existe una artefacto con ese nombre");
	interfaz->InicioEscena(1,"Escena1");
	ver2(interfaz->AgregarArtefacto(3,"Art3"), ERROR, "Fue iniciada la grabación de una escena");
	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR AgregarArtefacto");
};

void PruebasEjemploDeUso::pruebaERROR3()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR CambiarEstadoLuz");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(10, 0));

	interfaz->AgregarLuz(1,"Luz 1");
	interfaz->AgregarLuz(2,"Luz 2");
	ver2(interfaz->CambiarEstadoLuz(3,80), ERROR, "No existe una luz con ese número");
	ver2(interfaz->CambiarEstadoLuz(2,120), ERROR, "El porcentaje ingresado supera al 100%");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR CambiarEstadoLuz");
};

void PruebasEjemploDeUso::pruebaERROR4()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR CambiarEstadoArtefacto");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(10, 0));
		
	interfaz->AgregarArtefacto(1,"Art1");
	ver2(interfaz->CambiarEstadoArtefacto(2,ON), ERROR, "No existe un artefacto con ese número");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR CambiarEstadoArtefacto");
};

void PruebasEjemploDeUso::pruebaERROR5()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR ImprimirEstadoCasa");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(10, 0));
	cargarDatos();	
	interfaz->InicioEscena(1,"Escena 1");

	ver2(interfaz->ImprimirEstadoCasa(), ERROR, "Fue iniciada la grabación de una escena");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR ImprimirEstadoCasa");
};

void PruebasEjemploDeUso::pruebaERROR6()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR CrearCondicion");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(10, 0));
	cargarDatos();
	interfaz->CrearCondicion(1,cumploCondicionEjemploDeUso,noCumploCondicionEjemploDeUso);
	ver2(interfaz->CrearCondicion(1,cumploCondicionEjemploDeUso,noCumploCondicionEjemploDeUso), ERROR, "Ya hay una condición con ese número");
	
	interfaz->InicioEscena(1,"Escena 1");
	ver2(interfaz->CrearCondicion(2,cumploCondicionEjemploDeUso,noCumploCondicionEjemploDeUso), ERROR, "Fue iniciada la grabación de una escena");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR CrearCondicion");
};

void PruebasEjemploDeUso::pruebaERROR7()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR AgregarSensorACondicion");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(10, 0));
	cargarDatos();
	interfaz->CrearCondicion(1,cumploCondicionEjemploDeUso,noCumploCondicionEjemploDeUso);
	ver2(interfaz->AgregarSensorACondicion(2,1,NORMAL), ERROR, "No existe la condición 2");
	ver2(interfaz->AgregarSensorACondicion(1,11,NORMAL), ERROR, "El nroSensor debe ser menor o igual a CANT_SENSORES");
	interfaz->InicioEscena(1,"Escena 1");
	ver2(interfaz->AgregarSensorACondicion(1,1,NORMAL), ERROR, "Fue iniciada la grabación de una escena");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR AgregarSensorACondicion");
};

void PruebasEjemploDeUso::pruebaERROR8()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR CambiarEstadoSensor");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(5, 0));
	cargarDatos();
	inicializarCondiciones();
	ver2(interfaz->CambiarEstadoSensor(6,ENALARMA),ERROR, "El nroSensor debe ser menor o igual a CANT_SENSORES");
	interfaz->InicioEscena(1,"Escena 1");
	ver2(interfaz->CambiarEstadoSensor(5,ENALARMA),ERROR, "Fue iniciada la grabación de una escena");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR CambiarEstadoSensor");
};

void PruebasEjemploDeUso::pruebaERROR9()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR InicioEscena");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(5, 0));
	cargarDatos();
	interfaz->InicioEscena(1, "Escena 1");
	interfaz->FinEscena();
	ver2(interfaz->InicioEscena(1, "Escena 2"),ERROR, "Ya hay una escena con el número 1");
	ver2(interfaz->InicioEscena(2, "Escena 1"),ERROR, "Ya hay una escena con el nombre \"Escena 1\"");
	interfaz->InicioEscena(2, "Escena 2");
	ver2(interfaz->InicioEscena(3, "Escena 3"),ERROR, "Ya se está grabando una escena en este momento");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR InicioEscena");
};

void PruebasEjemploDeUso::pruebaERROR10()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR FinEscena");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(5, 0));
	cargarDatos();
	ver2(interfaz->FinEscena(),ERROR, "No está grabando una escena en este momento");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR FinEscena");
};

void PruebasEjemploDeUso::pruebaERROR11()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR EjecutarEscena");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(5, 0));
	cargarDatos();
	inicializarEscenas();
	interfaz->InicioEscena(3,"Escena 3");
	ver2(interfaz->EjecutarEscena(1),ERROR,"No se puede ejecutar la escena 1 ya que hay una escena grabándose en este momento");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR EjecutarEscena");
};

void PruebasEjemploDeUso::pruebaERROR12()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR ImprimirEscenas");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(5, 0));
	cargarDatos();
	inicializarEscenas();
	interfaz->InicioEscena(3,"Escena 3");
	ver2(interfaz->ImprimirEscenas(),ERROR,"No se puede imprimir las escenas ya que hay una escena grabándose en este momento");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR ImprimirEscenas");
};

void PruebasEjemploDeUso::pruebaERROR13()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR ImprimirEscena");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(5, 0));
	cargarDatos();
	inicializarEscenas();
	interfaz->InicioEscena(3,"Escena 3");
	ver2(interfaz->ImprimirEscena(1),ERROR,"No se puede imprimir la escena 1 ya que hay una escena grabándose en este momento");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR ImprimirEscena");
};

void PruebasEjemploDeUso::pruebaERROR14()
{
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR ImprimirEscenasRaras");
	
	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(5, 0));
	cargarDatos();
	inicializarEscenas();
	interfaz->InicioEscena(3,"Escena 3");
	ver2(interfaz->ImprimirEscenasRaras(),ERROR,"No se puede imprimir las escenas raras ya que hay una escena grabándose en este momento");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR ImprimirEscenasRaras");
};


void PruebasEjemploDeUso::PruebasOkOpcional(){
	this->mImpresion.iniciarSeccion("PRUEBAS OK OPCIONAL");

	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(5, 2));
	
	//Cargar datos
	interfaz->AgregarLuz(1, "Luz 1");
	interfaz->AgregarLuz(2, "Luz 2");
	interfaz->AgregarArtefacto(1, "Art 1");
	interfaz->AgregarArtefacto(2, "Art 2");

	//cout << "Imprimo el estado actual de la casa, corroborando que todas las luces están al 0%\n\n";
	interfaz->ImprimirEstadoCasa();
	ver2(interfaz->GuardarEstadoActual(), OK, "Se guarda el estado actual de la casa.");

	//cout<<"Aumento la luz 1 al 100% y vuelvo a imprimir el estado de la casa\n\n";
	interfaz->CambiarEstadoLuz(1,100);
	ver2(interfaz->ImprimirEstadoCasa(),OK, "Imprime el estado de la casa");

	ver2(interfaz->GuardarEstadoActual(), OK, "Se guarda el estado actual de la casa.");

	interfaz->CambiarEstadoLuz(1,50);
	ver2(interfaz->ImprimirEstadoCasa(),OK, "Imprime el estado de la casa");

	ver2(interfaz->VolverAlEstadoAnterior(),OK,"Vuelve atrás la modificación de la intensidad de la luz 1");
	ver2(interfaz->ImprimirEstadoCasa(),OK, "Imprime el estado de la casa");

	ver2(interfaz->VolverAlEstadoAnterior(),OK,"Vuelve atrás la modificación de la intensidad de la luz 1");

	//cout<<"Vuelvo a imprimir el estado actual de la casa, corroborando que todas las luces están al 0%\n\n";
	ver2(interfaz->ImprimirEstadoCasa(),OK, "Imprime el estado de la casa");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS OK OPCIONAL");
}

void PruebasEjemploDeUso::PruebasErrorOpcional(){
	this->mImpresion.iniciarSeccion("PRUEBAS ERROR OPCIONAL");

	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(5, 0));
	ver2(interfaz->VolverAlEstadoAnterior(),ERROR,"No quedan estados guardados.");
	
	delete interfaz;

	interfaz = new InterfazDelSistemaProxy(new InterfazDelSistemaImp(5, 2));
	interfaz->GuardarEstadoActual();
	interfaz->GuardarEstadoActual();
	interfaz->VolverAlEstadoAnterior();
	interfaz->VolverAlEstadoAnterior();
	ver2(interfaz->VolverAlEstadoAnterior(),ERROR,"No quedan mas estados guardados.");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ERROR OPCIONAL");
}

void PruebasEjemploDeUso::cargarDatos()
{
	interfaz->AgregarLuz(1,"Luz 1");
	interfaz->AgregarLuz(2,"Luz 2");
	interfaz->AgregarArtefacto(1,"Art1");
	interfaz->AgregarArtefacto(2,"Art2");
};

void PruebasEjemploDeUso::inicializarCondiciones()
{
	interfaz->CrearCondicion(1,cumploCondicionEjemploDeUso,noCumploCondicionEjemploDeUso);
	interfaz->CrearCondicion(2,cumploCondicionEjemploDeUso,noCumploCondicionEjemploDeUso);
	interfaz->CrearCondicion(3,cumploCondicionEjemploDeUso,noCumploCondicionEjemploDeUso);
	interfaz->AgregarSensorACondicion(1,2,NORMAL);
	interfaz->AgregarSensorACondicion(1,3,ENALARMA);
	interfaz->AgregarSensorACondicion(1,5,ENALARMA);
	interfaz->AgregarSensorACondicion(2,1,NORMAL);
	interfaz->AgregarSensorACondicion(2,3,NORMAL);
	interfaz->AgregarSensorACondicion(3,1,NORMAL);
	interfaz->AgregarSensorACondicion(3,5,NORMAL);

};

void PruebasEjemploDeUso::inicializarEscenas(){
	interfaz->InicioEscena(1, "Escena 1");
	interfaz->CambiarEstadoLuz(1,50);
	interfaz->CambiarEstadoLuz(2,70);
	interfaz->FinEscena();
	interfaz->InicioEscena(2, "Escena 2");
	interfaz->CambiarEstadoArtefacto(1,ON);
	interfaz->FinEscena();
}


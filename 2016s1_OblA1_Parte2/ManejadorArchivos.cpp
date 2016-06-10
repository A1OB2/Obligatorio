#include "ManejadorArchivos.h"

vector<string> split(string str, char delimiter) {
	vector<string> vec;
	stringstream ss(str);
	string tok;

	while (getline(ss, tok, delimiter)) {
		vec.push_back(tok);
	}

	return vec;
}

bool replace(string& source, string const& find, string const& replace) {
	bool found = false;
	for (string::size_type i = 0; (i = source.find(find, i)) != string::npos;) {
		found = true;
		source.replace(i, find.length(), replace);
		i += replace.length();
	}
	return found;
}

bool isInteger(const std::string & s) {
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}



ManejadorArchivos::ManejadorArchivos(char* rutaL, char* rutaC, char* rutaS) {
	this->rutaL = rutaL;
	this->rutaC = rutaC;
	this->rutaS = rutaS;

	pCorrectas = 0;
	pNI = 0;
	pComentadas = 0;
	pIncorrectas = 0;
}

bool ManejadorArchivos::esIniSeccion(string & linea) const {
	if (!Prefijo(linea, "-!-"))
		return false;

	Asociacion<string, string> palabras = ObtenerPalabraReservada(linea);
	string tipoComando = palabras.GetDominio(); //Puede ser Ini, Fin o un número de prueba.

	if (tipoComando == "Ini")
		return true;

	return false;
}

bool ManejadorArchivos::esFinSeccion(string & linea) const {
	if (!Prefijo(linea, "-!-"))
		return false;

	Asociacion<string, string> palabras = ObtenerPalabraReservada(linea);
	string tipoComando = palabras.GetDominio(); //Puede ser Ini, Fin o un número de prueba.

	if (tipoComando == "Fin")
		return true;

	return false;
}

bool ManejadorArchivos::esFinDePrueba(string & linea) const {
	if (!Prefijo(linea, "-!-"))
		return false;

	Asociacion<string, string> palabras = ObtenerPalabraReservada(linea);
	string tipoComando = palabras.GetDominio(); //Puede ser Ini, Fin o un número de prueba.

	if (tipoComando == "Ini" || tipoComando == "Fin")
		return false;

	return true;
}

int ManejadorArchivos::obtenerNumeroDePrueba(string & linea) const {
	Asociacion<string, string> palabras = ObtenerPalabraReservada(linea);
	string tipoComando = palabras.GetDominio(); //Puede ser Ini, Fin o un número de prueba.
	return atoi(palabras.GetDominio().c_str());
}

bool ManejadorArchivos::AvanzarHastaProximaPrueba(ifstream &archivo, int &nroPrueba, string &textoRes, string &contenidoFin, bool imprimirIniFin, ofstream &salida) const {
	string linea;
	textoRes = "";

	while (getline(archivo, linea)) {
		if (esIniSeccion(linea) || esFinSeccion(linea)) {
			if (imprimirIniFin) {
				Asociacion<string, string> palabras = ObtenerPalabraReservada(linea);
				string contenido = palabras.GetRango();
				if (esIniSeccion(linea))
					ImprimirInicio(salida, contenido);
				else
					ImprimirFin(salida, contenido);
			}
		} else if (!esFinDePrueba(linea)) {
			textoRes += linea + "\n";
		} else // llego al fin de la prueba
		{
			nroPrueba = obtenerNumeroDePrueba(linea);
			Asociacion<string, string> palabras = ObtenerPalabraReservada(linea);
			contenidoFin = palabras.GetRango();
			return true;
		}
	}

	nroPrueba = 0;
	textoRes = "";
	contenidoFin = "COMENTADA-COMENTADA-Se llega al fin del archivo de forma inesperada";

	return false;
}

void ManejadorArchivos::Comparar(bool mostrarSalidas, bool soloMostrarErrores) {
	string lineaL, lineaC, textoL, textoC, contenidoFinL, comentarioL;
	int pruebaActualC, pruebaActualL = 0;

	ifstream archivoLectura;
	ifstream archivoCorreccion;
	ofstream salida;

	archivoLectura.open(rutaL, ios::in);
	archivoCorreccion.open(rutaC, ios::in);
	salida.open(rutaS);

	archivoCorreccion.clear();
	archivoCorreccion.seekg(0, ios::beg); //Reinicia la lectura del archivo.
	archivoLectura.clear();
	archivoLectura.seekg(0, ios::beg); //Reinicia la lectura del archivo.

	AvanzarHastaProximaPrueba(archivoLectura, pruebaActualL, textoL, contenidoFinL, false, salida);
	vector<string> resultados = split(contenidoFinL, '-');
	comentarioL = resultados[2];

	while (getline(archivoCorreccion, lineaC)) {
		if (esIniSeccion(lineaC) || esFinSeccion(lineaC)) {
			Asociacion<string, string> palabras = this->ObtenerPalabraReservada(lineaC);
			if (esIniSeccion(lineaC))
				ImprimirInicio(salida, palabras.GetRango());
			else
				ImprimirFin(salida, palabras.GetRango());
		} else {
			if (!esFinDePrueba(lineaC)) {
				textoC += lineaC + "\n";
			} else // llego al fin de la prueba
			{
				pruebaActualC = obtenerNumeroDePrueba(lineaC);
				Asociacion<string, string> palabras = ObtenerPalabraReservada(lineaC);
				resultados = split(palabras.GetRango(), '-');
				string retornoEsperado = resultados[0];
				string retornoObtenido = resultados[1];
				string comentarioC = resultados[2];

				if (retornoEsperado != retornoObtenido) {
					assert(false); // la solucion o las pruebas son incorrectas
				}

				if (pruebaActualC < pruebaActualL || comentarioL != comentarioC) // la prueba no existe en el generado por alumno. no me muevo en el archivo de lectura
				{
					salida << "!!!!!! HAY QUE COMENTAR PRUEBAS UTILIZANDO EL COMANDO interfaz->Comentar(); y interfaz->Descomentar(); para DESCOMENTAR" << endl;
				} else if (pruebaActualC > pruebaActualL) // la prueba no existe en el archivo de correccion
				{
					salida << "!!!!!! HAY QUE COMENTAR PRUEBAS UTILIZANDO EL COMANDO interfaz->Comentar(); y interfaz->Descomentar(); para DESCOMENTAR" << endl;
				} else // comparo las pruebas y avanzo en el archivo de lectura
				{
					resultados = split(contenidoFinL, '-');
					comentarioL = resultados[2];
					retornoObtenido = resultados[1];
					ImprimirComparacion(salida, pruebaActualC, textoL, textoC, retornoEsperado, retornoObtenido, comentarioL, mostrarSalidas, soloMostrarErrores);

					AvanzarHastaProximaPrueba(archivoLectura, pruebaActualL, textoL, contenidoFinL, false, salida);
					resultados = split(contenidoFinL, '-');
					comentarioL = resultados[2];
				}
				textoC = "";
			}
		}
	}

	ImprimirEstadisticas(salida);

	archivoLectura.close();
	archivoCorreccion.close();
	salida.close();
}


bool ManejadorArchivos::Prefijo(string linea, string pref) const {
	return linea.compare(0, pref.length(), pref) == 0;
}

//PRE: Prefijo(linea, "-!-")
Asociacion<string, string> ManejadorArchivos::ObtenerPalabraReservada(string linea) const {
	int pos = linea.find("::");
	string izq = linea.substr(3, pos - 3); //Desde 2 para sacar el "-!-"
	string der = linea.substr(pos + 2);

	return Asociacion<string, string>(izq, der);
}

void ManejadorArchivos::ImprimirInicio(ofstream &salida, string titulo) const {
	salida << "********* INICIO " << titulo << "*******" << endl;
}

void ManejadorArchivos::ImprimirFin(ofstream &salida, string titulo) const {
	salida << "********* FIN " << titulo << "*******" << endl << endl;
}

// Compara la salida esperada contra la obtenida.
void ManejadorArchivos::ImprimirComparacion(ofstream &salida, int nroPrueba, string obt, string esp, string retE, string retO, string com, bool mostrarSalidas, bool soloMostrarErrores) {
	if (MismaImpresion(esp, obt) && retO == retE) {
		this->pCorrectas++;
		if (soloMostrarErrores) return;
		salida << "-----------------------------------" << endl;
		salida << "Prueba " << nroPrueba << ": " << com;
		salida << " -> OK" << endl;
		if (mostrarSalidas && obt != "")
			salida << endl << "Se imprimió: " << endl << obt << endl;
	} else if (retO == "COMENTADA") {
		salida << "-----------------------------------" << endl;
		salida << "Prueba " << nroPrueba << ": " << com;
		salida << endl << " -> ERROR PRUEBA COMENTADA" << endl;
		this->pComentadas++;
	} else if (retO == "NO_IMPLEMENTADA") {
		salida << "-----------------------------------" << endl;
		salida << "Prueba " << nroPrueba << ": " << com;
		salida << endl << " -> ERROR PRUEBA NO_IMPLEMENTADA" << endl;
		this->pNI++;
	} else {
		salida << "-----------------------------------" << endl;
		salida << "Prueba " << nroPrueba << ": " << com;
		if (retO != retE) {
			salida << endl << " -> ERROR retorno incorrecto" << endl;
			salida << "\t Se esperaba: " << retE << endl;
			salida << "\t Se obtuvo: " << retO << endl;
		}
		if (!MismaImpresion(esp, obt)) {
			salida << endl << " -> ERROR impresión incorrecta" << endl;
			ImprimirEsperadoVsRecibido(salida, esp, obt);
		}
		this->pIncorrectas++;
	}
}


// Imprimo el resultado esperado vs el recibido
// Mostrar la linea (y posicion) en la que hay diferencia
// Marcar la linea con la diferencia
void ManejadorArchivos::ImprimirEsperadoVsRecibido(ofstream &salida, string &esp, string &obt) const {
	vector<string> vecEsp = split(esp, '\n');
	vector<string> vecObt = split(obt, '\n');
	unsigned int iEsp = 1, iObt = 1;

	salida << "Se esperaba imprimir (el numero de linea fue agregado, no se debe imprimir): " << endl;
	for (vector<string>::const_iterator i = vecEsp.begin(); i != vecEsp.end(); ++i) {
		salida << setw(2) << iEsp++ << setw(0) << ": " << *i << endl;
		salida << setw(0);
	}

	salida << endl;
	salida << "Se imprimio (el numero de linea fue agregado, no se debe imprimir): " << endl;
	salida << "(Los numeros de linea aparecen con : si coinciden y ! si no coinciden)" << endl;
	for (vector<string>::const_iterator i = vecObt.begin(); i != vecObt.end(); ++i) {
		salida << setw(2) << iObt++ << setw(0);
		if (iObt <= iEsp && vecObt[iObt - 2] == vecEsp[iObt - 2]) {
			salida << ": ";
		} else {
			salida << "! ";
		}
		salida << *i << endl;
		salida << setw(0);
	}

}

void ManejadorArchivos::ImprimirEstadisticas(ofstream &salida) const {
	salida << endl << endl << "----------------" << endl;
	salida << "PRUEBAS CORRECTAS: " << this->pCorrectas << endl;
	salida << "PRUEBAS INCORRECTAS: " << this->pIncorrectas << endl;
	salida << "PRUEBAS NO IMPLEMENTADAS: " << this->pNI << endl;
	salida << "PRUEBAS COMENTADAS: " << this->pComentadas << endl;
}

bool removeFromStart(string& source, string const& find) {
	std::string::size_type i = source.find(find);
	if (i != std::string::npos && i == 0) {
		source.erase(i, find.length());
		return true;
	}
	return false;
}

bool removeFromEnd(string& source, string const& find) {
	std::string::size_type i = source.find_last_of(find);
	if (i != std::string::npos && i == source.length() - 1) {
		source.erase(i, 1);
		return true;
	}
	return false;
}


bool trimFromEnd(std::string &s) {
	// trim trailing spaces
	std::string::size_type i = s.find_last_of(" \t");
	if (i != std::string::npos && i == s.length() - 1) {
		s = s.erase(i, 1);
		return true;
	}
	return false;
}

bool ManejadorArchivos::MismaImpresion(string &esp, string &obt) const {
	if (esp == "" && obt == "")
		return true;

	while (true) {
		bool b = false;
		b = b || removeFromStart(esp, "\n");	// quito lineas en blanco al inicio	
		b = b || removeFromEnd(esp, "\n");		// quito lineas en blanco al final
		b = b || trimFromEnd(esp);				// quito espacios al final	
		b = b || replace(esp, " \n", "\n");		// quito espacios al final de cada linea
		b = b || replace(esp, "\t\n", "\n");	// quito tabuladores al final de cada linea
		b = b || replace(esp, ".\n", "\n");		// quito punto al final de cada linea (ERROR)
		b = b || removeFromEnd(esp, ".");		// quito punto al final
		b = b || removeFromEnd(esp, "\t");		// quito tabulador al final
		b = b || replace(esp, "  ", " ");		// reemplazo dos o más espacios por espacio
		b = b || replace(esp, "\t", " ");		// reemplazo tabuladores por espacios
		if (!b) break;
	}
	while (true) {
		bool b = false;
		b = b || removeFromStart(obt, "\n");	// quito lineas en blanco al inicio	
		b = b || removeFromEnd(obt, "\n");		// quito lineas en blanco al final
		b = b || trimFromEnd(obt);				// quito espacios al final	
		b = b || replace(obt, " \n", "\n");		// quito espacios al final de cada linea
		b = b || replace(obt, "\t\n", "\n");	// quito tabuladores al final de cada linea
		b = b || replace(obt, ".\n", "\n");		// quito punto al final de cada linea (ERROR)
		b = b || removeFromEnd(obt, ".");		// quito punto al final
		b = b || removeFromEnd(obt, "\t");		// quito tabulador al final
		b = b || replace(obt, "  ", " ");		// reemplazo dos o más espacios por espacio
		b = b || replace(obt, "\t", " ");		// reemplazo tabuladores por espacios
		if (!b) break;
	}


	//replace(esp, "\n\n", "\n");
	return esp == obt;
}
#include "GestorArchivos.h" 
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


GestorArchivos::GestorArchivos(char* nombre){
	archivoFuente.open(nombre);
}

GestorArchivos::~ GestorArchivos(){
	archivoFuente.close();
}

string GestorArchivos::getNextLine(){
	string linea; 
	getline(archivoFuente, linea);
    return linea;
}


int GestorArchivos::escribirLinea(string texto){
	archivoFuente << texto << endl;		
}


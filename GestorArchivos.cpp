#include "GestorArchivos.h" 
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


GestorArchivos::GestorArchivos(char* nombre, int tipo){
	if(tipo == 0){
	archivoFuente.open(nombre);
	}else{
	archivoFuente.open(nombre, fstream::out);			
	}
}

GestorArchivos::~ GestorArchivos(){
	archivoFuente.close();
}

string GestorArchivos::getNextLine(){
	string linea; 
	getline(archivoFuente, linea);
    return linea;
}


void GestorArchivos::escribirLinea(string texto){
	archivoFuente << texto << endl;	
	
}

bool GestorArchivos::fin(){
	return archivoFuente.eof();
}


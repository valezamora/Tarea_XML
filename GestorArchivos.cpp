#include "GestorArchivos.h" 
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


GestorArchivos::GestorArchivos(char* nombre){
	archivoFuente.open(nombre);
}

GestorArchivos::~ GestorArchivos(){

}

string GestorArchivos::getNextLine(){
	char temp = ' ';
	string linea; 
	archivoFuente >> temp;
	while(temp != '\n'){
		linea += temp;
		archivoFuente >> temp;
	}
    cout << linea << endl;
    return linea;
}
/*
int GestorArchivos:escribirLinea(string texto){
			
}
*/
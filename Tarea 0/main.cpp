/**
 * Código del main
 * Tarea 0 - CI1310
 * Valeria Zamora - B37743
 * */

#include <iostream>
#include <string>
#include <istream>
#include "GestorArchivos.h"
#include "GestorEtiquetas.h"
using namespace std;
 
int main(int argc, char* argv[] ){
    char* nomArchivo = (char *)"prueba.xml";
    bool s = false;
    if(argc>1){		//hay argumentos
	if(argc == 2){
		nomArchivo = argv[1];
	}else{
		if(string(argv[1]) == "-t"){
			nomArchivo = argv[2];
			s = true;
		}
			
	}
    }

    GestorArchivos archivo(nomArchivo, 0);
    GestorEtiquetas etiquetas;

    string sigue;
    string resultado;
    while(!archivo.fin()){
        sigue = etiquetas.extraerContenido(archivo.getNextLine());
	if(s){
		resultado += sigue;		

	}
    }    
    etiquetas.imprimirEtiquetas();

    if(s){
	char nombreSalida[] = "archivoSinEtiquetas.txt";
    	GestorArchivos salida(nombreSalida, 1);
	salida.escribirLinea(resultado);
    }

    return 0;
}

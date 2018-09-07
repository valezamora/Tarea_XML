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
    char* nomArchivo = (char *)"archivo.txt";
    if(argc>1){
		nomArchivo = argv[1];
	}
	
    GestorArchivos archivo(nomArchivo, 0);
    char nombreSalida[] = "archivoSinEtiquetas.txt";
    GestorArchivos salida(nombreSalida, 1);
    GestorEtiquetas etiquetas;

    string sigue;
    while(!archivo.fin()){
        sigue = etiquetas.extraerContenido(archivo.getNextLine());
	
	salida.escribirLinea(sigue);
    }
    
    etiquetas.imprimirEtiquetas();

    return 0;
}

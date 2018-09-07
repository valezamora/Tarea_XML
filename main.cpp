 #include <iostream>
#include "GestorArchivos.h"
#include "GestorEtiquetas.h"
using namespace std;
 
int main(int argc, char* argv[] ){
    char* nomArchivo = (char *)"archivo.txt";
    if(argc>1){
		nomArchivo = argv[1];
	}
	
    GestorArchivos archivo(nomArchivo);
    GestorArchivos salida("archivoSinEtiquetas.txt");
    GestorEtiquetas etiquetas;

    string sigue;
    do{
        sigue = etiquetas.extraerContenido(archivo.getNextLine());
    }while(!sigue.empty());
    
    etiquetas.imprimirEtiquetas();

    return 0;
}

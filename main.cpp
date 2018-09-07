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
    GestorEtiquetas etiquetas;

    bool sigue = 1;
    while(sigue){
        sigue = etiquetas.extraerContenido(archivo.getNextLine());
    }
    etiquetas.imprimirEtiquetas();

    return 0;
}

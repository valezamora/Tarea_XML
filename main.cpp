 #include <iostream>
#include "GestorArchivos.h"
#include "GestorEtiquetas.h"
using namespace std;
 
int main()
{
    char* nomArchivo = (char *)"archivo.txt";
    if(argc>1){
		nomArchivo = argv[1];
	}
	
    GestorArchivos archivo = new GestorArchivos(nomArchivo);
    GestorEtiquetas etiquetas;

    bool sigue = 1;
    while(sigue){
        sigue = etiquetas.extraerContenido(archivo.getNextLine());
    }
    etiquetas.imprimirEtiquetas();

    delete archivo;

    return 0;
}
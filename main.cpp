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
	
    GestorArchivos archivo(nomArchivo);
    GestorEtiquetas etiquetas;
    return 0;
}
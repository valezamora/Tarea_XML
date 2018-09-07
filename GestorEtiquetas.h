#ifndef GESTOR_ETIQUETAS
#define GESTOR_ETIQUETAS

#include<fstream>
#include <iostream>
#include <map>
#include <iterator>
 
class GestorEtiquetas{
	private:
		map<string, int> diccionarioEtiquetas;
        bool salida = 0;

	public:
        GestorEtiquetas();   
        addEtiqueta(string);
        imprimirEtiquetas();
        extraerContenido(string);	
};

#endif
#ifndef GESTOR_ETIQUETAS
#define GESTOR_ETIQUETAS

#include <fstream>
#include <iostream>
#include <map>
#include <iterator>
#include <string>
 
class GestorEtiquetas{
	private:
                map<string, int> diccionarioEtiquetas;
                //bool salida = 0;

	public:
        GestorEtiquetas();  
        ~GestorEtiquetas(); 
        bool addEtiqueta(string);
        void imprimirEtiquetas();
        bool extraerContenido(string);	
};

#endif
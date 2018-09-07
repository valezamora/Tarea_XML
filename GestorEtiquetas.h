#ifndef GESTOR_ETIQUETAS
#define GESTOR_ETIQUETAS

#include <fstream>
#include <iostream>
#include <map>
#include <iterator>
#include <string>
 
class GestorEtiquetas{
	private:
                std::map<std::string, int> diccionarioEtiquetas;
                //bool salida = 0;

	public:
        GestorEtiquetas();  
        ~GestorEtiquetas(); 
        bool addEtiqueta(std::string);
        void imprimirEtiquetas();
        std::string extraerContenido(std::string);	
};

#endif
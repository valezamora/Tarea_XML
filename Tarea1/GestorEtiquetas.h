/**
 * Prototipo de la clase GestorEtiquetas
 * Tarea 0 - CI1310
 * Valeria Zamora - B37743
 * 
 * Clase encargada del manejo de las etiquetas
 * */

#ifndef GESTOR_ETIQUETAS
#define GESTOR_ETIQUETAS

#include <fstream>
#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include "Buzon.h"
 
class GestorEtiquetas{
	private:
        std::map<std::string, int> diccionarioEtiquetas;        //almacena las etiquetas
	
	public:
        GestorEtiquetas();  
        ~GestorEtiquetas(); 
        bool addEtiqueta(std::string);
        void imprimirEtiquetas();
        std::string extraerContenido(std::string);
		void enviarEtiquetas(Buzon m);	
};

#endif

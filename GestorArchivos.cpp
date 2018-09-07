/**
 * Implementación de la clase GestorArchivos
 * Tarea 0 - CI1310
 * Valeria Zamora - B37743
 * 
 * Clase encargada del manejo de los archivos de entrada y salida
 * */

#include "GestorArchivos.h" 
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

/**
 * Contructor de GestorArchivos
 * Recibe: nombre del archivo, tipo (0: archivo de entrada, 1: archivo de salida)
 * Devuelve: siguiente línea del archivo fuente
 * Modifica: 
 **/
GestorArchivos::GestorArchivos(char* nombre, int tipo){
	if(tipo == 0){
	archivoFuente.open(nombre);
	}else{
	archivoFuente.open(nombre, fstream::out);			
	}
}

/**
 * Destructor de GestorArchivos
 * Recibe: 
 * Devuelve: 
 * Modifica: cierra archivo fuente
 * **/
GestorArchivos::~ GestorArchivos(){
	archivoFuente.close();
}

/**
 * Devuelve la siguiente línea del archivo
 * Recibe: 
 * Devuelve: siguiente línea del archivo fuente
 * Modifica: 
 * **/
string GestorArchivos::getNextLine(){
	string linea; 
	getline(archivoFuente, linea);
    return linea;
}

/**
 * Escribe una línea de texto en el archivo fuente.
 * Recibe: texto que se quiere escribir en el archivo
 * Devuelve: 
 * Modifica: archivo fuente
 * */
void GestorArchivos::escribirLinea(string texto){
	archivoFuente << texto << endl;	
	
}

/**
 * Indica si el archivo llegó a su fin
 * Recibe: 
 * Devuelve: booleano que indica si el archivo llegó al final o no
 * Modifica: 

 * */
bool GestorArchivos::fin(){
	return archivoFuente.eof();
}


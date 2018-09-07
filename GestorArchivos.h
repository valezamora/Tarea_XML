/**
 * Prototipo de la clase GestorArchivos
 * Tarea 0 - CI1310
 * Valeria Zamora - B37743
 * 
 * Clase encargada del manejo de los archivos de entrada y salida
 * */

#ifndef GESTOR_ARCHIVOS
#define GESTOR_ARCHIVOS

#include <fstream>
#include <string>
 
class GestorArchivos{
	private:
		std::fstream archivoFuente;

	public:
		GestorArchivos(char*, int);
		~GestorArchivos();
		std::string getNextLine();
		void escribirLinea(std::string);
		bool fin();
};

#endif

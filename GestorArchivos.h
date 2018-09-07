#ifndef GESTOR_ARCHIVOS
#define GESTOR_ARCHIVOS

#include <fstream>
#include <string>
 
class GestorArchivos{
	private:
		std::fstream archivoFuente;

	public:
		GestorArchivos(char*);
		~GestorArchivos();
		std::string getNextLine();
		int escribirLinea(std::string);
};

#endif
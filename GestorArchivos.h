#ifndef GESTOR_ARCHIVOS
#define GESTOR_ARCHIVOS

#include <fstream>
#include <string>
 
class GestorArchivos{
	private:
		fstream archivoFuente;

	public:
		GestorArchivos(char*);
		~GestorArchivos();
		string getNextLine();
		//int escribirLinea(std::string)
};

#endif
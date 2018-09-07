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

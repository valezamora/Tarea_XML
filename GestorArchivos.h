#ifndef GESTOR_ARCHIVOS
#define GESTOR_ARCHIVOS

#include<fstream>
#include<string>

using namespace std;
 
class GestorArchivos{
	private:
		fstream archivoFuente;

	public:
		GestorArchivos(char*);
		string getNextLine();
		int escribirLinea(string)

};

#endif
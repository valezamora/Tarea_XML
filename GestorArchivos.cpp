#include 'GestorArchivos.h'
#include<fstream>

GestorArchivos:GestorArchivos(char* nombre){
	archivoFuente.open(nombre);
}

string GestorArchivos:getNextLine(){
	char temp = '';
	string linea; 
	archivoFuente >> temp;
	while(temp != '\n'){
		linea.append(temp);
		archivoFuente >> temp;
	}
    cout << linea << endl;
    return linea;
}

int GestorArchivos:escribirLinea(string texto){
			
}
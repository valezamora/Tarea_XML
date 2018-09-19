/**
 * Código del main
 * Tarea 1 - CI1310
 * Valeria Zamora - B37743
 * */

#include <iostream>
#include <string>
#include <istream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include "GestorArchivos.h"
#include "GestorEtiquetas.h"
#include "Buzon.h"
#include "Semaforo.h"
using namespace std;
 
int main(int argc, char* argv[] ){
    char* nomArchivo = (char *)"prueba.xml";
    bool s = false;
  	int n = argc;
    if(n>1){		//hay argumentos
		for(int i=1; i<=n; ++i){
			if(!fork()){
				//tarea0 enviando mensajes
				tarea0(i, argv[i]);
				_exit(0);
			}
		}
    }else{
    	//error
    	cout << "Debe ingresar nombre de los archivos que desea utilizar." << endl;
    }

    GestorArchivos archivo(nomArchivo, 0);
    GestorEtiquetas etiquetas;
    Buzon m;
    int i, id;
	char a[512];
	long t = 8;
	Semaforo sem;
	int id = shmget( KEY, 1024, 0700 | IPC_CREAT );
   	char * area = (char *) shmat( id, NULL, 0 );

    return 0;
}


void tarea0(int num, char* file){
	string sigue;
    string resultado;
    while(!archivo.fin()){
        sigue = etiquetas.extraerContenido(archivo.getNextLine());
		if(s){
			resultado += sigue;		

		}
	}    
    etiquetas.imprimirEtiquetas();

    if(s){
	char nombreSalida[] = "archivoSinEtiquetas.txt";
    	GestorArchivos salida(nombreSalida, 1);
	salida.escribirLinea(resultado);
    }
}

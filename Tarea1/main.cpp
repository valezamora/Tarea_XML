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

#define ET_SIZE 64
#define CANT_ET 128

using namespace std;
 
int main(int argc, char* argv[] ){
    bool s = false;
  	int n = argc;
  	if(string(argv[1]) == "-t"){
		s=true;
	}
		
    Buzon buzon;
    int i, id;
	char a[512];
	long t = 8;
	Semaforo sem;
	int id = shmget( KEY, 1024, 0700 | IPC_CREAT );
   	struct AreaComp * area = (AreaComp *) shmat( id, NULL, 0 );
  	
  	
    if(n>1){		//hay argumentos
		for(int i=1; i<=n; ++i){
			if(!fork()){
				//tarea0 enviando mensajes
				tarea0(i, argv[i], s, buzon);
				_exit(0);
			}
		}
    }else{
    	//error no indica archivos.
    	cout << "Debe ingresar nombre de los archivos que desea utilizar." << endl;
    }
    
    if(!fork()){
    	//imprime todo lo que hay en la memoria compartida
    	//activa semaforo
    	sem.Wait();
    }else{
    	char letraInicial;
    	bool hayEtiquetas = true;
    	
    	while(hayEtiquetas){
    		
    		//if letra es diferente
    		sem.Signal();
    	}
    	//reciba
    	buzon.Receive();
    	//guarda en un vector todos los mensajes de todos los hijos
    	//busca el menor, busca si hay iguales y saca y pide otro de una vez
    	//si cambia de letra cuando encuentra el menor entonces activa semaforo para imprimir de la memoria compartida
    	//si encuentra el mensaje de EOF entonces termina
    }

    return 0;
}

struct AreaComp{
	int cantidad;
	struct Etiqueta et[CANT_ET];
};

void tarea0(int num, char* nomArchivo, bool crearArchivo, Buzon buzon){
	//abrir archivo
	GestorArchivos archivo(nomArchivo, 0);
    GestorEtiquetas etiquetas;
	string sigue;
    string resultado;
    
    //guarda etiquetas
    while(!archivo.fin()){
        sigue = etiquetas.extraerContenido(archivo.getNextLine());
		if(crearArchivo){
			resultado += sigue;		
		}
	}    
	
	//crea archivo sin etiquetas en caso de que sea necesario
	if(crearArchivo){
		char nombreSalida[] = nomArchivo + num +".txt";
    	GestorArchivos salida(nombreSalida, 1);
		salida.escribirLinea(resultado);
    }
    
	//enviar mensajes (uno por cada etiqueta)
	
	enviar();
	

    
}

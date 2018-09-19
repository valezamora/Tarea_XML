#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY 0xB37743	// Valor de la llave del recurso
#define ET 64

class Buzon {
    public:
		Buzon();
      	~Buzon();
    	int Send( int veces, char * mensaje, long tipo);
  		int Receive( char *mensaje, int len, long tipo);   // len es el tamaño máximo que soporte la variable mensaje
    private:
      	int id;		// Identificador del buzon


	struct msgbuf{
		long mtype;
		int veces;
		char etiqueta[ET];	
	};

};


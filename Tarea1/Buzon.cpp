#include "Buzon.h"

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>

// para borrar buzones: ipcrm msg ID

Buzon::Buzon(){
	int st;
	id=msgget(KEY, IPC_CREAT|0600);
	if(-1 == id){ //hubo error
		perror("Error en el constructor del buzon \n");
		exit(2);
	}

	st=msgctl(id,IPC_SET,0);
}

Buzon::~Buzon(){
	msgctl(id,IPC_RMID,0);
}

int Buzon::Send(int veces, char * mensaje, long tipo){
	struct msgbuf m;
	size_t len = sizeof(m)-sizeof(long); 
	m.mtype = tipo;
	m.veces = veces;
	strncpy(m.etiqueta, mensaje, ET);
	int st = msgsnd(id, &m, len, IPC_NOWAIT);
	if(-1 == st){
		perror("Fallo snd \n");
		exit(EXIT_FAILURE);
	}
	return st;
}

int Buzon::Receive(char *mensaje, int len, long tipo){
	struct msgbuf m;
	int st = msgrcv(id, &m, len, tipo, 0);

	if(-1 == st){
		perror("Fallo rcv \n");
		exit(EXIT_FAILURE);
	} else {
		strncpy(mensaje, m.etiqueta, len);	
		printf("Mensaje recibido.");
	}
	return st;
}

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "Semaforo.h"

Semaforo::Semaforo(int v){
	int st;
	id=semget(KEY, 1, IPC_CREAT|0600);	//tercer parametro son los permisos en octal
	if(-1 == id){ //hubo error
		perror("Error en el constructor del semaforo: ");
		exit(2);
	}
	union semun a;
	a.val=v;
	st=semctl(id,0,SETVAL,a);
}

Semaforo::~Semaforo(){
	int st=semctl(id,0,IPC_RMID);
}

int Semaforo::Signal(){	
	int st;
	struct sembuf s;
	s.sem_num=0;
	s.sem_op=+1; //signal+1
	s.sem_flg=0;
	st=semop(id,&s,1);
	return st;
}

int Semaforo::Wait(){
	int st;
 	struct sembuf s;
	s.sem_num=0;
	s.sem_op=-1; //signal+1
	s.sem_flg=0;
	st=semop(id,&s,1);
	return st;
}

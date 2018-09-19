#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 0xB37743	// Valor de la llave del recurso

class Semaforo {
   public:	
	Semaforo( int ValorInicial = 0 );
      	~Semaforo();
      	int Signal();	// Puede llamarse V
      	int Wait();	// Puede llamarse P
   private:
      	int id;		// Identificador del semaforo




    union semun {
	int val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO(Linux-specific) */
    };
	
};

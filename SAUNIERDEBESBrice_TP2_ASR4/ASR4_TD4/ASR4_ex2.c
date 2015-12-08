#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]){
	// le nombre de processus fils a creer
		switch(pid=fork()){
		
			case -1 :
				perror("fork");
				exit(1);
			case 0 :
				exit(0);
			default :
				printf("je suis le père %d\net mon fils est : %d\n", getpid(), pid);
				int proc_fils=wait(NULL);
				//On met le pere en pause pour l'empecher de se reproduire, et on récupère les id des processus fils lorsqu’ils meurent
				printf("Processus fils vient de mourir avec le pid : %d\n", proc_fils);
				
		}			
	}
	return 0;
}





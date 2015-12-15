#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]){
  if(argc < 2){
    printf("Usage : %s suivi d’un nom de repertoire \n", argv[0]);
    exit(1);
  }

  switch(fork()){
    case -1 : ;
    case 0 : execlp("mkdir","mkdir", argv[1], NULL);
             perror("execlp esseur");
             break;
    case default : wait(NULL);
                   execlp("touch","touch",".lock",NULL);
                   perror("Probleme execlp");
  }
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  pid_t pid;
  for(int i=0;i<3;i++){//On créé 3 processus 1 à 1
  pid = fork () ;
  switch (pid) {
    case -1 : /* erreur */
      perror ("\nErreur fork") ;
    case 0 : /* fils */
      printf ("fils : %d, pid du père : %d\n", getpid(), getppid());
      exit(0); //On sort du switch case (pour ne pas passer par default)
    default : /* pere */
      printf ("pere : %d\n", getpid()) ;
      wait(NULL); //On met le pere en pause pour l'empecher de se reproduire
  }
  }
}

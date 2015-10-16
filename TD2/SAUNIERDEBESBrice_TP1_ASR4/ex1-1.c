#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  pid_t pid;
  int nombre_processus_a_creer;
  if(argc >= 1)
    nombre_processus_a_creer = atoi(argv[1]);
  else
    nombre_processus_a_creer = 3;
  for(int i=0;i<nombre_processus_a_creer;i++){//On créé 3 processus 1 à 1
  pid = fork () ;
  switch (pid) {
    case -1 : /* erreur */
      perror ("\nErreur fork") ;
    case 0 : /* fils */
      printf ("fils : %d, pid du père : %d\n", getpid(), getppid());
      exit(0); //On sort du switch case (pour ne pas passer par default)
    default : /* pere */
      printf ("pere : %d\n", getpid()) ;
      printf("Processus fils vient de mourir avec le pid : %d\n", wait(NULL)); //On met le pere en pause pour l'empecher de se reproduire, et on récupère les id des processus fils lorsqu’ils meurent
  }
  }
}

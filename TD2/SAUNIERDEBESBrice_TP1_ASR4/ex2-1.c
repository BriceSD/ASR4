#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
  pid_t pid;
  pid = fork () ;
  switch (pid) {
    case -1 : /* erreur */
      perror ("\nerreur fork") ;
    case 0 : /* fils */
      printf ("fils : %d, pid du père : %d\n", getpid(), getppid());
      execlp("mkdir","mkdir", argv[1],0);
      exit(0); //On sort du switch case (pour ne pas passer par default)
    default : /* pere */
      printf ("pere : %d\n", getpid()) ;
      wait(NULL); //On met le pere en pause pour l'empecher de se reproduire
  }
//execlp("cd","cd", argv[1],0);
execlp("touch","touch", ".profile",0);
return 0;
}

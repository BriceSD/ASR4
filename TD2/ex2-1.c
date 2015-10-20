#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

int main(int argc, char **argv)
{
  pid_t pid_commande1 = fork ();
  switch (pid_commande1 ) {
    case -1 : /* erreur */
      perror ("\nErreur fork") ;
    case 0 : /* fils */
      printf ("fils : %d, pid du père : %d\n", getpid(), getppid());
      printf ("mkdir :\n");
      execlp("mkdir","mkdir", argv[1],NULL);
      exit(0); //On sort du switch case (pour ne pas passer par default)
    default : /* pere */
      printf ("pere : %d\n", getpid()) ;
      wait(NULL); //On met le pere en pause pour l'empecher de se reproduire
  }
char chaine[100];
strcpy(chaine, "./");
strcat(chaine, argv[1]);
strcat(chaine, "/");
strcat(chaine, argv[2]);
execlp("touch","touch", chaine, NULL);
return 0;
}

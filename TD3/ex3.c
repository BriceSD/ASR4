#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

int main(int argc, char **argv)
{
  for(int i = 1; i < argc; i++){
    pid_t pid_commande1 = fork ();
    switch (pid_commande1 ) {
     case -1 : /* erreur */
       perror ("\nErreur fork") ;
     case 0 : /* fils */
       printf ("Commande %s :\n", argv[i]);
       execlp(argv[i],argv[i], NULL);
       exit(0); //On sort du switch case (pour ne pas passer par default)
     default : /* pere */
       wait(NULL); //On met le pere en pause pour l'empecher de se reproduire
    }
  }
return 0;
}


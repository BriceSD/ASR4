#include <stdio.h>


int main(int argc, char **argv, char **envp)
{
   int i;
   for (i=0 ; envp[i]!=NULL ; i++) //envp permet de récupérer toutes les variables d'environnement
      puts(envp[i]); //On les affiches une à une
   return 0;
}

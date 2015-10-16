#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   char *valeur;
   valeur = getenv(argv[1]); //On recupère la variable d'environement demander par l'utilisateur
   if (valeur != NULL) //Si c'est bien une variable d'environnement
      printf("%s vaut : %s/\n",argv[1], valeur); //On affiche le chemin de la dite variable
   return 0;
}

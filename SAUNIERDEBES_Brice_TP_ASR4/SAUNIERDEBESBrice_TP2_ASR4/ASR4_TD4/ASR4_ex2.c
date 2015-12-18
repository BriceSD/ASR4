#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <time.h>
#include <wait.h>

int main(int argc, char *argv[]){
  FILE *fd; // stream du fichier créé
  char buffer[100];
  int readingSize = 3;

  //Initialisation de la chaine de caractère
  for(int i = 0; i < 100; i++){
    buffer[i]=' ';
  }

  if((fd = fopen("fichier", "r")) == NULL)
    perror("open");

  fread(buffer, readingSize, 1, fd);
  printf("Premiere lecture : %s\n", buffer);

  //Ouverture d’un cream
  switch(fork()){
    case -1:
      printf("Erreur");
      exit(1);
    case 0:
      fread(buffer, readingSize, 1, fd);
      printf("Fils : Seconde lecture : %s\n", buffer);
    default:
      wait(NULL);
      exit(1);
  }
  return 0;
}

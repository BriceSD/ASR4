#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  char *name = argv[1];
  int ligne_voulu = atoi(argv[2]);
  int ligne_actuelle = 1;
  int fd;
  char c;
  char caractere_fin_de_ligne = '\n';

  if((fd = open(name, O_RDONLY))==-1){
    perror("open");
    exit(1);
  }

  while(read(fd,&c,1)){
    if(c == caractere_fin_de_ligne)
      ligne_actuelle++;
    if(ligne_voulu == ligne_actuelle)
      printf("%c", c);

  }
}

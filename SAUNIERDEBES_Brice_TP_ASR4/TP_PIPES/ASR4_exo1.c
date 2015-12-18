#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
int pip[2];
int pip2[2];
//descripteur de pipe

//Le fils lis dans le pipe

void fils()
{
  char buffer[15];
  char buffer2[15];
  int i;
  strcpy(buffer2,"toto    ");
  for(i=0;i<10;i++)
  {
    if(read(pip[0],buffer,15) != 15){
      perror("Erreur read fils\n");
      exit(1);
    }

    printf("Lu: %s\n", buffer);
    buffer2[5]=i+48;
    buffer2[6]=0;
    if( write(pip2[1], buffer2, 15) != 15)
    {
      perror("Erreur write fils\n");
      exit(2);
    }
  }
}

//Le pere ecrit dans le pipe

void pere()
{
  int i;
  char buf[15];
  char buf2[15];
  strcpy(buf,"Hello World ");
  for(i=0;i<10;i++)
  {
    buf[12]=i+48;
    buf[13]=0;
    if( write(pip[1],buf,15) != 15)
    { perror("Erreur write pere\n");
      exit(1);
    }
    if( read(pip2[0], buf2, 15) != 15)
    {
      perror("Erreur read pere\n");
      exit(3);
    }
    printf("Lu: %s\n", buf2);
  }
}

int main()
{
  //Ouverture d'un pipe
  if(pipe(pip)||pipe(pip2)){
    perror("Erreur de pipe");
    exit(1);
  }
  printf("Dernier message avant fork\n");

  //Creation d'un processus
  switch(fork()){
    case -1 : perror("Erreur de fork"); exit(1);
    case 0 : fils();break;
    default :pere();
  }

}

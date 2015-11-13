#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
 char *name= argv[1];
 int fd;
 char c;

   if((fd = open(name, O_RDONLY))==-1){
     perror("open");
     exit(1);
   }

  while(read(fd,&c,1)){
   printf("%c", c);
  }
}

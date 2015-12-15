#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

void fils(int i, int n){
  sleep(i*n);
  printf("pid = %d, ppid = %d\n", getpid(), getppid());
  exit(0);
}

void pere(){
  int pid=wait(NULL);
  printf("%d est decede\n", pid);
}


int main(int argc, char *argv[]){
  int n,i;

  if(argc < 2){
    printf("Usage : %s suivi d’un entier \n", argv[0]);
    exit(1);
  }

  n = atoi(argv[1]);

 for(int i = 0; i < n; i++){
   switch(fork()){
      case -1 : perror ("fork"); exit(2); break;
      case 0: fils(i, n); break;
      default : pere();
    }
  }
}

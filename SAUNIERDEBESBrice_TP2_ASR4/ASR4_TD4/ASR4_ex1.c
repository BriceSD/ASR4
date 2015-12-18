#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <time.h>
#include <sys/times.h>

int main(int argc, char *argv[]){
  clock_t start_t = clock();
  struct tms tms_start, tms_end;

  times(&tms_start);

  //le processus en question
  int pid = getpid();
  int ppid = getppid();
  int uid = getuid();
  int gid = getgid();

  printf("Identification du processus: %d\n", pid);
  printf("Identification du processus père : %d\n", ppid);
  printf("Identification du propriétaire réel : %d\n", uid);
  printf("Identification du propriétaire effectif : %d\n", gid);

  /*Afficher le repertoire courant*/
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) != NULL)
    printf("Repertoire courant: %s\n", cwd);
  else
    perror("getcwd() error\n");

  /*Temps CPU utilisateur consomme*/
  for(int i=0; i<100000000;i++);
  times(&tms_end);

  printf("Temps CPU user: %ld ms\n", tms_end.tms_utime - tms_start.tms_utime);

  /*Temps CPU noyau consomme*/
  //A COMPLETER
  clock_t end_t = clock();
  clock_t total_t = end_t - start_t;
  printf("Temps CPU noyau: %lu ms\n", total_t);

  printf("\n");
  return EXIT_SUCCESS;
}

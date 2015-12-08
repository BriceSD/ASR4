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

  //clock_t times(struct tms *);

  /*
  struct tms {
    clock_t tms_utime;
    clock_t tms_stime;
    clock_t tms_cutime;
    clock_t tms_cstime;
  };
  */

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
  //A COMPLETER

  struct tms* time_cpu = malloc(sizeof(struct tms *));
  clock_t time_user = times(time_cpu);
  printf("Temps CPU user: %ld\n", time_cpu->tms_utime);

  /*Temps CPU noyau consomme*/
  //A COMPLETER
  clock_t end_t = clock();
  clock_t total_t = (double)(end_t - start_t);
  printf("Temps CPU noyau: %lu ms\n", total_t);

  printf("\n");
  return EXIT_SUCCESS;
}

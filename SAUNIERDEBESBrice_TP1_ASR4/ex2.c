#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
  //Pour que les droits soient bien à 777 il faut dabords mettre umask à 000 (777-000=777)
  char *name="test1.txt";
  int fd = open("test1.txt", O_CREAT|O_WRONLY, 0777);
  write(fd,argv[1], strlen(argv[1]));

  struct stat statistique;
  int d = stat(name, &statistique);
  printf("id: %d\n",(int) statistique.st_dev);
  printf("i-node: %d\n",(int) statistique.st_ino);
  printf("mode: %d\n",(int) statistique.st_mode);
  printf("%d\n",(int) statistique.st_nlink);
  printf("%d\n",(int) statistique.st_uid);
  printf("%d\n",(int) statistique.st_gid);
  printf("%d\n",(int) statistique.st_rdev);
  printf("%d\n",(int) statistique.st_size);
  printf("%d\n",(int) statistique.st_blksize);
  printf("%d\n",(int) statistique.st_blocks);
  printf("%d\n",(int) statistique.st_atime);
  printf("%d\n",(int) statistique.st_mtime);
  printf("%d\n",(int) statistique.st_ctime);


}

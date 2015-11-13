#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]){
  //Pour que les droits soient bien à 777 il faut dabords mettre umask à 000 (777-000=777)
 open("test1.txt", O_CREAT, 0777);
}

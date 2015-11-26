#include <stdio.h>
#include <stdlib.h>



void f1(){
    char *p = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char p2= p[3];
}

void f2(){
    char p[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char p2= p[3];
}

void f3(){
    static char *p = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char p2= p[3];
}

void f4(){
    static char p[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char p2= p[3];
}

#define f5(){ char *p = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; char p2= p[3]; }

int main(int argc, char** argv){

    switch(atoi(argv[1])){
        case 1:
            printf("f1");
            for(int i = 0; i<500000000; i++){
                f1();
            }
            break;

        case 2:
            printf("f2");
            for(int i = 0; i<500000000; i++){
                f2();
            }
            break;

        case 3:
            printf("f3");
            for(int i = 0; i<500000000; i++){
                f3();
            }
            break;

        case 4:
            printf("f4");
            for(int i = 0; i<500000000; i++){
                f4();
            }
            break;
        case 5:
            printf("f5");
            for(int i = 0; i<500000000; i++){
                f5();
            }
            break;
    }
    return 0;

}

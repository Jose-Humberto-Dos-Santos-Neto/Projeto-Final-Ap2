#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "planos.h"

int main(void){
    /*int classe;
    printf("gostaria de vizualizar nossos planos? ");
    printf("\n| 1- sim\t| 2- nao");
    scanf("%d", &classe);
    planos(classe);
    printf("%d",classe);*/
    char x[50];
    fflush(stdin);
    gets(x);
    printf("palavra: %s",x);
    fflush(stdin);
    gets(x);
    printf("palavra nova: %s",x);
}

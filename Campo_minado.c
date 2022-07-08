#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct{
    int ** matriz;
}campo;

void cria_campo(campo * c){
    c[0].matriz = calloc(10, sizeof(int*));

    for (int i = 0; i < 10; i++)
    {
       c[0].matriz[i] = calloc(20, sizeof(int));
    }
}

void preencher_campo(campo * c){

    srand(time(NULL));
    
    for (int i = 0; i < 10; i++)
    {
        for (int a = 0; a < 20; a++)
        {
           c[0].matriz[i][a] = rand()%2;
        }   
    }
}

void print_campo(campo * c){
    for (int i = 0; i < 10; i++)
    {
        for (int a = 0; a < 20; a++)
        {
            printf("%d", c[0].matriz[i][a]);
        }
        printf("\n");
    }
}


int main (){

    campo *c;
    c = malloc (sizeof(campo)*2);

    cria_campo(c);
    preencher_campo(c);
    print_campo(c);


    return 0;
}
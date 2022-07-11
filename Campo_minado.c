#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Definição da struct que armazena a matriz
typedef struct{
    int ** matriz;
}campo;


// Essa função cria a matriz e faz a alocação dinâmica dos ca6mpos
void cria_campo(campo * c){
    c[0].matriz = calloc(10, sizeof(int*));
    c[1].matriz = calloc(10, sizeof(int*));
    for (int i = 0; i < 10; i++)
    {
       c[0].matriz[i] = calloc(20, sizeof(int));
       c[1].matriz[i] = calloc(20, sizeof(int));
    }
}




// Função para preencher a matriz com as minas
void preencher_campo(campo * c){
    //Essa parte do código gera os índices dos campos que ficaram as minas.
    int indices_aleatorios[40][2];
    int sn=0;
    int linha, coluna=0;

    srand(time(NULL));
    
    // limpa a matriz de índices aleatórios colocando -1 em todas as posições  
    for(int i = 0; i < 40; i++){
        for(int a = 0; a < 2; a++){
            indices_aleatorios[i][a] = -1;
        }
    }
    //-----------------------------------------------------------------------

    //Gera os 40 índices aleatórios das minas
    for(int i = 0; i < 40; i++){
        linha = rand()%10;
        coluna = rand()%20;    

        for(int l = 0; l < 40; l++){
            if(linha == indices_aleatorios[l][0] && coluna == indices_aleatorios[l][1]){
                sn=1;
            }
        }
        if(sn == 1){
            i--;
        }else{
            indices_aleatorios[i][0]=linha;
            indices_aleatorios[i][1]=coluna;
            // printf("%d %d\n", indices_aleatorios[i][0], indices_aleatorios[i][1]);
        }
        sn=0;
    }
    //----------------------------------------------------------------------------------

    //Preenche a matriz com as minas

    for (int i = 0; i < 40; i++)
    {
        c[0].matriz[indices_aleatorios[i][0]][indices_aleatorios[i][1]] = 1;
    }
    //-----------------------------------------------------------
}
//-----------------------------fim da função--------------------------------

//Função para mostrar a matriz
void print_campo(campo * c){
    int cont_linha = 0;
    printf("    1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20 \n");
    printf("  ---------------------------------------------------------------------------------\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d |", cont_linha);
        for (int a = 0; a < 20; a++)
        {
            printf(" %d |", c[1].matriz[i][a]);
        }
        printf("\n");
        printf("  ---------------------------------------------------------------------------------\n");
        cont_linha++;
    }
}
//----------------------------fim da função----------------------------------


int main (){

    campo *c;
    c = malloc (sizeof(campo)*2);

    cria_campo(c);
    preencher_campo(c);
    printf("\n\n");
    printf("\t\t\t\t    CAMPO MINADO\n\n");
    print_campo(c);


    return 0;
}
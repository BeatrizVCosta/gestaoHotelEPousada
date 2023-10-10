#include <stdio.h>/* Para o printf */
#include <ctype.h>
#include <string.h>
#include "validacao.h"

void ler_nome(char* nome){
    int valido;
    do{
        printf("\tDigite o nome:  ");
        fflush(stdin);
        fgets(nome, 100, stdin);
        valido=verifica_nome(nome);
        if (valido==1)
        {
            printf("\tNome invalido!\n");
        }
        
    }while(valido!=0);
    
   
}
int verifica_nome(char* nome) {
    int i, tamanho;
    tamanho = strlen(nome) - 1;

    for(i = 0; i < tamanho; i++) {
        if(!isalpha(nome[i]) && nome[i] != ' ') {
            return 1;
        }
    }
    return 0;
}


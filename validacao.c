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

void ler_data(int dia, int mes, int ano){
    int valido;
    do{
        printf("\tDigite a data no formato(dd/mm/aaaa):  ");
        fflush(stdin);
        scanf("%d/%d/%d", &dia, &mes, &ano);
        valido=verifica_data(dia, mes, ano);
        if (valido==1)
        {
            printf("\tData invalida!\n");
        }
        
    }while(valido!=0);
}
// Função adaptada do Bing AI
int verifica_data(int dia,int mes,int ano){
    if (ano < 0) {
        //printf("Data invalida! O ano nao pode ser negativo.\n");
        return 1;
    }

    if (mes < 1 || mes > 12) {
        //printf("Data invalida! O mes deve estar entre 1 e 12.\n");
        return 1;
    }

    int diasNoMes;
    switch (mes) {
        case 4: case 6: case 9: case 11:
            diasNoMes = 30;
            break;
        case 2:
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
                diasNoMes = 29;
            else
                diasNoMes = 28;
            break;
        default:
            diasNoMes = 31;
    }

    if (dia < 1 || dia > diasNoMes) {
        // printf("Data invalida! O dia deve estar entre 1 e %d para o mes %d.\n", diasNoMes, mes);
        return 1;
    }

    //printf("Data valida!\n");
    return 0;
}
// void ler_cpf(char* cpf){
//         int valido;
//     do{
//         printf("\tDigite o CPF:  ");
//         fflush(stdin);
//         fgets(cpf, 100, stdin);
//         valido=verifica_cpf(cpf);
//         if (valido==1)
//         {
//             printf("\tCPF invalido!\n");
//         }
        
//     }while(valido!=0);
    
// }


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
void ler_cargo(char* cargo){
    int valido;
    do{
        printf("\tDigite o cargo:  ");
        fflush(stdin);
        fgets(cargo, 100, stdin);
        valido=verifica_nome(cargo);
        if (valido==1)
        {
            printf("\tCargo invalido!\n");
        }
        
    }while(valido!=0);
    
   
}
void ler_numero(char* numero){
    printf("\tDigite o numero do quarto:  ");
    fflush(stdin);
    fgets(numero, 3, stdin);
   
}
void ler_tipo(char* tipo){
    printf("\t 1-VIP 2-PREMIUM 3-BASICO\n");
    printf("\tDigite o tipo do quarto(1/2/3):  ");
    fflush(stdin);
    fgets(tipo, 3, stdin);
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

void ler_data(int dia,int mes,int ano){
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
    return 1;
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

void ler_email(char* email){
    int valido;
    do{
        printf("\tDigite o email:  ");
        fflush(stdin);
        fgets(email, 100, stdin);
        valido=verifica_email(email);
        if (valido==1)
        {
            printf("\tEmail invalida!\n");
        }
        
    }while(valido!=0);
}
//Função feita por Flavius gorgonio
int verifica_email(char* email){
  int tam=strlen(email);
  int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;
  for (i = 0; i < tam; i++) {
    char c = email[i];
    if(c == '@') {
      if (arroba)
         break; // não pode ter uma segunda @
      arroba++;
      if (i < 3)
        break; // se @ vier antes de 3 caracteres, erro
    }
    else if (arroba) { // se já encontrou @
      if (ponto) { // se já encontrou . depois de @@
        depoisPonto++;
      }
      else if(c == '.') {
        ponto = 1;
        if (antesPonto < 3) {
          break; // se . depois de @ vier antes de 3 caracteres, erro
        }
      }
      else {
        antesPonto++;
      }
    }
  } // for
    if (i == tam && depoisPonto > 1)
        return 0;
    else
        return 1;
} 
void ler_cpf(char* CPF){
        printf("\tDigite o CPF:  ");
        fflush(stdin);
        fgets(CPF, 100, stdin);
}
// função feita por flavius
// int valida_cpf(char* cpf_cnpj)
// {
//   int tam;

//   tam = strlen(cpf_cnpj);
//    // Verifica se o CPF tem 11 digitos
//     if (tam != 12) {
//       return 0;
//     }

// // Exclui opcoes invalidas
//     else if ((strcmp(cpf_cnpj,"00000000000\n") == 0) || (strcmp(cpf_cnpj,"11111111111\n") == 0) || 
//     (strcmp(cpf_cnpj,"22222222222\n") == 0) || (strcmp(cpf_cnpj,"33333333333\n") == 0) || 
//     (strcmp(cpf_cnpj,"44444444444\n") == 0) || (strcmp(cpf_cnpj,"55555555555\n") == 0) || 
//     (strcmp(cpf_cnpj,"66666666666\n") == 0) || (strcmp(cpf_cnpj,"77777777777\n") == 0) || 
//     (strcmp(cpf_cnpj,"88888888888\n") == 0) || (strcmp(cpf_cnpj,"99999999999\n") == 0)) {
//       return 0;
//     }

//     // Verifica se todos os caracteres sao digitos numericos
//     for (int i = 0; i < tam - 1; i++) {
//       if (!eh_num(cpf_cnpj[i])) {
//         return 0;
//       }
//     }

//     // Calcula o primeiro digito verificador
//     int soma = 0;
//     for (int i = 0; i < 9; i++) {
//       soma += (cpf_cnpj[i] - '0') * (10 - i);
//     }

//     int primeiro_digito = (soma * 10) % 11;
//     if (primeiro_digito >= 10) {
//       primeiro_digito = 0;
//     }

//     // Calcula o segundo digito verificador
//     soma = 0;
//     for (int i = 0; i < 10; i++) {
//         soma += (cpf_cnpj[i] - '0') * (11 - i);
//     }
//     int segundo_digito = 11 - (soma % 11);
//     if (segundo_digito >= 10) {
//         segundo_digito = 0;
//     }

//     // Verifica se os digitos verificadores sao iguais aos fornecidos
//     if (cpf_cnpj[9] - '0' == primeiro_digito && cpf_cnpj[10] - '0' == segundo_digito) {
//         return 1;
//     } else {
//         return 0;
//     }
// }
// int eh_num(char c) 
// {
//   if (c >= '0' && c <= '9') {
//     return 1;
//   } else if (c == 13) {
//     return 1;
//   } else {
//     return 0;
//   }  
// }




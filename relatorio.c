#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "quartos.h"
#include "relatorio.h"
#include "atendimento.h"
#include "validacao.h"

char relatorio(){
    char op2;
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                         RELATORIO                                    |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         0- Sair                                      |\n");
    printf("|                         1- Consultar quartos disponiveis             |\n");
    printf("|                         2- Listar check-in                           |\n");
    printf("|                         3- Listar check-out                          |\n");
    printf("|                         4- Tabela de precos                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite sua escolha:  ");
    scanf("%c", &op2);
    getchar();
    fflush(stdin);
    printf("------------------------------------------------------------------------\n");
    return op2;
}
void quartos_disponiveis(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                       QUARTOS DISPONIVEIS                            |\n");
    printf("------------------------------------------------------------------------\n");
    printf("| Numero do quarto              | Tipo do quarto                       |\n");
    listar_quad();
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void listar_quad(void) {
  FILE* fq;
  Quarto* qua; 
  int aux;
  qua = (Quarto*) malloc(sizeof(Quarto));
  fq = fopen("quartos.dat", "rb");
  if (fq == NULL) {
    printf("\tOps! Ocorreu um erro na abertura do arquivo!\n");
    printf("\tNão é possível continuar este programa...\n");
    getchar();
    return;
  }
  while(fread(qua, sizeof(Quarto), 1, fq)) {
    if (qua->livre == 'D' && qua->status != 'D') {
      exibe_quartosT(qua);
      aux=aux+1;
    }
  }
  if (aux==0){
    printf("------------------------------------------------------------------------\n");
    printf("|                       NENHUM QUARTO DISPONIVEL                       |\n");
    printf("------------------------------------------------------------------------\n");
  }
  
  fclose(fq);
  free(qua);
}

void exibe_quartosT(Quarto* qua) {
    char nquarto[5];
    strncpy (nquarto,qua->numero,strlen(qua->numero));
    for (int i = 0; i < 5; i++){
      if (nquarto[i]=='\n'){
        nquarto[i]='\0';
      }  
    }
    printf("|----------------------------------------------------------------------|\n");
    printf("| %-29s | %-36s |\n", nquarto, qua->tipo);
}

void listar_atendimentoT(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                         LISTAR CHECK-IN                              |\n");
    printf("------------------------------------------------------------------------\n");
    printf("| Nome do cliente    |    CPF do cliente     |    Data do check-in     |\n");
    listar_ateT();
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}

void listar_ateT(void) {
  FILE* fa;
  Atendimento* ate;
  int aux; 
  ate = (Atendimento*) malloc(sizeof(Atendimento));
  fa = fopen("atendimentos.dat", "rb");
  if (fa == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Nao e possivel continuar este programa...\n");
    // exit(1);
    getchar();
    return;
  }
  while(fread(ate, sizeof(Atendimento), 1, fa)) {
    if (ate->status != 'D') {
      exibe_atendimentoT(ate);
      aux=aux+1;
      
    }
  }
  if (aux==0){
    printf("------------------------------------------------------------------------\n");
    printf("|                       NENHUM CHECK-IN EM ABERTO                      |\n");
    printf("------------------------------------------------------------------------\n");
  }
  fclose(fa);
  free(ate);
}
void exibe_atendimentoT(Atendimento* ate) {
  if ((ate == NULL) || (ate->status == 'D')) {
    printf("------------------------------------------------------------------------\n");
    printf("|                       Atendimento Inexistente                        |\n");
    printf("------------------------------------------------------------------------\n");
  } else {
    char nome[100];
    strncpy (nome,ate->nome,strlen(ate->nome));
    for (int i = 0; i < 100; i++){
      if (nome[i]=='\n'){
        nome[i]='\0';
      }  
    }
    printf("------------------------------------------------------------------------\n");
    printf("| %-15s    | %-16s      | %-21s   |\n", nome, ate->CPF, ate->data_in);
  }
}

void listar_checkoutT(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                         LISTAR CHECK-OUT                             |\n");
    printf("------------------------------------------------------------------------\n");
    printf("| CPF do Cliente    |    CPF do Funcionario  |    Valor da Estadia     |\n");
    listar_coutT();
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}

void exibe_coutT(Atendimento* ate) {
    if ((ate == NULL) || (ate->status == 'A')) {
        printf("|--------------------------------------------------------------------|\n");
        printf("|                       NENHUM CHECK-OUT FEITO                       |\n");
        printf("|--------------------------------------------------------------------|\n");
    } else {
        printf("|----------------------------------------------------------------------|\n");
        printf("| %-14s    | %-17s      | %-21d   |\n", ate->CPF, ate->CPF_fun, ate->valor);
    }
}

void listar_coutT(void) {
    FILE* fa;
    Atendimento* ate; 
    int aux = 0;
    ate = (Atendimento*) malloc(sizeof(Atendimento));
    fa = fopen("atendimentos.dat", "rb");
    if (fa == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Nao e possivel continuar este programa...\n");
        getchar();
        return;
    }
    while(fread(ate, sizeof(Atendimento), 1, fa)) {
        if (ate->status != 'A') {
            aux++;
            exibe_coutT(ate);
        }
    }
    if (aux==0){
        printf("|--------------------------------------------------------------------|\n");
        printf("|                       NENHUM CHECK-OUT FEITO                       |\n");
        printf("|--------------------------------------------------------------------|\n");
    }
    fclose(fa);
    free(ate);
}

void precos(void){
    system("clear||cls");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("|                                TABELA DE PRECOS                                       |\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("|   Tipo de Quarto    |   Caracteristicas                           |   Preco Diaria    |\n");
    printf("|---------------------|---------------------------------------------|-------------------|\n");
    printf("|  1- Quarto VIP      | Suite com hidromassagem, Cafe da manha,     |                   |\n");
    printf("|                     | Duas camas, Acesso ao massagista do hotel   |   1200            |\n");
    printf("|---------------------------------------------------------------------------------------|\n");
    printf("|  2- Quarto Premium  | Suite com banheira, Cafe da manha,          |                   |\n");
    printf("|                     | Duas camas                                  |   800             |\n");
    printf("|---------------------------------------------------------------------------------------|\n");
    printf("|  3- Quarto Basico   | Uma suite, Cafe da manha, Uma cama          |   500             |\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}

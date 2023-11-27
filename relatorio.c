#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "quartos.h"
#include "relatorio.h"
#include "atendimento.h"

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
    printf("|                         5- Relatorio Geral                           |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite sua escolha:  ");
    scanf("%c", &op2);
    printf("------------------------------------------------------------------------\n");
    return op2;
}
void quartos_disponiveis(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                       QUARTOS DISPONIVEIS                            |\n");
    printf("------------------------------------------------------------------------\n");
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
  }
  while(fread(qua, sizeof(Quarto), 1, fq)) {
    if (qua->livre == 'D' && qua->status != 'D') {
      exibe_quartos(qua);
      aux=aux+1;
      printf("------------------------------------------------------------------------\n");
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

void listar_atendimento(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                         LISTAR CHECK-IN                              |\n");
    printf("------------------------------------------------------------------------\n");
    listar_ate();
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}

void listar_ate(void) {
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
  }
  while(fread(ate, sizeof(Atendimento), 1, fa)) {
    if (ate->status != 'D') {
      exibe_atendimento(ate);
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


void exibe_atendimento(Atendimento* ate) {
  char situacao[13];
  if ((ate == NULL) || (ate->status == 'D')) {
    printf("------------------------------------------------------------------------\n");
    printf("|                       Atendimento Inexistente                        |\n");
    printf("------------------------------------------------------------------------\n");
  } else {
    printf("------------------------------------------------------------------------\n");
    printf("|                       Atendimento Encontrado                         |\n");
    printf("------------------------------------------------------------------------\n");
    if (ate->status == 'A') {
      strcpy(situacao, "Ativado");
    } else if (ate->status == 'D') {
      strcpy(situacao, "Desativado");
    } else {
      strcpy(situacao, "Inexistente");
    }
    printf("\t\tSituacao do Atendimento: %s\n", situacao);
    printf("|\t\tData e hora: %s\n", ate->data_in);
    printf("|\t\tValor da estadia: %d\n", ate->valor);
    printf("|\n");
    printf("|                         Dados do cliente                             |\n");
    printf("|\n");
    printf("|\t\tNome: %s\n", ate->nome);
    printf("|\t\tCPF: %s\n", ate->CPF);
    printf("|\n");
    printf("|                          Dados do quarto                             |\n");
    printf("|\n");
    printf("|\t\tNumero: %s\n", ate->numero);
    printf("|\t\tTipo: %s\n", ate->tipo);
    printf("|\n");
    printf("|                Dados do funcionario que realizou o check-in          |\n");
    printf("\n");
    printf("|\t\tNome: %s\n", ate->nome_fun);
    printf("|\t\tCPF: %s\n", ate->CPF_fun);
    printf("------------------------------------------------------------------------\n");
  }
}

void listar_checkout(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                         LISTAR CHECK-OUT                             |\n");
    printf("------------------------------------------------------------------------\n");
    listar_cout();
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}

void listar_cout(void) {
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
  }
  while(fread(ate, sizeof(Atendimento), 1, fa)) {
    if (ate->status != 'A') {
      aux=aux+1;
      exibe_cout(ate);
      
    }
  }
  if (aux==0){
    printf("------------------------------------------------------------------------\n");
    printf("|                       NENHUM CHECK-OUT FEITO                         |\n");
    printf("------------------------------------------------------------------------\n");
  }
  fclose(fa);
  free(ate);
}
void exibe_cout(Atendimento* ate) {
  char situacao[13];
  if ((ate == NULL) || (ate->status == 'A')) {
    printf("------------------------------------------------------------------------\n");
    printf("|                       NENHUM CHECK-OUT FEITO                         |\n");
    printf("------------------------------------------------------------------------\n");
  } else {
    printf("------------------------------------------------------------------------\n");
    printf("|                       Atendimento Encontrado                         |\n");
    printf("------------------------------------------------------------------------\n");
    if (ate->status == 'A') {
      strcpy(situacao, "Ativado");
    } else if (ate->status == 'D') {
      strcpy(situacao, "Desativado");
    } else {
      strcpy(situacao, "Inexistente");
    }
    printf("\t\tSituacao do Atendimento: %s\n", situacao);
    printf("|\t\tData e hora do check-in: %s\n", ate->data_in);
    printf("|\t\tData e hora do check-out: %s\n", ate->data_out);
    printf("|\t\tValor da estadia: %d\n", ate->valor);
    printf("|\n");
    printf("|                         Dados do cliente                             |\n");
    printf("|\n");
    printf("|\t\tNome: %s\n", ate->nome);
    printf("|\t\tCPF: %s\n", ate->CPF);
    printf("|\n");
    printf("|                          Dados do quarto                             |\n");
    printf("|\n");
    printf("|\t\tNumero: %s\n", ate->numero);
    printf("|\t\tTipo: %s\n", ate->tipo);
    printf("|\n");
    printf("|                Dados do funcionario que realizou o check-in          |\n");
    printf("\n");
    printf("|\t\tNome: %s\n", ate->nome_fun);
    printf("|\t\tCPF: %s\n", ate->CPF_fun);
    printf("------------------------------------------------------------------------\n");
  }
}


void relatorio_geral(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                        RELATORIO GERAL                               |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    // mostrar todos os check-in e check-out do dia, mês ou ano
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void precos(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                        TABELA DE PRECOS                              |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t1- Quarto VIP: \n");
    printf("\t\t- Possui uma suite com hidromassagem \n");
    printf("\t\t- Cafe da manha\n");
    printf("\t\t- Duas camas \n");
    printf("\t\t- Acesso ao massagista do hotel\n");
    printf("\t\t- Preco pernoite: 1200  \n\n");
    printf("\t\t2- Quarto Premium: \n");
    printf("\t\t- Possui uma suite com banheira \n");
    printf("\t\t- Cafe da manha\n");
    printf("\t\t- Duas cama \n");
    printf("\t\t- Preco pernoite: 800  \n\n");
    printf("\t\t3- Quarto Basico: \n");
    printf("\t\t- Uma suite \n");
    printf("\t\t- Cafe da manha\n");
    printf("\t\t- Uma camas \n");
    printf("\t\t- Preco pernoite: 500  \n");
    // mostrar o preço de todos os tipos de quartos
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
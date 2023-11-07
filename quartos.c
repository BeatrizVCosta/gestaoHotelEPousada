#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include <string.h>
#include "quartos.h"
#include "validacao.h"
char menu_quartos(){
    char op2;
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                             QUARTOS                                  |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         0- Sair                                      |\n");
    printf("|                         1- Cadastrar                                 |\n");
    printf("|                         2- Listar                                    |\n");
    printf("|                         3- Procurar                                  |\n");
    printf("|                         4- Atualizar                                 |\n");  
    printf("|                         5- Deletar                                   |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite sua escolha:  ");
    scanf("%c", &op2);
    printf("------------------------------------------------------------------------\n");
    return op2;
}
void cadastrar_quartos(void){
    system("clear||cls");
    Quarto *qua = (Quarto*) malloc(sizeof(Quarto)); 
    printf("------------------------------------------------------------------------\n");
    printf("|                      CADASTRAR  QUARTOS                              |\n");
    printf("------------------------------------------------------------------------\n");
    ler_numero(qua->numero);
    ler_tipo(qua->tipo);
    qua->status='A'; 
    printf("------------------------------------------------------------------------\n");
    grava_quarto(qua);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void grava_quarto(Quarto* qua) //.h
{
    FILE* fp;
    fp = fopen("quartos.dat", "ab");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Nao e possivel continuar este programa...\n");
        exit(1);
    }
    fwrite(qua, sizeof(Quarto), 1, fp);
    fclose(fp);
    printf("|\t\tQuarto cadastrado com sucesso!\t\t\t\t|\n|\n");
    printf("|\t\tNumero: %s\n", qua->numero);
    printf("|\t\tTipo: %s\n", qua->tipo);
    printf("|\t\tStatus: %c\n", qua->status);
}
void exibe_quartos(Quarto* qua) {
  char situacao[13];
  if ((qua == NULL) || (qua->status == 'D')) {
    printf("\n\t\tQuarto Inexistente\n");
  } else {
    printf("\n\t\tQuarto Encontrado\n");
    printf("Numero: %s\n", qua->numero);
    quartos();
    printf("Tipo: %s\n", qua->tipo);
    if (qua->status == 'A') {
      strcpy(situacao, "Ativado");
    } else if (qua->status == 'D') {
      strcpy(situacao, "Desativado");
    } else {
      strcpy(situacao, "Inexistente");
    }
    printf("Situacao do quarto: %s\n", situacao);
  }
}
void procurar_quartos(void){
    system("clear||cls");
    char numero[10];
    printf("------------------------------------------------------------------------\n");
    printf("|                      PROCURAR QUARTO                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\tDigite o numero do quarto:  \n");
    fflush(stdin);
    fgets(numero,10, stdin);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}
void listar_quartos(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      TODOS OS QUARTOS                                |\n");
    printf("------------------------------------------------------------------------\n");
    listar_qua();
    printf("Pressione qualquer tecla para continuar...\n");
    fflush(stdin);
    getchar();
}
void listar_qua(void) {
  FILE* fp;
  Quarto* qua; 
  qua = (Quarto*) malloc(sizeof(Quarto));
  fp = fopen("quartos.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  while(fread(qua, sizeof(Quarto), 1, fp)) {
    if (qua->status != 'D') {
      exibe_quartos(qua);
      printf("------------------------------------------------------------------------\n");
    }
  }
  fclose(fp);
  free(qua);
}
void atualizar_quartos(void){
    system("clear||cls");
    char tipo[1];
    printf("------------------------------------------------------------------------\n");
    printf("|                      ATUALIZAR  QUARTOS                              |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\tDigite o novo status do quarto");
    fflush(stdin);
    fgets(tipo,1, stdin);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}
void deletar_quartos(void){
    system("clear||cls");
    char numero[10];
    printf("------------------------------------------------------------------------\n");
    printf("|                      DELETAR QUARTOS                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\tDigite o numero do quarto que deseja deletar:");
    fflush(stdin);
    fgets(numero,10, stdin);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}

void quartos(void){
  printf("1-VIP");
  printf(" 2-Premium");
  printf(" 3-Basico");
}
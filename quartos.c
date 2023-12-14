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
    getchar();
    fflush(stdin);
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
    qua->livre='D'; 
    printf("------------------------------------------------------------------------\n");
    grava_quarto(qua);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void grava_quarto(Quarto* qua) //.h
{
    FILE* fq;
    fq = fopen("quartos.dat", "ab");
    if (fq == NULL) 
    {
        printf("\tOps! Ocorreu um erro na abertura do arquivo!\n");
        printf("\tNao e possivel continuar este programa...\n");
        getchar();
    }
    fwrite(qua, sizeof(Quarto), 1, fq);
    fclose(fq);
    printf("|\t\tQuarto cadastrado com sucesso!\t\t\t\t|\n|\n");
    printf("|\t\tNumero: %s\n", qua->numero);
    printf("|\t\tTipo: %s\n", qua->tipo);
    printf("|\t\tStatus: %c\n", qua->status);
    printf("|\t\tSituacao: %c\n", qua->livre);
}
void exibe_quartos(Quarto* qua) {
  char situacao[13];
  char situ[13];
  if ((qua == NULL) || (qua->status == 'D')) {
    printf("\n\t\tQuarto Inexistente\n");
  } else {
    printf("\n\t\tQuarto Encontrado\n");
    printf("Numero: %s\n", qua->numero);
    quartos();
    printf("\nTipo: %s\n", qua->tipo);
    if (qua->status == 'A') {
      strcpy(situacao, "Ativado");
    } else if (qua->status == 'D') {
      strcpy(situacao, "Desativado");
    } else {
      strcpy(situacao, "Inexistente");
    }
    printf("Status do quarto: %s\n", situacao);
    if (qua->livre == 'D') {
      strcpy(situ, "Desocupado");
    } else if (qua->livre == 'O') {
      strcpy(situ, "Ocupado");
    } else {
      strcpy(situ, "Inexistente");
    }
    printf("Situacao do quarto: %s\n", situ);
  }
}
void procurar_quartos(void){
    system("clear||cls");
    Quarto* qua;
    printf("------------------------------------------------------------------------\n");
    printf("|                      PROCURAR QUARTO                                 |\n");
    printf("------------------------------------------------------------------------\n");
    qua=busca_quartos();
    free(qua);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}
Quarto* busca_quartos(void) {
  FILE* fq;
  Quarto* qua;
  char numero[5];
  printf("\t\tDigite o numero do quarto:  ");
  fflush(stdin);
  fgets(numero, 5, stdin);
  qua = (Quarto*) malloc(sizeof(Quarto));
  fq = fopen("quartos.dat", "rb");
  if (fq == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Nao e possivel continuar este programa...\n");
    getchar();
    return;
  }
  // while(!feof(fq)) {
  //   fread(fun, sizeof(Funcionario), 1, fq);
    while(fread(qua, sizeof(Quarto), 1, fq)){
    if ((strcmp(qua->numero, numero)==0) && (qua->status == 'A')) {
      // fclose(fq);
      // return fun;
      exibe_quartos(qua);
    }
  }
  fclose(fq);
  return NULL;
}

void listar_quartos(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      TODOS OS QUARTOS                                |\n");
    printf("------------------------------------------------------------------------\n");
    printf("| Numero do quarto              | Tipo do quarto                       |\n");
    listar_qua();
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    fflush(stdin);
    getchar();
}
void listar_qua(void) {
  FILE* fq;
  Quarto* qua; 
  qua = (Quarto*) malloc(sizeof(Quarto));
  fq = fopen("quartos.dat", "rb");
  if (fq == NULL) {
    printf("\tOps! Ocorreu um erro na abertura do arquivo!\n");
    printf("\tNao e possivel continuar este programa...\n");
    getchar();
    return;
  }
  while(fread(qua, sizeof(Quarto), 1, fq)) {
    if (qua->status != 'D') {
      exibe_quartosT(qua);
    }
  }
  fclose(fq);
  free(qua);
}
void atualizar_quartos(void){
    system("clear||cls");
    char numero[5];
    printf("------------------------------------------------------------------------\n");
    printf("|                      ATUALIZAR  QUARTOS                              |\n");
    printf("------------------------------------------------------------------------\n");
    ler_numero(numero);
    att_quarto(numero);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}
void att_quarto(char *numero){
  FILE* fq;
  Quarto* qua;
  int encontra=0;
  int esc;
  qua=(Quarto*)malloc(sizeof(Quarto));
  fq=fopen("quartos.dat","r+b");
  if (fq==NULL){
    printf("\tNenhum quarto cadastrado!");
    return;
  }
  while (fread(qua, sizeof(Quarto), 1, fq)) {
    if ((strcmp(qua->numero, numero) == 0) && (qua->status == 'A')){
      encontra=1;
        while(esc!=0){
          system("clear||cls");
          printf("------------------------------------------------------------------------\n");
          printf("|                      ATUALIZAR QUARTO                                |\n");
          printf("------------------------------------------------------------------------\n");
          printf("                 Dados do quarto:\n");
          printf("\t\tNumero do quarto:%s",qua->numero);
          printf("\t\tTipo do quarto:%s\n",qua->tipo);
          printf("\t\tStatus do quarto:%c\n",qua->status);
          printf("\t\tSituacao do quarto:%c\n",qua->livre);
          printf("\n");
          printf("|                Digite [1] para atualizar o tipo                      |\n");
          printf("|                Digite [0] para sair                                  |\n");
          printf("------------------------------------------------------------------------\n");
          printf("\t\tConfirmar:");
          scanf("%d",&esc);
          getchar();
          fflush(stdin);
          switch (esc){
            case 1:
              ler_tipo(qua->tipo);
              printf("\t\tTipo atualizado com sucesso!");
              printf("\t\nDigite enter para continuar...");getchar();fflush(stdin);
              break;
            case 0:
              esc=0;
              break;
            default:
              printf("\t\nOpção Invalida!\n");
              printf("\tDigite enter para continuar...");getchar();fflush(stdin);
              break;
            }
            fseek(fq, -1 * (long)sizeof(Quarto), SEEK_CUR);
            fwrite(qua, sizeof(Quarto), 1, fq);
          }break;
      }
  }
  if (!encontra){
    printf("\t\tQuarto não encontrado!");
  }
  fclose(fq);
  free(qua);
}

void deletar_quartos(void){
    system("clear||cls");
    char numero[5];
    printf("------------------------------------------------------------------------\n");
    printf("|                      DELETAR QUARTOS                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    ler_numero(numero);
    delete_quarto(numero);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}
void delete_quarto(char *numero){
  FILE* fq;
  Quarto* qua;
  int encontra=0;
  int esc;
  qua=(Quarto*)malloc(sizeof(Quarto));
  fq=fopen("quartos.dat","r+b");
  if (fq==NULL){
    printf("\tNenhum quarto cadastrado!");
    return;
  }
  if (fq==NULL){
    printf("\tNenhum quarto cadastrado!");
    return;
  }
  while (fread(qua, sizeof(Quarto), 1, fq)) {
    if ((strcmp(qua->numero, numero) == 0) && (qua->status == 'A')){
      encontra=1;
        while(esc!=0){
          system("clear||cls");
          printf("------------------------------------------------------------------------\n");
          printf("|                         DELETAR QUARTO                                |\n");
          printf("------------------------------------------------------------------------\n");
          printf("                 Dados do quarto:\n");
          printf("\t\tNumero do quarto:%s",qua->numero);
          printf("\t\tTipo do quarto:%s\n",qua->tipo);
          printf("\t\tStatus do quarto:%c\n",qua->status);
          printf("\t\tSituacao do quarto:%c\n",qua->livre);
          printf("\n");
          printf("|                Digite [1] para deletar o quarto                      |\n");
          printf("|                Digite [0] para sair                                  |\n");
          printf("------------------------------------------------------------------------\n");
          printf("\t\tConfirmar:");
          fflush(stdin);
          scanf("%d",&esc);
          getchar();
          fflush(stdin);
          switch (esc){
            case 1:
              qua->status='D';
              printf("\t\tQuarto deletado com sucesso!");
              printf("\t\nDigite enter para continuar...");getchar();
              esc=0;
              break;
            case 0:
              esc=0;
              break;
            default:
              printf("\t\nOpção Invalida!\n");
              printf("\tDigite enter para continuar...");getchar(); 
              break;
            }
            fseek(fq, -1 * (long)sizeof(Quarto), SEEK_CUR);
            fwrite(qua, sizeof(Quarto), 1, fq);
          }break;
      }
  }
  if (!encontra){
    printf("\t\tQuarto não encontrado!");
  }
  fclose(fq);
  free(qua);
}

void quartos(void){
  printf("1-VIP");
  printf(" 2-Premium");
  printf(" 3-Basico");
}
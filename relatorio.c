#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include "quartos.h"
#include "relatorio.h"

char relatorio(){
    char op2;
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                         RELATORIO                                    |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         0- Sair                                      |\n");
    printf("|                         1- Consultar quartos disponiveis             |\n");
    printf("|                         2- Tabela de precos                          |\n");
    printf("|                         3- Relatorio Geral                           |\n");
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
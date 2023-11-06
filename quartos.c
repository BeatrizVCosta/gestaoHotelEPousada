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
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
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
    printf("|\t\t\tQuarto cadastrado com sucesso!\t\t\t|\n|\n");
    printf("|\t\tNumero: %s\n", qua->numero);
    char tip[8];
    if(qua->tipo == 1) {
      strcpy(tip, "VIP");
    } else if (qua->tipo== 2) {
      strcpy(tip, "Premium");
    } else if(qua->tipo==3){
      strcpy(tip, "Basico");
    }else{
        strcpy(tip, "Outro");
    }
    printf("|\t\tTipo do quarto: %s\n", tip);
    printf("|\t\tstatus: %c\n", qua->status);
}
void procurar_quartos(void){
    system("clear||cls");
    char numero[10];
    printf("------------------------------------------------------------------------\n");
    printf("|                      PROCURAR QUARTO                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
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
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("Pressione qualquer tecla para continuar...\n");
    fflush(stdin);
    getchar();
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
#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include "quartos.h"

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
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite sua escolha:  ");
    scanf("%c", &op2);
    printf("------------------------------------------------------------------------\n");
    return op2;
}
void cadastrar_quartos(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      CADASTRAR  QUARTOS                              |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite o número do quarto:  \n");
    printf("\t\t\tDigite a quantidade de camas:  \n");
    printf("\t\t\tDigite se possui banheiro:  \n");
    printf("\t\t\tDigite o status do quarto:  \n");
    printf("\t\t\tDigite o valor do quarto per noite:  \n");
    printf("\t\t\tDigite o valor do quarto para 24h completas:  \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void procurar_quartos(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      PROCURAR QUARTO                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite o número do quarto:  \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void listar_quartos(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      TODOS OS QUARTOS                                |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void atualizar_quartos(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      ATUALIZAR  QUARTOS                              |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite a quantidade de camas:  \n");
    printf("\t\t\tDigite o valor do quarto per noite:  \n");
    printf("\t\t\tDigite o valor do quarto para 24h completas:  \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
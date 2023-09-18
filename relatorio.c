#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include "relatorio.h"

char relatorio(){
    char op2;
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                         RELATÓRIO                                    |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         0- Sair                                      |\n");
    printf("|                         1- Consultar quartos disponíveis             |\n");
    printf("|                         2- Check-in                                  |\n");
    printf("|                         3- Check-out                                 |\n");
    printf("|                         4- Preços                                    |\n");
    printf("|                         5- Relatório Geral                           |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite sua escolha:  ");
    scanf("%c", &op2);
    printf("------------------------------------------------------------------------\n");
    return op2;
}
void quartos_disponiveis(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                       QUARTOS DISPONÍVEIS                                |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void check_in(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                             CHECK-IN                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void check_out(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                            CHECK-OUT                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void relatorio_geral(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                        RELATÓRIO GERAL                               |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void precos(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                        TABELA DE PREÇOS                              |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
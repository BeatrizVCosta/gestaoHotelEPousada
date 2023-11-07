#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include "atendimento.h"

char atendimento(){
    char op2;
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                          ATENDIMENTO                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         0- Sair                                      |\n");
    printf("|                         1- Check-in                                  |\n");
    printf("|                         2- Check-out                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite sua escolha:  ");
    scanf("%c", &op2);
    printf("------------------------------------------------------------------------\n");
    return op2;
}
void check_in(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                             CHECK-IN                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    // fazer check in
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
    // fazer check out
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
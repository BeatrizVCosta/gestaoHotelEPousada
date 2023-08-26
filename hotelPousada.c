#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include <locale.h> /* Para a acentua��o*/

    void menu_principal(void);
    void menu_clientes(void);
    void menu_funcionarios(void);
    void menu_quartos(void);
    void sobre(void);

int main(void){
    setlocale(LC_ALL, "Portuguese_Brazil");
    menu_principal();
    sobre();
    menu_clientes();
    menu_funcionarios();
    menu_quartos();
    return 0;
}
void menu_principal(void){
    system("clear||cls");
    printf("------------------------------\n");
    printf("-------------MENU-------------\n");
    printf("------------------------------\n");
    printf("|       0- Sair               |\n");
    printf("|       1- Clientes           |\n");
    printf("|       2- Funcion�rios       |\n");
    printf("|       3- Quartos            |\n");
    printf("-------------------------------\n");
    system("PAUSE");
}
void sobre(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("------------------Gest�o de hot�is e pousadas---------------------------\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         UFRN | Caic�                                 |\n");
    printf("|              Disciplina DCT1106 -- Programa��o                       |\n");
    printf("|                   Dev: Beatriz Vit�ria da Costa                      |\n");
    printf("|              Professor: Flavius Gorg�nio                             |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|   Sistema de gest�o para hot�is e pousadas, para ser utilizado no    |\n");
    printf("| gerenciamento de clientes,funcion�rios e quartos do estabelecimento. |\n");
    printf("|              PROJETO EM DESENVOLVIMENTO                              |\n");
    printf("-------------------------------------------------------------------------\n");
    system("PAUSE");
}
void menu_clientes(void){
    system("clear||cls");
    printf("------------------------------\n");
    printf("----------CLIENTES------------\n");
    printf("------------------------------\n");
    printf("|       0- Sair               |\n");
    printf("|       1- Listar             |\n");
    printf("|       2- Procurar           |\n");
    printf("|       3- Cadastrar          |\n");
    printf("|       3- Remover            |\n");
    printf("-------------------------------\n");
    system("PAUSE");
}
void menu_funcionarios(void){
    system("clear||cls");
    printf("------------------------------\n");
    printf("---------FUNCION�RIOS---------\n");
    printf("------------------------------\n");
    printf("|       0- Sair               |\n");
    printf("|       1- Listar             |\n");
    printf("|       2- Procurar           |\n");
    printf("|       3- Cadastrar          |\n");
    printf("|       3- Remover            |\n");
    printf("-------------------------------\n");
    system("PAUSE");
}
void menu_quartos(void){
    system("clear||cls");
    printf("------------------------------\n");
    printf("----------QUARTOS-------------\n");
    printf("------------------------------\n");
    printf("|       0- Sair               |\n");
    printf("|       1- Listar             |\n");
    printf("|       2- Procurar           |\n");
    printf("|       3- Cadastrar          |\n");
    printf("|       3- Remover            |\n");
    printf("-------------------------------\n");
    system("PAUSE");
}
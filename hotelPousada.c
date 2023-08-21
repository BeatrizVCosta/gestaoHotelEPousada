#include <stdio.h>

    void menu_principal(void);
    void menu_clientes(void);
    void menu_funcionarios(void);
    void menu_quartos(void);
    void sobre(void);

int main(void){
    menu_principal();
    sobre();
    menu_clientes();
    menu_funcionarios();
    menu_quartos();
    return 0;
}
void menu_principal(void){
    printf("------------------------------\n");
    printf("-------------MENU-------------\n");
    printf("------------------------------\n");
    printf("|       0- Sair               |\n");
    printf("|       1- Clientes           |\n");
    printf("|       2- Funcionarios       |\n");
    printf("|       3- Quartos            |\n");
    printf("-------------------------------\n");
}
void sobre(void){
    printf("------------------------------------------------------------------------\n");
    printf("------------------Gestao de hoteis e pousadas---------------------------\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         UFRN | Caico                                 |\n");
    printf("|              Disciplina DCT1106 -- Programacao                       |\n");
    printf("|                   Dev: Beatriz Vitoria da Costa                      |\n");
    printf("|              Professor: Flavius Gorgônio                             |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|              Sistema de gestao para hoteis e pousadas                |\n ");
    printf("| Para ser utilizado no gerenciamento de clientes,funcionarios e quartos do estabelecimento.|\n");
    printf("|              PROJETO EM DESENVOLVIMENTO                             |\n");
    printf("-------------------------------------------------------------------------\n");
}
void menu_clientes(void){
    printf("------------------------------\n");
    printf("----------CLIENTES------------\n");
    printf("------------------------------\n");
    printf("|       0- Sair               |\n");
    printf("|       1- Listar             |\n");
    printf("|       2- Procurar           |\n");
    printf("|       3- Cadastrar          |\n");
    printf("|       3- Remover            |\n");
    printf("-------------------------------\n");
}
void menu_funcionarios(void){
    printf("------------------------------\n");
    printf("---------FUNCIONARIOS---------\n");
    printf("------------------------------\n");
    printf("|       0- Sair               |\n");
    printf("|       1- Listar             |\n");
    printf("|       2- Procurar           |\n");
    printf("|       3- Cadastrar          |\n");
    printf("|       3- Remover            |\n");
    printf("-------------------------------\n");
}
void menu_quartos(void){
    printf("------------------------------\n");
    printf("----------QUARTOS-------------\n");
    printf("------------------------------\n");
    printf("|       0- Sair               |\n");
    printf("|       1- Listar             |\n");
    printf("|       2- Procurar           |\n");
    printf("|       3- Cadastrar          |\n");
    printf("|       3- Remover            |\n");
    printf("-------------------------------\n");
}
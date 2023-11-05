#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include "cliente.h"
#include "validacao.h"


char menu_clientes(){
    char op2;
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                             CLIENTES                                 |\n");
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
void cadastrar_clientes(void){
    system("clear||cls");
    Cliente *cli = (Cliente*) malloc(sizeof(Cliente)); 
    printf("------------------------------------------------------------------------\n");
    printf("|                      CADASTRAR  CLIENTES                             |\n");
    printf("------------------------------------------------------------------------\n");
    ler_nome(cli->nome);
    // ler_data(cli->dia,cli->mes,cli->ano);
    ler_email(cli->email);
    ler_cpf(cli->CPF);
    printf("------------------------------------------------------------------------\n");
    grava_cliente(cli);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
    
}
void grava_cliente(Cliente* cli) //.h
{
    FILE* fp;
    fp = fopen("clientes.dat", "ab");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Nao e possivel continuar este programa...\n");
        exit(1);
    }
    fwrite(cli, sizeof(Cliente), 1, fp);
    fclose(fp);
    printf("|\t\t\tCliente cadastrado com sucesso.\t\t\t|\n");
}

void procurar_clientes(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      PROCURAR CLIENTE                               |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite o nome do cliente:  \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void listar_clientes(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      TODOS OS CLIENTES                               |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void atualizar_clientes(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      ATUALIZAR CLIENTES                              |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite o status do cliente:  \n");
    // colocar se o cliente foi banido do hotel
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void deletar_clientes(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DELETAR CLIENTES                                |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}

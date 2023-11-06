#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include "funcionario.h"
#include "validacao.h"

char menu_funcionarios(){
    char op2;
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                           FUNCIONARIOS                               |\n");
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
void cadastrar_funcionarios(void){
    system("clear||cls");
    Funcionario *fun = (Funcionario*) malloc(sizeof(Funcionario));
    printf("------------------------------------------------------------------------\n");
    printf("|                      CADASTRAR  FUNCIONARIOS                         |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    ler_nome(fun->nome);
    ler_email(fun->email);
    ler_cpf(fun->CPF);
    ler_cargo(fun->cargo);
    fun->status='A';
    printf("------------------------------------------------------------------------\n");
    grava_funcionario(fun);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}
void grava_funcionario(Funcionario* fun) //.h
{
    FILE* fp;
    fp = fopen("funconario.dat", "ab");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Nao e possivel continuar este programa...\n");
        exit(1);
    }
    fwrite(fun, sizeof(Funcionario), 1, fp);
    fclose(fp);
    printf("|\t\tFuncionario cadastrado com sucesso!\t\t\t|\n|\n");
    printf("|\t\tNome: %s", fun->nome);
    printf("|\t\tE-mail: %s", fun->email);
    printf("|\t\tCPF: %s", fun->CPF);
    printf("|\t\tCargo: %s", fun->cargo);
    printf("|\t\tstatus: %c\n", fun->status);
}
void procurar_funcionarios(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      PROCURAR FUNCIONARIO                            |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite o nome do funcionário:  \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void listar_funcionarios(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      TODOS OS FUNCIONARIOS                           |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void atualizar_funcionarios(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      ATUALIZAR FUNCIONARIOS                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite o status do funcionário:  \n");
    // atualizar se ele ainda trabalha para a empresa ou nao
    printf("\t\t\tDigite o novo cargo do funcionário  \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void deletar_funcionarios(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DELETAR FUNCIONARIO                             |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
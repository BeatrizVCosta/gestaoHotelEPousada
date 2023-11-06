#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include <string.h>
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
    fp = fopen("funcionario.dat", "ab");
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
    printf("|\t\tStatus: %c\n", fun->status);
}
void exibe_funcionario(Funcionario* fun) {
  char situacao[13];
  if ((fun == NULL) || (fun->status == 'D')) {
    printf("\n\t\tFuncionario Inexistente\n");
  } else {
    printf("\n\t\tFuncionario Encontrado\n");
    printf("Nome: %s\n", fun->nome);
    printf("E-mail: %s\n", fun->email);
    printf("CPF: %s\n", fun->CPF);
    printf("Cargo: %s\n", fun->cargo);
    if (fun->status == 'A') {
      strcpy(situacao, "Ativado");
    } else if (fun->status == 'D') {
      strcpy(situacao, "Desativado");
    } else {
      strcpy(situacao, "Inexistente");
    }
    printf("Situacao do funcionario: %s\n", situacao);
  }
}
void procurar_funcionarios(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      PROCURAR FUNCIONARIO                            |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\tDigite o nome do funcionario:  \n");
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void listar_funcionarios(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      TODOS OS FUNCIONARIOS                           |\n");
    printf("------------------------------------------------------------------------\n");
    listar_fun();
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void listar_fun(void) {
  FILE* fp;
  Funcionario* fun; 
  fun = (Funcionario*) malloc(sizeof(Funcionario));
  fp = fopen("funcionario.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Nao e possivel continuar este programa...\n");
    exit(1);
  }
  while(fread(fun, sizeof(Funcionario), 1, fp)) {
    if (fun->status != 'D') {
      exibe_funcionario(fun);
      printf("------------------------------------------------------------------------\n");
    }
  }
  fclose(fp);
  free(fun);
}
void atualizar_funcionarios(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      ATUALIZAR FUNCIONARIOS                          |\n");
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
#include <stdio.h>/* Para o printf */
#include <string.h>
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
    cli->status='A';
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
    printf("|\t\tCliente cadastrado com sucesso!\t\t\t\t|\n|\n");
    printf("|\t\tNome: %s", cli->nome);
    printf("|\t\tE-mail: %s", cli->email);
    printf("|\t\tCPF: %s", cli->CPF);
    printf("|\t\tStatus: %c\n", cli->status);

}

void procurar_clientes(void){
    system("clear||cls");
    Cliente* cli;
    printf("------------------------------------------------------------------------\n");
    printf("|                      PROCURAR CLIENTE                               |\n");
    printf("------------------------------------------------------------------------\n");
    cli=busca_cliente();
    exibe_cliente(cli);
    free(cli);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}
Cliente* busca_cliente(void) {
  FILE* fp;
  Cliente* cli;
  char nome[100];
  printf("\t\tDigite o nome do cliente:  ");
  fflush(stdin);
  fgets(nome, 100, stdin);
  cli = (Cliente*) malloc(sizeof(Cliente));
  fp = fopen("clientes.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Nao e possivel continuar este programa...\n");
    exit(1);
  }
  while(!feof(fp)) {
    fread(cli, sizeof(Cliente), 1, fp);
    if ((cli->nome == nome) && (cli->status != 'A')) {
      fclose(fp);
      return cli;
    }
  }
  fclose(fp);
  return NULL;
}
void exibe_cliente(Cliente* cli) {
  char situacao[13];
  if ((cli == NULL) || (cli->status == 'D')) {
    printf("\n\t\tCliente Inexistente\n");
  } else {
    printf("\n\t\tCliente Encontrado\n");
    printf("Nome: %s\n", cli->nome);
    printf("E-mail: %s\n", cli->email);
    printf("CPF: %s\n", cli->CPF);
    if (cli->status == 'A') {
      strcpy(situacao, "Ativado");
    } else if (cli->status == 'D') {
      strcpy(situacao, "Desativado");
    } else {
      strcpy(situacao, "Inexistente");
    }
    printf("Situacao do cliente: %s\n", situacao);
  }
}
void listar_clientes(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      TODOS OS CLIENTES                               |\n");
    printf("------------------------------------------------------------------------\n");
    listar_cli();
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void listar_cli(void) {
  FILE* fp;
  Cliente* cli; 
  cli = (Cliente*) malloc(sizeof(Cliente));
  fp = fopen("clientes.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  while(fread(cli, sizeof(Cliente), 1, fp)) {
    if (cli->status != 'D') {
      exibe_cliente(cli);
      printf("------------------------------------------------------------------------\n");
    }
  }
  fclose(fp);
  free(cli);
}
void atualizar_clientes(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      ATUALIZAR CLIENTES                              |\n");
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

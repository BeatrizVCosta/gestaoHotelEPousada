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
    getchar();getchar();
    
}
void grava_cliente(Cliente* cli){
    FILE* fc;
    fc = fopen("clientes.dat", "ab");
    if (fc == NULL) 
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Nao e possivel continuar este programa...\n");
        getchar();
    }
    fwrite(cli, sizeof(Cliente), 1, fc);
    fclose(fc);
    printf("|\t\tCliente cadastrado com sucesso!\t\t\t\t|\n|\n");
    printf("|\t\tNome: %s\n", cli->nome);
    printf("|\t\tE-mail: %s\n", cli->email);
    printf("|\t\tCPF: %s\n", cli->CPF);
    // printf("|\t\tdata: %n/%n/%n\n", cli->dia,cli->mes,cli->ano);
    printf("|\t\tStatus: %c\n", cli->status);

}

void procurar_clientes(void){
    system("clear||cls");
    Cliente* cli;
    printf("------------------------------------------------------------------------\n");
    printf("|                      PROCURAR CLIENTE                               |\n");
    printf("------------------------------------------------------------------------\n");
    cli=busca_cliente();
    free(cli);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}
Cliente* busca_cliente(void) {
  FILE* fc;
  Cliente* cli;
  char nome[100];
  printf("\t\tDigite o nome do cliente:  ");
  fflush(stdin);
  fgets(nome, 100, stdin);
  cli = (Cliente*) malloc(sizeof(Cliente));
  fc = fopen("clientes.dat", "rb");
  if (fc == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Nao e possivel continuar este programa...\n");
    // exit(1);
    getchar();
  }
  // while(!feof(fc)) {
    // fread(cli, sizeof(Cliente), 1, fc);
  while(fread(cli, sizeof(Cliente), 1, fc)) {
    if ((strcmp(cli->nome, nome)==0) && (cli->status == 'A')) {
      // fclose(fc);
      // return cli;
      exibe_cliente(cli);
    }
  }
  fclose(fc);
  return NULL;
}
void exibe_cliente(Cliente* cli) {
  char situacao[13];
  if ((cli == NULL) || (cli->status == 'D')) {
    printf("\n\t\tCliente Inexistente\n");
  } else {
    printf("\n\t\tCliente Encontrado\n");
    printf("Nome: %s\n", cli->nome);
    // printf("Data de nascimento: %n/%n/%n\n", cli->dia,cli->mes,cli->ano);
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
  FILE* fc;
  Cliente* cli; 
  cli = (Cliente*) malloc(sizeof(Cliente));
  fc = fopen("clientes.dat", "rb");
  if (fc == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  while(fread(cli, sizeof(Cliente), 1, fc)) {
    if (cli->status != 'D') {
      exibe_cliente(cli);
      printf("------------------------------------------------------------------------\n");
    }
  }
  fclose(fc);
  free(cli);
}
void atualizar_clientes(void){
    system("clear||cls");
    char nome[100];
    printf("------------------------------------------------------------------------\n");
    printf("|                      ATUALIZAR CLIENTES                              |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\tDigite o nome do cliente que deseja atualizar  \n");
    ler_nome(nome);
    att_cliente(nome);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void deletar_clientes(void){
    system("clear||cls");
    char nome[100];
    printf("------------------------------------------------------------------------\n");
    printf("|                      DELETAR CLIENTES                                |\n");
    printf("------------------------------------------------------------------------\n");
    ler_nome(nome);
    delete_cliente(nome);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void delete_cliente(char *nome){
  FILE* fc;
  Cliente* cli;
  int encontra=0;
  int esc;
  cli=(Cliente*)malloc(sizeof(Cliente));
  fc=fopen("clientes.dat","r+b");
  if (fc==NULL){
    printf("Nenhum cliente cadastrado!");
    return;
  }
  if (fc==NULL){
    printf("Nenhum cliente cadastrado!");
    return;
  }
  while (fread(cli, sizeof(Cliente), 1, fc)) {
    if ((strcmp(cli->nome, nome) == 0) && (cli->status == 'A')){
      encontra=1;
        while(esc!=0){
          system("clear||cls");
          printf("------------------------------------------------------------------------\n");
          printf("|                      DELETAR CLIENTES                              |\n");
          printf("------------------------------------------------------------------------\n");
          printf("                 Dados do cliente:\n");
          printf("\t\tNome do cliente:%s\n",cli->nome);
          printf("\t\tEmail do cliente:%s\n",cli->email);
          printf("\t\tCPF do cliente:%s\n",cli->CPF);
          printf("\n");
          printf("|                Digite [1] para deletar o cliente                     |\n");
          printf("|                Digite [0] para sair                                  |\n");
          printf("------------------------------------------------------------------------\n");
          printf("\t\tConfirmar:");
          fflush(stdin);
          scanf("%d",&esc);
          fflush(stdin);
          switch (esc){
            case 1:
              cli->status='D';
              printf("\t\tCliente deletado com sucesso!");
              printf("\t\nDigite enter para continuar...");getchar();
              esc=0;
              break;
            case 0:
              esc=0;
              break;
            default:
              printf("\t\nOpção Inválida!\n");
              printf("\tDigite enter para continuar...");getchar(); 
              break;
            }
            fseek(fc, -1 * (long)sizeof(Cliente), SEEK_CUR);
            fwrite(cli, sizeof(Cliente), 1, fc);
          }break;
      }
  }
  if (!encontra){
    printf("Cliente não encontrado!");
  }
  fclose(fc);
  free(cli);
}
//função adaptada de Matheus Diniz
void att_cliente(char *nome){
  FILE* fc;
  Cliente* cli;
  int encontra=0;
  int esc;
  cli=(Cliente*)malloc(sizeof(Cliente));
  fc=fopen("clientes.dat","r+b");
  if (fc==NULL){
    printf("Nenhum cliente cadastrado!");
    return;
  }
  while (fread(cli, sizeof(Cliente), 1, fc)) {
    if ((strcmp(cli->nome, nome) == 0) && (cli->status == 'A')){
      encontra=1;
        while(esc!=0){
          system("clear||cls");
          printf("------------------------------------------------------------------------\n");
          printf("|                      ATUALIZAR CLIENTES                              |\n");
          printf("------------------------------------------------------------------------\n");
          printf("                 Dados do cliente:\n");
          printf("\t\tNome do cliente:%s\n",cli->nome);
          printf("\t\tEmail do cliente:%s\n",cli->email);
          printf("\t\tCPF do cliente:%s\n",cli->CPF);
          printf("\n");
          printf("|                Digite [1] para alterar o email                       |\n");
          printf("|                Digite [2] para alterar o nome                        |\n");
          printf("|                Digite [0] para sair                                  |\n");
          printf("------------------------------------------------------------------------\n");
          printf("O que deseja fazer?");
          fflush(stdin);
          scanf("%d",&esc);
          fflush(stdin);
          switch (esc){
            case 1:
              ler_email(cli->email);
              printf("\tEmail atualizado com sucesso!");
              printf("\nDigite enter para continuar...");getchar();
              break;
            case 2:
              ler_nome(cli->nome);
              printf("\tNome atualizado com sucesso!");
              printf("\nDigite enter para continuar...");getchar();
            case 0:
              esc=0;
              break;
            default:
              printf("\nOpção Inválida!\n");
              printf("Digite enter para continuar...");getchar(); 
              break;
            }
            fseek(fc, -1 * (long)sizeof(Cliente), SEEK_CUR);
            fwrite(cli, sizeof(Cliente), 1, fc);
          }break;
      }
  }
  if (!encontra){
    printf("Cliente não encontrado!");
  }
  fclose(fc);
  free(cli);
}
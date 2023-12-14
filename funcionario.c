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
    getchar();
    fflush(stdin);
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
void grava_funcionario(Funcionario* fun){
    FILE* fp;
    fp = fopen("funcionario.dat", "ab");
    if (fp == NULL) 
    {
        printf("\tOps! Ocorreu um erro na abertura do arquivo!\n");
        printf("\tNao e possivel continuar este programa...\n");
        getchar();
    }
    fwrite(fun, sizeof(Funcionario), 1, fp);
    fclose(fp);
    printf("|\t\tFuncionario cadastrado com sucesso!\t\t\t|\n|\n");
    printf("|\t\tNome: %s\n", fun->nome);
    printf("|\t\tE-mail: %s\n", fun->email);
    printf("|\t\tCPF: %s\n", fun->CPF);
    printf("|\t\tCargo: %s\n", fun->cargo);
    printf("|\t\tStatus: %c\n", fun->status);
}
void exibe_funcionario(Funcionario* fun) {
  char situacao[13];
  if ((fun == NULL) || (fun->status == 'D')) {
    printf("\n\t\tFuncionario Inexistente\n");
  } else {
    printf("\n\t\tFuncionario Encontrado\n");
    printf("Nome: %s", fun->nome);
    printf("E-mail: %s", fun->email);
    printf("CPF: %s\n", fun->CPF);
    printf("Cargo: %s", fun->cargo);
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
    Funcionario* fun;
    printf("------------------------------------------------------------------------\n");
    printf("|                      PROCURAR FUNCIONARIO                            |\n");
    printf("------------------------------------------------------------------------\n");
    fun=busca_funcionario();
    free(fun);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}
Funcionario* busca_funcionario(void) {
  FILE* fp;
  Funcionario* fun;
  char nome[100];
  printf("\t\tDigite o nome do funcionario:  ");
  fflush(stdin);
  fgets(nome, 100, stdin);
  fun = (Funcionario*) malloc(sizeof(Funcionario));
  fp = fopen("funcionario.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Nao e possivel continuar este programa...\n");
    getchar();
    return;
  }
  // while(!feof(fp)) {
  //   fread(fun, sizeof(Funcionario), 1, fp);
    while(fread(fun, sizeof(Funcionario), 1, fp)){
    if ((strcmp(fun->nome, nome)==0) && (fun->status == 'A')) {
      // fclose(fp);
      // return fun;
      exibe_funcionario(fun);
    }
  }
  fclose(fp);
  return NULL;
}
void listar_funcionarios(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      TODOS OS FUNCIONARIOS                           |\n");
    printf("------------------------------------------------------------------------\n");
    printf("| Nome do funcionario            |    CPF do funcionario               |\n");
    printf("------------------------------------------------------------------------\n");
    listar_fun();
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void exibe_funcionarioT(Funcionario* fun) {
  if ((fun == NULL) || (fun->status == 'D')) {
    printf("------------------------------------------------------------------------\n");
    printf("|                       Cliente Inexistente                        |\n");
    printf("------------------------------------------------------------------------\n");
  } else {   
    char nome[100];
    strncpy (nome,fun->nome,strlen(fun->nome));
    for (int i = 0; i < 100; i++){
      if (nome[i]=='\n'){
        nome[i]='\0';
      }  
    }
    printf("|----------------------------------------------------------------------|\n");
    printf("| %-27s    | %-31s     |\n",nome, fun->CPF);
  }
}
void listar_fun(void) {
  FILE* fp;
  Funcionario* fun; 
  fun = (Funcionario*) malloc(sizeof(Funcionario));
  fp = fopen("funcionario.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Nao e possivel continuar este programa...\n");
    getchar();
    return;
  }
  while(fread(fun, sizeof(Funcionario), 1, fp)) {
    if (fun->status != 'D') {
      exibe_funcionarioT(fun);
    }
  }
  fclose(fp);
  free(fun);
}
void atualizar_funcionarios(void){
    system("clear||cls");
    char nome[100];
    printf("------------------------------------------------------------------------\n");
    printf("|                      ATUALIZAR FUNCIONARIOS                          |\n");
    printf("------------------------------------------------------------------------\n");
    ler_nome(nome);
    att_funcionario(nome);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}
void att_funcionario(char *nome){
  FILE* fp;
  Funcionario* fun;
  int encontra=0;
  int esc;
  fun=(Funcionario*)malloc(sizeof(Funcionario));
  fp=fopen("funcionario.dat","r+b");
  if (fp==NULL){
    printf("\tNenhum funcionario cadastrado!");
    return;
  }
  if (fp==NULL){
    printf("\tNenhum funcionario cadastrado!");
    return;
  }
  while (fread(fun, sizeof(Funcionario), 1, fp)) {
    if ((strcmp(fun->nome, nome) == 0) && (fun->status == 'A')){
      encontra=1;
        while(esc!=0){
          system("clear||cls");
          printf("------------------------------------------------------------------------\n");
          printf("|                      ATUALIZAR FUNCIONARIO                             |\n");
          printf("------------------------------------------------------------------------\n");
          printf("                 Dados do funcionario:\n");
          printf("\t\tNome do funcionario:%s",fun->nome);
          printf("\t\tEmail do funcionario:%s",fun->email);
          printf("\t\tCPF do funcionario:%s\n",fun->CPF);
          printf("\t\tCargo do funcionario:%s\n",fun->cargo);
          printf("\n");
          printf("|                Digite [1] para atualizar o email                     |\n");
          printf("|                Digite [2] para atualizar o nome                      |\n");
          printf("|                Digite [0] para sair                                  |\n");
          printf("------------------------------------------------------------------------\n");
          printf("\t\tConfirmar:");
          fflush(stdin);
          scanf("%d",&esc);
          getchar();
          fflush(stdin);
          switch (esc){
            case 1:
              ler_email(fun->email);
              printf("\t\tEmail atualizado com sucesso!");
              printf("\t\nDigite enter para continuar...");getchar();
              break;
            case 2:
              ler_nome(fun->nome);
              printf("\t\tNome atualizado com sucesso!");
              printf("\t\nDigite enter para continuar...");getchar();
              break;
            case 0:
              esc=0;
              break;
            default:
              printf("\t\nOpção Inválida!\n");
              printf("\tDigite enter para continuar...");getchar(); 
              break;
            }
            fseek(fp, -1 * (long)sizeof(Funcionario), SEEK_CUR);
            fwrite(fun, sizeof(Funcionario), 1, fp);
          }break;
      }
  }
  if (!encontra){
    printf("Funcionario não encontrado!");
  }
  fclose(fp);
  free(fun);
}

void deletar_funcionarios(void){
    system("clear||cls");
    char nome[100];
    printf("------------------------------------------------------------------------\n");
    printf("|                      DELETAR FUNCIONARIO                             |\n");
    printf("------------------------------------------------------------------------\n");
    ler_nome(nome);
    delete_funcionario(nome);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}

void delete_funcionario(char *nome){
  FILE* fp;
  Funcionario* fun;
  int encontra=0;
  int esc;
  fun=(Funcionario*)malloc(sizeof(Funcionario));
  fp=fopen("funcionario.dat","r+b");
  if (fp==NULL){
    printf("\tNenhum funcionario cadastrado!");
    return;
  }
  if (fp==NULL){
    printf("\tNenhum funcionario cadastrado!");
    return;
  }
  while (fread(fun, sizeof(Funcionario), 1, fp)) {
    if ((strcmp(fun->nome, nome) == 0) && (fun->status == 'A')){
      encontra=1;
        while(esc!=0){
          system("clear||cls");
          printf("------------------------------------------------------------------------\n");
          printf("|                      DELETAR FUNCIONARIO                             |\n");
          printf("------------------------------------------------------------------------\n");
          printf("                 Dados do funcionario:\n");
          printf("\t\tNome do funcionario:%s\n",fun->nome);
          printf("\t\tEmail do funcionario:%s\n",fun->email);
          printf("\t\tCPF do funcionario:%s\n",fun->CPF);
          printf("\t\tCargo do funcionario:%s\n",fun->cargo);
          printf("\n");
          printf("|                Digite [1] para deletar o funcionario                     |\n");
          printf("|                Digite [0] para sair                                  |\n");
          printf("------------------------------------------------------------------------\n");
          printf("\t\tConfirmar:");
          fflush(stdin);
          scanf("%d",&esc);
          getchar();
          fflush(stdin);
          switch (esc){
            case 1:
              fun->status='D';
              printf("\t\tFuncionario deletado com sucesso!");
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
            fseek(fp, -1 * (long)sizeof(Funcionario), SEEK_CUR);
            fwrite(fun, sizeof(Funcionario), 1, fp);
          }break;
      }
  }
  if (!encontra){
    printf("Funcionario não encontrado!");
  }
  fclose(fp);
  free(fun);
}

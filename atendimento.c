#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include <string.h>
#include <stdbool.h>
#include "atendimento.h"
#include "validacao.h"
#include "cliente.h"
#include "quartos.h"
#include "funcionario.h"

char atendimento(){
    char op2;
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                          ATENDIMENTO                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         0- Sair                                      |\n");
    printf("|                         1- Check-in                                  |\n");
    // printf("|                         2- Pesquisar Check-in                        |\n");
    printf("|                         2- Check-out                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite sua escolha:  ");
    scanf("%c", &op2);
    printf("------------------------------------------------------------------------\n");
    return op2;
}
void check_in(void){
    bool v = true, f = false;
    Atendimento *ate = (Atendimento*) malloc(sizeof(Atendimento));
    FILE *fc;
    fc=fopen("clientes.dat","rb");
    if(fc==NULL){   
        printf("------------------------------------------------------------------------\n");
        printf("|                     Nenhum cliente cadastrado!                       |\n");
        printf("------------------------------------------------------------------------\n");
        getchar();getchar();
        return;
    }
    FILE *fq;
    fq=fopen("quartos.dat","rb");
    if(fq==NULL){   
        printf("------------------------------------------------------------------------\n");
        printf("|                     Nenhum quarto cadastrado!                        |\n");
        printf("------------------------------------------------------------------------\n");
        getchar();getchar();
        return;
    }
    FILE *fp;
    fp=fopen("funcionario.dat","rb");
    if(fp==NULL){   
        printf("------------------------------------------------------------------------\n");
        printf("|                     Nenhum funcionario cadastrado!                   |\n");
        printf("------------------------------------------------------------------------\n");
        getchar();getchar();
        return;
    }
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                             CHECK-IN                                 |\n");
    printf("------------------------------------------------------------------------\n");
    //verifica se o cpf digitado esta nos clientes registrados
    while(v){
        printf("\t\tDigite os dados do cliente\n");
        ler_cpf(ate->CPF);
        ler_nome(ate->nome);
        if(busca_cliente_existe(ate->CPF,ate->nome)==1){
             v=f;
        }else{
            printf("------------------------------------------------------------------------\n");
            printf("|                     Cliente nao existente!                            |\n");
            printf("------------------------------------------------------------------------\n");
        }
    }
    //verificar se o numero e tipo digitado esta nos quartos registrados
    v = true, f = false;
    while(v){
        printf("\t\tDigite os dados do quarto\n");
        ler_numero(ate->numero);
        ler_tipo(ate->tipo);
        if(busca_quarto_existe(ate->numero,ate->tipo)==1){
             v=f;
        }else{
            printf("------------------------------------------------------------------------\n");
            printf("|                     Quarto nao existente!                            |\n");
            printf("------------------------------------------------------------------------\n");
        }
    }
    //verificar se os dados do funcionario estão cadastrados
    v = true, f = false;
    while(v){
        printf("\t\tDigite os dados do funcionario que realizou o check-in\n");
        ler_cpf(ate->CPF_fun);
        ler_nome(ate->nome_fun);
        if(busca_funcionario_existe(ate->CPF_fun,ate->nome_fun)==1){
             v=f;
        }else{
            printf("------------------------------------------------------------------------\n");
            printf("|                     Funcionario nao existente!                       |\n");
            printf("------------------------------------------------------------------------\n");
        }
    }
    //salvando o status como ativado
    ate->status='A';
    //salva as informações do struct
    printf("------------------------------------------------------------------------\n");
    grava_atendimento(ate);
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
void grava_atendimento(Atendimento* ate){
    FILE* fa;
    fa = fopen("atendimentos.dat", "ab");
    if (fa == NULL) 
    {
        printf("\tOps! Ocorreu um erro na abertura do arquivo!\n");
        printf("\tNao e possivel continuar este programa...\n");
        getchar();
    }
    fwrite(ate, sizeof(Atendimento), 1, fa);
    fclose(fa);
    printf("|                 Check-in cadastrado com sucesso!                     |\n|\n");
    printf("|\t\tStatus: %c\n", ate->status);
    printf("------------------------------------------------------------------------\n");
    printf("|                         Dados do cliente                             |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|\t\tNome: %s\n", ate->nome);
    printf("|\t\tCPF: %s\n", ate->CPF);
    printf("------------------------------------------------------------------------\n");
    printf("|                          Dados do quarto                             |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|\t\tNumero: %s\n", ate->numero);
    printf("|\t\tTipo: %s\n", ate->tipo);
    printf("------------------------------------------------------------------------\n");
    printf("|                Dados do funcionario que realizou o check-in          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|\t\tNome: %s\n", ate->nome_fun);
    printf("|\t\tCPF: %s\n", ate->CPF_fun);

}


void exibe_atendimento(Atendimento* ate) {
  char situacao[13];
  if ((ate == NULL) || (ate->status == 'D')) {
    printf("------------------------------------------------------------------------\n");
    printf("|                       Atendimento Inexistente                        |\n");
    printf("------------------------------------------------------------------------\n");
  } else {
    printf("------------------------------------------------------------------------\n");
    printf("|                       Atendimento Encontrado                         |\n");
    printf("------------------------------------------------------------------------\n");
    if (ate->status == 'A') {
      strcpy(situacao, "Ativado");
    } else if (ate->status == 'D') {
      strcpy(situacao, "Desativado");
    } else {
      strcpy(situacao, "Inexistente");
    }
    printf("\t\tSituacao do Atendimento: %s\n", situacao);
    printf("------------------------------------------------------------------------\n");
    printf("|                         Dados do cliente                             |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|\t\tNome: %s\n", ate->nome);
    printf("|\t\tCPF: %s\n", ate->CPF);
    printf("------------------------------------------------------------------------\n");
    printf("|                          Dados do quarto                             |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|\t\tNumero: %s\n", ate->numero);
    printf("|\t\tTipo: %s\n", ate->tipo);
    printf("------------------------------------------------------------------------\n");
  }
}

int busca_cliente_existe(char cpf[], char nome[]) {
  FILE* fc;
  Cliente* cli;
  int encontrado=0;
  cli = (Cliente*) malloc(sizeof(Cliente));
  fc = fopen("clientes.dat", "rb");
  if (fc == NULL) {
    printf("\tOps! Ocorreu um erro na abertura do arquivo!\n");
    printf("\tNao e possivel continuar este programa...\n");
    return 0;
  }
  while(fread(cli, sizeof(Cliente), 1, fc)) {
    if ((strcmp(cli->nome, nome)==0) && (cli->status == 'A') && (strcmp(cli->CPF, cpf)==0)) {
       encontrado=1;
       return 1;
    }
  }
  if(!encontrado){
    return 0;
  }
  fclose(fc);
  free(cli);
  return 0;
}

int busca_quarto_existe(char numero[], char tipo[]) {
  FILE* fq;
  Quarto* qua;
  int encontrado=0;
  qua = (Quarto*) malloc(sizeof(Quarto));
  fq = fopen("quartos.dat", "rb");
  if (fq == NULL) {
    printf("\tOps! Ocorreu um erro na abertura do arquivo!\n");
    printf("\tNao e possivel continuar este programa...\n");
    return 0;
  }
  while(fread(qua, sizeof(Quarto), 1, fq)) {
    if ((strcmp(qua->numero, numero)==0) && (qua->status == 'A') && (strcmp(qua->tipo, tipo)==0)) {
       encontrado=1;
       return 1;
    }
  }
  if(!encontrado){ 
    printf("------------------------------------------------------------------------\n");
    printf("|                     Quarto nao existente!                            |\n");
    printf("------------------------------------------------------------------------\n");
    return 0;
  }
  fclose(fq);
  free(qua);
  return 0;
}

int busca_funcionario_existe(char cpf[], char nome[]) {
  FILE* fp;
  Funcionario* fun;
  int encontrado=0;
  fun = (Funcionario*) malloc(sizeof(Funcionario));
  fp = fopen("funcionario.dat", "rb");
  if (fp == NULL) {
    printf("\tOps! Ocorreu um erro na abertura do arquivo!\n");
    printf("\tNao e possivel continuar este programa...\n");
    return 0;
  }
  while(fread(fun, sizeof(Funcionario), 1, fp)) {
    if ((strcmp(fun->nome, nome)==0) && (fun->status == 'A') && (strcmp(fun->CPF, cpf)==0)) {
       encontrado=1;
       return 1;
    }
  }
  if(!encontrado){
    return 0;
  }
  fclose(fp);
  free(fun);
  return 0;
}

void check_out(void){
    system("clear||cls");
    char cpf[15];
    printf("------------------------------------------------------------------------\n");
    printf("|                            CHECK-OUT                                 |\n");
    printf("------------------------------------------------------------------------\n");
    ler_cpf(cpf);
    delete_atendimento(cpf);

    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}
void delete_atendimento(char *cpf){
  FILE* fa;
  Atendimento* ate;
  int encontra=0;
  int esc;
  ate=(Atendimento*)malloc(sizeof(Atendimento));
  fa=fopen("atendimentos.dat","r+b");
  if (fa==NULL){
    printf("------------------------------------------------------------------------\n");
    printf("|                    Nenhum check-in cadastrado!                       |\n");
    printf("------------------------------------------------------------------------\n");
    return;
  }
  while (fread(ate, sizeof(Atendimento), 1, fa)) {
    if ((strcmp(ate->CPF, cpf) == 0) && (ate->status == 'A')){
      encontra=1;
        while(esc!=0){
          system("clear||cls");
          printf("------------------------------------------------------------------------\n");
          printf("|                          FAZER CHECK-OUT                             |\n");
          printf("------------------------------------------------------------------------\n");
          printf("                 Dados do check-in:\n\n");
          printf("\t\tNome do cliente:%s",ate->nome);
          printf("\t\tCPF do cliente:%s\n",ate->CPF);
          printf("\t\tNumero do quarto:%s",ate->numero);
          printf("\t\tTipo do quarto:%s\n",ate->tipo);
          printf("\n");
          printf("------------------------------------------------------------------------\n");
          printf("|                Digite [1] para deletar o cliente                     |\n");
          printf("|                Digite [0] para sair                                  |\n");
          printf("------------------------------------------------------------------------\n");
          printf("\t\tConfirmar:");
          fflush(stdin);
          scanf("%d",&esc);
          fflush(stdin);
          switch (esc){
            case 1:
              ate->status='D';
              printf("------------------------------------------------------------------------\n");
              printf("|                     Check-out realizado com sucesso!                 |\n");
              printf("------------------------------------------------------------------------\n");
              printf("\t\nDigite enter para continuar...");getchar();
              esc=0;
              break;
            case 0:
              esc=0;
              break;
            default:
              printf("\t\nOpção Invalida!\n");
              printf("\tDigite enter para continuar...");getchar(); 
              break;
            }
            fseek(fa, -1 * (long)sizeof(Atendimento), SEEK_CUR);
            fwrite(ate, sizeof(Atendimento), 1, fa);
          }break;
      }
  }
  if (!encontra){
    printf("------------------------------------------------------------------------\n");
    printf("|                      Check-in nao encontrado                         |\n");
    printf("------------------------------------------------------------------------\n");
    getchar();
  }
  fclose(fa);
  free(ate);
}

// void procurar_cin(void){
//     system("clear||cls");
//     Atendimento* ate;
//     printf("------------------------------------------------------------------------\n");
//     printf("|                       PROCURAR CHECK-IN                              |\n");
//     printf("------------------------------------------------------------------------\n");
//     ate=busca_Atendimento();
//     free(ate); 
//     printf("------------------------------------------------------------------------\n");
//     printf("Pressione qualquer tecla para continuar...\n");
//     getchar();getchar();
// }
// Atendimento* busca_Atendimento(void) {
//   FILE* fa;
//   Atendimento* ate;
//   char cpf[15];
//   printf("\t\tDigite o CPF do cliente:  ");
//   fflush(stdin);
//   fgets(cpf, 15, stdin);
//   printf(cpf);
//   ate = (Atendimento*) malloc(sizeof(Atendimento));
//   fa = fopen("atendimentos.dat", "rb");
//   if (fa == NULL) {
//     printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
//     printf("Nao e possivel continuar este programa...\n");
//     getchar();
//   }
//   while(fread(ate, sizeof(Atendimento), 1, fa)) {
//     if ((strcmp(ate->CPF, cpf)==0) && (ate->status == 'A')) {
//         printf("aaa");
//       exibe_atendimento(ate);
//     }
//   }
//   fclose(fa);
//   return NULL;
// }

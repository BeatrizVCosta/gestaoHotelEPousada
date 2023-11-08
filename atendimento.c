#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include <string.h>
#include <stdbool.h>
#include "atendimento.h"
#include "validacao.h"
#include "cliente.h"

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
    bool v = true, f = false;
    FILE *fc;
    Atendimento *ate = (Atendimento*) malloc(sizeof(Atendimento));
    fc=fopen("clientes.dat","rb");
    if(fc==NULL){
        printf("Nenhum cliente cadastrado!");
        getchar();getchar();
        return;
    }
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                             CHECK-IN                                 |\n");
    printf("------------------------------------------------------------------------\n");
    //verificar se o cpf digitado esta nos clientes registrados
    while(v){
        ler_cpf(ate->CPF);
        ler_nome(ate->nome);
        if(busca_cliente_existe(ate->CPF,ate->nome)==1){
             v=f;
        }else{
            printf("usuário não existente");
        }
    }
    ler_numero(ate->numero);
    ler_tipo(ate->tipo);
    ate->status='A';
    //cadastrar as informações do struct
    // fazer check in
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
    printf("|\t\tCheck-in cadastrado com sucesso!\t\t\t|\n|\n");
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

}

void procurar_cin(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                       PROCURAR CLIENTE                               |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    //procurar cpf nos dados do checkin e exibir 
    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
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
    printf("cliente não cadastrado!");
    return 0;
  }
  fclose(fc);
  free(cli);
  return 0;
}
void check_out(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                            CHECK-OUT                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    // fazer check out
    //deletar o checkin

    printf("------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}
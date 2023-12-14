#include <stdio.h>/* Para o printf */
#include <ctype.h>
#include <string.h>
#include "atendimento.h"
#include "validacao.h"
#include <stdbool.h>

// void limpar_buffer(void){
//   int c;
//   while ((c = getchar()) != '\n' && c != EOF)
//   {
//     // Lê e descarta cada caractere até encontrar uma nova linha ('\n') ou o fim do arquivo (EOF)
//   }
// }
void ler_nome(char* nome){
    int valido;
    do{
        printf("\tDigite o nome:  ");
        fflush(stdin);
        fgets(nome, 100, stdin);
        valido=verifica_nome(nome);
        if (valido==1)
        {
            printf("\tNome invalido!\n");
        }
        
    }while(valido!=0);
    
   
}
void ler_cargo(char* cargo){
    int valido;
    do{
        printf("\tDigite o cargo:  ");
        fflush(stdin);
        fgets(cargo, 100, stdin);
        valido=verifica_nome(cargo);
        if (valido==1)
        {
            printf("\tCargo invalido!\n");
        }
        
    }while(valido!=0);
    
   
}
void ler_numero(char* numero){
    printf("\tDigite o numero do quarto(XXX):  ");
    fflush(stdin);
    fgets(numero, 5, stdin);
   
}
int ler_diaria(void){
    int diaria;
    printf("\tDigite o numero de diarias:  ");
    fflush(stdin);
    scanf("%d", &diaria);
    getchar();
    fflush(stdin);
    return diaria;
}

int ler_valor(char* tipo, int diaria){
    int valor;
    if ((strcmp(tipo, "1")==0)){
        int preco=1200;
        valor=diaria*preco;
        return valor;
    }else if((strcmp(tipo, "2")==0)){
        int preco=800;
        valor=diaria*preco;
        return valor;
    }else if((strcmp(tipo, "3")==0)){
        int preco=500;
        valor=diaria*preco;
        return valor;
    }else{
        return 0;
    }
}
void ler_tipo(char* tipo){
    int t;  
    bool v=true,f=false;
    printf("\t 1-VIP 2-PREMIUM 3-BASICO\n");
    while(v){
        printf("\tDigite o tipo do quarto(1/2/3):");
        fflush(stdin);
        scanf("%[^\n]",tipo);
        getchar();
        fflush(stdin);
        t=verifica_tipo(tipo);
        if (t==1){
            v=f; 
        }else{
            printf("Tipo de quarto não existe\n");
        }
    }
}


int verifica_tipo(char * tipo){
    int tam=strlen(tipo);
    char *t[]={"1","2","3"};
    if (tam!=1){
        return 0;
    }
    for (int i=0; i<3 ;i++){
        if(strcmp(tipo,t[i])==0){
            return 1;
        }
    }
    return 0;
}

int verifica_nome(char* nome) {
    int i, tamanho;
    tamanho = strlen(nome);

    // Verifica se o nome é apenas um '\n'
    if (tamanho == 1 && nome[0] == '\n') {
        return 1;
    }

    for(i = 0; i < tamanho; i++) {
        if(!isalpha(nome[i]) && nome[i] != ' ' && nome[i] != '\n') {
            return 1;
        }
    }
    return 0;
}

void ler_email(char* email){
    int valido;
    do{
        printf("\tDigite o email:  ");
        fflush(stdin);
        fgets(email, 255, stdin);
        valido=verifica_email(email);
        if (valido==1)
        {
            printf("\tEmail invalida!\n");
        }
        
    }while(valido!=0);
}
//Função feita por Flavius gorgonio
int verifica_email(char* email){
  int tam=strlen(email);
  int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;
  for (i = 0; i < tam; i++) {
    char c = email[i];
    if(c == '@') {
      if (arroba)
         break; // não pode ter uma segunda @
      arroba++;
      if (i < 3)
        break; // se @ vier antes de 3 caracteres, erro
    }
    else if (arroba) { // se já encontrou @
      if (ponto) { // se já encontrou . depois de @@
        depoisPonto++;
      }
      else if(c == '.') {
        ponto = 1;
        if (antesPonto < 3) {
          break; // se . depois de @ vier antes de 3 caracteres, erro
        }
      }
      else {
        antesPonto++;
      }
    }
  } // for
    if (i == tam && depoisPonto > 1)
        return 0;
    else
        return 1;
} 



void removerCaracteresNaoNumericos(char cpf[]) {
    //feita pelo chat gpt
    int len = strlen(cpf);
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9') {
            cpf[k] = cpf[i];
            k++;
        }
    }
    cpf[k] = '\0'; // Adicione o terminador nulo ao final
}

int validarCPF(char cpf[]) {
    //validação de cpf retirado do site http://wurthmann.blogspot.com/ e sofreu algumas adpatações por Matheus Diniz
    // Remova os caracteres de pontuação (.) e hífen (-) do CPF
    removerCaracteresNaoNumericos(cpf);

    int i, j, digito1 = 0, digito2 = 0;

    if (strlen(cpf) != 11)
        return 0;
    else if ( 
             (strcmp(cpf, "22222222222") == 0) || (strcmp(cpf, "33333333333") == 0) ||
             (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
             (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) ||
             (strcmp(cpf, "88888888888") == 0) || (strcmp(cpf, "99999999999") == 0))
        return 0;
    else {
        // Digito 1
        for (i = 0, j = 10; i < 9; i++, j--) {
            digito1 += (cpf[i] - '0') * j;
        }
        digito1 %= 11;
        if (digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if ((cpf[9] - '0') != digito1)
            return 0;

        // Digito 2
        for (i = 0, j = 11; i < 10; i++, j--) {
            digito2 += (cpf[i] - '0') * j;
        }
        digito2 %= 11;
        if (digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if ((cpf[10] - '0') != digito2)
            return 0;
    }

    return 1;
}

void ler_cpf(char cpf[]) {
    //função reutilizável para realizar a leitura do cpf
    int c;
    bool v=true,f=false;
    while (v) {
        printf("\tDigite o CPF: ");
        scanf("%s", cpf);
        getchar();
        fflush(stdin);
        c = validarCPF(cpf);
        if (c == 1) {
            v=f;
        } else if (c == 0) {
            printf("\tCPF invalido!\n");
        }
    }
}

#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include <locale.h> /* Para a acentua��o*/

    char menu_principal();
    void menu_clientes(void);
    void menu_funcionarios(void);
    void menu_quartos(void);
    void sobre(void);
    void cadastrar_funcionarios(void);
    void cadastrar_quartos(void);
    void cadastrar_clientes(void);
    void listar_funcionarios(void);
    void listar_quartos(void);
    void listar_clientes(void);
    void procurar_funcionarios(void);
    void procurar_quartos(void);
    void procurar_clientes(void);
    void atualizar_funcionarios(void);
    void atualizar_quartos(void);
    void atualizar_clientes(void);
    void relatorio(void);
    void quartos_disponiveis(void); 
    void relatorio_geral(void);
    void check_in(void);
    void check_out(void);
    void precos(void);

int main(void){
    setlocale(LC_ALL, "Portuguese_Brazil");
    char op = menu_principal();
    while (op!='0'){
        op = menu_principal();
        if (op=='1'){
            menu_clientes();
        }else if(op=='2'){
            menu_funcionarios();
        }else if(op=='3'){
            menu_quartos();
        }else if(op=='4'){
            precos();
        }else if(op=='5'){
            relatorio();
        }else if(op=='6'){
            sobre();
        }else if(op=='0'){
            printf("FIM");
        }else {
            printf("Op��o inv�lida!");
        }

    }
    return 0;
} 
char menu_principal(){
    char op;
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                             MENU PRINCIPAL                           |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         0- Sair                                      |\n");
    printf("|                         1- Clientes                                  |\n");
    printf("|                         2- Funcion�rios                              |\n");
    printf("|                         3- Quartos                                   |\n");
    printf("|                         4- Pre�os                                    |\n");
    printf("|                         5- Relat�rio                                 |\n");
    printf("|                         6- Sobre                                     |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite sua escolha:  ");
    scanf("%c", &op);
    printf("------------------------------------------------------------------------\n");
    return op;

}
void sobre(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                   Gest�o de hot�is e pousadas                        |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         UFRN | Caic�                                 |\n");
    printf("|              Disciplina DCT1106 -- Programa��o                       |\n");
    printf("|                   Dev: Beatriz Vit�ria da Costa                      |\n");
    printf("|              Professor: Flavius Gorg�nio                             |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|   Sistema de gest�o para hot�is e pousadas, para ser utilizado no    |\n");
    printf("| gerenciamento de clientes,funcion�rios e quartos do estabelecimento. |\n");
    printf("|                     PROJETO EM DESENVOLVIMENTO                       |\n");
    printf("-------------------------------------------------------------------------\n");
    system("PAUSE");
}
void menu_clientes(void){
    char op;
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                             CLIENTES                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         0- Sair                                      |\n");
    printf("|                         1- Cadastrar                                 |\n");
    printf("|                         2- Listar                                    |\n");
    printf("|                         3- Procurar                                  |\n");
    printf("|                         4- Atualizar                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite sua escolha:  ");
    scanf("%c", &op);
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void menu_funcionarios(void){
    char op;
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                           FUNCION�RIOS                               |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         0- Sair                                      |\n");
    printf("|                         1- Cadastrar                                 |\n");
    printf("|                         2- Listar                                    |\n");
    printf("|                         3- Procurar                                  |\n");
    printf("|                         4- Atualizar                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite sua escolha:  ");
    scanf("%c", &op);
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void menu_quartos(void){
    char op;
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                             QUARTOS                                  |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         0- Sair                                      |\n");
    printf("|                         1- Cadastrar                                 |\n");
    printf("|                         2- Listar                                    |\n");
    printf("|                         3- Procurar                                  |\n");
    printf("|                         4- Atualizar                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite sua escolha:  ");
    scanf("%c", &op);
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void cadastrar_funcionarios(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      CADASTRAR  FUNCION�RIOS                         |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite o CPF:  \n");
    printf("\t\t\tDigite o nome:  \n");
    printf("\t\t\tDigite a data de nascimento:  \n");
    printf("\t\t\tDigite o cargo do funcion�rio:  \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void cadastrar_clientes(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      CADASTRAR  CLIENTES                             |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite quantas pessoas ser�o:  \n");
    printf("\t\t\tDigite o CPF de cada um:  \n");
    printf("\t\t\tDigite o nome de cada um:  \n");
    printf("\t\t\tDigite se v�o incluir o caf� da manh�:  \n");
    printf("\t\t\tDigite se v�o incluir os servi�os de quarto:  \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void cadastrar_quartos(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      CADASTRAR  QUARTOS                              |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite o n�mero do quarto:  \n");
    printf("\t\t\tDigite a quantidade de camas:  \n");
    printf("\t\t\tDigite se possui banheiro:  \n");
    printf("\t\t\tDigite o status do quarto:  \n");
    printf("\t\t\tDigite o valor do quarto per noite:  \n");
    printf("\t\t\tDigite o valor do quarto para 24h completas:  \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void procurar_funcionarios(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      PROCURAR FUNCION�RIO                            |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite o nome do funcion�rio:  \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
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
    system("PAUSE");
}
void procurar_quartos(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      PROCURAR QUARTO                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite o n�mero do quarto:  \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void listar_funcionarios(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      TODOS OS FUNCION�RIOS                           |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void listar_clientes(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      TODOS OS CLIENTES                               |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void listar_quartos(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      TODOS OS QUARTOS                                |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void atualizar_funcionarios(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      ATUALIZAR FUNCION�RIOS                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite o status do funcion�rio:  \n");
    // atualizar se ele ainda trabalha para a empresa ou n�o
    printf("\t\t\tDigite o novo cargo do funcion�rio  \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void atualizar_quartos(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      ATUALIZAR  QUARTOS                              |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite a quantidade de camas:  \n");
    printf("\t\t\tDigite o valor do quarto per noite:  \n");
    printf("\t\t\tDigite o valor do quarto para 24h completas:  \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
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
    system("PAUSE");
}
void relatorio(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                         RELAT�RIO                                    |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         0- Sair                                      |\n");
    printf("|                         1- Consultar quartos dispon�veis             |\n");
    printf("|                         2- Check-in                                  |\n");
    printf("|                         3- Check-out                                 |\n");
    printf("|                         4- Relat�rio Geral                           |\n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void quartos_disponiveis(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                       QUARTOS DISPON�VEIS                                |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void check_in(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                             CHECK-IN                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void check_out(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                            CHECK-OUT                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void relatorio_geral(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                        RELAT�RIO GERAL                               |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void precos(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                        TABELA DE PRE�OS                              |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}


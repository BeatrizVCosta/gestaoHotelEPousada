#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include <locale.h> /* Para a acentuação*/

    void menu_principal(void);
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

int main(void){
    setlocale(LC_ALL, "Portuguese_Brazil");
    menu_principal();
    sobre();
    menu_clientes();
    menu_funcionarios();
    menu_quartos();
    cadastrar_funcionarios();
    cadastrar_quartos();
    cadastrar_clientes();
    listar_funcionarios();
    listar_quartos();
    listar_clientes();
    procurar_funcionarios();
    procurar_quartos();
    procurar_clientes();
    atualizar_funcionarios();
    atualizar_quartos();
    atualizar_clientes();
    relatorio();
    return 0;
}
void menu_principal(void){
    char op;
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                             MENU PRINCIPAL                           |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         0- Sair                                      |\n");
    printf("|                         1- Clientes                                  |\n");
    printf("|                         2- Funcionários                              |\n");
    printf("|                         3- Quartos                                   |\n");
    printf("|                         4- Preços                                    |\n");
    printf("|                         5- Relatório                                 |\n");
    printf("|                         6- Sobre                                     |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite sua escolha:  ");
    scanf("%c", &op);
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void sobre(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                   Gestão de hotéis e pousadas                        |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         UFRN | Caicó                                 |\n");
    printf("|              Disciplina DCT1106 -- Programação                       |\n");
    printf("|                   Dev: Beatriz Vitória da Costa                      |\n");
    printf("|              Professor: Flavius Gorgônio                             |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|   Sistema de gestão para hotéis e pousadas, para ser utilizado no    |\n");
    printf("| gerenciamento de clientes,funcionários e quartos do estabelecimento. |\n");
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
    printf("|                           FUNCIONÁRIOS                               |\n");
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
    printf("|                      CADASTRAR  FUNCIONÁRIOS                         |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite o CPF:  \n");
    printf("\t\t\tDigite o nome:  \n");
    printf("\t\t\tDigite a data de nascimento:  \n");
    printf("\t\t\tDigite o cargo do funcionário:  \n");
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
    printf("\t\t\tDigite quantas pessoas serão:  \n");
    printf("\t\t\tDigite o CPF de cada um:  \n");
    printf("\t\t\tDigite o nome de cada um:  \n");
    printf("\t\t\tDigite se vão incluir o café da manhã:  \n");
    printf("\t\t\tDigite se vão incluir os serviços de quarto:  \n");
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
    printf("\t\t\tDigite o número do quarto:  \n");
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
    printf("|                      PROCURAR FUNCIONÁRIO                            |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite o nome do funcionário:  \n");
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
    printf("\t\t\tDigite o número do quarto:  \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void listar_funcionarios(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                      TODOS OS FUNCIONÁRIOS                           |\n");
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
    printf("|                      ATUALIZAR FUNCIONÁRIOS                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                      DIGITE 0 PARA CANCELAR                          |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite o status do funcionário:  \n");
    // atualizar se ele ainda trabalha para a empresa ou não
    printf("\t\t\tDigite o novo cargo do funcionário  \n");
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
    printf("|                         RELATÓRIO                                    |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         0- Sair                                      |\n");
    printf("|                         1- Consultar quartos disponiveis             |\n");
    printf("|                         2- Check-in                                  |\n");
    printf("|                         3- Check-out                                 |\n");
    printf("|                         4- Relatório Geral                           |\n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}

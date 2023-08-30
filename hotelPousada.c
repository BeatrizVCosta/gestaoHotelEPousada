#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include <locale.h> /* Para a acentuaï¿½ï¿½o*/

    char menu_principal();
    char menu_clientes();
    char menu_funcionarios();
    char menu_quartos();
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
    char relatorio();
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
            char op2 = menu_clientes();
            while (op2!='0'){
                op2 = menu_clientes();
                if (op2=='1'){
                    cadastrar_clientes();
                }else if(op2=='2'){
                    listar_clientes();
                }else if(op2=='3'){
                    procurar_clientes();
                }else if(op2=='4'){
                    atualizar_clientes();
                }else{
                    printf("Opção inválida!");
                }
            }   
        }else if(op=='2'){
            char op2 = menu_funcionarios();
            while (op2!='0'){
                op2 = menu_funcionarios();
                if (op2=='1'){
                    cadastrar_funcionarios();
                }else if(op2=='2'){
                    listar_funcionarios();
                }else if(op2=='3'){
                    procurar_funcionarios();
                }else if(op2=='4'){
                    atualizar_funcionarios();
                }else{
                    printf("Opção inválida!");
                }
            } 
        }else if(op=='3'){
            char op2 = menu_quartos();
            while (op2!='0'){
                op2 = menu_quartos();
                if (op2=='1'){
                    cadastrar_quartos();
                }else if(op2=='2'){
                    listar_quartos();
                }else if(op2=='3'){
                    procurar_quartos();
                }else if(op2=='4'){
                    atualizar_quartos();
                }else{
                    printf("Opção inválida!");
                }
            }
        }else if(op=='4'){
            precos();
        }else if(op=='5'){
            char op2 = relatorio();
            while (op2!='0'){
                op2 = relatorio();
                if (op2=='1'){
                    quartos_disponiveis();
                }else if(op2=='2'){
                    check_in();
                }else if(op2=='3'){
                    check_out();
                }else if(op2=='4'){
                    relatorio_geral();
                }else{
                    printf("Opção inválida!");
                }
            }
        }else if(op=='6'){
            sobre();
        }else if(op=='0'){
            printf("FIM");
        }else {
            printf("Opção inválida!");
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
    printf("|                         2- Funcionários                              |\n");
    printf("|                         3- Quartos                                   |\n");
    printf("|                         4- Preços                                    |\n");
    printf("|                         5- Relatório                                 |\n");
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
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite sua escolha:  ");
    scanf("%c", &op2);
    printf("------------------------------------------------------------------------\n");
    return op2;
}
char menu_funcionarios(){
    char op2;
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
    scanf("%c", &op2);
    printf("------------------------------------------------------------------------\n");
    return op2;
}
char menu_quartos(){
    char op2;
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
    scanf("%c", &op2);
    printf("------------------------------------------------------------------------\n");
    return op2;
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
    printf("\t\t\tDigite quantas pessoas por quarto:  \n");
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
    // atualizar se ele ainda trabalha para a empresa ou nao
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
char relatorio(){
    char op2;
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                         RELATÓRIO                                    |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         0- Sair                                      |\n");
    printf("|                         1- Consultar quartos disponíveis             |\n");
    printf("|                         2- Check-in                                  |\n");
    printf("|                         3- Check-out                                 |\n");
    printf("|                         4- Relatório Geral                           |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tDigite sua escolha:  ");
    scanf("%c", &op2);
    printf("------------------------------------------------------------------------\n");
    return op2;
}
void quartos_disponiveis(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                       QUARTOS DISPONÍVEIS                                |\n");
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
    printf("|                        RELATÓRIO GERAL                               |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}
void precos(void){
    system("clear||cls");
    printf("------------------------------------------------------------------------\n");
    printf("|                        TABELA DE PREÇOS                              |\n");
    printf("------------------------------------------------------------------------\n");
    printf("\t\t\tEM ANDAMENTO...... \n");
    printf("------------------------------------------------------------------------\n");
    system("PAUSE");
}


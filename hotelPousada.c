#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include "cliente.h"
#include "funcionario.h"
#include "relatorio.h"
#include "quartos.h"
#include "atendimento.h"
    char menu_principal();
    void sobre(void);

int main(void){
    char op = menu_principal();
    while (op!='0'){
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
                }else if(op2=='5'){
                    deletar_clientes();
                }else{
                    printf("Opcao invalida!");
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
                }else if(op2=='5'){
                    deletar_funcionarios();
                }else{
                    printf("Opcao invalida!");
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
                }else if(op2=='5'){
                    deletar_quartos();
                }else{
                    printf("Opcao invalida!");
                }
            }
        }else if(op=='4'){
            char op2 = atendimento();
            while (op2!='0'){
                op2 = atendimento();
                if (op2=='1'){
                    check_in();
                }else if(op2=='2'){
                    check_out();
                }else if(op2=='3'){
                    buscar_cin();
                }else if(op2=='4'){
                    buscar_cout();
                }else if(op2=='5'){
                    listar_atendimento();
                    listar_checkout();
                }else{
                    printf("Opcao invalida!");
                }
            }
        }else if(op=='5'){
            char op2 = relatorio();
            while (op2!='0'){
                op2 = relatorio();
                if (op2=='1'){
                    quartos_disponiveis();
                }else if(op2=='2'){
                    listar_atendimentoT();
                }else if(op2=='3'){
                    listar_checkoutT();
                }else if(op2=='4'){
                    precos();
                }else{
                    printf("Opcao invalida!");
                }
            }
        }else if(op=='6'){
            sobre();
        }else if(op=='0'){
            printf("FIM");
        }else {
            printf("Opcao invalida!");
        }
    op = menu_principal();
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
    printf("|                         2- Funcionarios                              |\n");
    printf("|                         3- Quartos                                   |\n");
    printf("|                         4- Atendimentos                              |\n");
    printf("|                         5- Relatorio                                 |\n");
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
    printf("|                   Gestao de hoteis e pousadas                        |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|                         UFRN | Caico                                 |\n");
    printf("|              Disciplina DCT1106 -- Programacao                       |\n");
    printf("|                   Dev: Beatriz Vitoria da Costa                      |\n");
    printf("|              Professor: Flavius Gorgonio                             |\n");
    printf("------------------------------------------------------------------------\n");
    printf("|   Sistema de gestao para hoteis e pousadas, para ser utilizado no    |\n");
    printf("| gerenciamento de clientes,funcionarios e quartos do estabelecimento. |\n");
    printf("|                     PROJETO EM DESENVOLVIMENTO                       |\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}




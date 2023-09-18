#include <stdio.h>/* Para o printf */
#include <stdlib.h>/*Para o system */
#include <locale.h> /* Para a acentua��o*/
#include "cliente.h"
#include "funcionario.h"
#include "relatorio.h"
#include "quartos.h"
    char menu_principal();
    void sobre(void);

int main(void){
    setlocale(LC_ALL, "Portuguese_Brazil");
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
                }else{
                    printf("Op��o inv�lida!");
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
                    printf("Op��o inv�lida!");
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
                    printf("Op��o inv�lida!");
                }
            }
        }else if(op=='4'){
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
                    precos();
                }else if(op2=='5'){
                    relatorio_geral();
                }else{
                    printf("Op��o inv�lida!");
                }
            }
        }else if(op=='5'){
            sobre();
        }else if(op=='0'){
            printf("FIM");
        }else {
            printf("Op��o inv�lida!");
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
    printf("|                         2- Funcion�rios                              |\n");
    printf("|                         3- Quartos                                   |\n");
    printf("|                         4- Relat�rio                                 |\n");
    printf("|                         5- Sobre                                     |\n");
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
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();getchar();
}




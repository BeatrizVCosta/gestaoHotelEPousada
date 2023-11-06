    //struc
    typedef struct funcionario {
    char nome[100];
    char CPF[11];
    char email[41];
    char dia[2];
    char mes[2];
    char ano[4];
    char cargo[10];
    char status;//A-ativado ou D-desativado
    }Funcionario;
    //funções
    char menu_funcionarios();
    void cadastrar_funcionarios(void);
    void grava_funcionario(Funcionario* fun);
    void listar_funcionarios(void);
    void procurar_funcionarios(void);
    void atualizar_funcionarios(void);
    void deletar_funcionarios(void);
    //struc
    typedef struct funcionario {
    char nome[100];
    char CPF[15];
    char email[255];
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
    void listar_fun(void);
    void exibe_funcionario(Funcionario* fun);
    void delete_funcionario(char *nome);
    void att_funcionario(char *nome);
    Funcionario* busca_funcionario(void);
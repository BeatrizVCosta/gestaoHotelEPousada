    // struct
    typedef struct cliente {
    char nome[100];
    char CPF[11];
    char email[41];
    char dia[2];
    char mes[2];
    char ano[4];
    char status[10]; // ativo ou desativado
    } Cliente;
    // funções
    char menu_clientes();
    void cadastrar_clientes(void);
    void atualizar_clientes(void);
    void procurar_clientes(void);
    void listar_clientes(void);
    void deletar_clientes(void);
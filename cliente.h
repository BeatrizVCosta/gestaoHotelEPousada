    // struct
    typedef struct cliente {
    char nome[100];
    char CPF[15];
    char email[255];
    int dia[2];
    int mes[2];
    int ano[4];
    char status; // A-ativo ou D-desativado
    char situ; //Desocupado ou ocupado - para verificar se o cliente ja fez check-in antes
    } Cliente;
    // funções
    char menu_clientes();
    void cadastrar_clientes(void);
    void grava_cliente(Cliente* cli);
    void atualizar_clientes(void);
    void procurar_clientes(void);
    Cliente* busca_cliente(void);
    
    void exibe_cliente(Cliente* cli);
    void exibe_clienteT(Cliente* cli);
    void listar_clientes(void);

    void deletar_clientes(void);
    void listar_cli(void);
    void att_cliente(char *nome);
    void delete_cliente(char* nome);
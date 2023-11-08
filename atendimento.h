
    typedef struct atendimento
    {
        char CPF[15];
        char nome[100];
        char numero[4];
        char tipo[3];
        char data_in[20];
        char data_out[20];
        char CPF_fun[15];
        char nome_fun[100];
        char diarias[4];
        char status;
    }Atendimento;
    
    char atendimento(void);
    void exibe_atendimento(Atendimento* ate);

    void check_in(void);
    void grava_atendimento(Atendimento* ate);

    void check_out(void);

    void procurar_cin(void);
    Atendimento* busca_Atendimento(void);
    int busca_cliente_existe(char cpf[], char nome[]);
    int busca_quarto_existe(char numero[], char tipo[]);
    int busca_funcionario_existe(char cpf[], char nome[]);

    void delete_atendimento(char *cpf, char *nome);
    void listar_atendimento(void);
    void listar_ate(void);

    char* data_hora(char* data_hora, size_t tam);
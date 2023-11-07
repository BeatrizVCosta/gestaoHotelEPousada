
    typedef struct atendimento
    {
        char CPF[15];
        char nome[100];
        // data
        char numero[4];
        char tipo[3];
        char diarias[4];
    }Atendimento;
    
    char atendimento(void);
    void check_in(void);
    void check_out(void);
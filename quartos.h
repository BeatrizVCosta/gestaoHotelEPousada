    // struct
    
    typedef struct quarto {
    char numero[3];
    char tipo[1];
    char status[10]; // ativo ou desativado
    } Quarto;


    // funções
    char menu_quartos();
    void cadastrar_quartos(void);
    void listar_quartos(void);
    void procurar_quartos(void);
    void atualizar_quartos(void);
    void deletar_quartos(void);
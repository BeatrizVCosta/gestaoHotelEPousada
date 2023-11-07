    // struct
    
    typedef struct quarto {
    char numero[3];
    char tipo[3];
    char status; // ativo ou desativado
    } Quarto;


    // funções
    char menu_quartos();
    void cadastrar_quartos(void);
    void grava_quarto(Quarto* qua);
    void listar_quartos(void);
    void procurar_quartos(void);
    void atualizar_quartos(void);
    void deletar_quartos(void);
    void listar_qua(void);
    void exibe_quartos(Quarto* qua);
    void quartos(void);
    // struct
    
    typedef struct quarto {
    char numero[4];
    char tipo[3];
    char status; // ativo ou desativado
    char livre; //quarto Desocupado ou Ocupado
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
    void att_quarto(char *numero);
    void delete_quarto(char *numero);
    Quarto* busca_quartos(void);
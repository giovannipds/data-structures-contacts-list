typedef struct lista {
	char *nome;
	int cpf;
	struct lista *proximo;
} Dados;

Dados *inicia_dados(char *nome, int cpf);
Dados *insere_dados(Dados *dados, char *nome, int cpf);
void exibe_dados(Dados *dados);
void busca_dados(Dados *dados, char *chave);
Dados *delete_dados(Dados *dados);
int checa_vazio(dados *dados);

void insere(void);
void exibe(void);
void busca(void);
void deleta(void);


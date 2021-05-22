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

Dados *principal = NULL;

Dados *inica_dados(char *nome, int cpf) {
	Dados *novo;
	novo = (Dados *)malloc(sizeof(Dados));
	novo->nome = (char *)malloc(strlen(nome)+1);
	strncpy(novo->nome, nome, strlen(nome)+1);
	novo->cpf = cpf;
	novo->proximo = NULL;
	
	return novo;
}

Dados *insere_dados(Dados *dados, char*nome, int cpf) {
	
	Dados *novo;
	
	novo = (Dados *)malloc(sizeof(Dados));
	novo->nome = (char *)malloc(strlen(nome)+1);
	strncpy(novo->nome, nome, strlen(nome)+1);
	novo->cpf = cpf;
	novo->proxmo = dados;
	
	return novo;
}

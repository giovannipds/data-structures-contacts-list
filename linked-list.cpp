#include <stdio.h> /* scanf, etc. */
#include <stdlib.h> /* malloc, free, etc. */
#include <string.h> /* strlen, etc. */
#include <unistd.h>
#include <conio.h>
#define BUFFER 64
#include <windows.h>

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
int checa_vazio(Dados *dados);

void insere(void);
void exibe(void);
void busca(void);
void deleta(void);

Dados *principal = NULL;

int main(void) {
	SetConsoleOutputCP(1252);
	char opcao;
	do {
		system("CLS"); /* Nao lembro de nada! ?? */
		fprintf(stdout, "\n Cadastro de Pessoas ");
		fprintf(stdout, "\n Escolha uma opcao: ");
		fprintf(stdout, "\n 1 - Insere Dados");
		fprintf(stdout, "\n 2 - Exibe Dados");
		fprintf(stdout, "\n 3 - Busca Dados");
		fprintf(stdout, "\n 4 - Deleta Dados");
		fprintf(stdout, "\n 5 - Sair \n");
		scanf("%c", &opcao);
		fflush(stdin);
		switch (opcao) {
			case '1':
				insere();
			case '2':
				exibe();
				break;
			case '3':
				busca();
				break;
			case '4':
				deleta();
				break;
			case '5':
				break;
			default:
				fprintf(stdout, "Opção inválida, tente novamente");
				getchar();
				break;
		}
	} while (opcao != '5');
}

Dados *inicia_dados(char *nome, int cpf) {
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
	novo->proximo = dados;
	return novo;
}

void exibe_dados(Dados *dados) {
	fprintf(stdout, "\n Cadastro: \n\n");
	fprintf(stdout, "------------------------\n");
	for (; dados != NULL; dados = dados->proximo) {
		fprintf(stdout, "\n Nome: %s ", dados->nome);
		fprintf(stdout, "\n CFP: %d \n", dados->cpf);
		fprintf(stdout, "\n------------------------\n");
	}
	getchar();
}

void busca_dados(Dados *dados, char *chave) {
	int achou = 0;
	fprintf(stdout, " Cadastro:\n");
	for (; dados != NULL; dados = dados->proximo) {
		if (strcmp(chave, dados->nome) == 0) {
			fprintf(stdout, "\n------------------------\n");
			fprintf(stdout, "\n Nome: %s ", dados->nome);
			fprintf(stdout, "\n CPF: %d \n", dados->cpf);
			fprintf(stdout, "\n------------------------\n");
			achou++;
		}
	}
	if (achou == 0)
		fprintf(stdout, "\n Nenhum resultado encontrado. ");
	else
		fprintf(stdout, "\n Foram encontrados %d registros", achou);	
//	sleep(1);
	getchar();
}

Dados *deleta_dados (Dados *dados) {
	Dados *novo;
	novo = dados->proximo;
	free(dados->nome);
	free(dados);
	fprintf(stdout, "\n O último registro inserido foi deletado com sucesso.");
//	sleep(1);
	getchar();
	return novo;
}

int checa_vazio(Dados *dados) {
	if (dados == NULL) {
		fprintf(stdout, "\n Lista vazia! ");
		sleep(1);
		return 1;
	} else
		return 0;
}

void insere(void) {
	char *nome;
	int cpf;
	nome = (char *)malloc(BUFFER);
	fprintf(stdout, "\n Digite o Nome: ----> ");
	scanf("%s", nome);
	fflush(stdin);
//	fprintf(stdout, "\n");
	fprintf(stdout, "\n Digite a cpf: ----> ");
	scanf("%d", &cpf);
	fflush(stdin);
	fprintf(stdout, "\n");
	if (principal == NULL)
		principal = inicia_dados(nome, cpf);
	else
		principal = insere_dados(principal, nome, cpf);
}

void exibe(void) {
	if (!checa_vazio(principal))
		exibe_dados(principal);
}

void busca(void) {
	char *chave;
	if (!checa_vazio(principal)) {
		chave = (char *)malloc(BUFFER);
		fprintf(stdout, "\n Digite o nome para buscar: --> ");
		scanf("%s", chave);
		fflush(stdin);
		busca_dados(principal, chave);
	}
}

void deleta(void) {
	if (!checa_vazio(principal))
		principal = deleta_dados(principal);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100
#define TAM_CPF 15
#define TAM_ENDERECO 150
#define TAM_TELEFONE 20
#define MAX_CLIENTES 100

typedef struct {
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    char endereco[TAM_ENDERECO];
    char telefone[TAM_TELEFONE];
    int idade;
} Cliente;

void salvarClientes(Cliente *clientes, int quantidade) {
    FILE *arquivo = fopen("clientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%s|%s|%s|%s|%d\n",
            clientes[i].nome,
            clientes[i].cpf,
            clientes[i].endereco,
            clientes[i].telefone,
            clientes[i].idade);
    }

    fclose(arquivo);
    printf("Clientes salvos com sucesso!\n");
}
				// Salvar clientes em arquivo

void removerQuebraLinha(char *str) {
    size_t len = strlen(str);
    if(len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Cadastrar cliente
void cadastrarCliente(Cliente *cliente) {
    printf("Nome: ");
    fgets(cliente->nome, TAM_NOME, stdin);
    removerQuebraLinha(cliente->nome);

    printf("CPF: ");
    fgets(cliente->cpf, TAM_CPF, stdin);
    removerQuebraLinha(cliente->cpf);

    printf("Endereço: ");
    fgets(cliente->endereco, TAM_ENDERECO, stdin);
    removerQuebraLinha(cliente->endereco);

    printf("Telefone: ");
    fgets(cliente->telefone, TAM_TELEFONE, stdin);
    removerQuebraLinha(cliente->telefone);

    printf("Idade: ");
    scanf("%d", &cliente->idade);
    getchar(); // Limpa o buffer
}
// Função para remover o \n do fgets

// Salvar clientes em arquivo


// Ler clientes do arquivo
int lerClientes(Cliente *clientes) {
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo não encontrado.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(arquivo, "%[^|]|%[^|]|%[^|]|%[^|]|%d\n",
        clientes[count].nome,
        clientes[count].cpf,
        clientes[count].endereco,
        clientes[count].telefone,
        &clientes[count].idade) == 5) {
        count++;
        if (count >= MAX_CLIENTES) break;
    }

    fclose(arquivo);
    return count;
}

// Exibir todos os clientes
void exibirClientes(Cliente *clientes, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("\nCliente %d:\n", i + 1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Endereço: %s\n", clientes[i].endereco);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("Idade: %d\n", clientes[i].idade);
    }
}

int main() {
    Cliente clientes[MAX_CLIENTES];
    int quantidade = 0, opcao;

    // Carrega clientes do arquivo ao iniciar
    quantidade = lerClientes(clientes);

    do {
        printf("\n1. Cadastrar novo cliente\n");
        printf("2. Exibir clientes\n");
        printf("3. Salvar clientes\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer

        switch(opcao) {
            case 1:
                if (quantidade < MAX_CLIENTES) {
                    cadastrarCliente(&clientes[quantidade]);
                    quantidade++;
                } else {
                    printf("Limite de clientes atingido!\n");
                }
                break;
            case 2:
                exibirClientes(clientes, quantidade);
                break;
            case 3:
                salvarClientes(clientes, quantidade);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while(opcao != 0);

    return 0;
}



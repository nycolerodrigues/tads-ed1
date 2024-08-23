// NYCOLE MARIA COSTA RODRIGUES

/*Roteiro para teste:
1 Crie uma coleção
  2 Insira tres elementos na coleção
3 Liste os elementos da Colecao
4 Consulte um dos elementos da coleçào
5 remova o segundo elemento inserido na colecao
6 Liste os elementos da coleçào
7 Esvazie a colecao
8 Liste os elementos da coleçào*/

#include "DLList.h"
#include "DLList.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do tipo disco

typedef struct _disco_
{
    char nome[30];
    int ano;
    float preco;
} Disco;

// Função de comparação

int compareDisco(void *a, void *b)
{
    Disco *discoA = (Disco *)a;
    Disco *discoB = (Disco *)b;
    return (strcmp(discoA->nome, discoB->nome) == 0 &&
            discoA->ano == discoB->ano &&
            discoA->preco == discoB->preco);
}

// Função para imprimir a lista

void printList(DLList *list)
{
    void *data = dllGetFirst(list);
    while (data != NULL)
    {
        Disco *disco = (Disco *)data;
        printf("Nome: %s, Ano: %d, Preco: %.2f\n", disco->nome, disco->ano, disco->preco);
        data = dllGetNext(list);
    }
}

// Menu de opções

int main()
{
    DLList *lista = NULL;
    int opcao;

    do
    {
        printf("\n-----  TAD Lista Duplamente Encadeada -----\n");
        printf("1. Criar uma Colecao\n");
        printf("2. Inserir um Disco\n");
        printf("3. Consultar um Disco\n");
        printf("4. Remover um Disco\n");
        printf("5. Listar os Discos\n");
        printf("6. Esvaziar a Colecao\n");
        printf("7. Destruir a Colecao\n");
        printf("0. Sair\n");
        printf("------------------------------------------------------\n");
        printf("Escolha uma opcao\n ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: // Criar Coleção
            if (lista == NULL)
            {
                lista = dllCreate();
                printf("\n");
                printf("Colecao criada.\n");
            }
            else
            {
                printf("Ja existe uma colecao criada.\n");
            }
            break;

        case 2: // Inserir Disco
            if (lista != NULL)
            {
                Disco *novoDisco = malloc(sizeof(Disco));
                printf("\n");
                printf("Digite o nome do disco: ");
                scanf("%s", novoDisco->nome);
                printf("Digite o ano do disco: ");
                scanf("%d", &novoDisco->ano);
                printf("Digite o preco do disco: ");
                scanf("%f", &novoDisco->preco);
                dllInsertAsLast(lista, novoDisco);
                printf("Disco inserido na colecao.\n");
            }
            else
            {
                printf("Crie uma colecao antes de inserir o disco.\n");
            }
            break;

        case 3: // Consultar Disco
            if (lista != NULL)
            {
                Disco discoConsulta;
                printf("Digite o nome do disco: ");
                scanf("%s", discoConsulta.nome);
                printf("Digite o ano do disco: ");
                scanf("%d", &discoConsulta.ano);
                printf("Digite o preco do disco: ");
                scanf("%f", &discoConsulta.preco);
                Disco *discoEncontrado = dllQuery(lista, &discoConsulta, compareDisco);
                if (discoEncontrado != NULL)
                {
                    printf("Disco encontrado: Nome: %s, Ano: %d, Preco: %.2f\n", discoEncontrado->nome, discoEncontrado->ano, discoEncontrado->preco);
                }
                else
                {
                    printf("Disco nao encontrado.\n");
                }
            }
            else
            {
                printf("Crie uma colecao antes de consultar discos.\n");
            }
            break;

        case 4: // Remover Disco
            if (lista != NULL)
            {
                Disco discoRemover;
                printf("Digite o nome do disco: ");
                scanf("%s", discoRemover.nome);
                printf("Digite o ano do disco: ");
                scanf("%d", &discoRemover.ano);
                printf("Digite o preco do disco: ");
                scanf("%f", &discoRemover.preco);
                Disco *discoRemovido = dllRemoveSpec(lista, &discoRemover, compareDisco);
                if (discoRemovido != NULL)
                {
                    printf("O disco removido foi: Nome: %s, Ano: %d, Preco: %.2f\n", discoRemovido->nome, discoRemovido->ano, discoRemovido->preco);
                    free(discoRemovido);
                }
                else
                {
                    printf("Disco nao encontrado para remover.\n");
                }
            }
            else
            {
                printf("Crie uma colecao antes de remover discos.\n");
            }
            break;
        case 5: // Listar Discos
            if (lista != NULL)
            {
                if (dllGetFirst(lista) == NULL)
                {
                    printf("Nao tem nenhum disco na colecao.\n");
                }
                else
                {
                    printf("\n------- Lista de Discos -------\n");
                    printList(lista);
                }
            }
            else
            {
                printf("Crie uma colecao antes de listar discos.\n");
            }
            break;

        case 6: // Esvaziar colecao
            if (lista != NULL)
            {
                if (dllCleanList(lista))
                {
                    printf("Colecao esvaziada.\n");
                }
                else
                {
                    printf("Erro ao esvaziar a colecao.\n");
                }
            }
            else
            {
                printf("Crie uma colecao antes de esvaziar.\n");
            }
            break;

        case 7: // Destruir colecao

            if (lista != NULL)
            {
                if (dllDestroy(lista))
                {
                    printf("Colecao destruida.\n");
                    lista = NULL;
                }
                else
                {
                    printf("Erro ao destruir a colecao.\n");
                }
            }
            else
            {
                printf("Nao existe nenhuma colecao criada.\n");
            }
            break;

        case 0: // Sair
            printf("Tchau!\n");
            break;

        default:
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}

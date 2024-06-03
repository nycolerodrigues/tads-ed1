/*NYCOLE MARIA COSTA RODRIGUES*/
/*
Roteiro para teste:
1 Crie uma coleção
2 Insira tres elementos na coleção
3 Liste os elementos da Colecao
4 Consulte um dos elementos da coleçào
5 remova o segundo elemento inserido na colecao
6 Liste os elementos da coleçào
7 Esvazie a colecao
8 Liste os elementos da coleçào
*/
/*Discos: LM5, 2018, 100.0
Confetti, 2020, 200.0
Salute, 2013,300.0*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SLList.h"
#include "SLList.c"

typedef struct _disco_
{
    char nome[30];
    int ano;
    float preco;
} Disco;

// Função de comparação
int compareStrings(void *a, void *b)
{
    return strcmp((char *)a, (char *)b) == 0;
}

// Função para imprimir a lista
void printList(SLList *list)
{
    SLNode *node = list->first;
    while (node != NULL)
    {
        Disco *disco = (Disco *)node->data;
        printf("Nome: %s, Ano: %d, Preco: %.2f\n", disco->nome, disco->ano, disco->preco);
        node = sllGetNext(node);
    }
}

// Menu de opções
int main()
{
    SLList *lista = NULL;
    int opcao;

    do
    {
        printf("\n-----  Menu TAD Lista Simplesmente Encadeada -----\n");
        printf("1. Criar uma Colecao\n");
        printf("2. Inserir um Disco\n");
        printf("3. Consultar um Disco\n");
        printf("4. Remover um Disco\n");
        printf("5. Listar os Discos\n");
        printf("6. Esvaziar a Colecao\n");
        printf("7. Destruir a Colecao\n");
        printf("0. Sair\n");
        printf("------------------------------------------------------\n");
        printf("O que vc deseja fazer?\n ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: // Criar Coleção
            if (lista == NULL)
            {
                lista = sllCreate();
                printf("\nColecao criada.\n");
            }
            else
            {
                printf("A colecao ja foi criada.\n");
            }
            break;

        case 2: // Inserir Disco
            if (lista != NULL)
            {
                Disco *novoDisco = (Disco *)malloc(sizeof(Disco));
                printf("\nDigite o nome do disco: ");
                scanf("%s", novoDisco->nome);
                printf("Digite o ano do disco: ");
                scanf("%d", &novoDisco->ano);
                printf("Digite o preco do disco: ");
                scanf("%f", &novoDisco->preco);
                sllInsertLast(lista, novoDisco);
                printf("Disco inserido na colecao.\n");
            }
            else
            {
                printf("Crie a colecao antes de inserir discos.\n");
            }
            break;
        case 3: // Consultar Disco
            if (lista != NULL)
            {
                if (lista->first != NULL)
                {
                    char nome[30];
                    int ano;
                    float preco;

                    printf("Digite o nome do disco: ");
                    scanf("%s", nome);
                    printf("Digite o ano do disco: ");
                    scanf("%d", &ano);
                    printf("Digite o preco do disco: ");
                    scanf("%f", &preco);

                    SLNode *node = lista->first;
                    int discoEncontrado = 0;

                    while (node != NULL)
                    {
                        Disco *disco = (Disco *)node->data;
                        if (strcmp(disco->nome, nome) == 0 && disco->ano == ano && disco->preco == preco)
                        {
                            printf("O disco encontrado foi o : %s, de %d, preco %.2f\n", disco->nome, disco->ano, disco->preco);
                            discoEncontrado = 1;
                            break;
                        }
                        node = node->next;
                    }

                    if (!discoEncontrado)
                    {
                        printf("Disco nao encontrado.\n");
                    }
                }
                else
                {
                    printf("A colecao esta vazia. Nenhum disco para consultar.\n");
                }
            }
            else
            {
                printf("Crie a colecao antes de consultar discos.\n");
            }
            break;

        case 4: // Remover Disco
            if (lista != NULL)
            {
                if (lista->first != NULL)
                {
                    char nome[30];
                    int ano;
                    float preco;

                    printf("Digite o nome do disco: ");
                    scanf("%s", nome);
                    printf("Digite o ano do disco: ");
                    scanf("%d", &ano);
                    printf("Digite o preco do disco: ");
                    scanf("%f", &preco);

                    SLNode *prev = NULL;
                    SLNode *node = lista->first;
                    int discoEncontrado = 0;
                    while (node != NULL)
                    {
                        Disco *disco = (Disco *)node->data;
                        if (strcmp(disco->nome, nome) == 0 && disco->ano == ano && disco->preco == preco)
                        {

                            if (prev == NULL)
                            {
                                lista->first = node->next;
                            }
                            else
                            {
                                prev->next = node->next;
                            }
                            void *data = node->data;
                            free(node);
                            printf("O disco removido foi o : %s, de %d, preco %.2f\n", disco->nome, disco->ano, disco->preco);
                            free(data);
                            discoEncontrado = 1;
                            break;
                        }
                        prev = node;
                        node = node->next;
                    }

                    if (!discoEncontrado)
                    {
                        printf("Disco nao encontrado para remover.\n");
                    }
                }
                else
                {
                    printf("A colecao esta vazia. Nenhum disco para remover.\n");
                }
            }
            else
            {
                printf("Crie a colecao antes de remover discos.\n");
            }
            break;

        case 5: // Listar Discos
            if (lista != NULL)
            {
                if (lista->first != NULL)
                {
                    printf("\n------- Lista de Discos -------\n");
                    printList(lista);
                }
                else
                {
                    printf("A colecao esta vazia. Nenhum disco para listar.\n");
                }
            }
            else
            {
                printf("Crie a colecao antes de listar discos.\n");
            }
            break;

        case 6: // Esvaziar colecao
            if (lista != NULL)
            {
                if (sllCleanList(lista))
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
                printf("Crie a colecao antes de esvaziar.\n");
            }
            break;

        case 7: // Destruir colecao
            if (lista != NULL)
            {
                if (sllDestroy(lista))
                {
                    printf("A colecao foi destruida.\n");
                    lista = NULL;
                }
                else
                {
                    printf("Erro ao destruir a colecao.\n");
                }
            }
            else
            {
                printf("A colecao ja esta destruida.\n");
            }
            break;

        case 0: // Sair
            printf("Tchau!\n");
            break;

        default:
            printf("Opa, opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp.c"

#define TRUE 1
#define FALSE 0

int countNodes(TNode *t);

void destroyTree(TNode *t);

void emptyTree(TNode **t);

void limparBuffer();

int cmp(void *data, void *key);

void visit(void *data);

/*1 Crie uma coleção
  2 Insira tres elementos na coleção
3 Liste os elementos da Colecao
4 Consulte um dos elementos da coleçào
5 remova o segundo elemento inserido na colecao
6 Liste os elementos da coleçào
7 Esvazie a colecao
8 Liste os elementos da coleçào*/
int main()
{
    TNode *raiz;
    Pessoa *p;
    int option;

    while (1)
    {
        printf("---------MENU-------:\n");
        printf("1. Criar uma nova colecao\n");
        printf("2. Inserir um item\n");
        printf("3. Remover um item\n");
        printf("4. Mostrar todos os itens da arvore\n");
        printf("5. Verificar se um item esta na arvore\n");
        printf("6. Mostrar o numero de itens da arvore\n");
        printf("7. Esvaziar a arvore\n");
        printf("8. Destruir a arvore\n");
        printf("9. Sair\n");

        scanf("%d", &option);
        limparBuffer();

        switch (option)
        {
        case 1:
            raiz = NULL;
            printf("\nNova colecao criada.\n");
            break;

        case 2:
            p = (Pessoa *)malloc(sizeof(Pessoa));
            printf("Digite o peso: ");
            scanf("%f", &p->peso);
            limparBuffer();
            printf("Digite o nome: ");
            fgets(p->nome, sizeof(p->nome), stdin);
            p->nome[strcspn(p->nome, "\n")] = '\0'; 
            printf("Digite a idade: ");
            scanf("%d", &p->idade);
            limparBuffer();
            raiz = abpInsert(raiz, (void *)p, cmp);
            if (raiz != NULL)
            {
                printf("\nItem inserido!\n");
            }
            else
            {
                printf("\nNao foi possivel inserir o item!\n");
            }
            break;

        case 3:
            if (raiz != NULL)
            {
                Pessoa *chave = (Pessoa *)malloc(sizeof(Pessoa));
                printf("\nDigite o peso do item que deseja retirar: ");
                scanf("%f", &chave->peso);
                limparBuffer();
                printf("Digite o nome do item que deseja retirar: ");
                fgets(chave->nome, sizeof(chave->nome), stdin);
                chave->nome[strcspn(chave->nome, "\n")] = '\0'; 
                printf("Digite a idade do item que deseja retirar: ");
                scanf("%d", &chave->idade);
                limparBuffer();
                void *data;
                Pessoa *p = (Pessoa *)abpQuery(raiz, (void *)chave, cmp);
                if (p != NULL)
                {
                    raiz = abpRemove(raiz, (void *)chave, cmp, &data);
                    printf("\nItem retirado da arvore\n");
                    if (raiz != NULL)
                    {
                        Pessoa *p = (Pessoa *)raiz->data;
                        printf("\nRaiz: %s, Idade: %d\n", p->nome, p->idade);
                    }
                }
                else
                {
                    printf("\nItem não encontrado\n");
                }
                free(chave);
            }
            else
            {
                printf("\nPrimeiro insira algum item na arvore!\n");
            }
            break;

        case 4:
            if (raiz != NULL)
            {
                printf("\nItens na arvore: ");
                simetrico(raiz, visit);
                printf("\n");
            }
            else
            {
                printf("\nPrimeiro insira algum item na arvore!\n");
            }
            break;

        case 5:
            if (raiz != NULL)
            {
                Pessoa *chave = (Pessoa *)malloc(sizeof(Pessoa));
                printf("\nDigite o peso do item que voce deseja encontrar: ");
                scanf("%f", &chave->peso);
                limparBuffer();
                printf("Digite o nome do item que voce deseja encontrar: ");
                fgets(chave->nome, sizeof(chave->nome), stdin);
                chave->nome[strcspn(chave->nome, "\n")] = '\0';  // Remove o newline
                printf("Digite a idade do item que voce deseja encontrar: ");
                scanf("%d", &chave->idade);
                limparBuffer();
                Pessoa *p = (Pessoa *)abpQuery(raiz, (void *)chave, cmp);
                if (p != NULL)
                {
                    printf("\nO item esta na arvore\n");
                }
                else
                {
                    printf("\nO item nao esta na arvore\n");
                }
                free(chave);
            }
            else
            {
                printf("Primeiro insira um item na arvore\n");
            }
            break;

        case 6:
            printf("\nNumero de itens na arvore: %d\n", countNodes(raiz));
            break;

        case 7:
            emptyTree(&raiz);
            printf("\nArvore esvaziada.\n");
            break;

        case 8:
            if (raiz == NULL)
            {
                printf("\nArvore destruida.\n");
                destroyTree(raiz);
               
            }
            else
            {
                printf("\nA arvore precisa estar vazia antes de ser destruida.\n");
            }
            break;

        case 9:
            printf("\nSaindo...\n");
            destroyTree(raiz);
            return 0;

        default:
            printf("Opcao invalida. Tente novamente.\n");
            limparBuffer();
        }
    }

    return 0;
}

int cmp(void *data, void *key)
{
    Pessoa *p1 = (Pessoa *)data;
    Pessoa *p2 = (Pessoa *)key;

    if (p1->peso > p2->peso) {
        return 1;
    } else if (p1->peso < p2->peso) {
        return -1;
    }

    int nomeCmp = strcmp(p1->nome, p2->nome);
    if (nomeCmp > 0) {
        return 1;
    } else if (nomeCmp < 0) {
        return -1;
    }

    if (p1->idade > p2->idade) {
        return 1;
    } else if (p1->idade < p2->idade) {
        return -1;
    }

    return 0;
}

void visit(void *data)
{
    Pessoa *p = (Pessoa *)data;
    printf("Nome: %s, Idade: %d, Peso: %.2f\n", p->nome, p->idade, p->peso);
}

int countNodes(TNode *t)
{
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countNodes(t->left) + countNodes(t->right);
    }
}

void destroyTree(TNode *t)
{
    if (t != NULL)
    {
        destroyTree(t->left);
        destroyTree(t->right);
        free(t->data);
        free(t);
    }
}

void emptyTree(TNode **t)
{
    if (*t != NULL)
    {
        emptyTree(&(*t)->left);
        emptyTree(&(*t)->right);
        free((*t)->data);
        free(*t);
        *t = NULL;
    }
}

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

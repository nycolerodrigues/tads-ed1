
/*NYCOLE MARIA COSTA RODRIGUES*/
/*
1 - Crie uma coleção
2 - Insira tres elementos na coleção
3- Liste os elementos da Colecao
4 - Consulte um dos elementos da coleçào
5 - remova o segundo elemento inserido na colecao
6- Liste os elementos da coleçào
7 - Esvazie a colecao
8- Liste os elementos da coleçào
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cofo.h"
#include "cofo.c"

typedef struct _pessoa_
{
    char nome[30];
    int idade;
    float altura;
} Pessoa;

// fazer busca pelo nome
int cmpString(void *item, void *chave)
{
    Pessoa *item_temp = (Pessoa *)item;

    if (strcmp(item_temp->nome, (char *)chave) == 0)
    {
        return 1;
    }
    return 0;
}

// fazer busca pela idade
int cmpInt(void *item, void *chave)
{
    Pessoa *item_temp = (Pessoa *)item;
    if (item_temp->idade == *(int *)chave)
    {
        return 1;
    }
    return 0;
}

// fazer busca pela altura
int cmpFloat(void *item, void *chave)
{
    Pessoa *item_temp = (Pessoa *)item;
    if (item_temp->altura == *(float *)chave)
    {
        return 1;
    }
    return 0;
}

void imprimeelemento(Pessoa *pessoa)
{
    printf("\nNome: %s", pessoa->nome);
    printf("\nIdade: %d", pessoa->idade);
    printf("\nAltura: %.2f\n", pessoa->altura);
}

int main()
{
    int flag = 1, resp = 0, maxItems = 0, tipoBusca = 0, idade = 0;
    float altura = 0;
    char nome[30];
    Pessoa *pessoa;
    gCofo *gc = NULL;
    Pessoa *pessoaResult;
    Pessoa *pessoaParaRemover;
    printf("Bem vinde ao cofo generico \n");
    while (flag == 1)
    {
        printf("-------------MENU---------------\n");
        printf("\n1- Criar um cofo \n2- Inserir um elemento no cofo \n3 - Consultar um elemento no cofo \n4- Remover um elemento do cofo\n5- Listar elementos do cofo\n6- Esvaziar o cofo\n7- Sair\n\n");
        scanf("%d", &resp);

        switch (resp)
        {

        case 1:
            // verifica se já existe um cofo criado para evitar a criação de vários cofos
            if (gc != NULL)
            {
                printf("Ja existe um cofo criado ;)\n");
            }
            else
            {
                printf("\nQual o tamanho do seu cofo? ");
                scanf("%d", &maxItems);
                gc = gcofCreate(maxItems);
                printf("Cofo criado :)\n");
            }
            break;

        case 2:
            // verifica se já tem um cofo criado para evitar realizar a operação mesmo sem um cofo criado
            if (gc == NULL)
            {
                printf("Crie um cofo primeiro ;)\n");
                break;
            }
            // verifica se o cofo já está cheio para evitar adicionar além do tamanho do cofo
            if (gc->numItens >= gc->maxItens)
            {
                printf("O cofo esta cheio :(\n");
                break;
            }
            pessoa = (Pessoa *)malloc(sizeof(Pessoa));
            printf("\nDigite nome da pessoa: ");
            scanf(" %s", pessoa->nome);
            printf("\nDigite a idade da pessoa: ");
            scanf("%d", &pessoa->idade);
            printf("\nDigite altura: ");
            scanf("%f", &pessoa->altura);
            if (gcofInsert(gc, (void *)pessoa) == 1)
            {
                printf("\nPessoa adicionada :)\n");
            }
            else
            {
                printf("\nNão foi possível adicionar :(\n");
                free(pessoa); // Liberar a memória alocada se não foi possível adicionar
            }
            break;

        case 3:
            if (gc == NULL)
            {
                printf("Crie um cofo primeiro ;)\n");
                break;
            }
            printf("\n1- Buscar pelo nome \n2- Buscar pela idade \n3- Buscar pela altura\n\n");
            scanf("%d", &tipoBusca);
            switch (tipoBusca)
            {
            case 1:
                printf("\nDigite o nome: ");
                scanf("%s", nome);
                pessoaResult = (Pessoa *)gcofQuery(gc, (void *)nome, cmpString);
                if (pessoaResult != NULL)
                {
                    printf("aqui esta: \n");
                    imprimeelemento(pessoaResult);
                }
                else
                {
                    printf("Nao encontrado :(\n");
                }
                break;

            case 2:
                printf("\nDigite a idade: ");
                scanf("%d", &idade);
                pessoaResult = (Pessoa *)gcofQuery(gc, &idade, cmpInt);
                if (pessoaResult != NULL)
                {
                    printf("aqui esta: \n");
                    imprimeelemento(pessoaResult);
                }
                else
                {
                    printf("Nao encontrado :(\n");
                }
                break;

            case 3:
                printf("\nDigite a altura: ");
                scanf("%f", &altura);
                pessoaResult = (Pessoa *)gcofQuery(gc, &altura, cmpFloat);
                if (pessoaResult != NULL)
                {
                    printf("aqui esta: \n");
                    imprimeelemento(pessoaResult);
                }
                else
                {
                    printf("Nao encontrado :(\n");
                }
                break;
            }
            break;

        case 4:
            if (gc == NULL)
            {
                printf("Crie um cofo primeiro ;)\n");
                break;
            }
            pessoaParaRemover = (Pessoa *)malloc(sizeof(Pessoa));
            printf("\nDigite idade da pessoa que quer remover: ");
            scanf("%d", &idade);
            printf("\nDigite nome da pessoa que quer remover: ");
            scanf(" %s", pessoaParaRemover->nome);
            printf("\nDigite altura da pessoa que quer remover: ");
            scanf("%f", &pessoaParaRemover->altura);
            pessoaResult = (Pessoa *)gcofQuery(gc, &idade, cmpInt);
            if (elemRemover(gc, (void *)pessoaResult) != NULL)
            {
                printf("A pessoa foi de link na bio ;)\n");
            }
            else
            {
                printf("Nao deu pra remover :(\n");
            }
            break;

        case 5:
            if (gc == NULL)
            {
                printf("Nao tem ninguem aqui :O \n");
                break;
            }
            if (gc->numItens == 0)
            {
                printf("Aqui nao tem ninguem :O \n");
                break;
            }
            for (int i = 0; i < gc->numItens; i++)
            {
                imprimeelemento((Pessoa *)gc->item[i]);
            }
            break;

        case 6:
            if (gc == NULL)
            {
                printf("Nao existe cofo, logo nao tem como esvaziar :O\n");
                break;
            }
            gcofEmpty(gc);
            printf("Aqui nao tem mais ninguem :O \n");
            break;

        case 7:
            if (gc != NULL)
            {
                gcofDestroy(gc);
                printf("O cofo queimou :O \n");
            }
            flag = 0;
            printf("Tchau, queride ;)\n");
            break;

        default:
            printf("\nOpcao invalida :(\n");
            break;
        }
    }
    return 0;
}

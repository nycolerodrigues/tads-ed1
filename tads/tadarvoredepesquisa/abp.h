/*Nycole Maria Costa Rodrigues*/

#ifndef __ABP_H_
#define __ABP_H_

typedef struct t_node
{
    void *data;
    struct t_node *left;
    struct t_node *right;
} TNode;

typedef struct _pessoa_
{
    float peso;
    char nome [30];
    int idade;
} Pessoa;

TNode *abpInsert(TNode *t, void *data, int (*cmp)(void *, void *));
void simetrico(TNode *t, void (*visit)(void *));
TNode *abpRemove(TNode *t, void *key, int (*cmp)(void *, void *), void **data);
TNode *abpRemoveMaior(TNode *t, int (*cmp)(void *, void *), void **data);
void *abpQuery(TNode *t, void *key, int (*cmp)(void *, void *));


#endif
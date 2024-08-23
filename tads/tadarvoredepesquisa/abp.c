/*Nycole Maria Costa Rodrigues*/

#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

#ifndef __ABP_C_
#define __ABP_C_

#define TRUE 1
#define FALSE 0

TNode *abpInsert(TNode *t, void *data, int (*cmp)(void *, void *)) {
    if (t == NULL) {
        TNode *newnode = (TNode *)malloc(sizeof(TNode));
        if (newnode != NULL) {
            newnode->data = data;
            newnode->left = newnode->right = NULL;
            return newnode;
        } else {
            return NULL;
        }
    }

    int stat = cmp(data, t->data);

    if (stat < 0) {
        t->left = abpInsert(t->left, data, cmp);
    } else if (stat > 0) {
        t->right = abpInsert(t->right, data, cmp);
    } 

    return t;
}
void simetrico(TNode *t, void (*visit)(void *))
{
    if (t != NULL)
    {
        simetrico(t->left, visit);
        visit(t->data);
        simetrico(t->right, visit);
    }
}


TNode *abpRemove(TNode *t, void *key, int (*cmp)(void *, void *), void **data)
{
    void *data2;
    int stat;
    TNode *aux;
    if (t != NULL)
    {
        stat = cmp(key, t->data);
        if (stat < 0)
        {
            t->left = abpRemove(t->left, key, cmp, data);
            return t;
        }
        else if (stat > 0)
        {
            t->right = abpRemove(t->right, key, cmp, data);
            return t;
        }
        else
        {
            if (t->left == NULL && t->right == NULL)
            {
                *data = t->data;
                free(t);
                return NULL;
            }
            else if (t->left == NULL)
            {
                aux = t->right;
                *data = t->data;
                free(t);
                return aux;
            }
            else if (t->right == NULL)
            {
                aux = t->left;
                *data = t->data;
                free(t);
                return aux;
            }
            else
            {
                *data = t->data;
                t->left = abpRemoveMaior(t->left, cmp, &data2);
                t->data = data2;
                return t;
            }
        }
    }
    *data = NULL;
    return NULL;
}

TNode *abpRemoveMaior(TNode *t, int (*cmp)(void *, void *), void **data) {
    TNode *aux;
    if (t != NULL) {
        if (t->right != NULL) {
            t->right = abpRemoveMaior(t->right, cmp, data);
            return t;
        } else {
            aux = t->left;
            *data = t->data;
            free(t);
            return aux;
        }
    }
    *data = NULL;
    return NULL;
}

void *abpQuery(TNode *t, void *key, int (*cmp)(void *, void *))
{
    int stat;
    if (t != NULL)
    {
        stat = cmp(key, t->data);
        if (stat == 0)
        {
            return t->data;
        }
        else if (stat < 0)
        {
            return abpQuery(t->left, key, cmp);
        }
        else
        {
            return abpQuery(t->right, key, cmp);
        }
    }
    return NULL;
}



#endif
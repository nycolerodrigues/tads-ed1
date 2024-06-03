/* NYCOLE MARIA COSTA RODRIGUES */

#ifndef _SLLIST_C_
#define _SLLIST_C_

#include "SLList.h"
#include <stdlib.h>

typedef struct _slnode_
{
    void *data;
    struct _slnode_ *next;
} SLNode;

typedef struct _sllist_
{
    SLNode *first;
} SLList;

/* Cria a lista */
SLList *sllCreate(void)
{
    SLList *l = (SLList *)malloc(sizeof(SLList));
    if (l != NULL)
    {
        l->first = NULL;
        return l;
    }
    return NULL;
}

/* Destroi a lista */
int sllDestroy(SLList *l)
{
    if (l != NULL)
    {
        if (l->first == NULL)
        {
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}

/* Insere o primeiro elemento */
int sllInsertFirst(SLList *l, void *data)
{
    if (l != NULL)
    {
        SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
        if (newnode != NULL)
        {
            newnode->data = data;
            newnode->next = l->first;
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}

/* Remove o primeiro elemento */
void *sllRemoveFirst(SLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *first = l->first;
            void *data = first->data;
            l->first = first->next;
            free(first);
            return data;
        }
    }
    return NULL;
}

/* Insere como ultimo elemento */
int sllInsertLast(SLList *l, void *data)
{
    if (l != NULL)
    {
        SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
        if (newnode != NULL)
        {
            newnode->data = data;
            newnode->next = NULL;
            if (l->first == NULL)
            {
                l->first = newnode;
            }
            else
            {
                SLNode *last = l->first;
                while (last->next != NULL)
                {
                    last = last->next;
                }
                last->next = newnode;
            }
            return TRUE;
        }
    }
    return FALSE;
}

/* Pega o primeiro da lista */
void *sllGetFirst(SLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            return l->first->data;
        }
    }
    return NULL;
}

/* Pega o ultimo */
void *sllGetLast(SLList *l)
{
    if (l != NULL)
    {
        SLNode *last = l->first;
        if (last != NULL)
        {
            while (last->next != NULL)
            {
                last = last->next;
            }
            return last->data;
        }
    }
    return NULL;
}

/* Esvazia a lista */
int sllCleanList(SLList *l)
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *aux = l->first;
            while (aux != NULL)
            {
                SLNode *next = aux->next;
                free(aux->data);
                free(aux);
                aux = next;
            }
            l->first = NULL;
            return TRUE;
        }
    }
    return FALSE;
}

/* Consultar um elemento da lista identificado por uma chave */
void *sllQuery(SLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *spec = l->first;
            int stat = cmp(spec->data, key);
            while (spec->next != NULL && stat != TRUE)
            {
                spec = spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE)
            {
                return spec->data;
            }
        }
    }
    return NULL;
}

/* Remover especifico */
void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *spec = l->first;
            SLNode *prev = NULL;
            int stat = cmp(spec->data, key);
            while (stat != TRUE && spec->next != NULL)
            {
                prev = spec;
                spec = spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE)
            {
                void *data = spec->data;
                if (prev == NULL)
                {
                    l->first = spec->next;
                }
                else
                {
                    prev->next = spec->next;
                }
                free(spec);
                return data;
            }
        }
    }
    return NULL;
}

/* Inserir depois de um nó especificado pela chave */
int sllInserftAfterSpec(SLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            SLNode *spec = l->first;
            int stat = cmp(spec->data, key);
            while (stat != TRUE && spec->next != NULL)
            {
                spec = spec->next;
                stat = cmp(spec->data, key);
            }
            if (stat == TRUE)
            {
                SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
                if (newnode != NULL)
                {
                    newnode->data = data;
                    newnode->next = spec->next;
                    spec->next = newnode;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

/* Inserir antes de um elemento específico da lista */
int sllInsertBeforeSpec(SLList *l, void *key, int (*cmp)(void *, void *), void *data)
{
    if (l != NULL && l->first != NULL)
    {
        SLNode *spec = l->first;
        SLNode *prev = NULL;
        int stat = cmp(spec->data, key);
        while (spec->next != NULL && stat != TRUE)
        {
            prev = spec;
            spec = spec->next;
            stat = cmp(spec->data, key);
        }
        if (stat == TRUE)
        {
            SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
            if (newnode != NULL)
            {
                newnode->data = data;
                newnode->next = spec;
                if (prev != NULL)
                {
                    prev->next = newnode;
                }
                else
                {
                    l->first = newnode;
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}

/* Obter o próximo nó na lista */
void *sllGetNext(SLNode *current)
{
    if (current != NULL)
    {
        return current->next;
    }
    return NULL;
}

#endif

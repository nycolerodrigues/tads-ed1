/*NYCOLE MARIA COSTA RODRIGUES*/
#ifndef _SLLIST_H_
#define _SLLIST_H_

#define TRUE 1
#define FALSE 0

#ifdef _SLLIST_C_



typedef struct _slnode_ {
    void *data;
    struct _slnode_ *next;
} SLNode;

typedef struct _sllist_ {
    SLNode *first;
} SLList;

/* Criar lista */
SLList *sllCreate();

/* Destruir lista */
int sllDestroy(SLList *l);

/* Pegar primeiro da lista */
void *sllGetFirst(SLList *l);

/* Pegar o último */
void *sllGetLast(SLList *l);

/* Obter o próximo nó na lista */
void *sllGetNext(SLNode *current);

/* Inserir como último */
int sllInsertAsLast(SLList *l, void *data);

/* Inserir como primeiro */
int sllInsertAsFirst(SLList *l, void *data);

/* Consultar um elemento da lista identificado por uma chave */
void *sllQuery(SLList *l, void *key, int (*cmp)(void *, void *));

/* Remover primeiro */
void *sllRemoveFirst(SLList *l);

/* Remover específico */
void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void *));

/* Inserir depois de um nó especificado pela chave */
int sllInsertAfterSpec(SLList *l, void *key, void *data, int (*cmp)(void *, void *));

/* Inserir antes de um elemento específico da lista */
int sllInsertBeforeSpec(SLList *l, void *key, int (*cmp)(void *, void *), void *data);

/* Limpar a lista */
int sllCleanList(SLList *l);

#else

typedef struct _sllist_ SLList;
typedef struct _slnode_ SLNode;

SLList *SllCreate();

extern int sllDestroy(SLList *l);

extern void *sllGetFirst(SLList *l);

extern void *sllGetLast(SLList *l);

extern void *sllGetNext(SLNode *current);

extern int sllInsertAsLast(SLList *l, void *data);

extern int sllInsertAsFirst(SLList *l, void *data);

extern void *sllQuery(SLList *l, void *key, int (*cmp)(void *, void *));

extern void *sllRemoveFirst(SLList *l);

extern void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void *));

extern int sllInsertAfterSpec(SLList *l, void *key, void *data, int (*cmp)(void *, void *));

extern int sllInsertBeforeSpec(SLList *l, void *key, int (*cmp)(void *, void *), void *data);

extern int sllCleanList(SLList *l);

#endif

#endif

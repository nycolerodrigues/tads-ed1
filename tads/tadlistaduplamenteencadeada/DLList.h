//NYCOLE MARIA COSTA RODRIGUES

#ifndef _DLLIST_H_
#define _DLLIST_H_
#define TRUE 1
#define FALSE 0

#ifdef _DLLIST_C_
#include <stdlib.h>
#include <stdio.h>
typedef struct _dlnode_
{

    struct _dlnode_ *next, *prev;
    void *data;

} DLNode;

typedef struct _dllist_
{

    DLNode *first;
    DLNode *cur;

} DLList;

DLList *dllCreate();

int dllDestroy(DLList *l);

void *dllGetNext(DLList *l);

void *dllGetFirst(DLList *l);

int dllInsertAsLast(DLList *l, void *data);

int dllInsertAsFirst(DLList *l, void *data);

void *dllQuery(DLList *l, void *key, int (*cmp)(void *, void *));

void *dllRemoveFirst(DLList *l);

void *dllRemoveLast(DLList *l);

void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *));

int dllInsertAfterSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *));

int dllInsertBeforeSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *));

int dllCleanList(DLList *l);

#else

typedef struct _dllist_ DLList;
typedef struct _dlnode_ DLNode;

DLList *dllCreate();

extern int dllDestroy(DLList *l);

extern void *dllGetNext(DLList *l);

extern void *dllGetFirst(DLList *l);

extern int dllInsertAsLast(DLList *l, void *data);

extern int dllInsertAsFirst(DLList *l, void *data);

extern void *dllQuery(DLList *l, void *key, int (*cmp)(void *, void *));

extern void *dllRemoveFirst(DLList *l);

extern void *dllRemoveLast(DLList *l);

extern void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *));

extern int dllInsertAfterSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *));

extern int dllInsertBeforeSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *));

extern int dllCleanList(DLList *l);
#endif
#endif

/*NYCOLE MARIA COSTA RODRIGUES*/

#ifndef _COFO_H
#define _COFO_H

typedef struct _gcofo_ {
  int numItens;
  int maxItens;
  int cur;
  void **item;
} gCofo;

gCofo *gcofCreate(int max_itens);
int gcofInsert(gCofo *c, void *item);
void *gcofRemove(gCofo *c, void *key);
void *gcofQuery(gCofo *gc, void *key, int (*cmp)(void *, void *));
void *elemRemover(gCofo *col, void *chave);
int gcofDestroy (gCofo *gc);
void gcofEmpty(gCofo *gc);

#else
extern gCofo *gcofCreate(int max_itens);
extern int gcofInsert(gCofo *c, void *item);
extern void *gcofRemove(gCofo *c, void *key);
extern void*gcofQuery(gCofo *gc, void *key, int (*cmp)(void *, void *));
extern int gcofDestroy (gCofo *gc);
extern void gcofEmpty(gCofo *gc);

#endif // __COFO_H
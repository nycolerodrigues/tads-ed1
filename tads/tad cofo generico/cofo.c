/*NYCOLE MARIA COSTA RODRIGUES*/

#include <stdlib.h>
#include <stdio.h>
#include "cofo.h"

//criar um cofo
gCofo *gcofCreate( int max_itens ){
    gCofo *gc;
    if ( max_itens > 0) {
        gc = (gCofo *) malloc(sizeof (gCofo ));
        if ( gc != NULL) {
            gc->item = (void **) malloc (sizeof(void *)*max_itens);
            if (gc->item != NULL){
                gc->numItens = 0;
                gc->maxItens = max_itens;
                gc-> cur = -1;
                return gc;
            }
        }
    }
    free(gc);
    return NULL;
}

//inserir no cofo
int gcofInsert(gCofo *gc, void *item ){
    if ( gc != NULL ) {
        if ( gc->numItens < gc->maxItens) {
            gc->item[gc->numItens] = item;
            gc->numItens++;
            return 1;
        }
    }
    return 0;
}
//buscar no cofo
void *gcofQuery (gCofo *gc, void *key, int (*cmp)(void *, void *)){
    int i=0; 
    int stat;
    if (gc!=NULL) {
        if (gc->numItens > 0 ){
            stat = cmp(gc->item[i], key);
            for(int i = 0; i < gc->numItens; i++){
                stat = cmp(gc->item[i], key);
                if(stat ==1){
                   
                    return gc->item[i];
                }
            }
        }
    }
  
    return NULL;
}

void* elemRemover (gCofo *col, void* chave) {
    void* data;
    if (col == NULL)
        return NULL;

    
    if (col->numItens <= 0) {
        return NULL;
    }

    
    for (int i = 0; i < col->numItens; i++) {
        
        if (col->item[i] == chave) {
            
            data = col->item[i];
          
            for (int j = i; j < col->numItens; j++) {
                col->item[j] = col->item[j+1];
            }
           
            col->numItens--;
            return data;
        }
    }
    return NULL;
}
//destruir o cofo
int gcofDestroy (gCofo *gc){
 if ( gc != NULL ){
    if ( gc->numItens == 0 ){
        free(gc->item);
        free(gc);
        return 1;
    }
 }
 return 0;
}
// Esvaziar o cofo
void gcofEmpty(gCofo *gc) {
    if (gc != NULL) {
        while (gc->numItens > 0) {
            void *removedItem = elemRemover(gc, gc->item[0]);
            free(removedItem);
        }
    }
}




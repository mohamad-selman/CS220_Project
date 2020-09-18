#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

void insert(Column *c, void *data, int rowNumber){
    Node **temp = &(c->head);
    while((*temp) != NULL){
        temp = &((*temp)->nextRow);
    }
    *temp = (Node *)malloc(sizeof(Node));
    
    switch(c->type){
        case INT:
            (*temp)->data.i = *(int *)data;
            break;
        case FLT:
            (*temp)->data.f = *(float *)data;
            break;
        case CHAR:
            (*temp)->data.c = *(char *)data;
            break;
        case STR:
            (*temp)->data.str = strdup((char *)data);
            break;
    }
    
    (*temp)->rowNumber = rowNumber;
    (*temp)->nextRow = NULL;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

void insert(Node **head, void *data, int type, int rowNumber){
    if(!(*head)){
        *head = (Node *)malloc(sizeof(Node));

        switch(type){
        case INT:
            (*head)->data.i = *(int *)data;
            (*head)->type = INT;
            break;
        case FLT:
            (*head)->data.f = *(float *)data;
            (*head)->type = FLT;
            break;
        case CHAR:
            (*head)->data.c = *(char *)data;
            (*head)->type = CHAR;
            break;
        case STR:
            (*head)->data.str = strdup((char *)data);
            (*head)->type = STR;
            break;
        }

        (*head)->rowNumber = rowNumber;
        (*head)->nextRow = NULL;
    }
    else{
        insert(&(*head)->nextRow, data, type, rowNumber);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

#define MAXWORD 500

Column * createTable(int c){
    Column *tempPtr = (Column *)malloc(c * sizeof(Column));
    for(int i=0; i<c; i++){
        tempPtr[i].head = NULL;
    }
    return tempPtr;
}

void readNames(Column *table, int c){
    puts("");
    for(int i=0; i<c; i++){
        printf("Enter the name of column no. %d: ", i+1);
        char name[MAXWORD];
        scanf("%s", name);
        table[i].columnName = strdup(name);
    }
    puts("");
}

void freeColumn(Node *head){
    if(head){
        if(head->nextRow){
            freeColumn(head->nextRow);
        }
        free(head);
    }
}

void freeTable(Column *table, int numberOfColumns){
    for(int i=0; i<numberOfColumns; i++){
        if(table[i].head){
            freeColumn(table[i].head);
        }
    }
    free(table);
}
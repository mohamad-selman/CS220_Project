#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

Column * createTable(int n){
    numberOfColumns = n;
    Column *tempPtr = (Column *)malloc(n * sizeof(Column));
    for(int i=0; i<n; i++){
        tempPtr[i].head = NULL;
    }
    return tempPtr;
}

void setColumns(Column *table){
    puts("");
    for(int i=0; i<numberOfColumns; i++){
        printf("Enter the name of column no. %d: ", i+1);
        char name[MAXWORD];
        scanf("%s", name);
        table[i].columnName = strdup(name);
        printf("Enter the type (int: 1, float: 2, char: 3, string: 4) of column no. %d: ", i+1);
        int t;
        scanf("%d", &t);
        table[i].type = t;
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

void freeTable(Column *table){
    for(int i=0; i<numberOfColumns; i++){
        if(table[i].head){
            freeColumn(table[i].head);
        }
    }
    free(table);
}

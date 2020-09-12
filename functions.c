#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int numOfRows(Node *head){
    Node *current = head;
    int n=0;

    while(current){
        n++;
        current = current->nextRow;
    }
    return n;
}

Node * select(Column *table, int row, int column){
    column--;
    Node *current = table[column].head;
    while(current->rowNumber != row && current->nextRow != NULL){
        current = current->nextRow;
    }
    return current;
}
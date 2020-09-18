#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

void delete(Column *table, int row, int column){
    Node *current = table[column-1].head;
    Node *prev = table[column-1].head;
    while(current->rowNumber != row){
        prev = current;
        current = current->nextRow;
    }

    if(current == table[column-1].head){
        Node *temp = (table[column-1].head)->nextRow;
        free(table[column-1].head);
        table[column-1].head = temp;
    }
    else{
        prev->nextRow = current->nextRow;
        free(current);
        current = prev;
    }
}

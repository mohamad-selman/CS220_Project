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

int highestRow(Column *table){
    int highest = -1;
    for(int i=0; i<numberOfColumns; i++){
        int t = numOfRows(table[i].head);
        if(t>highest){
            highest = t;
        }
    }

    return highest;
}

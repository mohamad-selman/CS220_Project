#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

Node * selectByIndex(Column *table, int row, int column){
    column--;
    Node *current = table[column].head;
    while(current->rowNumber != row && current->nextRow != NULL){
        current = current->nextRow;
    }
    return current;
}

Node ** search(Column *table, void *data, int type, int *n){
    int numberOfMatchings = 1, cntr=0;
    Node **matchings = (Node **)malloc(numberOfMatchings * sizeof(Node *));

    for(int i=0; i<numberOfColumns; i++){
        if(table[i].type != type){
            continue;
        }

        Node *current = table[i].head;
        while(current != NULL){
            if(type == INT && current->data.i == *(int *)data){
                matchings[cntr] = current;
                cntr++;
            }
            else if(type == FLT && current->data.f == *(float *)data){
                matchings[cntr] = current;
                cntr++;
            }
            else if(type == CHAR && current->data.c == *(char *)data){
                matchings[cntr] = current;
                cntr++;
            }
            else if(type == STR && strcmp(current->data.str, (char *)data)==0){
                matchings[cntr] = current;
                cntr++;
            }
            
            if(numberOfMatchings == cntr){
                numberOfMatchings++;
                matchings = realloc(matchings, numberOfMatchings * sizeof(Node *));
            }
            current = current->nextRow;
        }
    }

    *n = cntr;
    return matchings;
}

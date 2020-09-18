#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

void printRow(Column *table, FILE *outputFile, int rowIndex){
    for(int i=0; i < numberOfColumns; i++){
        Node *current = table[i].head;
        while(current != NULL){
            if(current->rowNumber == rowIndex ){
                switch(table[i].type){
                    case INT:
                        fprintf(outputFile, "%d", current->data.i);
                        break;
                    case FLT:
                        fprintf(outputFile, "%f", current->data.f);
                        break;
                    case CHAR:
                        fprintf(outputFile, "%c", current->data.c);
                        break;
                    case STR:
                        fprintf(outputFile, "%s", current->data.str);
                        break;
                    }
            }
            current = current->nextRow;
        }
        if(i+1 < numberOfColumns){
            fprintf(outputFile, ",");
        }
    }
    fprintf(outputFile, "\n");
}

void printTable(Column *table, FILE *outputFile){
    for(int i=0; i<numberOfColumns; i++){
        fprintf(outputFile, "%s", table[i].columnName);
        if(i+1 < numberOfColumns){
            fprintf(outputFile, ",");
        }
    }fprintf(outputFile, "\n");

    int n = highestRow(table);
    for(int i=1; i<=n; i++){
        printRow(table, outputFile, i);
    }
}

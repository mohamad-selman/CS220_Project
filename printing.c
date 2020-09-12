#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

void printRow(Column *table, int NumberOfColumns, FILE *outputFile, int rowIndex){
    for(int i=0; i < NumberOfColumns && table[i].head != NULL; i++){
        Node *current = table[i].head;
        while(current->rowNumber != rowIndex && current->nextRow != NULL){
            current = current->nextRow;
        }

        switch (current->type){
        case INT:
            fprintf(outputFile, "%d\t", current->data.i);
            break;
        case FLT:
            fprintf(outputFile, "%f\t", current->data.f);
            break;
        case CHAR:
            fprintf(outputFile, "%c\t", current->data.c);
            break;
        case STR:
            fprintf(outputFile, "%s\t", current->data.str);
            break;
        }   
    }
    fprintf(outputFile, "\n");
}

void printTable(Column *table, int numberOfColumns, FILE *outputFile){
    for(int i=0; i<numberOfColumns; i++){
        fprintf(outputFile, "%s\t", table[i].columnName);
    }fprintf(outputFile, "\n\n");

    int n = numOfRows(table[0].head);
    for(int i=1; i<=n; i++){
        printRow(table, numberOfColumns, outputFile, i);
    }
}
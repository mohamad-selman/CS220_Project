#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main(int argc, char *argv[]){
    FILE *outputFile = fopen("table.csv", "w");

    Column *table = createTable(2);
    setColumns(table);

    insert(&(table[0]), "A", 1);
    insert(&(table[0]), "A-", 2);
    insert(&(table[0]), "B+", 3);

    void *p;
    int integer;
    integer = 90; p = &integer;
    insert(&(table[1]), p, 2);

    integer = 95; p = &integer;
    insert(&(table[1]), p, 1);

    integer = 60; p = &integer;
    insert(&(table[1]), p, 3);

    // Node *cell = selectByIndex(table, 3, 2);
    // cell->data.i = 87;

    integer = 60; p = &integer;
    int n=0;
    Node **x = search(table, p, INT, &n);
    if(n>0){
        for(int i=0; i<n; i++){
            x[i]->data.i = 87;
        }
    }

    //delete(table, 1, 1);

    printTable(table, outputFile);
    puts("Table was printed to the file \"table.csv\"\n");

    freeTable(table);
    fclose(outputFile);
    return 0;
}

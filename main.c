#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main(int argc, char *argv[]){
    FILE *outputFile = fopen("table.txt", "w");

    // int c;
    // printf("Enter the number of columns: ");
    // scanf("%d", &c);

    Column *table = createTable(2);
    readNames(table, 2);

    void *p;
    char charcter;
    int integer;

    charcter = 'A'; p = &charcter;
    insert(&(table[0].head), p, CHAR, 1);

    
    insert(&(table[0].head), "A-", STR, 2);
    insert(&(table[0].head), "B+", STR, 3);

    integer = 90; p = &integer;
    insert(&(table[1].head), p, INT, 2);

    integer = 95; p = &integer;
    insert(&(table[1].head), p, INT, 1);

    integer = 60; p = &integer;
    insert(&(table[1].head), p, INT, 3);

    Node *cell = select(table, 3, 2);
    cell->data.i = 87;

    printTable(table, 2, outputFile);
    puts("Table was printed to the file \"Data.txt\"\n");

    freeTable(table, 2);
    fclose(outputFile);
    return 0;
}
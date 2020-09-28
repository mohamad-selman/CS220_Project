#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

int main(int argc, char *argv[]){
    FILE *socket = fopen("socket.txt", "r");
    FILE *outputFile = fopen("table.csv", "w");
    char line[MAXLINE];

    fgets(line, sizeof(line), socket);
    numberOfColumns = atoi(line);
    Column *table = createTable(numberOfColumns);
    
    for(int i=0; i<numberOfColumns; i++){
        fgets(line, sizeof(line), socket);
        line[strlen(line)-1]='\0';
        table[i].columnName = strdup(line);
        fgets(line, sizeof(line), socket);
        int t = atoi(line);
        table[i].type = t;
    }

    while(fgets(line, sizeof(line), socket) != NULL){
        char *token = strtok(line, ";");

        if(strcmp(token,"i") == 0){
            token = strtok(NULL, ";");
            int row = atoi(token);
            
            for(int i=0; i<numberOfColumns && token != NULL; i++){
                token = strtok(NULL, ";");

                int ti;
                double td;
                switch(table[i].type){
                    case INT:
                        ti = atoi(token);
                        insert(&(table[i]), (void *)&ti, row);
                        break;
                    case FLT:
                        td = atof(token);
                        insert(&(table[i]), (void *)&td, row);
                        break;
                    case CHAR:
                        insert(&(table[i]), (void *)(&token[0]), row);
                        break;
                    case STR:
                        insert(&(table[i]), (void *)token, row);
                        break;
                }
            }
        }
        else if(strcmp(token,"e") == 0){
            token = strtok(NULL, ";");
            int row = atoi(token);
            token = strtok(NULL, ";");
            int col = atoi(token);
            token = strtok(NULL, ";");

            Node *cell = selectByIndex(table, row, col);

            switch(table[col-1].type){
                case INT:
                    cell->data.i = atoi(token);
                    break;
                case FLT:
                    cell->data.f = atof(token);
                    break;
                case CHAR:
                    cell->data.c = token[0];
                    break;
                case STR:
                    cell->data.str = strdup(token);
                    break;
            }
        }
        else if(strcmp(token,"d") == 0){
            token = strtok(NULL, ";");
            int row = atoi(token);
            token = strtok(NULL, ";");
            int col = atoi(token);
            delete(table, row, col);
        }
    }

    printTable(table, outputFile);

    freeTable(table);
    fclose(outputFile);
    fclose(socket);

    return 0;
}

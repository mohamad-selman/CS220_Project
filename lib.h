#ifndef HEADER_FILE
#define HEADER_FILE

int numberOfColumns;
#define MAXWORD 500

typedef struct Node{
    union{
        int i;
        float f;
        char c;
        char *str;
    } data;
    int rowNumber;
    struct Node *nextRow;
} Node;

typedef struct Column{
    char *columnName;
    enum {INT=1, FLT, CHAR, STR} type; 
    Node *head;
} Column;

Column * createTable(int n);
void setColumns(Column *table);
void freeColumn(Node *head);
void freeTable(Column *table);
void insert(Column *c, void *data, int rowNumber);
int numOfRows(Node *head);
int highestRow(Column *table);
void printRow(Column *table, FILE *outputFile, int rowIndex);
void printTable(Column *table, FILE *outputFile);
Node * selectByIndex(Column *table, int row, int column);
void delete(Column *table, int row, int column);
Node ** search(Column *table, void *data, int type, int *n);

#endif

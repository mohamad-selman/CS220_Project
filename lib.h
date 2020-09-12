#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct Node{
    enum {INT=1, FLT, CHAR, STR} type;

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
    Node *head;
} Column;

Column * createTable(int c);
void readNames(Column *table, int c);
void freeColumn(Node *head);
void freeTable(Column *table, int numberOfColumns);
void insert(Node **head, void *data, int type, int rowNumber);
int numOfRows(Node *head);
void printRow(Column *table, int NumberOfColumns, FILE *outputFile, int rowIndex);
void printTable(Column *table, int numberOfColumns, FILE *outputFile);
Node * select(Column *table, int row, int column);

#endif
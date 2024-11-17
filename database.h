#ifndef DATABASE_H
#define DATABASE_H

#include "btree.h" // Importer les structures de btree.h

typedef struct {
    int id;
    char name[50];
} Row;

typedef struct {
    Row rows[100];
    int row_count;
} Table;

// Fonctions pour la gestion des tableaux
void insert_row(Table* table, int id, const char* name);
void display_table(const Table* table);
Row* find_row_by_id(Table* table, int id);
void delete_row(Table* table, int id);

#endif

#include "database.h"
#include <stdio.h>
#include <string.h>

void insert_row(Table* table, int id, const char* name) {
    if (table->row_count < 100) {
        table->rows[table->row_count].id = id;
        strncpy(table->rows[table->row_count].name, name, 50);
        table->row_count++;
    } else {
        printf("Table pleine, impossible d'ajouter une nouvelle ligne.\n");
    }
}

void display_table(const Table* table) {
    printf("Table actuelle:\n");
    for (int i = 0; i < table->row_count; i++) {
        printf("ID: %d, Nom: %s\n", table->rows[i].id, table->rows[i].name);
    }
}

Row* find_row_by_id(Table* table, int id) {
    for (int i = 0; i < table->row_count; i++) {
        if (table->rows[i].id == id) {
            return &table->rows[i];
        }
    }
    return NULL;
}

void delete_row(Table* table, int id) {
    int found = 0;
    for (int i = 0; i < table->row_count; i++) {
        if (table->rows[i].id == id) {
            found = 1;
            for (int j = i; j < table->row_count - 1; j++) {
                table->rows[j] = table->rows[j + 1];
            }
            table->row_count--;
            printf("Ligne avec ID = %d supprimée.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Aucune ligne avec ID = %d trouvée.\n", id);
    }
}

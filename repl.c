#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"

// Fonction REPL (Read-Eval-Print Loop)
void repl_loop() {
    BinaryTree tree = { .root = NULL };
    char command[256];

    printf("Welcome to the database REPL. Type 'help' for a list of commands.\n");

    while (1) {
        printf("db > ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("Error reading input. Exiting...\n");
            break;
        }

        // Commande 'exit' pour quitter
        if (strncmp(command, "exit", 4) == 0) {
            printf("Exiting...\n");
            free_tree(tree.root); // Libère toute la mémoire allouée
            break;
        }
        // Commande 'help' pour afficher les commandes disponibles
        else if (strncmp(command, "help", 4) == 0) {
            printf("Commands:\n");
            printf("  insert <ID> <Name> - Insert a node into the tree\n");
            printf("  select - Display all nodes in the tree\n");
            printf("  delete <ID> - Delete a node from the tree\n");
            printf("  save - Save the tree to a file\n");
            printf("  load - Load the tree from a file\n");
            printf("  exit - Quit the REPL\n");
        }
        // Commande 'insert' pour insérer un nœud dans l'arbre
        else if (strncmp(command, "insert", 6) == 0) {
            int id;
            char name[50];
            if (sscanf(command + 7, "%d %49s", &id, name) == 2) {
                insert_node(&tree, id, name);
                printf("Inserted: ID=%d, Name=%s\n", id, name);
            } else {
                printf("Usage: insert <ID> <Name>\n");
            }
        }
        // Commande 'select' pour afficher tous les nœuds
        else if (strncmp(command, "select", 6) == 0) {
            display_tree(tree.root);
        }
        // Commande 'delete' pour supprimer un nœud
        else if (strncmp(command, "delete", 6) == 0) {
            int id;
            if (sscanf(command + 7, "%d", &id) == 1) {
                delete_node(&tree, id);
            } else {
                printf("Usage: delete <ID>\n");
            }
        }
        // Commande 'save' pour sauvegarder l'arbre dans un fichier
        else if (strncmp(command, "save", 4) == 0) {
            FILE* file = fopen("tree_data.txt", "w");
            if (file != NULL) {
                save_tree(tree.root, file);
                fclose(file);
                printf("Tree saved to tree_data.txt\n");
            } else {
                printf("Error: Unable to save the tree.\n");
            }
        }
        // Commande 'load' pour charger un arbre depuis un fichier
        else if (strncmp(command, "load", 4) == 0) {
            FILE* file = fopen("tree_data.txt", "r");
            if (file != NULL) {
                free_tree(tree.root); // Libère l'ancien arbre
                tree.root = load_tree(file);
                fclose(file);
                printf("Tree loaded from tree_data.txt\n");
            } else {
                printf("Error: Unable to load the tree.\n");
            }
        }
        // Commande non reconnue
        else {
            printf("Unrecognized command: %s", command);
        }
    }
}

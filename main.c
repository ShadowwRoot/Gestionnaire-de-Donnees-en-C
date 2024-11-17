#include <stdio.h>
#include "database.h"
#include "btree.h"
#include "repl.h"

// Fonction pour exécuter les tests
void run_tests() {
    Table table = { .row_count = 0 };

    // Variables pour activer ou désactiver chaque test
    int run_insert_test = 1;
    int run_display_test = 1;
    int run_search_test = 1;
    int run_delete_test = 1;
    int run_binary_tree_insert_test = 1;
    int run_binary_tree_display_test = 1;

    // Tests pour les tableaux
    if (run_insert_test) {
        printf("== Test d'insertion dans la table ==\n");
        insert_row(&table, 1, "Alice");
        insert_row(&table, 2, "Bob");
        printf("Insertion effectuée.\n");
    }

    if (run_display_test) {
        printf("\n== Test d'affichage de la table ==\n");
        display_table(&table);
    }

    if (run_search_test) {
        printf("\n== Test de recherche dans la table ==\n");
        int search_id = 2;
        Row* result = find_row_by_id(&table, search_id);
        if (result != NULL) {
            printf("Ligne trouvée : ID = %d, Nom = %s\n", result->id, result->name);
        } else {
            printf("Ligne avec ID = %d non trouvée.\n", search_id);
        }
    }

    if (run_delete_test) {
        printf("\n== Test de suppression dans la table ==\n");
        delete_row(&table, 2);
        display_table(&table);
    }

    // Tests pour les arbres binaires
    BinaryTree tree = { .root = NULL };
    if (run_binary_tree_insert_test) {
        printf("\n== Test d'insertion dans l'arbre binaire ==\n");
        insert_node(&tree, 2, "Bob");
        insert_node(&tree, 1, "Alice");
        insert_node(&tree, 3, "Charlie");
        printf("Insertion dans l'arbre binaire effectuée.\n");
    }

    if (run_binary_tree_display_test) {
        printf("\n== Test d'affichage de l'arbre binaire ==\n");
        display_tree(tree.root);
    }

    free_tree(tree.root);
}

int main() {
    int choice = 0; // Initialisation à une valeur par défaut

    printf("Choisissez un mode :\n");
    printf("1. Mode Test\n");
    printf("2. Mode Interactif (REPL)\n");
    printf("Entrez votre choix : ");
    if (scanf("%d", &choice) != 1) {
        // Si l'entrée n'est pas un entier
        printf("Choix invalide. Quitter.\n");
        return 1;
    }

    switch (choice) {
        case 1:
            printf("Mode Test sélectionné.\n");
            run_tests(); // Appelle les tests
            break;
        case 2:
            printf("Mode Interactif sélectionné.\n");
            repl_loop(); // Passe en mode interactif
            break;
        default:
            printf("Choix invalide. Quitter.\n");
            break;
    }

    return 0;
}

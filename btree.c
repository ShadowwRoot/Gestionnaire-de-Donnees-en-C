#include "btree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Insère un nœud dans l'arbre binaire
void insert_node(BinaryTree* tree, int id, const char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Erreur : allocation mémoire échouée.\n");
        return;
    }
    new_node->id = id;
    strncpy(new_node->name, name, 50);
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node; // Si l'arbre est vide, le nœud devient la racine
        return;
    }

    Node* current = tree->root;
    while (1) {
        if (id < current->id) { // Aller à gauche
            if (current->left == NULL) {
                current->left = new_node;
                break;
            }
            current = current->left;
        } else { // Aller à droite
            if (current->right == NULL) {
                current->right = new_node;
                break;
            }
            current = current->right;
        }
    }
}

// Libère un nœud spécifique (si suppression implémentée)
void delete_node(BinaryTree* tree, int id) {
    // Implémentation minimale pour libérer le nœud correspondant
    printf("Suppression du nœud avec ID = %d (Non implémentée).\n", id);
}

// Libère l'arbre entier
void free_tree(Node* node) {
    if (node == NULL) {
        return;
    }
    free_tree(node->left);   // Libère le sous-arbre gauche
    free_tree(node->right);  // Libère le sous-arbre droit
    free(node);              // Libère le nœud actuel
}

// Affiche les nœuds de l'arbre
void display_tree(Node* node) {
    if (node == NULL) {
        return;
    }
    display_tree(node->left);
    printf("ID: %d, Nom: %s\n", node->id, node->name);
    display_tree(node->right);
}

// Sauvegarde l'arbre dans un fichier
void save_tree(Node* node, FILE* file) {
    if (node == NULL) {
        fprintf(file, "#\n");
        return;
    }
    fprintf(file, "%d %s\n", node->id, node->name);
    save_tree(node->left, file);
    save_tree(node->right, file);
}

// Charge l'arbre à partir d'un fichier
Node* load_tree(FILE* file) {
    char buffer[256];
    if (!fgets(buffer, sizeof(buffer), file)) {
        return NULL;
    }
    if (buffer[0] == '#') {
        return NULL;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    sscanf(buffer, "%d %49s", &new_node->id, new_node->name);
    new_node->left = load_tree(file);
    new_node->right = load_tree(file);

    return new_node;
}

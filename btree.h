#ifndef BTREE_H
#define BTREE_H

#include <stdio.h> // Ajout nécessaire pour le type FILE

typedef struct Node {
    int id;
    char name[50];
    struct Node* left;
    struct Node* right;
} Node;

typedef struct BinaryTree {
    Node* root;
} BinaryTree;

// Déclarations des fonctions
void insert_node(BinaryTree* tree, int id, const char* name);
void display_tree(Node* node);
void delete_node(BinaryTree* tree, int id);
void free_tree(Node* node);
void save_tree(Node* node, FILE* file);
Node* load_tree(FILE* file);

#endif

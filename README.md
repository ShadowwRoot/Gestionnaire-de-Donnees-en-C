FARSSI Samy


# Gestionnaire de Données avec Arbre Binaire

## Description
Ce projet est une application interactive en **C** permettant de gérer des données via un **arbre binaire**. 
Vous pouvez :
- Insérer des données (identifiant et nom).
- Afficher les données triées selon leur identifiant.
- Supprimer des données via leur identifiant.
- Sauvegarder et charger les données dans un fichier texte.

### Modes Disponibles :
1. **Mode Test** : Exécute des tests automatisés pour valider les fonctionnalités principales (insertion, affichage, suppression).
2. **Mode Interactif** : Permet une interaction en temps réel avec les données via des commandes.

---

## Technologies Utilisées
- **Langage** : C
- **Compilateur** : GCC (v10.3.0)
- **Outils** : Makefile pour automatiser la compilation.

---

## Prérequis
Avant de commencer, assurez-vous d'avoir les éléments suivants :
- **GCC** installé (vérifiez avec `gcc --version`).
- Un terminal ou une invite de commande pour exécuter les commandes.

---

## Installation
1. **Télécharger le projet :**
   - Clonez le projet depuis GitHub :
     ```bash
     git clone <URL_DU_DEPOT>
     cd <NOM_DU_DOSSIER>
     ```
2. **Compiler :**
   - Exécutez la commande suivante pour compiler le projet :
     ```bash
     make
     ```

---

## Exécution
### Lancer le programme :
- Sur **Linux/macOS** : 
  ```bash
  ./main
  ```
- Sur **Windows** : 
  ```bash
  ./main.exe
  ```

---

## Utilisation
### Sélection du mode :
Lors du lancement du programme, vous serez invité à choisir un mode :
```
1: Tests
2: Interactif
> 
```
- **Mode Test** : Exécute des tests automatiques pour valider les fonctionnalités principales.
- **Mode Interactif** : Permet d'utiliser des commandes pour gérer les données.

### Commandes Disponibles en Mode Interactif :
- **`insert <ID> <Nom>`** : Ajoute un élément dans l'arbre.
- **`select`** : Affiche tous les éléments triés par identifiant.
- **`delete <ID>`** : Supprime un élément via son identifiant.
- **`save`** : Sauvegarde les données dans un fichier texte (`tree_data.txt`).
- **`load`** : Charge les données depuis un fichier texte (`tree_data.txt`).
- **`exit`** : Quitte le programme.

---

## Exemple d'Utilisation :
1. **Insertion de données :**
 ```
   > insert 1 Alice
   > insert 2 Bob
   > insert 3 Charlie

   ```

2. **Affichage des données :**
   ```
   > select
   ID: 1, Nom: Alice
   ID: 2, Nom: Bob
   ID: 3, Nom: Charlie

   ```
3. **Sauvegarde :**
   ```
   > save
   ```
4. **Chargement :**
   ```
   > load
   ```

---

## Structure des Fichiers
- **main.c** : Contient la logique principale pour lancer le programme.
- **btree.c** : Gestion des opérations sur l'arbre binaire.
- **database.c** : Gestion des tables et des données tabulaires.
- **repl.c** : Interface utilisateur pour le mode interactif.
- **Makefile** : Automatisation de la compilation.
- **tree_data.txt** : Fichier utilisé pour la sauvegarde et le chargement des données.

---


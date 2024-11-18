
# Gestionnaire de Données avec Arbre Binaire

## Description
Ce projet est une application interactive en C permettant de gérer des données via un **arbre binaire**. Vous pouvez :
- Insérer des données (identifiant et nom).
- Afficher les données triées selon leur identifiant.
- Supprimer des données via leur identifiant.
- Sauvegarder et charger les données dans un fichier texte.

Le projet offre deux modes :
1. **Mode Test** : Exécute des tests automatisés pour valider les fonctionnalités principales.
2. **Mode Interactif** : Permet une interaction en temps réel avec les données via des commandes.

---

## Technologies Utilisées
- **Langage** : C.
- **Compilateur** : GCC (v10.3.0)
- **Outils** : Makefile pour l'automatisation de la compilation.

---

## Prérequis
Avant de commencer, assurez-vous d'avoir les éléments suivants :
- **GCC** installé (vérifiez avec `gcc --version`).
- Un terminal ou une invite de commande pour exécuter les commandes.

---

## Installation
1. Téléchargez tous les fichiers du projet dans un même répertoire.
2. Ouvrez un terminal dans ce répertoire.
3. Compilez le projet en utilisant la commande : ``` make```
  

---

## Exécution
### Lancer le programme :
- Sur **Linux/macOS** : 
  ```./main```
- Sur **Windows** : 
  ```main.exe```

### Sélection du mode :
Lorsque le programme démarre, vous serez invité à choisir un mode :
```
1: Tests
2: Interactif
> 
```

- **Mode Test** : Valide les fonctionnalités automatiquement (insertion, affichage, suppression).
- **Mode Interactif** : Vous pouvez manipuler l'arbre et la table en direct.

---

## Utilisation en Mode Interactif
Une fois en mode interactif, utilisez les commandes suivantes :
- `insert <ID> <Nom>` : Ajoute un élément dans l'arbre.
- `select` : Affiche tous les éléments triés par identifiant.
- `delete <ID>` : Supprime un élément via son identifiant.
- `save` : Sauvegarde les données de l'arbre dans le fichier `tree_data.txt`.
- `load` : Charge des données depuis le fichier `tree_data.txt`.
- `exit` : Quitte le programme.

### Exemple d'utilisation :
```
> insert 1 Alice
> insert 2 Bob
> insert 3 Charlie
> select
ID: 1, Nom: Alice
ID: 2, Nom: Bob
ID: 3, Nom: Charlie
> save
> exit
```

---



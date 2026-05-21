_This project has been created as part of the 42 curriculum by vihardy_

# 📌 ft_printf

## 📝 Description

Le projet **ft_printf** a pour objectif de recréer une version personnalisée de la fonction `printf` de la libc. Ce projet permet de comprendre en profondeur la gestion des formats ainsi que la manipulation des chaînes et des flux de sortie.

Avec la partie **bonus**, le projet étend la fonctionnalité du printf de base en ajoutant des options supplémentaires tout en respectant le comportement global attendu.

La partie mandatory inclue directement la partie **bonus** car mon algorithme est le meme pour les deux parties, make et make bonus font donc exactement la meme compilation.
---

## ⚙️ Instructions

### 🔧 Compilation

Utilisez le Makefile fourni pour compiler la librairie :

```sh
make        # compile la version obligatoire
make bonus  # compile la version bonus
make clean  # supprime les fichiers objets
make fclean # supprime les fichiers objets et la librairie
make re     # recompile depuis zéro
```

### 🚀 Utilisation

Après compilation, incluez `ft_printf.h` dans votre code et compilez votre programme avec la librairie générée :

```sh
gcc main.c libftprintf.a -o executable
```

L’appel à la fonction se fait ensuite comme avec `printf` :

```c
ft_printf("Valeur : %d\n", 42);
```

---

## 🧰 Choix techniques : Algorithmes & Structures de données

La fonction **ft_printf** repose sur un algorithme structuré en plusieurs étapes :

### 1. **Parcours séquentiel de la chaîne de format**

Chaque caractère est analysé un par un. Lorsqu’un symbole `%` est rencontré, l’algorithme identifie le type de conversion suivant.

### 2. **Délégation via un tableau de fonctions**

Chaque conversion (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`) est traitée par une fonction dédiée.

Ce choix repose sur :

* Une meilleure séparation des responsabilités ;
* Une meilleure lisibilité ;
* Une complexité maîtrisée ;
* Une extensibilité facilitée pour les bonus.

### 3. **Utilisation d’un buffer minimal**

Le projet ne demande pas d’optimisation de performance avancée, mais chaque fonction est pensée pour réduire les opérations inutiles.

### 4. **Gestion de la variadicité**

Le projet utilise `va_list`, `va_start`, `va_arg` et `va_end` pour gérer un nombre variable d’arguments. Une attention particulière est portée au typage et au traitement correct de chaque valeur.

### 5. Bonus

Les bonus incluent généralement :

* Le support des flags (`-`, `0`, `+`, espace, `#`)
* La gestion de la largeur et de la précision

---

## 📚 Ressources

Voici quelques références essentielles pour comprendre le fonctionnement d’un printf :

* Documentation `printf(3)` standard
* Article sur la variadicité en C
* Manuels sur la manipulation de chaînes en C
* Documentation POSIX sur les fonctions d’écriture (`write`)

### 💡 Usage de l’IA

L’IA a été utilisée pour :

* Reformuler certaines explications techniques pour une meilleure clarté ;
* Vérifier la lisibilité et la cohérence du README ;
* Générer une première version structurée du document.

Aucun code du projet n’a été généré par une IA.

---

## 🧪 Exemples d'utilisation

```c
ft_printf("%s possède %d pommes.\n", "Alice", 5);
ft_printf("Adresse mémoire : %p\n", ptr);
ft_printf("Hexa : %x | HEXA : %X\n", 255, 255);
```

---

## 🏁 Testeurs:

option 1: francinette
```sh
paco
paco -s
```

option 2: printfBetterTester
```sh
git clone https://github.com/ejacquem/printfBetterTester.git &&
cd printfBetterTester && make
```


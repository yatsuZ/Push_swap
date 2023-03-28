# Push_swap

<p align="center">
    <img  src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/push_swape.png" alt="Logo du projet push swap">
</p>
Push_swap est un projet de l'école 42 qui consiste à trier une pile d'entiers en utilisant un nombre limité d'opérations. Le but de ce projet est d'optimiser le nombre d'opérations nécessaires pour trier la pile.

## Installation

1. Clonez le dépôt Git sur votre ordinateur :

    ```bash
    git clone https://github.com/yatsuZ/PUSH_SWAP.git
    ```

2. Allez dans le dossier du projet :

    ```bash
    cd PUSH_SWAP/FIN
    ```

3. Compilez le programme :

    ```bash
    make
    ```

## Utilisation

Le programme prend en entrée une liste d'entiers non doublons séparés par des espaces et les empile sur la pile A. Vous pouvez utiliser la commande suivante pour lancer le programme :

```bash
./push_swap [liste d'entiers]
```

Par exemple :

```bash
./push_swap 3 1 4 2
```

OU

```bash
./push_swap "3 1 4 2"
```

Le programme affichera une série d'opérations à effectuer pour trier la pile A. Vous pouvez également utiliser la commande suivante pour visualiser les opérations en temps réel :

```bash
./push_swap [liste d'entiers] | ./checker [liste d'entiers]
```

## Fonctionnalités

Le projet comprend les fonctionnalités suivantes :

- Tri rapide et efficace de la pile A en utilisant un algorithme personnalisé.
- Affichage des opérations à effectuer pour trier la pile A.
- Vérification en temps réel de la validité des opérations pour trier la pile A.
- Gestion des erreurs et des cas spéciaux.

## Exemple de résultat

Voici un exemple de résultat pour la liste d'entiers "3 1 4 2" :

```bash
pb
sa
pb
pb
sa
pa
pa
pa
```

Ceci signifie que les opérations suivantes doivent être effectuées pour trier la pile A :

- Empiler le premier élément sur la pile B (pb).
- Échanger les deux premiers éléments de la pile A (sa).
- Empiler les deux premiers éléments de la pile A sur la pile B (pb pb).
- Échanger les deux premiers éléments de la pile A (sa).
- Replacer les éléments de la pile B sur la pile A dans l'ordre croissant (pa pa pa).

## Auteur

Ce projet a été réalisé par yzaoui à l'école 42.

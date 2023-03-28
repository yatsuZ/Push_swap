# Push_swap

<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/push_swape.png"
  alt="Logo du projet push swap">
</p>

Push_swap est un projet de l'école 42 qui consiste à trier des entiers,
mais avec 2 pile, pile 'a' et 'b'.
Mais la diffculte consiste a minimise le nombre d'operation.
Donc c'est un  projet basé sur l'algoritmy (c'est ce que j'aime dans le code :heart:).

## Status

Pas encore notée.

## Comment ai je proceder ?

Si vous voulez savoir comment j'ai cree push swap.
regarder ce fichier md -> [Creation du push swap de yassine](Creation_du_projet.md).

## Règle Push_Swap et classement

Le programme n'est autorisé à travailler qu'avec deux piles,
la pile A et la pile B.
Tous les nombres sont initialement ajoutés à la pile A et B est vide.

Les actions possibles sont :

| Code  | Instruction                         | Traduction                              | Action                                                                                                                   |
| ----- | ----------------------------------- | --------------------------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| `sa`  | swap a                              | échanger a                              | Intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.                   |
| `sb`  | swap b                              | échanger b                              | Intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.                   |
| `ss`  | swap a + swap b                     | échanger a  + échanger b                | sa et sb en même temps.                                                                                                  |
| `pa`  | push a                              | pousser a                               | Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.                                     |
| `pb`  | push b                              | pousser b                               | Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.                                     |
| `rb`  | rotate b                            | rotation b                              | Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.                |
| `ra`  | rotate a                            | rotation a                              | Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.                |
| `rr`  | rotate a + rotate b                 | rotation a + rotation b                 | ra et rb en même temps.                                                                                                  |
| `rra` | reverse rotate a                    | rotation inverse a                      | Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier                  |
| `rrb` | reverse rotate b                    | rotation inverse b                      | Décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.                 |
| `rrr` | reverse rotate a + reverse rotate b | rotation inverse a + rotation inverse b | rra et rrb en même temps.                                                                                                |

La note dépend de l'efficacité du processus de tri du programme.

- Tri 3 valeurs : pas plus de 3 actions.
- Tri 5 valeurs : pas plus de 12 actions.
- Tri de 100 valeurs : notation de 1 à 5 points deprend du nombre d'actions.

| Nombre de point | Score à avoir        |
| --------------- | -------------------- |
| 5 point         | moin de   700 action |
| 4 point         | moin de   900 action |
| 3 point         | moin de 1 100 action |
| 2 point         | moin de 1 300 action |
| 1 point         | moin de 1 500 action |

- Tri de 500 valeurs : notation de 1 à 5 points deprend du nombre d'actions.

| Nombre de point | Score à avoir         |
| --------------- | --------------------- |
| 5 point         | moin de  5 500 action |
| 4 point         | moin de  7 000 action |
| 3 point         | moin de  8 500 action |
| 2 point         | moin de 10 000 action |
| 1 point         | moin de 11 500 action |

## Explication Bonus

Le bonus consiste de faire son propre cheker comme "checker_linux" ou
"checker_Mac".
Il consistera a verifier que liste d'instruction permetra de bien trier
la pile.

----------------------------------------

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

Le programme prend en entrée une liste d'entiers sans doublons, séparés par des espaces.
les empile sur la pile A.

Vous pouvez utiliser la commande suivante pour lancer le programme :

```bash
./push_swap ["liste d'entiers"]
```

Par exemple :

```bash
./push_swap 3 1 4 2
```

OU

```bash
./push_swap "3 1 4 2"
```

Le programme affichera une série d'opérations à effectuer pour trier la pile A.
Vous pouvez également utiliser la commande suivante pour
visualiser les opérations en temps réel :

```bash
./push_swap ["liste d'entiers"] | ./checker ["liste d'entiers"]
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

Ceci signifie que les opérations suivantes doivent être effectuées
pour trier la pile A :

- Empiler le premier élément sur la pile B (pb).
- Échanger les deux premiers éléments de la pile A (sa).
- Empiler les deux premiers éléments de la pile A sur la pile B (pb pb).
- Échanger les deux premiers éléments de la pile A (sa).
- Replacer les éléments de la pile B sur la pile A dans
l'ordre croissant (pa pa pa).

## Avoir un visiluateur

voir ce repos si vous shouaiter avoir une interface visuel :
[visualisation](https://github.com/o-reo/push_swap_visualizer).

----------------------------------------

## Auteur

Ce projet a été réalisé par MOI !!! :smiley:

| Info          | Ou me retrouver                                                      |
| ------------- | -------------------------------------------------------------------- |
| Nom👋         | Zaoui                                                                |
| Prenom😄      | Yassine                                                              |
| Pseudo😁      | Yatsu                                                                |
| Login 42🏫    | Yzaoui                                                               |
| E-mail📬      | y.zaoui.pro@gmail.com                                                |
| E-mail42📩    | yzaoui@student.42.fr                                                 |
| Linkdin👨‍💻     | [Yassine Zaoui](https://www.linkedin.com/in/yassine-zaoui-23b005229/)|
| Instagram📸   | [@yatsu__officiel](https://www.instagram.com/yatsu__officiel/)       |

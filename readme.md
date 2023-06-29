# Push_swap

<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/push_swape.png"
  alt="Logo du projet push swap">
</p>

Push_swap est un projet de l'école 42 qui consiste à trier des entiers,
mais avec 2 pile, pile 'a' et 'b'.
Mais la diffculté consiste à minimiser le nombre d'opération.
Donc c'est un  projet basé sur l'algorythme (c'est ce que j'aime dans le code :heart:).

## Status

J'ai fais ma premiere correction à 114% mais je repasse mon pushswap.

## Comment ai-je procedé ?

Si vous voulez savoir comment j'ai crée push swap.
regardez ce fichier md -> [Creation du push swap de yassine](Creation_du_projet.md).

## Règle Push_Swap et classement

Si vous voulez savoir comment marche le systéme de notation.
regardez ce fichier md -> [Notation Push swap](Notation_Push_swap.md).


Le programme n'est autorisé à travailler qu'avec deux piles,
la pile A et la pile B.
Tous les nombres sont initialement ajoutés à la pile A tandis B est vide.

Les actions possibles sont :

| Code  | Instruction                         | Traduction                              | Action                                                                                                                   |
| ----- | ----------------------------------- | --------------------------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| `sa`  | swap a                              | échanger a                              | Intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.                   |
| `sb`  | swap b                              | échanger b                              | Intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.                   |
| `ss`  | swap a + swap b                     | échanger a  + échanger b                | sa et sb en même temps.                                                                                                  |
| `pa`  | push a                              | pousser a                               | Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.                                     |
| `pb`  | push b                              | pougitsser b                               | Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.                                     |
| `rb`  | rotate b                            | rotation b                              | Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.                |
| `ra`  | rotate a                            | rotation a                              | Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.                |
| `rr`  | rotate a + rotate b                 | rotation a + rotation b                 | ra et rb en même temps.                                                                                                  |
| `rra` | reverse rotate a                    | rotation inverse a                      | Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier                  |
| `rrb` | reverse rotate b                    | rotation inverse b                      | Décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.                 |
| `rrr` | reverse rotate a + reverse rotate b | rotation inverse a + rotation inverse b | rra et rrb en même temps.                                                                                                |

La note dépend de l'efficacité du processus de tri du programme.

- Tri 3 valeurs : pas plus de 3 actions.
- Tri 5 valeurs : pas plus de 12 actions.
- Tri de 100 valeurs : notation de 1 à 5 points dépend du nombre d'actions.

| Nombre de point | Score à avoir        |
| --------------- | -------------------- |
| 5 point         | moin de   700 action |
| 4 point         | moin de   900 action |
| 3 point         | moin de 1 100 action |
| 2 point         | moin de 1 300 action |
| 1 point         | moin de 1 500 action |

- Tri de 500 valeurs : notation de 1 à 5 points dépend du nombre d'actions.

| Nombre de point | Score à avoir         |
| --------------- | --------------------- |
| 5 point         | moin de  5 500 action |
| 4 point         | moin de  7 000 action |
| 3 point         | moin de  8 500 action |
| 2 point         | moin de 10 000 action |
| 1 point         | moin de 11 500 action |

## Explication Bonus

Le bonus consiste à faire son propre cheker.
Il consistera à verifier que la liste d'instruction et verifier que les liste dinstruction trie
bien la pile.

exemple :

```bash
ARG="(liste de nombres)"; ./checker $ARG
(Vous écrivez votre liste d'instructions, puis vous appuyez sur Ctrl+D lorsque vous avez terminé. Ensuite, le programme "checker" vous retournera quelque chose.)
```

```bash
Mais cela devrait aussi fonctionner comme ceci :

ARG="(liste de nombres)"; ./push_swap $ARG | ./checker $ARG
````
----------------------------------------

## Installation

Si vous voulez savoir comment utilise ou tester mon projet.
regardez ce fichier md -> [Tester Push swap](Tester_Push_swap.md).

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

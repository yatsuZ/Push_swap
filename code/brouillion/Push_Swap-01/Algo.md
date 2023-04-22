# Explication Algo

J'aurais 3 algo en fonction du nombre d'element dans la Pile A, Pour :

- 2 elements
- 3 elements.
- Plus 3 elements.

## 2 element

Si le plus petit n'est pas au debut faire SA.

## 3 element

pour x, y, z.

x > y > z.
donc avec les valeurs index sa va donner.
x = 2
y = 1
z = 0.

Il y a 6 combinaion possible. dont une que nous shouaitons :

|ID | ZERO | UN | DEUX | Trier | Qui est bien placer | Nombre minimume de mouve a faire |
|---|------|----|------|-------|-------------------------------|----------------------------------|
| 0 | 0    | 1  | 2    | OUI   | z, y, x                       | 0                                |
| 1 | 1    | 2  | 0    | OUI   | -                             | 1(rra)                           |
| 2 | 2    | 0  | 1    | OUI   | -                             | 1(ra)                            |
| 3 | 1    | 0  | 2    | NON   | x -> 2                        | 1(sa)                            |
| 4 | 2    | 1  | 0    | NON   | y -> 1                        | 2(rra, sa)                       |
| 5 | 0    | 2  | 1    | NON   | z -> 0                        | 2(ra, sa)                        |

| Note a moi : La commande SA ne sert que pour les piles qui on 3 ou 2 element.
Et je ne vois pas d'autre utilité a cette commande surtout SB.

Si les 2 premier element son bien placer alors c'est trier.
Si il n'y a aucun element qui est bien placer alors c'est trier,
il faudra faire tourner les element.
Sinon si la pile a n'est pas trier on essayera de faire en sorte que l'ID 4 et 5,
converge vers l'ID 3 qui est le plus cour et on se fie par raport a quelle element est bien placer.

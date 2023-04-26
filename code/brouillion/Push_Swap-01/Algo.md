# Explication Algo

J'aurais 3 algo en fonction du nombre d'element dans la Pile A, Pour :

- 2 elements
- 3 elements.
- Plus 3 elements.

## 2 element

Si le plus petit n'est pas au debut, faire SA.

## 3 element

pour c, b, a.

c > b > a.
donc avec les valeurs index ca va donner :

c = 2 |
b = 1 |
a = 0.

Il y a 6 combinaion possible. dont une que nous shouaitons :

|ID | \[0] | \[1] | \[2] | Trier | Qui est bien placer              | Nombre minimume de mouve a faire |
|---|------|------|------|-------|----------------------------------|----------------------------------|
| 0 | a    | b    | c    | OUI   | a, b, c                          | 0                                |
| 1 | b    | c    | a    | OUI   | -                                | 1(rra)                           |
| 2 | c    | a    | b    | OUI   | -                                | 1(ra)                            |
| 3 | b    | a    | c    | NON   | c -> \[2]                        | 1(sa)                            |
| 4 | c    | b    | a    | NON   | b -> \[1]                        | 2(rra, sa)                       |
| 5 | a    | c    | b    | NON   | a -> \[0]                        | 2(ra, sa)                        |

| Note a moi : La commande SA ne sert que pour les piles qui on 3 ou 2 element.
Et je ne vois pas d'autre utilité a cette commande surtout SB.

Si les 2 premier element son bien placer alors c'est trier.

Si il n'y a aucun element qui est bien placer alors c'est trier,
il faudra faire tourner les element.

Sinon si la pile a n'est pas trier on essayera de faire en sorte que l'ID 4 et 5,
converge vers l'ID 3 qui est le plus cour et on se fie par raport a quelle element est bien placer.

## Pour plus de 3 element

Nous transvaseront tout les mayon de la pile A dans B.

Sauf le plus petit, la median et le plus grand ou (Tant que la pile A n'est pas trier).

Crée un fonction qui fais cette etape : :x: .

Ensuite nous aurons plus qu'a faire pour chaque somet de la pile b bien placer les elements pour qu'il soit range
Exemple :

PA = 0, 5, 10
PB = 7, 3

Le 7 se place entre le 5 et 10, donc on decale la PA puis faire un Push A.
Puis en place la PB et on place le 3.

Pour optimiser les coupjai une formule :

Trie un mayon = Coup pour le placer un somet de la pile B + Coup pour ranger dans la pile A + Est il le mieux range

et on executera laction le plus petit coup de trie.

T = CP + CR + R.

CP = coup placement on va juste voir dans la PB quelle est le mieux entre rotate
B ou reverse rotate B pour chaque mayon de la pile B.

CR = Coup de rangement Pour chaque mayon nous alons voir combien de fois faudra til faire Rotate A ou Reverse Rotate A.
Pour que la valeur du mayon soit bien placer apres un PUSH A.

R = rangement on regarde si la valeur suit directement u  mayon suivant ou precendent.

On regarde pour chaque mayon le coup le plus faible pour chaque iteration on est sensée avoir un rangement de pile.
Optimise.

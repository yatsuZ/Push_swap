# Création du projet

Note a moi meme me renseignier sur les "enum" pour deffinir SA, SB ... etc.

## Présentation du projet

Le projet "Push_swap" consiste à trier une pile d'entiers en utilisant un nombre
limité d'opérations.
Ce projet est réalisé dans le cadre de l'école 42.

### Regle

La variable **z** sont des int, size_t, long etc qui son initialise à 0 pour
des raison de gain de ligne.

Les variable **i**, **j** sont des variables qui sont utilise comme Index pour
se deplacer dans les tableaux.

"g_text_error" dans *./utils/affichage.c* est un tableau contenant tout
mes message de texte.

## Étape 0 : Organisation du code

Avant de commencer à coder,
il est important de réfléchir à l'organisation du code.
Pour ce projet,
nous allons utiliser une structure de dossier similaire à celle-ci :

```txt
push_swap/
├── libft/
│   └── ...
├── Instruction/
│   ├── instructions.c
│   ├── push_a.c
│   └── ...
├── utils/
│   ├── affichage.c
│   ├── error.c
│   └── ...
├── srcs/
│   ├── main.c
│   ├── main.c
│   └── parsing.c
├── Creation_du_projet.md
├── Makefile
├── push_swap.h
└── ...
```

Dans ce dossier, nous avons :

- Un dossier libft contenant tout mes code de projet precedent donc : libft + GNL + FT_PRINTF.
- Un dossier Instruction contenant tout les actions possible du style rra rpa etc...
- Un dossier utils contenannt des fonction utile affichage et gestion d'erreur etc.
- Un dossier srcs contenant les fichiers sources du projet specifique a
la resolution du problème pushswap.
- Un fichier Creation_du_projet.md c'est un fichier qui suit l'avancement du projet.
- Un fichier push_swap.h qui est le headers pour srcs.
- Un fichier Makefile qui gère la compilation du projet.

### Étape 0 FINI

## Étape 1 : Importation de libft, printf GNL et création du Makefile et .h

Dans cette etape je vais reunir :

- PRINTF
- Libft
- GNL

> Dans le sujet de 42 ->

```md
Les variables globales sont interdites.
```

Dans le meme dossier dans la meme header et meme Makefile pour que tout soit reuni.
Je ferais des testes pour verifier que tout fonctione ensemble.
resultat du test : :white_check_mark:.

> dans le sujet ->

```md
- Vous devez rendre un Makefile qui compilera vos fichiers sources. Il ne doit pas
relink.

- Vous devez écrire un programme nommé **push_swap** qui prend en paramètre la
pile *a* sous la forme d’une liste d’entiers. Le premier paramètre est au sommet de
la pile (attention donc à l’ordre).
```

Puis je crée le makefile a la racine et verifier qu'il crée bien le programe esconter.
resultat du test : :white_check_mark:.

Concernant push_swap.h je dois trouver une structure pour mes 2 pile. :brain:

La voici ! :

```h
// Cree la structur d'un mayon
typedef struct s_mayon
{
 int    val;
 size_t index;
 size_t position;
 t_mayon *next;
 t_mayon *previous;
} t_mayon;

// Cree la structur contenant les 2 pile
typedef struct s_pile
{
 t_mayon *a;
 t_mayon *b;
 size_t  len_a;
 size_t  len_b;
 size_t  len_total;
} t_pile;
```

> Explication :

Il y aura une premiere structure **t_pile**
qui contiendra les attribut suivant :

- a, b  = qui correspondront à la pile "a" et
"b".
- len_total = la somme total de tout les elements.
- len_a     = la somme de tout les elements de a.
- len_b     = la somme de tout les elements de b.

J'ai decider que mes Pile A et B seront dans une structure
similaire à une list.
Ma structure sera compose :

- val       = la valeur de l'element *d'int min à int max*.
- index     = le positionement que devrai avoir
le mayon par raport à sa valeur Exemple:

```c
valeur  -> [10, 100, 3, 1, 12]
index   -> [ 4,   5, 2, 1,  3]
```

- position  =  le positionement que devrais avoir sont
placement de la pile.
En gros si l'element placer au debut de la pile 0
puis 1 ...etc. Je ne sait pas si cette ettribut est utilis.

- next      = l'element *suivant* dans la pile.
Je ne sais pas si pour le dernier mayon next sera NULL
ou le premier element.
- previous  = l'element *precedent* dans la pile.
Je ne sais pas si pour le premier mayon sa sera NULL
ou le dernier element.

Pour next, previous et position je verrais si ils
seront modifier plus tard.

> Pourquoi ce choix ??

Car au final la structure de Pile et plus facilement modable
pour le futur comparrer aux tableau.
Le fais que se soit plus modable et un atout car c'est un bon
attout quand on as pas trop d'idee precise sur
comment resoudre le problème algoritmy.

Plus opti aussi !! en comparison du tableau.
Dans un tableaux quand si je devrais deplacer UN SEUL element
Eh bien tout serais deplacer aussi et changerais de place
ce qui n'est pas ouf.

> SOURCE : Critstaline.:😂.

(C'est une blague par rapport au fais que c'est une suposition).

J'avais sur estimer la complexité des liste dans mon ancien
brouillion.

### Étape 1 FINI

## Étape 2 : crée un Parsing

> :information_source: Un Parsing sera une fonction qui verifira que
> les inputs sont correcte
>
> dans le sujet de 42 ->

```md
- Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre
l’invite de commande.

- En cas d’erreur, vous devez afficher "Error" suivi d’un ’\n’ sur la sortie d’erreur.
Par exemple, si certains paramètres ne sont pas des nombres, ne tiennent pas dans
un int, ou encore, s’il y a des doublons.

...

(consigne pour le bonus)
- En cas d’erreur, vous devez afficher "Error" suivi d’un ’\n’ sur la sortie d’erreur.
Par exemple, si certains paramètres ne sont pas des nombres, ne tiennent pas dans
un int, s’il y a des doublons ou, bien sûr, si une instruction n’existe pas ou est
mal formatée.
```

Un input incoreccte c'est :

- Si certains paramètres ne sont pas des nombres. ERROR !

- Si la valeur n'est pas compris dans les int. ERROR !
- Si il y a une redondonce c'est a dire 2 fois la meme valeur.
ERROR !
- Si l'instruction "pb", etc.. est mal formattée ou n'existe pas. ERROR !
- Appliquer l'erreur de formatage ?? ambigue car les quelle
sont des erreur de formatage :

```bash
cas 1 $>./push_swap 3- 1 0
cas 2 $>./push_swap 3+ 1 0
cas 3 $>./push_swap p3 1 0
cas 4 $>./push_swap "3 1 0"
cas 5 $>./push_swap 0000003 1 0
cas 6 $>./push_swap 3 "1 0" 12
```

> Alors le parsing retournera :

```c
NULL
```

> Je devrais tout *free* et avoir aucun problème de segmentation fault.
> Et le programme devra retourner **"Error" suivi d’un ’\n’** sur la sortie d’erreur
> c'est a dire

```c
write(2, "Error\n", 6)
```

> Sinon si correcte ALORS
>
> retournera une structure **t_mayon** puis l'atribut *a* recevra le mayon.

Le parsing est cree et cree une pile uniquement si les condition son valide

Resultat du test : :white_check_mark: .

## Crée les action possible

maintenant je dois crée les fonctions et pour caque foncion ils devrons afficher 'sa'etc :

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

Creation FINI : :white_check_mark: .

Verifier que les fonction marche sans leak et sans problème.
Verification des fonctions : :x:.

Crée le fichier Instruction/instructions.c pour metre dans un tableau toutes les fonctions
d'instruction, pour qu'on puisse tout gerer dans un seul endroit.

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

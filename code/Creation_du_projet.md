# Création du projet

## Présentation du projet

Le projet "Push_swap" consiste à trier une pile d'entiers en utilisant un nombre
limité d'opérations.
Ce projet est réalisé dans le cadre de l'école 42.

## Étape 0 : Organisation du code

Avant de commencer à coder,
il est important de réfléchir à l'organisation du code.
Pour ce projet,
nous allons utiliser une structure de dossier similaire à celle-ci :

```txt
push_swap/
├── libft/
│   └── ...
├── srcs/
│   ├── main.c
│   └── ...
├── Makefile
├── push_swap.h
└── ...
```

Dans ce dossier, nous avons :

- un dossier libft contenant tout mes code de projet precedent donc : libft + GNL,
- un dossier srcs contenant les fichiers sources du projet specifique a pushswap,
et d'autre sous dossier si il le faut.
- un fichier push_swap.h qui est le headers pour srcs,
- un fichier Makefile qui gère la compilation du projet.

### Étape 0 FINI

## Étape 1 : Importation de libft, printf GNL et création du Makefile et .H

Dans cette etape je vais reunir :

- PRINTF
- Libft
- GNL

Dans le meme dossier dans la meme header et meme Makefile pour que tout soit reuni.
Je ferais des testes pour verifier que tout fonctione ensemble.
resultat du test : :white_check_mark:.

Puis je crée le makefile a la racine et verifier qu'il crée bien le programe esconter.
resultat du test : :white_check_mark:.

Concernant push_swap.h je dois trouver une structure pour mes 2 pile. :brain:

La voici ! :

```h
// Cree la structur des pile a b
typedef struct s_pile_ab
{
 long *tab;
 long len;
 size_t seperateur;
} t_pile_ab;
```

> Explication :

J'ai decider que mes Pile A et B seront dans un seul Tableau.
ma structure sera compose :

- tab = un tableau de long.
- len = la longuer de tab.
- seperateur = qui sera un index qui delimite la pile A et B.

En gros au depart tout les nombre seront dans la pile A donc

> tab = [...]
>
> len = longuer de tab
>
> seperateur = 0

Quand je metrais un element dans la pile B et bien seperateur sacremente
je place l'element au debut de ma pile et
le seperateur sera la fin de la pile B et le debut de la pile A.

> Pourquoi ce choix ??

Plusieur personne on utilise des pile mais je pense que le faire avec un tableau
sera plus simple pour ce qu'il sagira de se deplacer dans la data.

### Étape 1 FINI

## Étape 2 : crée un checker

> :information_source: Un checker sera une fonction qui verifira que
> les inputs sont correcte et retournera une structure t_pile_ab pour

```h
tab = ['tout ce que le cheker aura lu']

len = longuer de tab

seperateur = 0
```

> Si les input son incorrectte
> (Si il y a des doublons et si le type n'est pas un long)
> Alors le cheker retournera :

```c
NULL
```

Apres avoir crée le cheker je le testerais.

Resultat du test : :x:.

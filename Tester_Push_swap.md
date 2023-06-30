# Tester mon programme Push Swap

Pour tester mon programme Push Swap, suivez les étapes ci-dessous :

1. Clonez ce dépôt Git sur votre machine :

``` shell
git clone [URL_DU_REPO]
```

2. Accédez au répertoire ./Push_swap_code.

3. Compilez les programmes en exécutant les commandes make et make bonus.

4. Une fois la compilation terminée, vous disposerez de deux programmes exécutables : ./push_swap et ./checker.

Ce sont ces deux programmes que vous devez tester. Vous pouvez utiliser les commandes suivantes :

Pour tester le programme Push Swap et vérifier si la liste d'instructions est valide et trie ARG :

```bash
ARG="(liste de nombres)"; ./push_swap $ARG | ./checker $ARG
```

Ou simplement exécuter le programme Push Swap sans vérification :

```bash
ARG="(liste de nombres)"; ./push_swap $ARG
```

Je vous conseille d'utiliser un testeur et/ou un visualiseur pour obtenir une meilleure vision du fonctionnement du programme.

Conseil pour le testeur : https://github.com/SimonCROS/push_swap_tester

Conseil pour le visualiseur : https://github.com/o-reo/push_swap_visualizer

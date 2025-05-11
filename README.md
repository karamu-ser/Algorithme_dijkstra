# Algorithme de Dijkstra en C

Ce projet implémente l'algorithme de Dijkstra pour calculer les plus courts chemins dans un graphe pondéré. Le graphe est représenté sous forme de liste d'adjacence, et l'algorithme est utilisé pour déterminer la distance minimale depuis un sommet source vers tous les autres sommets.

## Table des matières

- [Description](#description)
- [Fonctionnement](#fonctionnement)
- [Structure du Code](#structure-du-code)
- [Compilation et Exécution](#compilation-et-exécution)
- [Exemple](#exemple)

## Description

Ce projet met en œuvre l'algorithme de Dijkstra pour déterminer les plus courts chemins dans un graphe avec des arêtes pondérées. Le graphe est représenté par un tableau de listes d'adjacence, et l'algorithme calcule les distances minimales pour chaque sommet depuis un sommet source donné.

Le programme affiche l'état du graphe à chaque itération de l'algorithme, y compris les sommets marqués et les distances mises à jour.

## Fonctionnement

1. **Représentation du graphe** : Le graphe est représenté sous forme d'un tableau de listes d'adjacence, où chaque entrée du tableau correspond à un sommet et contient une liste de ses voisins ainsi que les poids des arêtes qui les relient.
   
2. **Initialisation** : Toutes les distances sont initialisées à l'infini, sauf pour le sommet source qui a une distance de 0. Les sommets non visités sont marqués comme non traités.
   
3. **Exécution de l'algorithme** : À chaque itération, l'algorithme sélectionne le sommet avec la plus petite distance parmi les sommets non visités. Ce sommet est marqué comme visité, et les distances de ses voisins sont mises à jour si une distance plus courte est trouvée.

4. **Affichage des résultats** : Une fois l'algorithme terminé, les distances finales et les prédécesseurs de chaque sommet sont affichés. En outre, les chemins les plus courts depuis le sommet source sont montrés.

## Structure du Code

### Structures

- **`AdjListNode`** : Représente un nœud dans la liste d'adjacence, contenant un sommet de destination, un poids d'arête et un pointeur vers le nœud suivant.
- **`AdjList`** : Représente une liste d'adjacence pour un sommet donné.
- **`Graphe`** : Représente le graphe lui-même, incluant un tableau de listes d'adjacence et le nombre total de sommets.
- **`Noeud`** : Structure qui stocke un sommet dans un tableau, avec sa distance et son prédécesseur.

### Fonctions

- **`nouveauAdjListNode`** : Crée un nouveau nœud pour la liste d'adjacence d'un sommet.
- **`creerGraphe`** : Crée un graphe avec un nombre de sommets spécifié.
- **`ajouterArete`** : Ajoute une arête entre deux sommets avec un poids donné.
- **`afficherResultats`** : Affiche les résultats finaux après l'exécution de l'algorithme, y compris les distances et les prédécesseurs.
- **`minDistance`** : Trouve le sommet non visité ayant la distance minimale.
- **`afficherChemin`** : Affiche le chemin le plus court d'un sommet source vers un sommet de destination.
- **`dijkstra`** : Implémente l'algorithme de Dijkstra pour trouver les plus courts chemins depuis un sommet source.

## Compilation et Exécution

### Compilation

Pour compiler le programme, utilisez la commande suivante dans un terminal, en supposant que vous avez installé un compilateur C comme `gcc` :

```bash
make
```
### execution
```bash
./dijkstra_prog 
```

### exemple
![exemple](/exemple_execution.png)

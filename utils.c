#include "header.h"

AdjListNode* nouveauAdjListNode(int dest, int poids)
{
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    newNode->dest = dest;
    newNode->poids = poids;
    newNode->next = NULL;
    return newNode;
}


Graphe* creerGraphe(int V)
{
    Graphe* graphe = (Graphe*)malloc(sizeof(Graphe));
    if (graphe == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    graphe->V = V;
    graphe->array = (AdjList*)malloc(V * sizeof(AdjList));
    if (graphe->array == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < V; ++i) {
        graphe->array[i].head = NULL;
    }

    return graphe;
}


void ajouterArete(Graphe* graphe, int src, int dest, int poids)
{
    AdjListNode* newNode = nouveauAdjListNode(dest, poids);
    newNode->next = graphe->array[src].head;
    graphe->array[src].head = newNode;
}

void afficherResultats(int dist[], int pred[], int n, char sommets[])
{
    printf("\nRésultats finaux:\n");
    printf("Sommet\tDistance\tPrédécesseur\n");
    for (int i = 0; i < n; i++) {
        printf("%c\t", sommets[i]);
        if (dist[i] == INFINI)
            printf("INFINI\t\t");
        else
            printf("%d\t\t", dist[i]);
        
        if (pred[i] == -1)
            printf("nul\n");
        else
            printf("%c\n", sommets[pred[i]]);
    }
}

int minDistance(int dist[], bool marque[], int V)
{
    int min = INFINI, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (marque[v] == false && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void afficherChemin(int pred[], int dest, char sommets[])
{
    if (pred[dest] == -1) {
        printf("%c", sommets[dest]);
        return;
    }
    
    afficherChemin(pred, pred[dest], sommets);
    printf(" -> %c", sommets[dest]);
}

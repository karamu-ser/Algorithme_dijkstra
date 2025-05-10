#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define INFINI INT_MAX
#define MAX_SOMMETS 5

typedef struct AdjListNode {
    int dest;                  
    int poids;                 
    struct AdjListNode* next;
} AdjListNode;


typedef struct AdjList {
    struct AdjListNode* head; 
} AdjList;


typedef struct Graphe {
    int V;              
    struct AdjList* array;    
} Graphe;


typedef struct Noeud {
    int sommet;
    int dist;
    int pred;
} Noeud;

AdjListNode* nouveauAdjListNode(int dest, int poids);
Graphe* creerGraphe(int V);
void ajouterArete(Graphe* graphe, int src, int dest, int poids);
void afficherResultats(int dist[], int pred[], int n, char sommets[]);
int minDistance(int dist[], bool marque[], int V);
void afficherChemin(int pred[], int dest, char sommets[]);
void dijkstra(Graphe* graphe, int src, char sommets[]);

#endif
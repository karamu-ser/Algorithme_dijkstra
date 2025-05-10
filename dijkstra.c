#include "header.h"

void dijkstra(Graphe* graphe, int src, char sommets[])
{
    int V = graphe->V;
    int dist[V]; 
    int pred[V];      
    bool marque[V]; 

    for (int i = 0; i < V; i++) {
        dist[i] = INFINI;
        pred[i] = -1;
        marque[i] = false;
    }
    dist[src] = 0;
    printf("Exécution de l'algorithme de Dijkstra:\n");
    printf("Itération\tmin_dist_M\tM\t\td(A)\td(B)\td(C)\td(D)\td(E)\tP(A)\tP(B)\tP(C)\tP(D)\tP(E)\n");
    printf("Initialisation\t0\t\tØ\t");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INFINI)
            printf("+∞\t");
        else
            printf("%d\t", dist[i]);
    }
    
    for (int i = 0; i < V; i++) {
        if (pred[i] == -1)
            printf("nul\t");
        else
            printf("%c\t", sommets[pred[i]]);
    }
    printf("\n");
    int iteration = 0;
    char marques[V * 2];
    marques[0] = '\0';
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, marque, V);
        if (u == -1) 
            break;
        marque[u] = true;
        if (marques[0] != '\0') {
            char temp[3] = ", ";
            temp[2] = '\0';
            strcat(marques, temp);
        }
        char temp[2] = {sommets[u], '\0'};
        strcat(marques, temp);
        iteration++;
        AdjListNode* pCrawl = graphe->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;
            
            if (!marque[v] && dist[u] != INFINI && 
                dist[u] + pCrawl->poids < dist[v]) {
                dist[v] = dist[u] + pCrawl->poids;
                pred[v] = u;
            }
            pCrawl = pCrawl->next;
        }
        printf("%d\t\t%d\t\t{%s}\t", iteration, dist[u], marques);
        
        for (int i = 0; i < V; i++) {
            if (dist[i] == INFINI)
                printf("+∞\t");
            else
                printf("%d\t", dist[i]);
        }
        
        for (int i = 0; i < V; i++) {
            if (pred[i] == -1)
                printf("nul\t");
            else
                printf("%c\t", sommets[pred[i]]);
        }
        printf("\n");
    }
    afficherResultats(dist, pred, V, sommets);
    printf("\nChemins les plus courts depuis %c:\n", sommets[src]);
    for (int i = 0; i < V; i++) {
        if (i != src) {
            printf("Vers %c: ", sommets[i]);
            if (dist[i] == INFINI)
                printf("Pas de chemin\n");
            else {
                afficherChemin(pred, i, sommets);
                printf(" (distance = %d)\n", dist[i]);
            }
        }
    }
}

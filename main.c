#include "header.h"

int main()
{
    char sommets[MAX_SOMMETS] = {'A', 'B', 'C', 'D', 'E'};

    Graphe* graphe = creerGraphe(MAX_SOMMETS);

    ajouterArete(graphe, 0, 1, 4); 
    ajouterArete(graphe, 0, 2, 2); 
    ajouterArete(graphe, 0, 3, 4); 

    ajouterArete(graphe, 1, 0, 4); 
    ajouterArete(graphe, 1, 2, 1); 
    ajouterArete(graphe, 1, 4, 2); 

    ajouterArete(graphe, 2, 0, 2); 
    ajouterArete(graphe, 2, 1, 1); 
    ajouterArete(graphe, 2, 3, 2); 
    ajouterArete(graphe, 2, 4, 4); 

    ajouterArete(graphe, 3, 0, 4); 
    ajouterArete(graphe, 3, 2, 2); 
    ajouterArete(graphe, 3, 4, 4); 

    ajouterArete(graphe, 4, 1, 2); 
    ajouterArete(graphe, 4, 2, 4); 
    ajouterArete(graphe, 4, 3, 4); 

    dijkstra(graphe, 0, sommets);

    for (int i = 0; i < MAX_SOMMETS; i++) {
        AdjListNode* pCrawl = graphe->array[i].head;
        while (pCrawl) {
            AdjListNode* temp = pCrawl;
            pCrawl = pCrawl->next;
            free(temp);
        }
    }
    free(graphe->array);
    free(graphe);
    return 0;
}
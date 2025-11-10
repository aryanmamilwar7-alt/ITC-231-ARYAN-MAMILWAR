#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct edge {
    int src, dest, weight;
};
struct subset {
    int parent, rank;
};
int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int compare(const void *a, const void *b) {
    struct edge *a1 = (struct edge *)a;
    struct edge *b1 = (struct edge *)b;
    return a1->weight - b1->weight;
}
void KruskalMST(struct edge edges[], int V, int E) {
    struct edge result[MAX]; 
    int e = 0; 
    int i = 0; 
    qsort(edges, E, sizeof(struct edge), compare);
    struct subset *subsets = (struct subset *) malloc(V * sizeof(struct subset));

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < E) {
        struct edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    printf("\nEdges in the Minimum Spanning Tree:\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost of Spanning Tree = %d\n", minimumCost);
}
int main() {
    int V, E;
    struct edge edges[MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter each edge (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d%d%d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
    KruskalMST(edges, V, E);
    return 0;
}

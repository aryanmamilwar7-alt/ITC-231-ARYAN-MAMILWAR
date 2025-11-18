#include <stdio.h>
#define MAX 30

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int cost[MAX][MAX], i, j, n = 4;
    int put[10], mincost = 0;
    int count = 1;

    for(i = 1; i <= n; i++)
        parent[i] = i;

    printf("\n Enter the number of vertices : ");
    scanf("%d", &n);
    printf("\n Enter the cost adjacency matrix : \n");

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\n Edge having least cost : Spanning tree : \n");

    while(count < n) {
        int min = 999, a = -1, b = -1;
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        int u = find(a);
        int v = find(b);
        if(u != v) {
            printf("\n (%d, %d) = %d", a, b, min);
            union1(u, v);
            mincost += min;
            count++;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\n Minimum cost = %d", mincost);

    return 0;
}

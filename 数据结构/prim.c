
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 7


int minKey(int key[], bool mstSet[])
{
  
    int min = INT_MAX, min_index;
	int v = 0;
    for(v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}


int printMST(int parent[], int graph[V][V])
{
	int i = 1;
    printf("Edge \tWeight\n");
    for(i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}


void primMST(int graph[V][V])
{
  
    int parent[V];
   
    int key[V];
    int count = 0;

    bool mstSet[V];

	int i = 0;
 
    for(i=0;i< V;i++)
        key[i] = INT_MAX, mstSet[i] = false;

  
    key[0] = 0;
    parent[0] = -1; 

  
    for(count = 0; count < V - 1; count++) {

        int u = minKey(key, mstSet);


        mstSet[u] = true;
		int v = 0;

        for(v = 0; v < V; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

 
    printMST(parent, graph);
}


int main()
{
 

    int graph[V][V] = { { 0, 5, 8, 7, 0, 3},
                        { 5,0,4,0,0,0},
                        { 8,4,0,5,0,0},
                        {7,0,5,0,5,0},
                        { 0,0,0,5,0,1},
                        {3,0,9,6,1,0}
                        };


    primMST(graph);

    return 0;
}

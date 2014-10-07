/*
Djikstra's algorithm (solves the problem of finding the shortest path from a point in a graph (the source) to a destination. 
It turns out that one can find the shortest paths from a given source to all points in a graph in the same time,
hence this problem is sometimes called the single-source shortest paths problem. 
*/

#include <stdio.h>
#include<stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

int k;

// A utility function to print the constructed distance array
int print(int dist[], int n)
{

	int i;
    printf("Vertex   Distance from Source\n");
    for (i = 0; i < n; i++)
    printf("%d \t\t %d\n", i, dist[i]);
}

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[],int n)
{

	// Initialize min value
   	int min = INT_MAX, min_index;
	int v;

	for (v = 0; v < n; v++)
     		if (sptSet[v] == false && dist[v] <= min)
         		min = dist[v], min_index = v;


    return min_index;
}

int maxDistance(int dist[], bool sptSet[],int n)
{

	// Initialize min value
   	int max = INT_MIN, max_index;
	int v;

	for (v = 0; v < n; v++)
     		if (sptSet[v] == false && dist[v] >= max)
         		max = dist[v], max_index = v;


    return max_index;
}



int** adjmatrix(int n)
{
	int i,x,j;

	//create 2D-adjacency matrix
	int** matrix = (int**) malloc(n*sizeof(int*));

	for(i = 0; i < n; i++)
	{
        matrix[i] = (int*) malloc(n*sizeof(int));
    }


	//Initialize 2D-adjacency matrix with random values as specified
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){

			if(i==j)
			{
				matrix[i][j]=0;
			}
			else{
				x = rand() % (10) + 1;
				matrix[i][j]=x;
				matrix[j][i]=matrix[i][j];
			}
		}
	}


    return matrix;
}


// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int** graph,int src,int n)
{

	int count,v,i;


    // The output array.  dist[i] will hold the shortest
    // distance from src to i
    int dist[n];

    // sptSet[i] will true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
     bool sptSet[n];

     // Initialize all distances as INFINITE and stpSet[] as false
     for (i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     // Distance of source vertex from itself is always 0
     dist[src] = 0;
     int a[10];


     // Find shortest path for all vertices
     printf("\n\n\nShortest Path from vertex 0:\n");
     for (count = 0; count < n-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet,n);
        k=maxDistance(dist, sptSet,n);
        k=maxDistance(dist, sptSet,n);
       printf("Node %d->",u);



       // Mark the picked vertex as processed
       sptSet[u] = true;

       // Update dist value of the adjacent vertices of the picked vertex.
       for (v = 0; v < n; v++)
       {
             // Update dist[v] only if is not in sptSet, there is an edge from
             // u to v, and total weight of path from src to  v through u is
             // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
            {

                    dist[v] = dist[u] + graph[u][v];
            }
        }

     }
     // print the constructed distance array
     printf("Node %d",k);
     printf("\n\n");
     print(dist, n);



}





//Display adjacency matrix
void display(int** A,int n)
{
	int i,j;
    printf("\n *************Adjancency Matrix is *************** \n");
	for(i=0;i<n;i++){

		for(j=0;j<n;j++){
			printf("\t%3d",A[i][j]);

	  	}
		printf("\n");
	}

}

int main()
{
	srand(time(NULL));

	int n = rand() % (5) + 5;
	printf("\n\nValue of random number generated is: %d\n",n);

	int **A=adjmatrix(n);
	display(A,n);
	dijkstra(A,0,n);

    return 0;
}




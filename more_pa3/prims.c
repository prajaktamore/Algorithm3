/*
Vnew are vertices included in final , and Enew is vertices included in final
    Input: A non-empty connected weighted graph with vertices V and edges E (the weights can be negative).
    Initialize: Vnew = {x}, where x is an arbitrary node (starting point) from V, Enew = {}
    Repeat until Vnew = V:
        Choose an edge (u, v) with minimal weight such that u is in Vnew and v is not (if there are multiple edges with the same weight, any of them may be picked)
        Add v to Vnew, and (u, v) to Enew
    Output: Vnew and Enew describe a minimal spanning tree

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10
#define PERM 1
#define TEMP 0
//Flag to set false as 0
#define FALSE 0   
//Flag to set true as 1
#define TRUE 1    

int visited[50],minvalue,minweight;

//Structure used to define node in minimum spanning tree
struct nodestruct
{
	int predecessor;
	//Distance from predecessor
	int dist;   
	//Status used as a flag returning either true or false
	int status; 
};


//Edge structure with starting point and ending point.
struct edgeStruct
{
	int u;
	int v;
};


//Declaration of adjanceny matrix
int adj[MAX][MAX]; 
//no of vertices in the give graph
int n;		   





void prims(int adjacency_matrix[][10])
{
    int a,b,edges=1;
    int u,v,i,j;
    for(i=2; i<=n; i++)
        visited[i]=0;
    printf("\nEdges in the minimal spanning tree are:");
    visited[1]=1;
    while(edges<n)
    {
        for(i=1,minvalue=5555; i<=n; i++)
            for(j=1; j<=n; j++)
                if(adjacency_matrix[i][j]<minvalue) {

                    if(visited[i]==0)
                        continue;

                    else
                    {
                        minvalue=adjacency_matrix[i][j];
                        a=u=i;
                        b=v=j;

                    }
                }

        if(visited[u]==0||visited[v]==0)
        {
            edges++;
            printf("\nEdge %d-->%d: %d\n",a,b,minvalue);
            minweight+=minvalue;
            visited[b]=1;
        }
        adjacency_matrix[a][b]=adjacency_matrix[b][a]=5555;
    }
    printf("\nMinimum weight of spanning tree is:%d\n",minweight);
}


//Function GenGraph: Generates the adjancecy matrix for the given graph
void genGraph()
{
	//Seed for the rand function
	 time_t seconds; 
	 int i,max_edges,wt,origin,destin;
	 int p,q;

	 time(&seconds) ;
	 srand((unsigned int)seconds);
	 printf("\nGenerating Vertices as a random number between 5-10");
	 srand(time(0));
	 n = rand() % 5 + 5;
	 printf("\nRandomly generating %d vertices",n);

	 max_edges=(n*(n-1))/2;

	for( p=0;p<n;p++)
		for( q=0;q<n;q++)
			adj[p][q] = 0;



	for( p=1;p<=n;p++)
		for(q=1;q<=n;q++)
		{
			if(adj[q][p] != 0)
				adj[p][q] = adj[q][p];
				else
				{
					if(p == q)
					adj[p][q] = 0;
					else if(p != q)
					adj[p][q] =rand() % (10) + 1;
				}
		}


} 
//end of genGraph

//Display Adjacency Matrix
void display()
{
	 int i,j;

	 for(i=1;i<=n;i++)
	  {
		 for(j=1;j<=n;j++)
         		printf("\t%3d",adj[i][j]);
		 printf("\n");
	  }
}


int main()
{

	int i,j;
	int wt_tree,count;
	struct edgeStruct tree[MAX]; 

	//Calling Generate Graph Function to construct the adjancency matrix for the  stated graph
	genGraph(); 

	printf("\n *************Adjancency Matrix is *************** \n");
	display();

	prims(adj);
}

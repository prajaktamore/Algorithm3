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


//adjanceny matrix
int adj[MAX][MAX];
//no of vertices for the graph
int n;

//To display the matrix
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

//Function to apply logic for Floyd to calculate minimum path
void floyds(int adj[][10]){

int i,j,k;
for(k = 1;k <= n ; k++)
{
    for(i = 1;i <= n; i++)
    {
        for(j = 1;j <= n ; j++)
        {
            if(i==j)
    			 adj[i][j]=0;
            else
                adj[i][j] = min (adj[i][j], adj[i][k] + adj[k][j] );
        }
    }
}

}

//TO RETURN THE LOWER NUMBER OF THE TWO
int min(int a,int b)
{
	if(a < b)
	return a;
	else
	return b;
}



//generateGraph: Generates the adjancecy matrix for the given graph
void generateGraph()
 {

	time_t seconds; //Seed for the rand function
	int i,max_edges,wt,origin,destin;
	int p,q;

	time(&seconds) ;
	srand((unsigned int)seconds);

	printf("\nGenerating Vertices as a random number between 5-10");
	srand(time(0));
	n = rand() % 5 + 5;
	printf("\nRandomly generate %d vertices",n);

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
				adj[p][q] = rand() % (10) + 1;
			}
	}



}
//end of generateGraph

int main()
{
	int i,j;
	int wt_tree,count;

	//Generating edgeStruct for all the edges including u and v as the end points
	struct edgeStruct tree[MAX];

	//Calling Generate Graph Function to construct the adjancency matrix for the  stated graph
	generateGraph();
	printf("\n*************Adjancency Matrix is *************** \n");
	display();

	floyds(adj);

	/*PRINT SHORTEST DISTANCE MATRIX*/
	printf("\n\n*************Shortest distance matrix*************\n");
	for(i = 1;i <= n; i++)
	{
	for(j = 1;j <= n; j++)
	{
	    printf("\t%d",adj[i][j]);
	}
	printf("\n");
	}


	printf("\n*************Shortest paths calculated are:*************");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
	if(i!=j)
	printf("\n<%d,%d>=%d",i,j,adj[i][j]);
	}
	printf("\n");

	return 0;
}

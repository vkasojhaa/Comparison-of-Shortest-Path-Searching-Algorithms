#include <stdio.h>
#include <limits.h>
int V;
int minDistance(int dist[], bool sptSet[])
{
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
	if (sptSet[v] == false && dist[v] <= min)
		min = dist[v], min_index = v;

return min_index;
}

int printSolution(int dist[], int n)
{
printf("Vertex Distance from Source\n");
for (int i = 0; i < V; i++)
	printf("%d tt %d\n", i, dist[i]);
}

int dijkstra(int graph[1000][1000], int src,int des)
{
	int dist[V];

	bool sptSet[V]; 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src] = 0;

	for (int count = 0; count < V-1; count++)
	{
	int u = minDistance(dist, sptSet);
	sptSet[u] = true;
	for (int v = 0; v < V; v++)

		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
									&& dist[u]+graph[u][v] < dist[v])
			dist[v] = dist[u] + graph[u][v];
	}
	return dist[des];
}

int main()
{
	
	int e,a,b,w,source,target;
	scanf("%d %d",&V,&e);
	int arr[1000][1000];
	for(int i=0;i<e;i++)
	{
		scanf("%d %d %d",&a,&b,&w);
		arr[a-1][b-1]=1;
		arr[b-1][a-1]=1;
	}
	scanf("%d %d",&source,&target);
	printf("%d\n",dijkstra(arr,source-1,target-1));
	return 0;
}

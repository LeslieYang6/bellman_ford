#include<iostream>

using namespace std;
const int V = 5;

void PrintPath(int parent[], int i)
{
	if (parent[i] == -1)
		return;
	else
	{
		PrintPath(parent, parent[i]);
		cout << parent[i] << "->";
	}
}
void Bellman_Ford(int graph[V][V], int s)
{
	int d[V];
	for (int i = 0; i < V; i++)
		d[i] = INT_MAX;
	for (int i = 0; i < V; i++)
	{   
		if(graph[s][i]!=0)
           d[i] = graph[s][i];
	}
	d[s] = 0;
	int parent[V];
	memset(parent, -1, sizeof(parent));
	for(int i=0;i<V;i++)
		for (int j = 0; j < V; j++)
		{
			if (graph[i][j]!=0&&d[j] > d[i] + graph[i][j])
			{
				d[j] = d[i] + graph[i][j];
				parent[j] = i;
			}
		}
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			if (graph[i][j]!=0&&d[j] > d[i] + graph[i][j])
			{
				cout << "minus cycle";
				return;
			}
	for (int i = 0; i < V; i++)
	{   
		cout << "The shortest path to " << i << " is "<<d[i]<<" : ";
		cout << "0->";
		PrintPath(parent, i);
		cout << i<<endl;
	}
}



int main()
{
	int graph[V][V] = {
	{ 0,-1,4,0,0},
	{ 0,0, 3,2,2},
	{ 0,0, 0,0,0},
	{ 0,1, 5,0,0},
	{ 0,0, 0,-3,0} };
	Bellman_Ford(graph, 0);
	system("pause");
}
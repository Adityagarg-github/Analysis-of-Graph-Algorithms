#include <bits/stdc++.h>
using namespace std;

void prims(int** edges, int n){
	//Declaring parent array to store the parent vertices
	//Visited array to store which vertices have been visited
	//Weight array to store the weigths of the corresponding edges
	int* parent = new int[n];
	int* weights = new int[n];
	bool* visited = new bool[n];

	for(int i = 0; i < n; i++){
		visited[i] = false;
		weights[i] = INT_MAX;
	}
	parent[0] = -1;
	weights[0] = 0;

	for(int i = 0; i < n - 1; i++){
		// Finding Min Vertex
		int minVertex = -1;
        for(int i = 0; i < n; i++){
            if(!visited[i] && (minVertex == - 1 || weights[i] < weights[minVertex])){
                minVertex = i;
            }
        }
		// Minvertex has been visited
		visited[minVertex] = true;
		// Finding the min weight amongst the edges connected to the min vertex
		for(int j = 0; j < n; j++){
			if(edges[minVertex][j] != 0 && !visited[j]){
				if(edges[minVertex][j] < weights[j]){
					weights[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}
	for(int i = 1; i < n; i++){
		if(parent[i] < i){
			cout << parent[i] << "-" << i << " " << weights[i] << "\n";
		}
		else{
			cout << i << " " << parent[i] << " " << weights[i] << "\n";
		}
	}
}

int main(){
	// Declaring the number of vertices and edges
	int n,e;
	cin >> n >> e;
	// Declaring the adjacency matrix
	int** edges = new int*[n];
	for(int i = 0; i < n; i++){
		edges[i] = new int[n];
		for (int j = 0; j < n; j++){
			edges[i][j] = 0;
		}
	}
	for(int i = 0; i < e; i++){
		int s, d, weight;
		cin >> s >> d >> weight;
		edges[s][d] = weight;
		edges[d][s] = weight;
	}
	cout << endl;
	prims(edges, n);
}
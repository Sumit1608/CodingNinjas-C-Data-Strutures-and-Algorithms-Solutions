#include<iostream>
using namespace std;
#include<algorithm>
#include<climits>

int findMinVertex( int *weights, bool *visited, int n){
	int minVertex = -1;
	
	for(int i=0; i<n; i++){
		if( !visited[i] && ( minVertex == -1 || weights[i] < weights[minVertex]) ){
			minVertex = i;
		}
	}
	return minVertex;
}

void prims(int **edges, int n){
	int *parent = new int[n];
	int *weights = new int[n];
	bool *visited = new bool[n];
	
	for(int i=0; i<n; i++){
		visited[i] = false;
		weights[i] = INT_MAX;
	}
	parent[0] = -1;
	weights[0] = 0;
	
	for(int i =0; i<n-1; i++){
		//Find min vertex and mark it visited
		int minVertex = findMinVertex(weights, visited, n);
		visited[minVertex] = true;
		//Explore unvisited neighbours
		for(int j=0; j<n; j++){
			//Check whether they are connected or not. Also the vertex must not be visited
			if( edges[minVertex][j] != 0 && !visited[j]){
				//Check for minimum weights
				if( edges[minVertex][j] < weights[j] ){
					//Update parent and weight for that vertex
					weights[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}
	
	for(int i=1; i<n; i++){
		if( parent[i] < i){
			cout << parent[i] << " " << i << " " << weights[i] << " " << endl;
		}
		else{
			cout << i << " " << parent[i] << " " << weights[i] << " " << endl;
		}
	}
	delete []visited;
	delete []parent;
	delete []weights;
}

int main(){
	int n;
	int e;
	cin >> n >> e;
	int **edges = new int*[n];
	for(int i=0; i<n; i++){
		edges[i] =  new int[n];
		for(int j=0; j<n; j++){
			edges[i][j] = 0;
		}
	}
	
	for(int i=0; i<e; i++){
		int f, s, weight; // f= 1st vertex, s = 2nd vertex
		cin >> f>> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	cout << endl;
	prims(edges, n);
	
	for(int i=0; i<n; i++){
		delete []edges[i];
	}
	delete []edges;
	return 0;
}

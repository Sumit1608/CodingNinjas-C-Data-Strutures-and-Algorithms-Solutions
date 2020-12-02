#include<iostream>
using namespace std;
#include<algorithm>
#include<climits>

int findMinVertex( int *distance, bool *visited, int n){
	int minVertex = -1;
	
	for(int i=0; i<n; i++){
		if( !visited[i] && ( minVertex == -1 || distance[i] < distance[minVertex]) ){
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstra(int **edges, int n){
	int *distance = new int[n];
	bool *visited = new bool[n];
	
	for(int i=0; i<n; i++){
		visited[i] = false;
		distance[i] = INT_MAX;
	}
	distance[0] = 0;
	
	for(int i =0; i<n-1; i++){
		//Find min vertex and mark it visited
		int minVertex = findMinVertex(distance, visited, n);
		visited[minVertex] = true;
		//Explore unvisited neighbours
		for(int j=0; j<n; j++){
			//Check whether they are connected or not. Also the vertex must not be visited
			if( edges[minVertex][j] != 0 && !visited[j]){
				//Check for minimum distance
				int dist = distance[minVertex] + edges[minVertex][j];
				if( dist < distance[j] ){
					//Update distance for that vertex
					distance[j] = dist;
				}
			}
		}
	}
	
	for(int i=0; i<n; i++){
		cout << i << " " << distance[i] << endl;
	}
	delete []visited;
	delete []distance;
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
		int f, s, weight;
		cin >> f>> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	cout << endl;
	dijkstra(edges, n);
	
	for(int i=0; i<n; i++){
		delete []edges[i];
	}
	delete []edges;
	return 0;
}

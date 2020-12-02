#include<iostream>
#include<queue>
using namespace std;


void printBFS( int **edges, int n, int sv, bool *visited){
	//sv = starting vertex
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	
	while( !q.empty() ){
		int f = q.front();
		cout << f <<endl;
		q.pop();
		for(int i=0; i<n; i++){
			if(i == f){
				continue;
			}
			if(edges[f][i] == 1 && !visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

void BFS( int **edges, int n){
	bool* visited = new bool[n];
	for(int i=0; i<n; i++){
		visited[i]=false;
	}
	
	for(int i=0; i<n; i++ ){
		if( !visited[i]){
			printBFS(edges, n, i, visited);
		}
	}
	delete []visited;
}




void printDFS( int **edges, int n, int sv, bool *visited){
	//sv = starting vertex
	cout << sv << endl;
	visited[sv] = true;
	for(int i =0; i<n; i++){
		if(i == sv){
			continue;
		}	
		if(edges[sv][i] == 1){
			if( visited[i]){
				continue;
			}
			printDFS(edges, n, i, visited);
		}
	}
}

void DFS( int **edges, int n){
	bool* visited = new bool[n];
	for(int i=0; i<n; i++){
		visited[i]=false;
	}
	
	for(int i=0; i<n; i++ ){
		if( !visited[i]){
			printDFS(edges, n, i, visited);
		}
	}
	delete []visited;
}




int main(){
	int n;
	int e;
	cin >> n >> e;
	int **edges = new int*[n]; //Adjacenecy Matrix
	for(int i=0; i<n; i++){
		edges[i] =  new int[n];
		for(int j=0; j<n; j++){
			edges[i][j] = 0;
		}
	}
	
	for(int i=0; i<e; i++){
		int f, s; // f= 1st vertex, s = 2nd vertex
		cin >> f>> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	
	cout << "DFS" << endl;
	DFS(edges, n);
	
	cout<< "BFS" <<endl;
	BFS(edges, n);

	for(int i=0; i<n; i++){
		delete []edges[i];
	}
	delete []edges;
	return 0;
}

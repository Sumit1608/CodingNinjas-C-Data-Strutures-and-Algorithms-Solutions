#include<iostream>
#include<queue>
using namespace std;


bool findPath( int **edges, int n, int v1, int v2, bool *visited){
	//sv = starting vertex
	queue<int> q;
	q.push(v1);
	visited[v1] = true;
	
	while( !q.empty() ){
		int f = q.front();
		q.pop();
		for(int i=0; i<n; i++){
			if(i == f){
				continue;
			}
			if(edges[f][i] == 1 && !visited[i]){
				q.push(i);
				visited[i] = true;
				if( i == v2){
					return true;
				}
			}
		}
	}
	return false;
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
	
	int v1, v2;
	cin>>v1>>v2;
	bool *visited = new bool[n];
	for(int i=0; i<n; i++){
		visited[i] = false;
	}
	
	if( findPath( edges, n, v1, v2, visited)){
		cout<<"True";
	}
	else{
		cout<<"False";
	}
	
	delete []visited;
	for(int i=0; i<n; i++){
		delete []edges[i];
	}
	delete []edges;
	return 0;
}

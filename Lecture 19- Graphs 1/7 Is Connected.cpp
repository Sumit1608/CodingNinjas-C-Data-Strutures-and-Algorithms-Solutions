#include<iostream>
#include<vector>
#include<queue>
using namespace std;


bool isConnected( int **edges, int n){
	queue<int> bfsQ;
	bool *visited = new bool[n];
	for(int i=0; i<n; i++){
		visited[i] = false;
	}	
	bfsQ.push(0);
	visited[0] = true;
	
	while( !bfsQ.empty()){
		int front = bfsQ.front();
		bfsQ.pop();
		for(int i=0; i<n; i++){
			if(edges[front][i] == 1 && !visited[i]){
				bfsQ.push(i);
				visited[i] = true;
			}
		}
	}
	
	bool ans = true;
	for(int i=0;i<n;i++)
		if(visited[i]==0){
			ans = false;
			break;
		}
	delete []visited;
    return ans;
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
	
	if(isConnected(edges, n)){
		cout<<"True";
	}
	else{
		cout<<"False";
	}
	
	for(int i=0; i<n; i++){
		delete []edges[i];
	}
	delete []edges;
	return 0;
}

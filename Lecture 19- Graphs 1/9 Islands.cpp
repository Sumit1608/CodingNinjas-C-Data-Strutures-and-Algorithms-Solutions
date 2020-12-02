#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void connected( int **edges, int n, int sv, bool *visited){
	visited[sv] = true;
	for(int i=1; i<n; i++){
		if(i == sv){
			continue;
		}
		if(edges[sv][i] == 1 && !visited[i]){
			connected( edges, n, i, visited);
		}
	}
}


int main(){
	int n, m;
	cin >> n >>m ;  // m=e
	int **edges = new int*[n+1]; //Adjacenecy Matrix
	for(int i=0; i<n+1; i++){
		edges[i] =  new int[n+1];
		for(int j=1; j<n+1; j++){
			edges[i][j] = 0;
		}
	}
	
	vector<int> u, v;
	int x;
	for(int i=0; i<m; i++){
		cin>>x;
		u.push_back(x);
	}
	for(int i=0; i<m; i++){
		cin>>x;
		v.push_back(x);
	}
	
	for(int i=0; i<m; i++){
		edges[ u[i]][ v[i]] = 1;
		edges[ v[i]][ u[i]] = 1;
	}
	
	bool *visited = new bool[n];
	for(int i=0; i<n+1; i++){
		visited[i] = false;
	}
	
	int count=0;
	for(int i = 1; i<n+1; i++){
		if( !visited[i] ){
			count++;
			connected(edges, n+1, i, visited);			
		}
	}
	cout << count << endl;
	
	delete []visited;
	for(int i=0; i<n; i++){
		delete []edges[i];
	}
	delete []edges;
	return 0;
}

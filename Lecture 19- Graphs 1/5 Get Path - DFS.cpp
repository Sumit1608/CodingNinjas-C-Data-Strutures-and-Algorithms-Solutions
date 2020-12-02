#include<iostream>
#include<vector>
using namespace std;


vector<int>* getPathDFS( int **edges, int n, int v1, int v2, bool *visited, vector<int> *output){
	if(v1 == v2){
		output->push_back(v2);
		return output;
	}
	
	visited[v1] = true;
	for(int i=0; i<n; i++){
		if(edges[v1][i] == 1 && !visited[i]){
			output = getPathDFS( edges, n, i, v2, visited, output);
			if(output != NULL){
				output->push_back(v1);
				return output;
			}
		}
	}
	return NULL;
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
	
	vector<int> *output = new vector<int> ();
	output = getPathDFS(edges, n, v1, v2, visited, output);
	if(output != NULL){
		for(int i=0; i<output->size(); i++){
			cout << output->at(i) << " ";
		}
		cout << endl;
	}
	
	
	delete []visited;
	for(int i=0; i<n; i++){
		delete []edges[i];
	}
	delete []edges;
	return 0;
}

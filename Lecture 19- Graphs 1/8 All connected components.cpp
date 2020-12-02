#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void connected( int **edges, int n, int sv, bool *visited, vector<int> *output){
	visited[sv] = true;
	output->push_back(sv);
	for(int i=0; i<n; i++){
		if(i == sv){
			continue;
		}
		if(edges[sv][i] == 1 && !visited[i]){
			connected( edges, n, i, visited, output);
		}
	}
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
	
	bool *visited = new bool[n];
	for(int i=0; i<n; i++){
		visited[i] = false;
	}
	
	for(int i=0; i<n; i++){
		if( !visited[i] ){
			vector<int> *output = new vector<int> ();
			connected(edges, n, i, visited, output);
			sort(output->begin(), output->end());
            for(int i=0; i<output->size(); i++){
                cout<<output->at(i)<<" ";
            }
            cout << endl;
        	delete output;			
		}
	}
	
	delete []visited;
	for(int i=0; i<n; i++){
		delete []edges[i];
	}
	delete []edges;
	return 0;
}

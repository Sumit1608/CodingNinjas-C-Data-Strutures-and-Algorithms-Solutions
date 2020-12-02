#include<iostream>
#include<vector>
using namespace std;


int solve(int n, int m ,vector<int>u ,vector<int>v ){
    int **a = new int*[n+1];
    int i, j, k, count=0;
    for(i=0; i<n+1; i++)
	    a[i] = new int[n+1];
    
    for(i=1; i<n+1; i++){
        for(j=1; j<n+1; j++){
            a[i][j] = 0;
        }
    }
    
    for(i=0; i<m; i++){
        int f = u[i];
        int s = v[i];
        a[f][s] = 1;
        a[s][f] = 1;
    }
    
    for(i=1; i<n+1; i++){
    	for(j=1; j<n+1; j++){
            if(a[i][j] == 1){
                for(k=1; k<n+1; k++)
			        if(a[j][k]==1 && a[k][i]==1) //If i,j,k form a cyce or not
				        count++;
     		}  
     	}
    }
    return count/6; 
}

int main(){
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}

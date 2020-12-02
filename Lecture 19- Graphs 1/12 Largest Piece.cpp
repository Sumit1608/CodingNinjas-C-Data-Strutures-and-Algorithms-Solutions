#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55
char cake[NMAX][NMAX];


char A[NMAX][NMAX];
int visited[NMAX][NMAX];
int cx[] = {0, 0, -1, 1};
int cy[] = {1, -1, 0, 0};

int DFS( int x, int y, int n){
	if(visited[x][y]){
		return 0;
	}
	visited[x][y] = 1;
	int count = 0;
	for(int i=0; i<4; i++){
		int nextX = x + cx[i];
		int nextY = y + cy[i];
		if( nextX>=0 && nextX<n && nextY>=0 && nextY<n && cake[nextX][nextY]=='1'){
			count += DFS( nextX, nextY, n);
		}
	}
	return count+1;
}

int solve(int n, char cake[NMAX][NMAX]){
	int maxSize =0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			visited[i][j] = 0;
		}
	}
	for( int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if( cake[i][j] == '1' && visited[i][j] == 0){
				maxSize = max( maxSize, DFS( i, j, n));
			}
		}
	}
	return maxSize;
}



/* Alternate Solution 
int Solve(int n,int i,int j,char cake[NMAX][NMAX],int** visit,int *temp){
    if(cake[i][j]=='1'){
        *temp=*temp+1;
      	visit[i][j]=1;
    }
    else{
        visit[i][j]=1;
        return *temp;
    }
    
    int ans; 
    if(i!=0&&visit[i-1][j]!=1)
	    ans=Solve(n,i-1,j,cake,visit,temp);
    if(j!=0&&visit[i][j-1]!=1)
	    ans=Solve(n,i,j-1,cake,visit,temp);
    if(i!=n-1&&visit[i+1][j]!=1)
	    ans=Solve(n,i+1,j,cake,visit,temp);
    if(j!=n-1&&visit[i][j+1]!=1)
    	ans=Solve(n,i,j+1,cake,visit,temp);
	return *temp;
}

int solve(int n,char cake[NMAX][NMAX]){
	// Write your code here .
    int i,j;
    int *temp=new int;
    int** visit=new int*[n];
    for(i=0;i<n;i++)
        visit[i]=new int[n];
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            visit[i][j]=0;
    int max=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(visit[i][j]==0&&cake[i][j]=='1'){
                *temp=0;
                *temp=Solve(n,i,j,cake,visit,temp);
                if(max<*temp)  
                  	max=*temp;
            }
        }
	}
    return max;
}
*/

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cake[i];
	}
	cout<<solve(n,cake)<<endl;
}

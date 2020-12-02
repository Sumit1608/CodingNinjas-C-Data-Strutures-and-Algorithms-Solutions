#include<bits/stdc++.h>
using namespace std;
#define MAXN 51

int visited[51][51];
int findCycle = 0;
int dx[] ={1, -1, 0, 0};
int dy[] ={0, 0, 1, -1};

void DFS(char board[][MAXN], int x, int y, int fromX, int fromY, char needColor, int N, int M){
	if( x<0 || x>=N || y<0 || y>=M)
		return;
	if(board[x][y] != needColor)
		return;
	if( visited[x][y] ){
		findCycle = 1;
		return;
	}
	visited[x][y] = 1;
	
	for(int f=0; f<4; f++){
		int nextX = x + dx[f];
		int nextY = y + dy[f];
		if(nextX == fromX && nextY == fromY)
			continue;
		DFS(board, nextX, nextY, x, y, needColor, N, M);
	}
}

int solve(char board[][MAXN], int N, int M){
	int i, j;
	memset(visited, 0, sizeof(visited));
	
	for(int i =0; i <N; i++){
		for(int j=0; j <M; j++){
			if( !visited[i][j] ){
				DFS(board, i, j, -1, -1, board[i][j], N, M);
			}
		}
	}
	
	return findCycle;
}




int main(){
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}

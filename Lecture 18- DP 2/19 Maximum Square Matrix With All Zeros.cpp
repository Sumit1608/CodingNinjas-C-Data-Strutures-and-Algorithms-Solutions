#include<iostream>
using namespace std;

int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int **output = new int*[row];
	
    for(int i = 0; i < row; i++) {
		output[i] = new int[col];
	}
    
    //Fill first row
    for(int i=0; i<col; i++){
        if( arr[0][i] = 0)
            output[0][i] = 1;
        else
            output[0][i] = 0;
    }
    
    //Fill first column
    for(int i=0; i < row; i++){
        if(arr[i][0] ==  0)
            output[i][0] = 1;
        else
            output[i][0] = 0;            
    }
    
    int max = 1;
    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            
            if(arr[i][j] == 0){
                output[i][j] = min( output[i-1][j-1], min( output[i-1][j], output[i][j-1] )) + 1;
                if(max < output[i][j])
                    max = output[i][j];
            }
            else
                output[i][j] = 0;
        }
    }
    
    return max;
}

int main(){
	int **arr,n,m,i,j;
	cin>>n>>m;
	arr=new int*[n];
	
	for(i=0;i<n;i++)
    	arr[i]=new int[m];
	
	for(i=0;i<n;i++)
    	for(j=0;j<m;j++)
	    	cin>>arr[i][j];
	
	cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
	delete arr;
	return 0;
}

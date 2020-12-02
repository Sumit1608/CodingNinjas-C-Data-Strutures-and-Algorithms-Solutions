#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCostPath(int **a, int m, int n, int i, int j){
    //Base Cases
    if(i == m-1 && j == n-1)
        return a[i][j];
    else if( i>=m || j>=n )
        return INT_MAX;
    
    //Recursive calls
    int x = minCostPath(a, m, n, i, j+1);
    int y = minCostPath(a, m, n, i+1, j);
    int z = minCostPath(a, m, n, i+1, j+1);
    
    //Small Calculation
    int ans = min(x, min(y,z)) + a[i][j];
    return ans;
}

int minCostPath(int **input, int m, int n) {
    return minCostPath(input, m, n ,0, 0);
}

int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}


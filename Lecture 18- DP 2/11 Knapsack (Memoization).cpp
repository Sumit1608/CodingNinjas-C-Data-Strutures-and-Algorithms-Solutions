#include <iostream>
using namespace std;

int knapsack_mem(int *weight, int *values, int n, int maxWeight, int **dp) {
	// Base case
	if(n<0) {
		return 0;
	}
	if(dp[n][maxWeight] != -1){
		return dp[n][maxWeight];
	}

	// Recursive calls
	if(weight[n] > maxWeight) {
		/* TODO (#1#): Memoization has some bugs to fix */
		dp[n][maxWeight] = knapsack_mem(weight, values, n - 1, maxWeight, dp);
		return dp[n][maxWeight];
	}
	else{
		int x = knapsack_mem(weight , values , n - 1, maxWeight - weight[n], dp) + values[0];
		int y = knapsack_mem(weight , values , n - 1, maxWeight, dp);
		dp[n][maxWeight] = max(x, y);
		return dp[n][maxWeight];
	}
}

int knapsack_mem(int *weight, int *values, int n, int maxWeight) 
{ 
    int **dp = new int*[n];
  
    for (int i = 0; i < n; i++){
       dp[i] = new int[maxWeight + 1]; 
	}
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= maxWeight; j++) 
            dp[i][j] = -1; 
	}
	
    return knapsack_mem(weight, values, n-1, maxWeight, dp); 
} 

int knapsack(int *weight, int *values, int n, int maxWeight) {
	// Base case
	if(n == 0 || maxWeight == 0) {
		return 0;
	}

	if(weight[0] > maxWeight) {
		return knapsack(weight + 1, values + 1, n - 1, maxWeight);
	}

	// Recursive calls
	int x = knapsack(weight + 1, values + 1, n - 1, maxWeight - weight[0]) + values[0];
	int y = knapsack(weight + 1, values + 1, n - 1, maxWeight);

	return max(x, y);
}


int main() {
	int n; 
	cin >> n;
	int* weights = new int[n];
	int* values = new int[n];

	for(int i = 0; i < n; i++){
		cin >> weights[i];
	}

	for(int i = 0; i < n; i++){
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack_mem(weights, values, n, maxWeight) << endl;
}

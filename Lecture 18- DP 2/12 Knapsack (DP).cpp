#include<iostream>
using namespace std;

int knapsack_dp(int* weights, int* values, int n, int maxWeight){
	int k[n+1][maxWeight+1];
    
    for(int i=0; i<=n; i++){
        for(int w=0; w<=maxWeight; w++){
            if(i ==0 || w==0){
                k[i][w] = 0;
            }
            else if(weights[i-1] <= w){
                k[i][w] = max( k[i-1][w], values[i-1] + k[i-1][w - weights[i-1]]);
            }
            else{
                k[i][w] = k[i-1][w];
            }
        }
    }
    
    return k[n][maxWeight];
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

	cout << knapsack_dp(weights, values, n, maxWeight) << endl;
}

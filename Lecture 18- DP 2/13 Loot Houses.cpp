#include <iostream>
using namespace std;

int maxMoneyLooted(int arr[], int n){
	int *maxSum = new int[n];
    
    maxSum[0] = arr[0];
    if(n > 1)
        maxSum[1] = arr[1];
    
    for(int i=2; i<n; i++){
        maxSum[i] = max( maxSum[i-1], arr[i]+maxSum[i-2]); 
    }
    int ans = maxSum[n-1];
    delete []maxSum;
    return ans;
}

int main(){
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}

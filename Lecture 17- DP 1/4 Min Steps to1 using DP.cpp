#include <bits/stdc++.h>
using namespace std;
#include<climits>

int countStepsToOne(int n){
	int *arr = new int[n+1];
    arr[0] = -1;
    arr[1] = 0;
    arr[2]=1;
    arr[3]=1;
    
    for(int i=4; i<=n; i++){
        if(i%2!=0 && i%3==0)
            arr[i] = min(arr[i-1], min(INT_MAX, arr[i/3]))+1;
        else if(i%2==0 && i%3!=0)
            arr[i] = min(arr[i-1], min(INT_MAX, arr[i/2]))+1;
        else if(i%2==0 && i%3==0)
            arr[i] = min(arr[i-1], min(arr[i/2], arr[i/3]))+1;
        else
            arr[i]=arr[i-1]+1;
    }
    return arr[n];
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}

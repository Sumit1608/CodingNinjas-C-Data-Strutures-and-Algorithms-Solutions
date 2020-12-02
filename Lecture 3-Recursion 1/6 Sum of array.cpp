#include<iostream>
using namespace std;

int sum(int input[], int n) {
    if( n==1){
        return input[0];
    }
    
    int s = input[0] + sum(input+1, n-1);
    return s;
}

int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin >> n;
    int *input = new int[n];
    cout<<"Enter the elements : ";
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    cout << sum(input, n) << endl;
}

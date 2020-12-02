#include <iostream>
using namespace std;


bool checkMaxHeap(int arr[], int n){
    if(n == 0)
        return true;
    int pi =0;
    int c1 =1;
    int c2 =2;
    
    while(c1 < n){
        if( (arr[pi] < arr[c1]) || (arr[pi] < arr[c2] && c2<n))
            return false;
        else{
            pi++;
            c1 = pi*2+1;
            c2 = pi*2+2;
        }
    }
    return true;
}




int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    delete [] arr;
}


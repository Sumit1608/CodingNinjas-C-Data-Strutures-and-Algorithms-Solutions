#include <iostream>
using namespace std;

#include<queue>

void findMedian(int arr[], int n){
    for(int i=1; i<=n; i++){
        if( i%2 == 0){
            priority_queue<int> maxheap;
    		priority_queue<int, vector<int> ,greater<int> > minheap;
            int j=0;
            while( j<i){
                maxheap.push(arr[j]);
                minheap.push(arr[j]);
                j++;
            }
            
            j = (i-2)/2;
            while(j > 0){
                maxheap.pop();
                minheap.pop();
                j--;
            }
            cout<< (maxheap.top() + minheap.top())/2 << endl;
        }
        else{
            priority_queue<int> maxheap;
            int j=0;
            while(j<i){
                maxheap.push(arr[j]);
                j++;
            }
            j=(i-1)/2;
            while(j > 0){
                maxheap.pop();
                j--;
            }
            cout<< maxheap.top() << endl;
        }
    }
}

int main() {
    
    int n;
    cin >> n;

    int arr[n], i;
    for(i=0;i<n;i++)
		cin>> arr[i];

    findMedian(arr, n);
}

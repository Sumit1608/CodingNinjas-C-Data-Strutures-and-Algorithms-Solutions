#include <iostream>
using namespace std;

#include<stack>
int* stockSpan(int *price, int size) {
    int *arr = new int[size];
    stack<int> s;
    s.push(0);
    arr[0] =1;
    
    int i=1;
    while(i<size){
        int count =0;
        while(!s.empty() && (price[s.top()] < price[i]))
            s.pop();
        
        if(s.empty())
            arr[i] = i+1;
        else
            arr[i] = i -  s.top();
        
        s.push(i);
        i++;  
    }
    
    return arr;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }
}

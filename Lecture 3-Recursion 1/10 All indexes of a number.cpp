#include<iostream>
#include<Cstring>
using namespace std;

void index(int input[], int currInd, int size, int x, int output[], int &k){
    if(currInd == size){
        return;
    }
    if(input[currInd] == x){
        output[k] = currInd;
        k++;
    }
    index(input, currInd+1, size, x, output, k);
}

int allIndexes(int input[], int size, int x, int output[]){
    int k=0;
    
    index(input, 0, size, x, output, k);
    return k;
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}

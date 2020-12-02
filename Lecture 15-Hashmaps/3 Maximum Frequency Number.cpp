#include<iostream>
using namespace std;
#include<unordered_map>



int highestFrequency(int *input, int n){
    unordered_map<int, int> freq;
    //Insert all elements in hash
    for(int i=0; i<n; i++)
        freq[input[i]]++;
    
    // find the max frequency 
    int max = 0, maxI = input[0]; 
    for (int i=0; i<n; i++){
        if (max < freq[input[i]] ){ 
            max = freq[input[i]];
            maxI = input[i];
        } 
    } 
  
    return maxI;
}



int main(){
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>input[i];
    int maxKey= highestFrequency(input, n);
    cout<<maxKey;
    return 0;
}

#include<iostream>
#include<unordered_map>
using namespace std;


int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
    int sum=0;
    int maxlength=0;
    unordered_map<int,int> s;
    
	for(int i=0;i<size;i++){
    	sum=sum+arr[i];
   	    if (arr[i] == 0 && maxlength == 0) 
            maxlength = 1; 
        if (sum == 0) 
            maxlength = i + 1; 
   		if(s.count(sum)>0){
	       maxlength=max(maxlength,i-s[sum]); 
        	}
	    else{
    	    s[sum]=i;
    	} 
	}
    return maxlength;  
}


int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  int ans = lengthOfLongestSubsetWithZeroSum(arr,size);
  cout << ans << endl;
  delete []arr;
}

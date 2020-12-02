#include<iostream>
using namespace std;
#include<unordered_map>



void printPairs(int *input, int n, int k) {
	unordered_map<int,int> s;
    for(int i=0; i<n; i++)
        s[input[i]]++;
    
    for(int i=0; i<n; i++){
        if(k==0){
            int nTime = s[input[i]];
            int count = (nTime*(nTime-1))/2;
            for(int j=0; j<count; j++)
                cout<< input[i]<< " "<< input[i]<< endl;                
        }
        else{
            int num1 = input[i] + k;
            int num2 = input[i] - k;
            
            if(s.count(num1) > 0){
                for(int j=0; j< s[num1]*s[input[i]]; j++)
            	    cout<< input[i] <<" " << num1<< endl;                    
            }
            if(s.count(num2) > 0){
                for(int j=0; j< s[num2]*s[input[i]]; j++)
            	    cout<< num2<< " "<< input[i] <<endl;                    
            }
        }
        s.erase(input[i]);        
    }
}



int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}

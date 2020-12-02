#include <iostream>
#include <algorithm>
using namespace std;


#include<unordered_map>

void intersection(int input1[], int input2[], int size1, int size2) {
	unordered_map<int,int> check;  // here i kept the frequency of each elememt of the smaller array
    
    if(size1>=size2){               // and increasing and decreasing its frequency
        for (int i=0;i<size2;i++){
            if (check.count(input2[i])> 0)
                check[input2[i]]++;
            else
            check[input2[i]]=1;
        }
        for (int i=0;i<size1;i++){
            if (check[input1[i]]>0){
                cout << input1[i]<<endl;
                check[input1[i]]--;
            }
        }
    }
    
	else{
        for(int i=0;i<size1;i++){
            if (check.count(input1[i])> 0)
                check[input1[i]]++;
            else
				check[input1[i]]=1;
        }
        for (int i=0;i<size2;i++){
            if (check[input2[i]]>0){
                cout << input2[i]<<endl;
                check[input2[i]]--;
            }
        }   
    }
}


int main() {
	int size1,size2;

	cin>>size1;
	int *input1=new int[1+size1];	
	for(int i=0;i<size1;i++)
		cin>>input1[i];

	cin>>size2;
	int *input2=new int[1+size2];	
	
	for(int i=0;i<size2;i++)
		cin>>input2[i];
	intersection(input1,input2,size1,size2);		
	return 0;
}

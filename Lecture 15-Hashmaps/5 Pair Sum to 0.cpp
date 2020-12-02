#include <bits/stdc++.h>
using namespace std;
#include<unordered_map>


void pairSum(int *input, int n){
	unordered_map<int, int> map;
	for(int i=0; i<n; i++){
		int compliment = -input[i];
		
		if(map.find(compliment) != map.end()){
			int counter = map[compliment];
			
			while(counter--){
				cout<< min(input[i], compliment) <<" "<< max(input[i], compliment) <<endl;
			}
		}
		++map[input[i]];
	}
}



int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	pairSum(arr, n);

	delete[] arr;

	return 0;
}

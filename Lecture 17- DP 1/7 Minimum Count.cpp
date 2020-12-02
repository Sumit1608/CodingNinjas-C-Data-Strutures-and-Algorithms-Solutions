#include <bits/stdc++.h>
using namespace std;
#include<climits>


int minCount(int n){
    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i<=n; i++){
        dp[i] = INT_MAX;
        for(int j=1; i-(j*j)>= 0; j++ ){
            dp[i] = min(dp[i], dp[i-(j*j)]);
        }
        dp[i] += 1;
    }
    
    int result = dp[n];
    delete []dp;
    return result;
}


/*OR 
#include<math.h>
int minCount(int n){
   int* dp = new int[n + 1]; 
  
    // getMinSquares table for base case entries 
    dp[0] = 0; 
    dp[1] = 1; 
    dp[2] = 2; 
    dp[3] = 3; 
  
    // getMinSquares rest of the table using recursive 
    // formula 
    for (int i = 4; i <= n; i++) { 
        // max value is i as i can always be represented 
        // as 1*1 + 1*1 + ... 
        dp[i] = i; 
  
        // Go through all smaller numbers to 
        // to recursively find minimum 
        for (int x = 1; x <= ceil(sqrt(i)); x++) { 
            int temp = x * x; 
            if (temp > i) 
                break; 
            else
                dp[i] = min(dp[i], 1 + dp[i - temp]); 
        } 
    } 
  
    // Store result and free dp[] 
    int res = dp[n]; 
    delete[] dp; 
  
    return res; 
} */

int main(){
	int n;
	cin >> n;
	cout << minCount(n);
}


#include<iostream>
using namespace std;
#include<string>
#include<climits>

//DP solution
int solve_dp(string S,string T){
	 int m = S.size(), n = T.size(); 
  
    // declaring 2D array of m + 1 rows and n + 1 columns dynamically 
    int dp[m+1][n+1]; 
  
    // T string is empty 
    for (int i = 0; i <= m; i++) 
        dp[i][0] = 1; 
  
    // S string is empty 
    for (int i = 0; i <= n; i++) 
        dp[0][i] = 1001; 
  
    for (int i = 1; i <= m; i++) { 
        for (int j = 1; j <= n; j++) { 
            char ch = S[i-1]; 
            int k; 
            for (k = j-1; k >= 0; k--){ 
                if (T[k] == ch) 
                    break; }
  
            // char not present in T 
            if (k == -1) 
                dp[i][j] = 1; 
            else
               dp[i][j] = min(dp[i-1][j], dp[i-1][k] + 1); 
        } 
    } 
  
    int ans = dp[m][n]; 
    if (ans >= 1001) 
        ans = -1; 
  
    return ans;
}

//Memoization solution
int solve_mem( string a, string b, int siA , int siB, int **dp){
	if(siB == b.length()){
		return 1;
	}
	if(siA == a.length()){
		return 1001;
	}
	
	if(dp[siA][siB] != -1){
		return dp[siA][siB];
	}
	
	int option1 = solve_mem(a, b, siA+1, siB, dp);
	int index = -1;
	for(int i=siB; i<b.length(); i++){
		if(b[i] == a[siA]){
			index = i;
			break;
		}
	}
	if(index == -1){
		return 1;
	}
	
	int option2 = 1 + solve_mem(a, b, siA +1, index+1, dp);
	dp[siA][siB] = min(option1, option2);
	return dp[siA][siB];
}

int solve_mem(string a, string b){
	int **dp = new int*[a.length()];
	
	for(int i=0; i<a.length(); i++){
		dp[i] = new int[b.length()];
		for(int j=0; j<b.length(); j++){
			dp[i][j] = -1;
		}
	}
	int ans = solve_mem(a,b,0,0,dp);
	for(int i=0; i<a.length(); i++){
		delete []dp[i];
	}
	delete []dp;
	return ans;
}

//Brute solution
int solve( string a, string b, int siA = 0, int siB = 0){
	if(siB == b.length()){
		return 1;
	}
	if(siA == a.length()){
		return 1001;
	}
	
	int option1 = solve(a, b, siA+1, siB);
	int index = -1;
	for(int i=siB; i<b.length(); i++){
		if(b[i] == a[siA]){
			index = i;
			break;
		}
	}
	if(index == -1){
		return 1;
	}
	
	int option2 = 1 + solve(a, b, siA +1, index+1);
	return min(option1, option2);
}

int main(){
	string a,b;
	cin>>a>>b;
	cout<< solve(a, b) <<endl;
	cout<< solve_mem(a, b) <<endl;
	cout<< solve_dp(a, b) <<endl;
}

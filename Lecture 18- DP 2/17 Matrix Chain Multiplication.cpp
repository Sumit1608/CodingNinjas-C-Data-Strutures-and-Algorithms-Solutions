#include<iostream>
using namespace std;
#include<climits>

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n


//DP solution
//Here, L is for Diagonal... order is O(n^3)
//m[i][j] represent min product cost of multiplcation form matrix Ai to Aj
int mcm_dp(int* p, int n){
    n++;
    /* For simplicity of the program, one extra row and one 
    extra column are allocated in m[][].  0th row and 0th 
    column of m[][] are not used */
	int m[n][n];
    int i, j, k, L, q;
    
    // cost is zero when multiplying one matrix.
	for(i=0; i<n; i++)
        m[i][i] = 0;    
 	
	// L is chain length.
    for (L=2; L<n; L++){
        for (i=1; i<n-L+1; i++){
            j = i+L-1;
            m[i][j] = INT_MAX;  
 
            for (k=i; k<=j-1; k++){
            	// q = cost/scalar multiplications 
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]){
                    m[i][j] = q;    
                }
            }
        }
    }
    return m[1][n-1];
}



//Brute solution (reference:GFG)
int MatrixChainOrder(int p[], int i, int j) { 
    if (i == j) 
        return 0; 
    int k; 
    int min = INT_MAX; 
    int count; 
  
    // place parenthesis at different places between first and last matrix, recursively 
	// calculate count of multiplications for each parenthesis placement and return the minimum count 
    for (k = i; k < j; k++) { 
        count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j]; 
  
        if (count < min) 
            min = count; 
    } 
  
    // Return minimum count 
    return min; 
}

int mcm(int *p, int n){
	return MatrixChainOrder(p,1,n);
}

//Brute soultion (usinf hint from CN)
//si =start index ; ei = end index
int mcm(int *p, int si, int ei){
	if(si==ei || si == ei-1){
		return 0;
	}
	
	int min = INT_MAX;
	for (int k = si+1; k < ei; k++) { 
        int count = mcm(p, si, k) + mcm(p, k, ei) + p[si] * p[k] * p[ei]; 
  
        if (count < min) 
            min = count; 
    } 
  
    // Return minimum count 
    return min; 
}




int main(){

  int n; 
  cin >> n;
  int* p = new int[n];

  for(int i = 0; i <= n; i++){
    cin >> p[i];
  }

  cout << mcm(p, n)<<endl;
  cout<< mcm(p,0,n)<<endl;
  cout << mcm_dp(p, n)<<endl;

}

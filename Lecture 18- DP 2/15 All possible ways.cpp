#include <iostream>
using namespace std;
#include<math.h>

int countWaysUtil(int x, int n, int num){ 
    // Base cases 
    int val = (x - pow(num, n)); 
    if (val == 0) 
        return 1; 
    else if (val < 0) 
        return 0; 
  
    // Consider two possibilities, num is included and num is not included. 
    return countWaysUtil(val, n, num + 1) + countWaysUtil(x, n, num + 1); 
} 
  
int allWays(int x, int n) {
	return countWaysUtil(x, n, 1);
}


int main(){
    int x, n;
    cin >> x >> n;
    cout << allWays(x, n);
    return 0;
}

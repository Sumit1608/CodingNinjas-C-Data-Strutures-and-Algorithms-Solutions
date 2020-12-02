#include <iostream>
using namespace std;
#include <math.h>

int balancedBTs(int h){
    if(h<=1)
        return 1;
    
    int mod = (int)(pow(10,9))+7;
    int x = balancedBTs(h-1);
    int y = balancedBTs(h-2);
    
    int ans1 = (int)(((long)(x)*x) %mod);
    int ans2 = (int)((2*(long)(x)*y) %mod);
    
    return (ans1 + ans2)%mod;
}

int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}


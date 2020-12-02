#include <iostream>
using namespace std;

int staircase(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }
    else if( n==3){
        return 4;
    }
    return staircase(n-1) + staircase(n-2) + staircase(n-3);
}

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}

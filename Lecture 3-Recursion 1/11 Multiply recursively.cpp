#include<iostream>
using namespace std;

int multiplyNumbers(int m, int n) {
    if(m==0 || n==0){
        return 0;
    }
    int s = m + multiplyNumbers(m, n-1);
    return s;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}

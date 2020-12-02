#include<iostream>
using namespace std;

int countZeros(int n) {
    if(n<10){
        return 0;
    }
    int r =0;
    if(n%10 == 0){
        r =1;
    }
    int s = r + countZeros(n/10);
    return s;
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}

#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if(n<10){
        return n;
    }
    int r = n%10;
    int s = r + sumOfDigits(n/10);
    return s;
}

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}

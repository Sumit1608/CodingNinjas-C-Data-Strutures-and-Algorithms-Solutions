#include<iostream>
using namespace std;

double geometricSum(int k) {
    if( k== 0){
        return 1.0;
    }
    double j =1.0;
    for(int i=1; i<=k; i++){
        j = j/2.0;
    }
    
    double s = j + geometricSum(k-1);
    return s;
}

int main() {
    int k;
    cin >> k;
    cout << geometricSum(k) << endl;   
}

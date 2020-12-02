#include <iostream>
using namespace std;
#include <math.h>

int binaryTreesOfHeightH(int h) {
    int arr[h+1];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=h;i++){
    	int mod = (int) (pow(10, 9)) + 7;
		int x = arr[i - 1];
		int y = arr[i - 2];

		int temp1 = (int)(((long)(x)*x) % mod);
		int temp2 = (int)((2* (long)(x) * y) % mod);
		arr[i] = (temp1 + temp2) % mod;
    }
    return arr[h];
}


int main() {
    int h;
    cin >> h;
    int ans = binaryTreesOfHeightH(h);
    cout << ans << endl;
}


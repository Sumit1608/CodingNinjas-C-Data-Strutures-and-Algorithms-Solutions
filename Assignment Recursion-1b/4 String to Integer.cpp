#include <iostream>
using namespace std;
#include<string.h>

int stringToNumber(char input[]) {
    int k = strlen(input);
    if(k == 0){
        return 0;
    }
    int n = input[0] - '0';
    if(k>1){
        for(int i=1; i<k;i++){
            n= n*10;
        }
    }
    int s = stringToNumber(input + 1);
    return s+n;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}


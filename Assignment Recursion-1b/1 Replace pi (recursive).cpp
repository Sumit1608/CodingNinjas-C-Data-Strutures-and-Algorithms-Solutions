#include <iostream>
using namespace std;
#include<string.h>

void replacePi(char input[]) {
    int k=strlen(input);
    if(k<=1){
        return;
    }
    if(input[0] == 'p' && input[1] == 'i'){
        for(int i=k; i>=2; i--){
            input[i+2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }
    return replacePi(input+1);
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}


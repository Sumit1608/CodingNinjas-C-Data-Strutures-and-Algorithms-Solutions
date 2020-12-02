#include <iostream>
using namespace std;
#include<string.h>

void removeX(char input[]) {
	int k=strlen(input);
    if(k==0){
        return;
    }
    removeX(input+1);
    
    if(input[0] == 'x'){
        for(int i=0; i<k; i++){
            input[i]=input[i+1];
        }  
    }
    else{
        return;
    }
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}


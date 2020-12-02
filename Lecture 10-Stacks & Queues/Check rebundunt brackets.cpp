#include <iostream>
using namespace std;

#include<stack>
#include<string.h>

bool checkRedundantBrackets(char *input) {
    stack<char> s;
    int len = strlen(input);
    
    for(int i=0; i< len; i++){
        if(input[i] == ')'){
            int count =0;
            while(s.top() != '('){
                count++;
                s.pop();
            }
            if(count != 0){
                s.pop();
                continue;
            }
            else
                return true;
        }
        
        else
            s.push(input[i]);
    }
    return false;
}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);

    if(checkRedundantBrackets(input)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}

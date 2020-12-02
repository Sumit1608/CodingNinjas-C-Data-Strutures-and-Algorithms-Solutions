#include <iostream>
using namespace std;

#include<stack>
#include<string.h>

bool checkBalanced(char *exp) {
    stack <char> s;
    int len = strlen(exp);
    for(int i=0; i< len; i++){
        if((exp[i] == '{') || (exp[i] == '[') || (exp[i] == '(')){
            s.push(exp[i]);
            continue;
        }
        else if((exp[i] == '}') || (exp[i] == ']') || (exp[i] == ')')){
            if(s.empty())
                return false;
            
            else if((s.top() == '{') && (exp[i] == '}')){
                s.pop();
                continue;
            }
            else if((s.top() == '[') && (exp[i] == ']')){
                s.pop();
                continue;
            }
            else if((s.top() == '(') && (exp[i] == ')')){
                s.pop();
                continue;
            }
            else
                return false;
        }
    }
    
    if(s.empty())
        return true;
    else
        return false;   
}

int main() {
    char input[100000];
    cout<<" Enter the expression "<<endl;
    cin.getline(input, 100000);

    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

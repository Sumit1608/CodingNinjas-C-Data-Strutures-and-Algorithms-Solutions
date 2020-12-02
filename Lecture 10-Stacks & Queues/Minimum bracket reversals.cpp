#include <iostream>
using namespace std;

#include<stack>
#include<string.h>

int countBracketReversals(char input[]){
	int len = strlen(input);
    
    if(len%2 == 0){
        stack<char> s;
        
        for(int i=0; i< len; i++){
            if(input[i] == '{')
                s.push(input[i]);
            else{
                if(!s.empty() && (s.top() == '{'))
                    s.pop();
                else
                    s.push(input[i]);
            }
        }
        
        int count =0;
        while(!s.empty()){
            int a = s.top();
            s.pop();
            int b= s.top();
            s.pop();
            if(a == b)
                count++;
            else
                count +=2;
        }
        return count;
    }
    else
        return -1;
}

/*Simple way of code without using stack
#include<string.h>
int countBracketReversals(char input[]){
    int len = strlen(input);
    int i=0, j=0;
    if(len % 2 == 0){
	    for(int k=0; k< len; k++){
            if(input[k] == '{')
                i++;
            else
                j++;
        }
        if(i>j)
            return (i-j)/2;
        else
            return (j-i)/2;
    }
    
    else{
        return -1;
    }
}*/

int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}

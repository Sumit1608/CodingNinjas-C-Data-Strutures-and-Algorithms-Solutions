#include <iostream>
using namespace std;

bool helper(char input[], int start, int end){
    if(start>end){
        return true;
    }
    else{
        if(input[start] == input[end]){
       		start ++;
        	end --;
    	    return helper(input, start, end);
   		}
        else{
            return false;
        }
    }
}

bool checkPalindrome(char input[]) {
    int start =0;
    int i=0;
    while(input[i] != '\0'){
        i++;
    }
    if(i ==1){
        return true;
    }
    int end = i-1;
    if(input[start] == input[end]){
        start ++;
        end --;
        return helper(input, start, end);
    }
    else{
        return false;
    }
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

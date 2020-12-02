#include<iostream>
using namespace std;
#include<unordered_map>
#include<string.h>


char* uniqueChar(char *str){
    int l= strlen(str);
    char *ans = new char[l];
    unordered_map<char, int> m;
    
    for(int i=0; i<l; i++)
        m[str[i]]++;
    int j=0;
    for(int i=0; i<l; i++){
        if(m.count(str[i]) > 0){
            ans[j] = str[i];
            j++;
            m.erase(str[i]);
        }
    }
    ans[j+1] = '/0';
    return ans;
}


int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}

#include <iostream>
using namespace std;

#include <stack>

void reverseStack(stack<int> &input, stack<int> &extra) {
	if(input.size() == 0 || input.size() ==1)
        return;
    
    int element = input.top();
    input.pop();
    reverseStack(input, extra);
    
    while(!input.empty()){
        int a = input.top();
        extra.push(a);
        input.pop();
    }
    input.push(element);
    
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
}

int main() {
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	s1.push(val);
    }
    reverseStack(s1, s2);
    while(!s1.empty()) {
    	cout << s1.top() << " ";
    	s1.pop();
    }
}

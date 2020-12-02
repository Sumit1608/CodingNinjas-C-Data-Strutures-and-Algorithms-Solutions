#include <iostream>
using namespace std;

int fib(int n) {
	if (n == 0 || n==1) {
		return n;
	}

	int output = fib(n -1) + fib(n - 2);
	return output;
}

int main() {
	int n;
	cout<<"Enter nth fibonacci number :"<<endl;
	cin>>n;
	cout << fib(n) << endl;
}


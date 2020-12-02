#include <iostream>
using namespace std;

void increment(int& i) {
	i++;
}

// bad practice
// here we return the reference
int& f(int n) {
	int a = n;
	return a;
}

// bad practice
// here we return the address of variable to the pointer
int* f2() {
	int i = 10;
	return &i;
}

int main() {
	int* p = f2();

	int i;
	i = 10;

	int& k1 = f(i);


	increment(i);
	cout << i << endl;

	int& j = i;

	i++;
	cout << j << endl;
	j++;
	cout << i << endl;

	int k = 100;
	j = k;
	cout << i << endl;
}
// bad practice because of scope of vriables.

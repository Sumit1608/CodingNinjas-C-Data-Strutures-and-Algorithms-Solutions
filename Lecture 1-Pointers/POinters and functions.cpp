#include<iostream>
using namespace std;

void print(int *p){
	cout<<*p<<endl;
}

void incrementPointer(int *p){
	p = p+1;
}

void increment(int *p){
	(*p)++;
}

int main(){
	int i=10;
	int *p =&i;
	
	print(p);
	
	cout<<"Before pointer increment : "<<p<<endl;
	incrementPointer(p);
	cout<<"After pointer increment: "<<p<<endl;
	
	cout<<"Before dereference increment: "<<*p<<endl;
	increment(p);
	cout<<"After dereference increment: "<<*p<<endl;
}

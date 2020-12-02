#include<iostream>
using namespace std;
;

class StackUsingArray{
	int *data;
	
	public:
		int nextIndex =0;
		int capacity = 10;
	
		//return the number of elements in my stack
		int size(){
			return nextIndex;
		}
		
		bool isEmpty(){
			/*if(nextIndex == 0){
				return true;
			}
			else
				return false
			*/
			return nextIndex == 0;
		}
		
		//insert Element
		void push(int element){
			if(nextIndex == capacity){
				/*
				cout<<" Stack is full "<<endl;
				return;
				*/
				int *newData = new int[2*capacity];
				for(int i=0; i< capacity; i++){
					newData[i] = data[i];
				}
				capacity *= 2;
				delete []data;
				data = newData;
			}
			
			data[nextIndex] = element;
			nextIndex++;
		}
		
		//delete element
		int pop(){
			if(isEmpty()){
				cout<<" Stack is empty "<<endl;
				return INT_MIN;
			}
			else{
				nextIndex--;
				return data[nextIndex];
			}
		}
		
		int top(){
			if(isEmpty()){
				cout<<" Stack is empty "<<endl;
				return INT_MIN;
			}				
			return data[nextIndex-1];
		}		
};
	
int main(){
	StackUsingArray s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	
	cout << s.top() << endl;
	
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	
	cout << s.size() << endl;
	cout<< s.isEmpty()<< endl;

}

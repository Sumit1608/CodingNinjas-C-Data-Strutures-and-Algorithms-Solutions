#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(int data){
			this -> data = data;
			next = NULL;
		}
};


//This has a complexity of O(n)
Node* takeInput_Better(){
	cout<<"To terminate taking input, type '-1'."<<endl;
	cout<<"Enter the data "<<endl;
	int data;
	cin>>data;
	Node *head = NULL;
	Node *tail = NULL;

	while(data != -1){
		Node *newNode = new Node(data);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail -> next = newNode;
			tail = tail -> next;//Or
			//tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head){
	while(head != NULL){
		cout<< head->data <<" ";
		head = head->next;
	}
	cout<<endl;
}

int main(){
	Node *head = takeInput_Better();
	print(head);
}

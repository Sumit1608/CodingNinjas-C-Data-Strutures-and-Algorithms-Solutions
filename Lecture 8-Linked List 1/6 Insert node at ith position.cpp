#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

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

int length(Node *head){
    int i=0;
    while(head != NULL){
        head = head-> next;
        i++;
    }
    return i;
}

void printIthNode(Node *head, int i){
    int len = length(head);
    if(i>= len){
        return;
    }
    else{
        int a=0;
        Node *temp= head;
        while(a<i)
        {
            temp = temp->next;
            a++;
        }
        cout<<temp->data;
    } 
}

void print(Node *head){
	
	while(head != NULL){
		cout<< head -> data << " ";
		head = head -> next;
	}
}

Node* insertNode(Node *head, int i, int data){
	Node *newNode = new Node(data);
	int count = 0;
	Node *temp = head;
	
	if(i == 0){
		newNode -> next = head;
		head = newNode;
		return head;
	}
	
	while(temp != NULL && count < i-1){
		temp = temp -> next;
		count++;
	}
	
	if(temp != NULL){
		Node *a = temp -> next;
		temp -> next = newNode;
		newNode -> next = a; //OR
		// newNode -> next = temp -> next;
		// temp -> next = newnode;
	}
	return head;
}

int main(){
	Node *head = takeInput_Better();
	
	print(head);
	int i, data;
	cin>> i >> data;
	head = insertNode(head, i , data);
	print(head);
}

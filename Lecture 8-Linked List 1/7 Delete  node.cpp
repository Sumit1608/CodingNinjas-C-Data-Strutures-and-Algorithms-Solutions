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

Node *takeinput(){
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head){
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int length(Node *head){
    int i=0;
    while(head != NULL){
        head = head-> next;
        i++;
    }
    return i;
}

Node *deleteNode(Node *head, int pos){
    int len = length(head);
    if(len <= pos){
        return head;
    }
    
    Node *temp = head;
    int i=0;
    if(head ==  NULL){
        return head;
    }
    if(pos == 0){ 
        head = head -> next;
    	return head;
    }
    
    while(temp != NULL && i < pos-1){
        temp = temp -> next;
        i++;
    }

    if(temp != NULL){
        Node *a = temp-> next;
        Node *b = a-> next;
        temp-> next = b;
        a->next = NULL;
        delete a;
    }
    return head;
}

int main(){
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}

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
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
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
        i++;
        head = head -> next;
    }
    return i;
}

Node *appendLastNToFirst(Node *head, int n){
    if(head == NULL || n ==0){
        return head;
    }
    
    int len = length(head);
    Node *temp = head;
    for(int i =1; i < len-n; i++){
        temp = temp -> next;
    }
    
    Node *newHead = temp-> next;
    temp-> next = NULL;
    
    Node *temp2 = newHead;
    while(temp2 -> next != NULL){
        temp2 = temp2 -> next;
    }
    
    temp2 -> next = head;
    return newHead;
}

int main(){
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}

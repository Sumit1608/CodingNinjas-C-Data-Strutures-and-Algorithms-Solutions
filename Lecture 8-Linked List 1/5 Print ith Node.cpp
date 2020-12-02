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

int main(){
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}

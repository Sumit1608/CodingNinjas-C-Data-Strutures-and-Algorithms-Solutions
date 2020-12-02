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

Node *reverseLinkedList(Node *head){
    Node *curr = head, *prev = NULL, *fwd = NULL;
    
    while(curr != NULL){
        fwd = curr-> next;
        curr-> next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

bool isPalindrome(Node *head){
    if(head == NULL || head-> next == NULL){
        return true;
    }
    
    //Find centre of list
    Node *fast = head, *slow = head;
    while(fast ->next != NULL && fast->next->next != NULL ){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    Node *head2 = slow-> next;
    slow-> next = NULL;
    head2 = reverseLinkedList(head2);
    
    //Compare the two sublists
    Node *firstSubList = head;
    Node *secondSubList = head2;
    
    bool ans = true;
        
    while(secondSubList != NULL){
        if(firstSubList -> data != secondSubList-> data) {
            ans = false;
            break;
        }
        firstSubList = firstSubList->next;
        secondSubList = secondSubList-> next;
    }
    
    //Rejoin the two sublists
    firstSubList = head;
    secondSubList = reverseLinkedList(head2);
    
    while(firstSubList-> next != NULL){
        firstSubList = firstSubList-> next;
    }
    firstSubList-> next = secondSubList;
    
    return ans;
}

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

int main(){
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}

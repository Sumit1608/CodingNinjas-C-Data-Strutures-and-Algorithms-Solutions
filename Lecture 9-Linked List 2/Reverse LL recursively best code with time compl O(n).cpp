//This have time complexity of O(n squared)
#include <iostream>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

node *reverseLL_3(node *head){
    if( head == NULL || head -> next == NULL){
        return head;
    }
    
    node *smallAns = reverseLL_3(head-> next);
    /*
	node *temp = smallAns;
    while(temp-> next != NULL){
        temp = temp-> next;
    }
    temp-> next = head;
    */
    
    node *tail = head-> next;
    tail-> next = head;
    head-> next = NULL;
    return smallAns;
}

void print(node *head){
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* head=takeinput();
    head=reverseLL_3(head);
    print(head);
    return 0;
}

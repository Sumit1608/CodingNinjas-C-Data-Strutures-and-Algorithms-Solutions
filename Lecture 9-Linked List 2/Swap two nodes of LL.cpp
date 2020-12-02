//Implement code to swap two elements of a Linked List. You need to swap the nodes not the data
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

void print(node *head){
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* swap_nodes(node *head, int i, int j){
    node *node1 = head, *node2 = head, *prev1 = NULL, *prev2 = NULL;
    
    while(i>0 && node1 != NULL){
        prev1 = node1;
        node1 = node1-> next;
        i--;
    }
    while(j>0 && node2 != NULL){
        prev2 = node2;
        node2 = node2-> next;
        j--;
    }    
    
    if(node1 == NULL || node2 == NULL){
        return head;
    }
    
    if(prev1 != NULL)
        prev1-> next = node2;
    else
        head = node2;
    
    if(prev2 != NULL)
        prev2 -> next = node1;
    else
        head = node1;
    
    node *shift = node2 -> next;
    node2 -> next = node1 -> next;
    node1 -> next = shift;
    
    return head;
}

int main(){
    int i,j;
    node* head =takeinput();
    cin>>i;
    cin>>j;
    head=swap_nodes(head,i,j);
    print(head);
    return 0;
}

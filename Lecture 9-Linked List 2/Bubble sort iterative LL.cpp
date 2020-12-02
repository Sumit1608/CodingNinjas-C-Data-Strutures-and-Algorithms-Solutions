//bubble sort iterative
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

int length(node *head){
    int i=0;
    while(head != NULL){
        i++;
        head = head->  next;
    }
    return i;
}

node* bubble_sort_LinkedList_itr(node* head){
    int len=length(head);
    
    for(int i=0;i<len;i++){
        node *current=head,*prev=NULL;
    	node *next=current->next;

        while(current->next!=NULL){
            if(current->data>next->data){
                if(prev==NULL){
                    current->next=next->next;
                    next->next=current;
                    prev=next;
                    head=prev;
                    next=current->next;
                }
                else{
                    prev->next=current->next;
                    current->next=next->next;
                    next->next=current;
                    prev=next;
                    next=current->next;
                }
            }
            else{
                prev=current;
                current=current->next;
                next=current->next;
            }
        }
    }
    return head;
}

int main(){
    node* head=takeinput();
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}

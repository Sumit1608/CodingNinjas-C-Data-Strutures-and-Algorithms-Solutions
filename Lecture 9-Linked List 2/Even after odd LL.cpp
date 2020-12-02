//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
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


node* merge(node *odd, node *even){
    node *temp = odd;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp-> next = even;
    return odd;
}

node* arrange_LinkedList(node*head){

    node *odd = NULL, *even = NULL;
    node *temp = head;
    
    while(temp != NULL){
        
        if((temp-> data %2) == 0){
            node *b = new node(temp-> data);
            if(even == NULL){
                even = b;
            }
            else{
                node *end2 = even;
                while(end2-> next != NULL){
                    end2 = end2 -> next;
                }
                end2 -> next = b;
            }
        }

        else{
            node *a = new node(temp-> data);
            if(odd == NULL ){
                odd = a;
            }
            else{
                node *end1 = odd;
                while(end1 -> next != NULL){
                    end1 = end1 -> next;
                }
                end1 -> next = a;
            }
        }
        temp = temp -> next;
    }
    
    if(odd == NULL){
        return even;
    }
    else{
        node *small = merge(odd, even);
        return small;
    }
}

int main(){
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}


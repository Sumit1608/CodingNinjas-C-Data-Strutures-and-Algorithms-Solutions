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

//Merge sort
int length(node *head){
    int count =0;
    while(head != NULL){
        count ++;
        head = head-> next;
    }
    return count;
}

node* mergeTwoLLs(node *head1, node *head2){
    node *fh = NULL, *ft = NULL;  //fh = head, ft = tail
    if(head1 -> data <= head2 -> data){
        fh = head1;
        ft = head1;
        head1 = head1 -> next;
    }
    else{
        fh = head2;;
        ft = head2;
        head2 = head2 -> next;
    }
    
    while( head1 != NULL && head2 != NULL){
        if(head1 -> data <= head2-> data){
            ft -> next = head1;
            ft = head1;
            head1 = head1 -> next;
        }
        else{
            ft-> next = head2;
            ft = head2;
            head2 = head2-> next;
        }
    }
    
    if(head1 == NULL){
        ft -> next = head2;
        return fh;
    }
    else{
        ft -> next = head1;
        return fh;
    }
}

node* mid(node *head)
{
    node *slow=head,*fast=head->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        
    }
    return slow;
}

node *mergeSort(node *head){
    int len = length(head);
    if(len == 1){
        return head;
    }
    
    node *middle = mid(head);
    node *head2 = middle ->next;
    middle -> next = NULL;
    
    head = mergeSort(head);
    head2 = mergeSort(head2);
    
    node *temp = mergeTwoLLs(head, head2);
    return temp;
}

int main(){
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;
}

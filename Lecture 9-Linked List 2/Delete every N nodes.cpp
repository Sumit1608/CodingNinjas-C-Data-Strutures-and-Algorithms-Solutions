#include <iostream>

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;

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

node* skipMdeleteN(node  *head, int M, int N){
    if(M== 0){
        return NULL;
    }
    else if(NULL){
        return head;
    }
    node *curr = head, *a;
    
    while(curr != NULL){
        for(int i=1; i<M && curr != NULL; i++)
            curr = curr-> next;
        if(curr == NULL)
            return head;
        a = curr-> next;
        for(int i=1; i<=N && a != NULL; i++){
            a = a-> next;
        }
        
        curr-> next = a;
        curr = a;
    }
    return head;
}

int main(){
    node* head=takeinput();
    int m,n;
    cin>>m >> n;
    head= skipMdeleteN(head,m,n);
    print(head);
    return 0;
}

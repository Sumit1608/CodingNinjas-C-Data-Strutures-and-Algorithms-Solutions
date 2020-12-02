#include <iostream>
using namespace std;

#include <vector>
#include <queue>

template <typename T>
class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
    }
};

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput(){
	int rootData;
	cout<<"Enter the data : ";
	cin>>rootData;
	if(rootData == -1)
		return NULL;
	
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(pendingNodes.size() != 0){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		
		cout<<"Enter left child of "<<front->data <<endl;
		int leftChildData;
		cin>>leftChildData;
		if(leftChildData != -1){
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front-> left = child;
			pendingNodes.push(child);
		}
		
		cout<<"Enter right child of "<<front->data <<endl;
		int rightChildData;
		cin>> rightChildData;
		if(rightChildData != -1){
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front-> right = child;
			pendingNodes.push(child);
		}
	}

	return root;
}

void print(node<int> *head)
{
    node<int> *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}



vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> q;
    vector<node<int>*> v;
    node<int> *head = NULL, *tail = NULL;
    
    q.push(root);
    q.push(NULL);
    
    while(q.size() != 0){
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if(front == NULL){
            v.push_back(head);
            head = NULL;
            tail = NULL;
            
            if(q.size() == 0)
                break;
            q.push(NULL);
        }
        else{
            if(front->left != NULL)
                q.push(front-> left);
            if(front->right != NULL)
                q.push(front->right);
            
            //inserting LL
            node<int> *n = new node<int>(front->data);
            if(head == NULL){
                head=n;
                tail=n;
            }
            else{
                tail->next =n;
                tail=n;
            }
        }
    }
    return v;
}



int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<node<int>*> ans = createLLForEachLevel(root);
    for(int i = 0; i < ans.size(); i++) {
	    print(ans[i]);
    }
}


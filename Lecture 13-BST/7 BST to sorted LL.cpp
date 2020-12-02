#include<iostream>
using namespace std;

#include<queue>

template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};


template<typename T>
class BinaryTreeNode{
	public:
		T data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;
		
		BinaryTreeNode(T data){
			this->data = data;
			left = NULL;
			right = NULL;
		}
		
		~BinaryTreeNode(){
			delete right;
			delete left;
		}		
};

BinaryTreeNode<int>* takeInputLevelWise(){
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



Node<int>* constructBST(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return NULL;
    
    Node<int> *Lhead = constructBST(root->left);
    Node<int> *newnode = new Node<int>(root->data);
    Node<int> *Rhead = constructBST(root->right);
    
    Node<int>* temp = Lhead;
    if(temp == NULL){
        newnode-> next = Rhead;
        return newnode;
    }
    else{
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = Rhead;
        return Lhead;
    }
}



int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    Node<int>* head = constructBST(root);
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    
}

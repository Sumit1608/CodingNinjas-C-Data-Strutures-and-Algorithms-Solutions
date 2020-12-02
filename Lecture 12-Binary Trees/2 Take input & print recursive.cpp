#include<iostream>
using namespace std;

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

void printTree(BinaryTreeNode<int>* root){
	//Base case
	if(root == NULL)
		return;
	cout<<root->data<<":";
	
	if(root->left != NULL)
		cout<<"L" << root->left->data <<",";
	if(root->right != NULL)
		cout<<"R" << root->right->data;		
	
	cout<<endl;
	printTree(root->left);
	printTree(root->right);
}

BinaryTreeNode<int>* takeInput(){
	int rootData;
	cout<<"Enter the data : ";
	cin>>rootData;
	if(rootData == -1)
		return NULL;
	
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();
	root->left = leftChild;
	root->right = rightChild;
	
	return root;
}

int main(){
	BinaryTreeNode<int>* root = takeInput();
	printTree(root);
	delete root;
}

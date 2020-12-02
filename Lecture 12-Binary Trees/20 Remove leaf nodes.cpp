#include<iostream>
using namespace std;
#include<queue>

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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    pending.push(NULL);
    
    while(pending.size() != 0){
        BinaryTreeNode<int> *front = pending.front();
        pending.pop();
        
        if(front == NULL){
            if(pending.size() == 0)
                break;
            cout<<endl;
            pending.push(NULL);
        }
        else{
        	cout<<front->data<<" ";
	        if(front->left != NULL)
    	        pending.push(front->left);
        	if(front->right != NULL)
            	pending.push(front->right);
        }
    }
    cout<<endl;
}


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



BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if(root == NULL || (root-> left== NULL && root->right == NULL))
        return NULL;
    root-> left = removeLeafNodes(root->left);
    root-> right = removeLeafNodes(root-> right);
    return root;
}




int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelATNewLine(root);
    cout<<"The tree after removal of leaf nodes "<<endl;
	root = removeLeafNodes(root);
    printLevelATNewLine(root);
	delete root;
}

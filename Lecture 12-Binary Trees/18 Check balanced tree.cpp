#include<iostream>
using namespace std;

//lib header used to use abs() fxn
#include <cstdlib>
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

void printLevelWise(BinaryTreeNode<int>* root){
	//Base case
	if(root == NULL)
		return;
	
	queue<BinaryTreeNode<int>*> pending;
	pending.push(root);
	
	while(pending.size() != 0){
		BinaryTreeNode<int> *front = pending.front();
		pending.pop();
		cout<<front->data<<":";
		
		if(front->left != NULL){
			cout<<"L" <<":"<< front->left->data ;
			pending.push(front->left);
		}
		else
			cout<<"L"<<":"<<"-1";
		
		if(front->right != NULL){
			cout<<","<<"R" << ":"<< front->right->data ;
			pending.push(front->right);
		}
		else
			cout<<","<<"R"<<":"<<"-1";
		
		cout<<endl;
	}
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



int height(BinaryTreeNode<int> *root){
    if(root == NULL)
        return 0;    
    return 1 + max(height(root->left), height(root->right) );
}

bool isBalanced(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return true;
    int left = height(root-> left);
    int right = height(root-> right);
    //abs is a inbuilt fxn which take mode of the values, i.e. absolute value
    if(abs(left - right) > 1)
        return false;
    
    bool ans1 = isBalanced(root->left);
    bool ans2 = isBalanced(root->right);
    if(ans1 && ans2)
        return true;
    else
        return false;
}



int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
    if(isBalanced(root))
    	cout << "true" << endl;
    else
	cout << "false" << endl;
	
	delete root;
}

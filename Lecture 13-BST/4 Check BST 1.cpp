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


//It have worse time complexity of O(nlogn), this is not the perfect way to check whether a tree is bst or not 
#include<climits>
int maximum(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return INT_MIN;
	}
	return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return INT_MAX;
	}
	return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return true;
	}

	int leftMax = maximum(root->left);
	int rightMin = minimum(root->right);
	bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
	return output;
}



int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    if(isBST(root)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    delete root;
}

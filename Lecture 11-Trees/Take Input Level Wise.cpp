#include <iostream>
using namespace std;

#include<queue>
#include<vector>
template<typename T>

class TreeNode{
	public:
		int data;
		vector<TreeNode<T>*> children;
		
		TreeNode(T data){
			this->data = data;
		}
};

TreeNode<int>* takeInputLevelWise() {
	int rootdata;
	cout<<"Enter root data" <<endl;
	cin>>rootdata;
	TreeNode<int>* root = new TreeNode<int>(rootdata);
	
	queue<TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	while(pendingNodes.size() != 0){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		
		cout<<"Enter number of children of "<<front->data<<endl;
		int numChild;
		cin>>numChild;
		
		for(int i=0; i<numChild; i++){
			int childData;
			cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
			cin>>childData;
			
			TreeNode<int> *child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

/*
TreeNode<int>* takeInput(){
	int rootdata;
	cout<<"Enter the data ";
	cin>>rootdata;
	TreeNode<int>* root = new TreeNode<int>(rootdata);
	
	int n;
	cout<<"Enter number of children ";
	cin>>n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;	
}*/

void printTree(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	cout<< root->data<<':';
	for(int i=0; i<root->children.size(); i++){
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	
	for(int i=0; i< root->children.size() ; i++){
		printTree(root->children[i]);
	}
}

int main(){
	TreeNode<int>* root = takeInputLevelWise();
	printTree(root);
}

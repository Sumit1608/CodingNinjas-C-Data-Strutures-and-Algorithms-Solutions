#include <iostream>
using namespace std;

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

void printTree(TreeNode<int>* root){
	cout<< root->data<< endl;
	for(int i=0; i< root->children.size() ; i++){
		printTree(root->children[i]);
	}
}

int main(){
	TreeNode<int>* root =new TreeNode<int>(1);
	TreeNode<int>* node1 =new TreeNode<int>(2);
	TreeNode<int>* node2 =new TreeNode<int>(3);
	// so here, individual treenodes are formed
	
	//Now we connect them 
	root->children.push_back(node1);  
	root->children.push_back(node2); 
	cout<<root->children.size()<<endl;
	printTree(root);
}

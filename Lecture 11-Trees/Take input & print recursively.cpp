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
}

//Thise fxn do not require base case as if the root do not have any child then the fxn will not run
void printTree(TreeNode<int>* root){
	//This is the edge case not base case
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
	TreeNode<int>* root = takeInput();
	printTree(root);
}

/*
Try using taking these input anf the tree will be as

Enter the data 1                              1
Enter number of children 3                  / | \
Enter the data 2                          2   3  4
Enter number of children 2             /  |   |   \
Enter the data 5                      5  6    7    8
Enter number of children 0
Enter the data 6
Enter number of children 0
Enter the data 3
Enter number of children 1
Enter the data 7
Enter number of children 0
Enter the data 4
Enter number of children 1
Enter the data 8
Enter number of children 0
*/

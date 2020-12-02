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

int main(){
	TreeNode<int> *root =new TreeNode<int>(1);
	TreeNode<int> *node1 =new TreeNode<int>(2);
	TreeNode<int> *node2 =new TreeNode<int>(2);// so here, individual treenode are formed
	
	//Now we connect them as                       1
	root->children.push_back(node1);     //      /  \   
	root->children.push_back(node2);     //     2    3
}

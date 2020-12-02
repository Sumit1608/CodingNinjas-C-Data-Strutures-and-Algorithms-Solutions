#include <iostream>
using namespace std;

#include <queue>

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

class PairAns {
    public :
    int min;
    int max;
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


#include<climits>
PairAns minMax(BinaryTreeNode<int> *root) {
    if(root == NULL){
        PairAns p;
        p.min = INT_MAX;
        p.max = INT_MIN;
        return p;
    }
    PairAns leftAns = minMax(root->left);
    PairAns rightAns = minMax(root->right);
    
    PairAns sol;
    sol.max = max(root->data, max(leftAns.max, rightAns.max));
    sol.min = min(root->data, min(leftAns.min, rightAns.min));
    return sol;
}


int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    PairAns ans = minMax(root);
    cout << ans.max << " " << ans.min << endl;
}

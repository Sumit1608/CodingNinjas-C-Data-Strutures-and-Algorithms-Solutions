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
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}



int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2){
    if(root == NULL)
        return -1;
    if(root->data == val1 || root->data == val2)
        return root->data;
    
    if(root->data < val1 && root->data < val2)
        return lcaInBST(root->right, val1, val2);
    else if(root->data > val1 && root->data > val2)
        return lcaInBST(root->left, val1, val2);
    else{
    	int left = lcaInBST(root->left, val1, val2);
    	int right = lcaInBST(root->right, val1, val2);
    
	    if(left != -1 && right == -1)
    	    return left;
    	else if(left == -1 && right != -1)
    	    return right;
    	else if(left == -1 && right == -1)
            return -1;
    	else
        	return root->data;
    }
}




int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << lcaInBST(root, a, b);
    delete root;
}

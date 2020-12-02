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



#include<climits>
bool helper(BinaryTreeNode<int> *root,int max,int min){
    if(root==NULL)
        return true;
    if(root->data>max||root->data<min)
        return false;
    
    bool left=helper(root->left,root->data-1,min);
    bool right=helper(root->right,max,root->data);
    
    return left&&right;
}

bool isBST(BinaryTreeNode<int> *root){
    bool ans=helper(root,INT_MAX,INT_MIN);
    return ans;
}

int height(BinaryTreeNode<int> *root){
    if(root == NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    if(root== NULL)
        return -1;
    
    if(isBST(root))
        return height(root);
    else{
        int left = largestBSTSubtree(root->left);
        int right = largestBSTSubtree(root->right);
        return max(left, right);
    }
    
}




int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}


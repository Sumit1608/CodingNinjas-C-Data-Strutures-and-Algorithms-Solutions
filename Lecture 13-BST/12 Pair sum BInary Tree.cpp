#include <iostream>
#include <vector>
using namespace std;
#include<queue>
#include<algorithm>

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
    	if(left) {
     		delete left;
    	}
	if(right) {
     		delete right;
    	}
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




void convertToArray(BinaryTreeNode<int> *root, vector<int> &output){
	if(root == NULL)
		return;
	output.push_back(root->data);
	convertToArray(root->left, output);
	convertToArray(root->right, output);
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum){
	vector<int> output;
	convertToArray(root, output);
	
	sort(output.begin(), output.end());
	
	int i=0, j = output.size()-1;
	while(i<j){
		if(output[i] + output[j] == sum){
			//If duplicates element are present
			int countI=1, countJ = 1;
			
			//Count the number of times 1st element is present
			int k=i+1;
			while(output[k] == output[i]){
				countI++;
				k++;
			}
			
			//Count the number of times 1st element is present
			k=j-1;
			while(output[k] == output[j]){
				countJ++;
				k--;
			}
			
			//Print the pair count times
			int count = countI*countJ;
			while(count>0){
				cout << output[i] << " "<< output[j] << endl;
				count--;
			}
			i += countI;
			j -= countJ;
		} 
		else if(output[i] + output[j] > sum)
			j--;
		else
			i++;
	}
	
}





int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    delete root;
}

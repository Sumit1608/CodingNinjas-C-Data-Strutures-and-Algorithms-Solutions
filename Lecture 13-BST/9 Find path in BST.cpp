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



#include<vector>
vector<int>* findPath(BinaryTreeNode<int> *root , int data){
    if(root==NULL)
        return NULL;
    if(root->data==data){
        vector<int>* out=new vector<int>();
        out->push_back(root->data);
        return out;
    }
    
    vector<int>* leftout=findPath(root->left,data);
    if(leftout!=NULL){
        leftout->push_back(root->data);
        return leftout;
    }
    
    vector<int>* rightout=findPath(root->right,data);
    if(rightout!=NULL){
        rightout->push_back(root->data);
        return rightout;
    }
    else
        return NULL;
}



int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    int k;
    cout<<"Enter the element : ";
    cin >> k;
    vector<int> *output = findPath(root, k);
    if(output != NULL) {
        for(int i = 0; i < output -> size(); i++) {
            cout << output -> at(i) << endl;
        }
    }
    delete output;
	delete root;
}

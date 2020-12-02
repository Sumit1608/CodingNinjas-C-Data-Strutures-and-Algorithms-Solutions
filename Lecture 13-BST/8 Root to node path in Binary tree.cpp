#include<iostream>
using namespace std;
#include<queue>
#include<vector>

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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    pending.push(NULL);
    
    while(pending.size() != 0){
        BinaryTreeNode<int> *front = pending.front();
        pending.pop();
        
        if(front == NULL){
            if(pending.size() == 0)
                break;
            cout<<endl;
            pending.push(NULL);
        }
        else{
        	cout<<front->data<<" ";
	        if(front->left != NULL)
    	        pending.push(front->left);
        	if(front->right != NULL)
            	pending.push(front->right);
        }
    }
    cout<<endl;
}


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




vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){
	if(root == NULL)
		return NULL;
	
	if(root->data == data ){
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}
	
	vector<int>* leftOutput = getRootToNodePath(root->left, data);
	if(leftOutput != NULL){
		leftOutput->push_back(root->data);
		return leftOutput;
	}
	
	vector<int>* rightOutput = getRootToNodePath(root->right, data);
	if(rightOutput != NULL){
		rightOutput->push_back(root->data);
		return rightOutput;
	}
	else{
		return NULL;
	}
}




int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
    int data;
    cout<<"Enter element to find path : ";
    cin>>data;
    
    vector<int>* output = getRootToNodePath(root, data);
    for(int i=0; i< output->size(); i++){
    	cout<< output->at(i) << endl;
	}
	delete output;
	delete root;
}

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

void printLevelWise(BinaryTreeNode<int>* root){
	//Base case
	if(root == NULL)
		return;
	
	queue<BinaryTreeNode<int>*> pending;
	pending.push(root);
	
	while(pending.size() != 0){
		BinaryTreeNode<int> *front = pending.front();
		pending.pop();
		cout<<front->data<<":";
		
		if(front->left != NULL){
			cout<<"L" <<":"<< front->left->data ;
			pending.push(front->left);
		}
		else
			cout<<"L"<<":"<<"-1";
		
		if(front->right != NULL){
			cout<<","<<"R" << ":"<< front->right->data ;
			pending.push(front->right);
		}
		else
			cout<<","<<"R"<<":"<<"-1";
		
		cout<<endl;
	}
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


#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            BinaryTreeNode<int> *temp1 = s1.top();
            s1.pop();
            cout<< temp1-> data<<" ";
            if(temp1->left != NULL)
                s2.push(temp1 -> left);
            if(temp1->right != NULL)
                s2.push(temp1 -> right);
        }
        if(s1.empty())
            cout<<endl;
        
        while(!s2.empty()){
            BinaryTreeNode<int> *temp2 = s2.top();
            s2.pop();
            cout<< temp2->data<<" ";
            if(temp2->right != NULL)
                s1.push(temp2->right);
            if(temp2->left != NULL)
                s1.push(temp2->left);
        }
        if(s2.empty())
            cout<<endl;
    }
}


int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	zigZagOrder(root);
	delete root;
}

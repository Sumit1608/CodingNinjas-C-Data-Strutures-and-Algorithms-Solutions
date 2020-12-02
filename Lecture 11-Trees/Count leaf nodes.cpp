#include <iostream>
using namespace std;

#include<queue>
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

TreeNode<int>* takeInputLevelWise() {
	int rootdata;
	cout<<"Enter root data" <<endl;
	cin>>rootdata;
	TreeNode<int>* root = new TreeNode<int>(rootdata);
	
	queue<TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	while(pendingNodes.size() != 0){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		
		cout<<"Enter number of children of "<<front->data<<endl;
		int numChild;
		cin>>numChild;
		
		for(int i=0; i<numChild; i++){
			int childData;
			cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
			cin>>childData;
			
			TreeNode<int> *child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

void printLevelWise(TreeNode<int>* root){
    if(root == NULL)
        return;
    
    queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
    
    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        
        cout<<front->data<<':';
        for(int i=0; i< front->children.size(); i++){
            if((front->children.size()-i)  == 1){
                 cout<<front->children.at(i)->data;
            	pendingNodes.push(front->children.at(i));
                continue;
            }
            cout<<front->children.at(i)->data<<',';
            pendingNodes.push(front->children.at(i));
        }   
        cout<<endl;
    }    
}

int numLeafNodes(TreeNode<int>* root) {
    if(root->children.size() == 0)
        return 1;
    int ans =0;
    for(int i=0; i< root-> children.size(); i++)
        ans += numLeafNodes(root-> children.at(i));
    return ans;
}

int main(){
	TreeNode<int>* root = takeInputLevelWise();
	cout<<numLeafNodes(root)<<endl;
}

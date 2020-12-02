#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <climits>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
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

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    TreeNode<int> *ans = NULL;
    if(root-> data>n)
        ans = root;
    
    for(int i=0; i<root-> children.size(); i++){
        TreeNode<int> *temp = nextLargerElement(root->children[i],n);
        if(ans == NULL)
            ans = temp;
        else if(temp != NULL )
            if(temp->data < ans->data)
	            ans = temp;   
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = nextLargerElement(root, n);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
    else {
        cout << INT_MIN << endl;
    }
}

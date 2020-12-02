#include <iostream>
using namespace std;
#include <vector>

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

#include <queue>
#include <climits>

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}



class Pair{
    public:
    TreeNode<int> *max;
    TreeNode<int> *sm;
    
};

Pair helper(TreeNode<int> *root){
    Pair ans;
    ans.max=root;
    ans.sm=NULL;
    for(int i=0;i<root->children.size();i++){
        Pair small=helper(root->children[i]);
        //both sm are NULL
        if(ans.sm==NULL&&small.sm==NULL){
            if(ans.max->data<small.max->data){
                TreeNode<int> *temp=ans.max;
                ans.max=small.max;
                ans.sm=temp;
            }
            else if(ans.max->data==small.max->data)
                return ans;
            else
                ans.sm=small.max;
        }
        //ans.sm is NULL
        else if(ans.sm==NULL&&small.sm!=NULL){
            if(ans.max->data>small.max->data)
                ans.sm=small.max;
            else{
                TreeNode<int> *temp=ans.max;
                ans.max=small.max;
                if(temp->data>small.sm->data)
                    ans.sm=temp;
                else
                    ans.sm=small.sm;
            }
            
        }
        
        //small.sm is NULL
        else if(ans.sm!=NULL&&small.sm==NULL){
            if(ans.max->data>small.max->data){
                if(ans.sm->data>small.max->data)
                    return ans;
                else
                    ans.sm=small.max;
            }
            else{
                TreeNode<int> *temp=ans.max;
                ans.max=small.max;
                ans.sm=temp;
            }
        }
        //not NULL
        else{
            if(ans.max->data>small.max->data){
                if(ans.sm->data<small.max->data)
                    ans.sm=small.max;
                else
                    return ans;
            }
            else{
                TreeNode<int> *temp=ans.max;
                ans.max=small.max;
                if(temp->data<small.sm->data)
                    ans.sm=small.sm;
                else
                    ans.sm=temp;
            }
            
        }
    }
    return ans;
}

TreeNode<int>* secondLargest(TreeNode<int> *root){
    Pair a=helper(root);
    return a.sm;
} 



int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL) {
        cout << INT_MIN << endl;
    }
    else {
        cout << ans -> data << endl;
    }
}

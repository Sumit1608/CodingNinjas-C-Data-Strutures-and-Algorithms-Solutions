#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};




class BST 
{
    BinaryTreeNode<int> *root;
    private:
    bool helpsearch(BinaryTreeNode<int> *root,int data)
    {
        if(root==NULL)
            return false;
        if(root->data==data)
            return true;
        if(root->data>data)
        {
            bool left=helpsearch(root->left,data);
            return left;
        }
        else
        {
            bool right=helpsearch(root->right,data);
            return right;
        }
    }
    BinaryTreeNode<int> *helpinsert(BinaryTreeNode<int> *root,int data)
    {
        if(root==NULL)
        {
            BinaryTreeNode<int> *n=new BinaryTreeNode<int>(data);
            return n;
        }
        
        if(root->data>data)
        {
            BinaryTreeNode<int> *left=helpinsert(root->left,data);
            root->left=left;
            
        }
        else
        {
            BinaryTreeNode<int> *right=helpinsert(root->right,data);
            root->right=right;
            
        }
        return root;
        
    }
   
    BinaryTreeNode<int> *helpDelete(BinaryTreeNode<int> *root,int data)
    {
        if(root==NULL)
            return NULL;
        
        if(root->data==data)
        {
            if(root->left==NULL&&root->right==NULL)
            {
                delete root;
                return NULL;
            }
            else if(root->left==NULL)
            {
                BinaryTreeNode<int> *temp=root->right;
                root->right=NULL;
                delete root;
                return temp;
            }
            else if(root->right==NULL)
            {
                BinaryTreeNode<int> *temp=root->left;
                root->left=NULL;
                delete root;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *rmin=root->right;
                while(rmin->left!=NULL)
                {
                    rmin=rmin->left;
                }
                int r=rmin->data;
                root->data=r;
                root->right=helpDelete(root->right,r);
                return root;
            }
        }
        else if(root->data>data)
        {
            root->left=helpDelete(root->left,data);
            return root;
            
        }
        else
        {
            root->right=helpDelete(root->right,data);
            return root;
        }
        
    }
    void p(BinaryTreeNode<int> *root)
    {
        if(root==NULL)
            return;
        cout<<root->data<<":";
        if(root->left!=NULL&&root->right!=NULL)
        {
            cout<<"L"<<":"<<root->left->data<<","<<"R"<<":"<<root->right->data<<endl;
        }
        else if(root->left==NULL&&root->right!=NULL)
        {
            cout<<"R"<<":"<<root->right->data<<endl;
        }
        else if(root->right==NULL&&root->left!=NULL)
        {
            cout<<"L"<<":"<<root->left->data<<","<<endl;
        }
        else
        {
            cout<<endl;
        }
            
        p(root->left);
        p(root->right);
            
    }
    
    public:
    bool hasData(int data)
    {
        return helpsearch(root,data);
    }
    void insert(int data)
    {
        this->root=helpinsert(root,data);
        
    }
	void deleteData(int data)
    {
       BinaryTreeNode<int> *ans= helpDelete(root,data);
    
    }
    void printTree()
    {
        p(root);
    }
    
};




int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
}

#include<iostream>
using namespace std;

template<class T>
class node
{
    public:
    node<T>* left;
    node<T>* right;
    int val;
};
    
    template<typename T>
    void inorder(node<T>* root)
    {
   	    if(root==NULL)
   		    return;
   	    inorder(root->left);
   	    cout<<root->val<<" ";
   	    inorder(root->right);
    }

    template<typename T>
    void preorder(node<T>* root)
    {
   	    if(root==NULL)
   		    return;
   	    cout<<root->val<<" ";
   	    preorder(root->left);
   	    preorder(root->right);
    }

    template<typename T>
    void postorder(node<T>* root)
    {
   	    if(root==NULL)
   		    return;
   	    postorder(root->left);
   	    postorder(root->right);
   	    cout<<root->val<<" ";
    }

    template<typename T>
    node<T>* createnode(node<T>* root,int e)
    {
        node<T>* n=new node<T>();
        n->left=n->right=nullptr;
        n->val=e;
        return n;
    }
    
    template<typename T>
    node<T>* insert(node<T>* root,int e)
    {
        if(root==nullptr)
        {
            root=createnode(root,e);
            return root;
        }
        if(e<=root->val)
            root->left=insert(root->left,e);
        else
            root->right=insert(root->right,e);
        return root;
    }

    int findmin(node<int>* root)
    {
        while(root->left!=NULL)
            root=root->left;
        return root->val;
    }

    template<typename T>
    node<T>* del(node<T>*root,int e)
    {
        if(root==NULL)
        {
            cout<<"Element doesnt exist in tree."<<endl;
            return root;
        }
        else if(root->val==e)
        {
            if(root->right==NULL && root->left==NULL)
                root=NULL;
            else if(root->right==NULL)
                root=root->left;
            else if(root->left==NULL)
                root=root->right;
            else
            {
                int n=findmin(root->right);
                root->val=n;
                root->right=del(root->right,n);
            }
        }
        else if(e<root->val)
            root->left=del(root->left,e);
        else if(e>root->val)
            root->right=del(root->right,e);
        return root;
    }
int menu()
{    
    int ch;
    cout<<endl<<"Menu:\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Delete\n6.END\n";
    cout<<"Choice:";
    cin>>ch;
    return ch;
}

int main()
{
    node<int>* root=nullptr;
    int ch,e;
    while(true)
    {
        ch=menu();
   	    switch(ch)
   	    {
   	        case 1:
   		        cout<<"Enter element:";
   		        cin>>e;
                root=insert(root,e);
		        break;
   	        case 2:
                inorder(root);
   		        break;
   	        case 3:
                preorder(root);
   	    	    break;
   	        case 4:
                postorder(root);
   		        break;
   	        case 5:
   		        cout<<"Enter element:";
   		        cin>>e;
                root=del(root,e);
                break;
   	        case 6:
   		        return 0;
   	        default:
   		        cout<<"Invalid Input";
   	    }
    }
    return 0;
}
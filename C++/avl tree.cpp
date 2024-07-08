#include<iostream>
using namespace std;
#include<cmath>
template<class T>
class node
{
    public:
    node<T>* left;
    node<T>* right;
    int val;
	int height;
};
       
    template<typename T>
    void inorder(node<T>* root)
    {
   	    if(root==NULL)
   		    return;
   	    inorder(root->left);
   	    cout<<"("<<root->val<<":"<<root->height<<") ";
   	    inorder(root->right);
    }

    template<typename T>
    void preorder(node<T>* root)
    {
   	    if(root==NULL)
   		    return;
   	    cout<<"("<<root->val<<":"<<root->height<<") ";
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
   	    cout<<"("<<root->val<<":"<<root->height<<") ";
    }

    template<typename T>
    node<T>* createnode(node<T>* root,int e)
    {
        node<T>* n=new node<T>();
        n->left=n->right=nullptr;
        n->val=e;
		n->height=0;
        return n;
    }
    
    template<typename T>
	int bal(node<T>* root)
	{
		return height(root->left)-height(root->right);
	}

    template<typename T>
	int height(node<T>* root)
	{
		if(root==NULL)
			return -1;
		else 
			return root->height;
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
		{
            int f1=height(root->left);
            root->left=insert(root->left,e);
			if(height(root->left)>height(root->right) && f1!=height(root->left))
				root->height+=1;
		}
		else if(e>root->val)
		{
            int f2=height(root->right);
            root->right=insert(root->right,e);
			if(height(root->left)<height(root->right) && f2!=height(root->right))
				root->height+=1;
		}
        root=check(root);
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
            {   
                root=root->left;
            }
            else if(root->left==NULL)
            {
                root=root->right;
            }
            else
            {
                int n=findmin(root->right);
                root->val=n;
                root->right=del(root->right,n);
            }
        }
        else if(e<root->val)
        {
            root->left=del(root->left,e);
        }
        else if(e>root->val)
        {
            root->right=del(root->right,e);
        }
        if(root!=NULL)
        {
            root->height = 1 + max(height(root->left), height(root->right));
            root=check(root);
        }
        return root;
    }

    template<typename T>
    node<T>* leftrot(node<T>* root)
    {
        node<T>* y=root->right;     
        node<T>* t=y->left;         
        y->left=root;               
        root->right=t;              
        return y; 
    }

    template<typename T>
    node<T>* rightrot(node<T>* root)
    {
        node<T>* y=root->left;
        node<T>* t=y->right;
        y->right=root;
        root->left=t; 
        return y; 
    }

    template<typename T>
    node<T>* check(node<T>* root)
    {
        if(bal(root)==2 && bal(root->left)==1)
        {
            root->height-=2;
            root=rightrot(root);
        }
        else if(bal(root)==-2 && bal(root->right)==-1)
        {
            root->height-=2;
            root=leftrot(root);
        }
        else if(bal(root)==-2)
        {
            if(bal(root->right)==1)
            {
                root->height-=2;
                root->right->height-=1;
                root->right->left->height+=1;
                root->right=rightrot(root->right);
                root=leftrot(root);
            }
            else if(bal(root->right)==0)
            {
                root->height-=2;
                root->right->left->height+=2;
                root->right=rightrot(root->right);
                root=leftrot(root);
            }
        }
        else if(bal(root)==2 && bal(root->left)<=0)
        { 
            if(bal(root->left)==-1)
            {
                root->height-=2;
                root->left->height-=1;
                root->left->right->height+=1;
                root->left=leftrot(root->left);
                root=rightrot(root);
            }
            else if(bal(root->left)==0)
            {
                root->height-=2;
                root->left->right->height+=2;
                root->left=leftrot(root->left);
                root=rightrot(root);
            }
        }
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
		        cout<<"Element added successfully\n";
                break;
   	        case 2:
                cout<<"(Element:Height)"<<endl;
                inorder(root);
   		        break;
   	        case 3:
                cout<<"(Element:Height)"<<endl;
                preorder(root);
   	    	    break;
   	        case 4:
                cout<<"(Element:Height)"<<endl;
                postorder(root);
   		        break;
   	        case 5:
   		        cout<<"Enter element:";
   		        cin>>e;
                root=del(root,e);
                cout<<"Element if present then deleted successfully\n";
                break;
   	        case 6:
   		        return 0;
   	        default:
   		        cout<<"Invalid Input";
   	    }
    }
    return 0;
}
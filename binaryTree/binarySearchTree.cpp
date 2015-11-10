#include<iostream>
#include<string>
using namespace std;

// BINARY SEARCH TREE
// inorder search insert delete findMin findMax getSuccesor lca kth smallest element
struct node
{
	int data;
	int count;
	node* left;
	node* right;
};

struct node* root=NULL;// pointer to root node and set tree as empty tree

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout<<root->data<<endl;
		inorder(root->right);
	}
}

//creating new node
struct node* getNewNode(int data)
{
	node* newnode= new node();
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}

//insertion
node* insert(node* root,int data)
{
	if(root==NULL)
	{
		root=getNewNode(data);
		return root;
	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
		return root;
	}
	else{
		root->right=insert(root->right,data);
		return root;
	}
}

node* Search(node* root,int data)
{
	if(root==NULL)
	return NULL;
	else if(data==root->data)
	return root;
	else if(data<= root->data)
	return Search(root->left,data);
	else if(data>root->data)
	return Search(root->right,data);
	else
	return NULL;
}

node* FindMin(node* root)
{
	if(root == NULL)
	{
		cout<<"empty tree";
		return root;
	}
	else if(root->left==NULL)
	return root;
	else
	return FindMin(root->left);
}

int FindMax(node* root)
{
	if(root==NULL)
	{
		cout<<"empty tree";
		return -1;
	}
	else if(root->right==NULL)
	return root->data;
	else
	return FindMax(root->right);
}

node* deleteNode(node* root,int data)
{
	if(root==NULL)
	return root;
	else if(data < root->data)
	root->left=deleteNode(root->left,data);
	else if(data > root->data)
	root->right=deleteNode(root->right,data);
	else
	{
		//Case1: no child
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			root=NULL;
			return root;
		}
		//Case2: one child
		else if(root->left==NULL)
		{
			node* temp=root;
			root=root->right;
			delete temp;
			return root;
		}
		else if(root->right==NULL)
		{
			node* temp=root;
			root=root->left;
			delete temp;
			return root;
		}
		//Case3: 2 child
		else
		{
			node* temp=FindMin(root->right);
			root->data=temp->data;
			root->right=deleteNode(root->right,temp->data);
			return root;
		}
	}	
}

node* getSuccesor(node* root,int data)
{
	//search the node with this data
	node* current=Search(root,data);
	if(current==NULL)
	return NULL;
	//case1: if node has right subtree
	if(current->right!=NULL)
	{
		return FindMin(current->right);
	}
	//case2: no right subtree
	else
	{
		node* ancestor=root;
		node* succesor=NULL;
		while(ancestor!=current)
		{
		if(current->data < ancestor->data)
		{
			succesor=ancestor;
			ancestor=ancestor->left;
		}
		else
		ancestor=ancestor->right;
		}
		return succesor;
    }
}

//finding lowest common ancestor and assuming both n1 and n2 are present in bst
node* lca(node* root,int n1,int n2)
{
	while(root!=NULL)
	{
		if(n1<root->data && n2<root->data)
		{
			root=root->left;
		}
		else if(n1>root->data && n2>root->data)
		{
			root=root->right;
		}
		else 
		break;
	}
return root;	
}
//get Succesor and predesor for given key
//finding kth smallest element in BST
int kthSmallestElementInBST(node* root,int k)
{
    int ret = 0;
 
    if( root!=NULL)
    {
        /* A crawling pointer */
        node*pTraverse = root;
 
        /* Go to k-th smallest */
        while(pTraverse!=NULL)
        {
            if( (pTraverse->count + 1) == k )
            {
                ret = pTraverse->data;
                break;
            }
            else if( k > pTraverse->count )
            {
                /*  There are less nodes on left subtree
                    Go to right subtree */
                k = k - (pTraverse->count + 1);
                pTraverse = pTraverse->right;
            }
            else
            {
                /* The node is on left subtree */
                pTraverse = pTraverse->left;
            }
        }
    }
 
    return ret;
}

int main()
{
	node* root=NULL;
	root=insert(root,5);
	root=insert(root,3);
	root=insert(root,8);
	root=insert(root,25);
	root=insert(root,20);
	root=insert(root,12);
	root=insert(root,34);
	root=insert(root,11);
	inorder(root);
//	int element;
//	cout<<"\nenter element to be searched"<<endl;
//	cin>>element;
//	node* r=Search(root,element);
//	if(r->data==element && r!=NULL)
//	cout<<"Found"<<endl;
//	else if(r==NULL)
//	cout<<"Not Found"<<endl;
//	int min=FindMin(root);
//	cout<<"\nMinimum element is:  "<<min<<endl;
	int max=FindMax(root);
	cout<<"\nMaximium element is:  "<<max<<endl<<endl;
	cout<<"\nAfter Deletion\n"<<endl;
	root=deleteNode(root,5);
	inorder(root);
	node* k=getSuccesor(root,20);
	cout<<"Succesor is:  "<<k->data;
	int n1=3, n2=11;
	node* t=lca(root,n1,n2);
	cout<<"\n\nlowest common ancesstor of  "<<n1<<"  and  "<<n2<<" is:  "<<t->data;
	int j=kthSmallestElementInBST(root,5);
	cout<<"\n\nkth smallest elemnent is:  "<<j<<endl;
	return 0;
}

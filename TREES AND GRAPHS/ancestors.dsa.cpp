#include<iostream> 
#include<algorithm>
#include<stack>
using namespace std;

struct BSTnode{
	int data;
	struct BSTnode* lchild;
	struct BSTnode* rchild;
};
typedef struct BSTnode* BSTptr;
stack <BSTptr> S;

BSTptr GetNewNode(int x)
{
	BSTptr T=new BSTnode();
	T->data=x;
	T->lchild=NULL;
	T->rchild=NULL;
	return T;
}

BSTptr CreateBST(BSTptr root,int x)
{		
	if(root==NULL)
	root=GetNewNode(x);
	else if(x<=root->data)
	root->lchild=CreateBST(root->lchild,x);
	else
	root->rchild=CreateBST(root->rchild,x);
	return root;
}

void PrintAncestors(BSTptr root,int x)
{
	if(root==NULL)
	return;	
	int a=1;
	while(a)
	{
		while(root && root->data!=x)
		{
			S.push(root);
			root=root->lchild;
		}
			
		if(root!=NULL && root->data==x)
		break;
		
		if(S.top()->rchild==NULL)
	{
			root=S.top();
			S.pop();
			
			while(!S.empty() && S.top()->rchild==root)
			{
				root=S.top();
				S.pop();
			}
		}
		if(S.empty())
		root=NULL;
		else root=S.top()->rchild;
	}
	while(!S.empty())
	{
		cout<<S.top()->data<<" ";
		S.pop();
	}
}

int main()
{
	int n,x; cout<<"Enter the number of elements:\n"; cin>>n;
	int num[n]; BSTptr root=NULL;
	cout<<"Enter the elements:\n";
	for(int i=0;i<n;i++)
	{ cin>>num[i]; root=CreateBST(root,num[i]);}
	int index;
	cout<<"Enter the key whose ancestor you want to print\n";
	cin>>index;
	PrintAncestors(root,index);
	return 0;
}



#include<iostream>
using namespace std;
struct bstnode
{   int data;
	struct bstnode *lc,*rc;
};
typedef struct bstnode *bstptr ;
 bstptr getnewnode(int data)
{   bstptr newnode=new bstnode();
	newnode->data=data;
	newnode->lc=newnode->rc=NULL;
	return newnode;
}
bstptr insert(bstptr root,int data)
{   if(root == NULL)  {  	root=getnewnode(data); }
  	else if(data<= root->data)  {  root->lc=insert(root->lc,data);  }
	else { 	root->rc=insert(root->rc,data);  }
	return root;
}
int min(bstptr temp)
{
	if(temp->lc)
	{
		return min(temp->lc) ;
	}
	return temp->data ;
}
int max(bstptr temp)
{
	if(temp->rc)
	{
		return max(temp->rc) ;
	}
	return temp->data ;
}


bool check_BST(bstptr t)
{
	if(t == NULL)
	{
		return true ;
	}
	if(t->lc)
	{
		if((max(t->lc)) >= t->data)
		return false ;
	}
	if(t->rc)
	{
		if((min(t->rc)) <= t->data)
		return false;
	}
	else if((t->lc || t->rc )&& (!(check_BST(t->lc)) || !(check_BST(t->rc)) ))
	{
		return false ;
	}
	 return true ;
}

int main()
{   bstptr root =NULL;
    cout<<"Enter how many nodes in tree "<<endl;
    int n;
    cin>>n;
    cout<<"Enter nodes data "<<endl;
    for(int i=0;i<n;i++)
    {
    	int x;
    	cin>>x;
    	root = insert(root , x) ;
	}
	bool x = check_BST(root) ;	
	if(x==true) cout<<" YES ";
	else cout<<" NO ";
    return 0;   
}
		


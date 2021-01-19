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
void printarr(int a[] ,int i)
{
	for(int k=0;k<i ;k++)
	{
		cout<<a[k]<<" ";
	}
	cout<<endl;
}
void print_all_branches(bstptr t , int i ,int a[])
{
	if(t->lc==NULL && t->rc == NULL)
	{
			a[i] = t->data;
			printarr(a,i+1) ;
	}
	else
	{
		a[i] = t->data ;
		i++;
		if(t->lc)
		print_all_branches(t->lc ,i ,a) ;
		if(t->rc)
		print_all_branches(t->rc ,i ,a) ;
	}
	
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
	int a[50] ;
	
	print_all_branches(root ,0 ,a) ;
}
		


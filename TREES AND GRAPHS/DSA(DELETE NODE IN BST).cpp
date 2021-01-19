#include<iostream>
#include<cstdlib>
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
void IN(bstptr t)
{ if(t)	{   IN(t->lc); cout<<t->data <<" "; IN(t->rc);}  }

bool DELETE_NODE(bstptr t , int key,bstptr par=NULL)
{
	if(t == NULL) return false;
	else if(t->data == key )
	{
		if(!(t->lc)  &&  !(t->rc))
		{
			return true;
		}
		else if(t->lc)
		{ 
			int x = max_lst(t->lc) ;
			bstptr temp = t->lc ;
			t->data = x ;
			DELETE_NODE(temp , x , temp) ;
		
		}
		else if(t->rc)
		{
			int y = min_rst(t->rc) ;
			bstptr temp = t->rc ;
			t->data = y ;
			DELETE_NODE(temp , y , temp) ;
		}
		
	}
	else if(t->data > key) 
	{
		if(DELETE_NODE(t->lc , key,t))
		t->lc = NULL;
		return false;
	}
	else if(t->data < key)
	{
		if(DELETE_NODE(t->rc , key,t))
		t->rc = NULL;
		return false;
	}
}


int main()
{   bstptr root =NULL;
	cout<<"Enter how many nodes , you want to enter "<<endl ;
	int n ;
	cin>> n ;
	cout<<"ENter node data "<<endl;
	for(int i=0 ; i<n ; i++)
	{
		int x ;
		cin>> x ;
		root=insert( root,x );
	}
	cout<<"Inorder traversal is : " ; 	IN(root);  cout<<endl;
 	int number;
	cout<<"Enter the node_data , which you want to delete : ";
    cin>>number;
     DELETE_NODE(root , number) ;
	cout<<"Inorder traversal is : " ; 	IN(root);  cout<<endl;
    return 0; 
	// 9   15 12 18 14 10 11 16 40  17  //
}
		


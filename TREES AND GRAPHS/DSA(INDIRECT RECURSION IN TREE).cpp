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

void PRE(bstptr t)
{
	if(t)
	{
		cout<<t->data <<" ";
		POST(t->lc) ;
		POST(t->rc) ;
	}
}
void POST(bstptr t)
{
	if(t)
	{
		PRE(t->lc) ;
		PRE(t->rc) ;
		cout<<t->data<<" ";
	}
}

int main()
{   bstptr root =NULL;
    root=insert(root,50); root=insert(root,15); root=insert(root,62);root=insert(root,5);
	root=insert(root,20); root=insert(root,58); root=insert(root,90); root=insert(root,3);
    PRE(root) ;
     return 0;   }
		


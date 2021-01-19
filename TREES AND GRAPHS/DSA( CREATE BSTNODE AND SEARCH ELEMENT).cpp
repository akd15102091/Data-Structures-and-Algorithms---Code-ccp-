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
void IN(bstptr t)
{ if(t)	{   IN(t->lc); cout<<t->data <<" "; IN(t->rc);}  }
void PRE(bstptr t)
{
	if(t){ cout<<t->data<<" " ;IN(t->lc);  IN(t->rc);} 
}
void POST(bstptr t)
{
	if(t)	{   IN(t->lc); IN(t->rc);  cout<<t->data <<" "  ;}
}

bool search(bstptr root,int data)
{  if(root==NULL) return false;
	else if(root->data== data) return true;
	else if(data<=root->data ) return search(root->lc,data) ;
	else return search(root->rc,data);  }
int main()
{   bstptr root =NULL;
    root=insert(root,50); root=insert(root,15); root=insert(root,62);root=insert(root,5);
	root=insert(root,20); root=insert(root,58); root=insert(root,90); root=insert(root,3);
	int number;
	cout<<"Enter the number : ";    cin>>number;
	if( search(root,number)==true) cout<<"Found"<<endl;
	else cout<<"Not found "<<endl;
	cout<<"Inorder traversal is : " ; 	IN(root);  cout<<endl;
	cout<<"Preorder traversal is : " ; 	PRE(root);  cout<<endl;
	cout<<"Postorder traversal is : " ; 	POST(root);  cout<<endl;
     return 0;   }
		


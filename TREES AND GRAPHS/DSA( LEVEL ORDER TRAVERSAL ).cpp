#include<bits/stdc++.h>
#include<queue>
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

void levelorder(bstptr root)
{
	if(root==NULL) return ;
	queue<bstptr>q;
	q.push(root);
	while(!q.empty())
	{
		bstptr temp=q.front();
		cout<<temp->data <<" ";
		if(temp->lc!=NULL) q.push(temp->lc);
		if(temp->rc!=NULL) q.push(temp->rc);
		q.pop();
	}
}

int main()
{   bstptr root =NULL;
    root=insert(root,50); root=insert(root,15); root=insert(root,62);root=insert(root,5);
	root=insert(root,20); root=insert(root,58); root=insert(root,90); root=insert(root,3);
	cout<<"Level order traversal is : "<<endl;
     levelorder( root) ;   
     return 0;   }
		


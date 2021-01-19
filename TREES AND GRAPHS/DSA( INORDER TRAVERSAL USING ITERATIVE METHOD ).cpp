#include<iostream>
#include<stack>
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
void inorderTraversal_iterative(bstptr t)
{
	stack<bstptr> s;
	bstptr temp = t ;
	while(temp!=NULL)
	{
		s.push(temp) ;
		temp = temp->lc ;
	}	
	while(!s.empty())
	{
		temp = s.top() ;
		s.pop() ;
		cout<<temp->data << " ";
		if(temp->rc)
		{
			temp=temp->rc ;
			while(temp!=NULL)
			{
				s.push(temp) ;
				temp= temp->lc ;
			}
		}
	}
} 
int main()
{  	stack<bstptr> s;
	 bstptr root =NULL;
	 int n;
 	cout<<"ENter the number of nodes "<<endl;
	cin>>n;
	cout<<"ENter the elements "<<endl;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		root = insert(root , x) ;		
	}  
	inorderTraversal_iterative(root) ;

   return 0;
}
	



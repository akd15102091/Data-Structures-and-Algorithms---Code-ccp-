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
	bstptr temp = root ;
	s.push(temp) ;

//	cout<<t->data <<" ";
	while(!s.empty())
	{  	bstptr t = s.top() ;
	    s.pop();
		while(t)
		{
			cout<<t->data <<" ";
			if(t->rc)
			{
				s.push(t->rc) ;
			}
			t = t->lc ;
		}
	}  
	
	return 0;
}
		



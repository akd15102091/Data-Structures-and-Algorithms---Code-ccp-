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
	int b[50] ;
	bstptr temp = root ;
	s.push(temp) ;
bstptr t = s.top() ;
//	cout<<t->data <<" ";
/*	while(!s.empty())
	{ 
		
		while(t->lc)
		{
			s.push(t->lc) ;
			t = t->lc ;
		}
		bstptr t2 = s.top() ;
		cout<<t2->data <<" ";
		s.pop() ;
		if(t2->rc) s.push(t2->rc) ;
		t = (s.top())->rc ;
		cout<<(s.top())->data << " ";
		s.pop();
	   
	}  */
	int j=0 ;
	while(!s.empty())
	{  	
		while(t)
		{
		
			if(t->lc)
			{
				s.push(t->lc) ;
			}
		//	cout<<t->data<<" ";
			b[j]=t->data ;
			j++ ;
			t = t->rc ;
		}
		 t = s.top() ;
	    s.pop();
	}
	for(int k=j-1 ;k>=0;k--)
	{
		cout<<b[k]<<" ";
	}
	
	return 0;
}
		



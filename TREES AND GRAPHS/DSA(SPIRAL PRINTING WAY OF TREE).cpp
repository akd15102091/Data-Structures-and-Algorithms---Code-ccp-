#include<iostream>
#include<queue>
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
int height_tree(bstptr t)
{
	if(t==NULL) return 0;
	if(!(t->lc) && !(t->rc) )
	{
		return 0;
	}
	int l = height_tree(t->lc) ;
	int r = height_tree(t->rc);
	return (1+((l>r)?l:r)) ;
}
  stack<int>s1,s2;
void krspiral(int d ,bstptr t  , int j)
{ 
	if(t == NULL )
	{   return ;
	}
	else
	{
		if(j==d && j%2) 
		{	
			cout<<t->data <<" ";
	    }
		else if(j==d && j%2==0)
		{
			s1.push(t->data) ;
		}
			
		
		krspiral(d, t->lc , j+1);
		krspiral(d, t->rc , j+1) ;
	}
	
	
}
int main()
{   bstptr root =NULL;
	int n ;
	cout<<"ENter how many number of nodes : "<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x ;
		root = insert(root ,x) ;
	}
    int H = height_tree(root) ;
    cout<<"Height of tree "<< H <<endl;
    for(int i=0 ;i< H+1 ;i++)
    {
    	while(!s1.empty())
			{
				cout<<s1.top()<<" ";
				s1.pop() ;
			}
			cout << endl;
    	krspiral(i,root,0) ;
    	cout<<endl;
	}
   // krspiral(root) ;
     return 0;   
}
		


#include<iostream>
using namespace std ;
struct btnode
{
	char data ;
	struct btnode *lc ;
	struct btnode *rc ;	
} ;
typedef struct btnode *btptr ;

btptr createNode(char x)
{
	if(x=='+') return NULL ;
	
	btptr temp = new struct btnode() ;
	temp->data = x;
	temp->lc = NULL ;
	temp->rc = NULL ;
	return temp;
}

btptr createTree(btptr t,char ch[],int &i,int n)
{
	if(i>=n) return t ;
	t = createNode(ch[i]) ;
	if(t==NULL) return NULL ;
	i++ ;
	t->lc =createTree(t->lc,ch,i,n) ;
	i++ ;
	t->rc =createTree(t->rc,ch,i,n) ;
}

void IN(btptr t)
{
	if(t)
	{
		IN(t->lc) ;
		cout<<t->data <<" ";
		IN(t->rc) ;
 	}
}

bool checkFullBinaryTree(btptr t)
{
	if(t==NULL) return true ;
	if(t->lc ==NULL && t->rc==NULL) return true ;
	else if(t->lc !=NULL && t->rc!=NULL)
	{
		return ((checkFullBinaryTree(t->lc)) && (checkFullBinaryTree(t->rc))) ;	
	}	
	else return false ;
}

int main()
{
	btptr root = NULL ;
	int n ;
	char ch[500] ;
	cout<<"Enter n : "<<endl ;
	cin>>n ;
	cout<<"Enter the elements : "<<endl ;
	for(int i=0;i<n;i++)
	{
		cin>>ch[i] ;
	}
	int i=0 ;
	root = createTree(root,ch,i,n) ;
	cout<<"IN ORDER is : "<<endl ;
	IN(root) ;
	cout<<endl ;
	bool x = checkFullBinaryTree(root) ;
	if(x==true) cout<<"Given tree is a full binary tree."<<endl;
	else cout<<"Given tree is not a full binary tree."<<endl;
}
/*
19
ABD++EH+I+++C+FG+++

23
ABD++EI++J++CG++FK++L++
*/

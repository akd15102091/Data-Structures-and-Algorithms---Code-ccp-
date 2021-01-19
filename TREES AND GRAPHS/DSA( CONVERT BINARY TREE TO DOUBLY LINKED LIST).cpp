#include<iostream>
#include<stack>
using namespace std;
struct btnode
{
	char data ;
	struct btnode *lc ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;
 btptr create_node(btptr t , char a[50] ,int i)
 {
 	if(a[i] != '+')
	{
    	btptr temp = NULL;
		temp = new struct btnode ;
		temp->data = a[i] ;
		temp->lc = NULL ;
		temp->rc = NULL ;
		return temp ;
	}
	else {	return NULL ;}
 }

btptr create_tree(btptr T , char a[50] ,int &i ,int n)
{
	if(i >= n)
	{
		return T ;
	}
	T = create_node(T , a ,i) ;
	if(T==NULL) return NULL;
	i++;
	T->lc = create_tree(T->lc , a ,i , n) ;
	i++;
	T->rc = create_tree(T->rc , a ,i ,n) ;
}
void fixprevptr(btptr root)
{
	static btptr  pre = NULL ;
	if(root)
	{
		fixprevptr(root->lc) ;
		root->lc = pre ;
		pre = root ;
		fixprevptr(root->rc) ;	
	}
}
btptr fixnextptr(btptr t)
{
	btptr prev = NULL ;
	while(t && t->rc)
	{
		t = t->rc ;
	}
	while(t && t->lc)
	{
		prev = t ;
		t = t->lc ;
		t->rc = prev ;
	}
	return t ;
}
void print_DLL( btptr t )
{
	while(t)
	{
		cout<<t->data<" ";
		t=t->rc ;
	}
} 
btptr BTtoDLL(btptr head)
{
	fixprevptr(head);
	return fixnextptr(head) ;
}
void IN(btptr t)
{
	if( t )
	{
		IN(t->lc) ;
		cout<<t->data <<" ";
		IN(t->rc) ;
	}
}

int main()
{	btptr root = NULL ;
	int n ;
	char a[50] ;
	cout<<"Enter the n "<<endl;
	cin>>n;
	cout<<"Enter the elements "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}
	 
	int j =0 ;
	root = create_tree( root ,a , j , n) ;
	cout<<"IN_ORDER IS : "<<endl;
	IN(root) ;
	cout<<endl ;
	root = BTtoDLL(root) ;
	print_DLL(root) ;
	//  13   A B C + + D + + E F + + + 
	return 0 ;
d}

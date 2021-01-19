#include<iostream>
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
void PRE(btptr t)
{
	if( t )
	{
		cout<<t->data <<" ";
		PRE(t->lc) ;
		PRE(t->rc) ;
	}
}
btptr swap_lc_rc( btptr t)
{
	if(t->lc==NULL && t->rc ==NULL) return t ;
	if(t->lc && t->rc)
	{
		int temp = t->lc->data ;
		t->lc->data = t->rc->data ;
		t->rc->data = temp ;
		swap_lc_rc(t->lc) ;
		swap_lc_rc(t->rc) ;
	}
	else
	{
		swap(t->lc ,t->rc) ;
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
	cout<<"PRE_ORDER IS : "<<endl;
	PRE(root) ;
	cout<<endl  ;
	swap_lc_rc( root ) ;
	PRE(root) ;
	
}

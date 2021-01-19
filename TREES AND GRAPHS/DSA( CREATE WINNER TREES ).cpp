#include<iostream>
#include<cstdlib>
using namespace std ;
struct winnode
{
	struct winnode *lc ;
	int data ;
	struct winnode *rc ;
} ;
typedef struct winnode *wptr ;
wptr create_WIN_TREE( wptr t , int a[] , int i , int k) 
{
	if(i>=k-1)
	{
		return t ;
	} 
	wptr temp = NULL ;
	temp = new struct winnode ;
	temp->data = a[i] ;
	temp->lc = temp->rc = NULL ;
	t = temp ;
	
	t->lc = create_WIN_TREE(t->lc , a , 2*i+1 , k) ;
	t->rc = create_WIN_TREE(t->rc , a , 2*i+2 , k) ;
}
/*void PRE(wptr t)
{
	if(t)
	{
		cout << t->data <<" ";
		PRE(t->lc) ;
		PRE(t->rc) ;
	}
}*/
int WINNER(wptr t )
{
	if(t == NULL ) return -1 ;
	//if(t == NULL) return max_score;
	if(!(t->lc)  &&  !(t->rc) )
	{
		return t->data  ;
	}
	int l =  WINNER(t->lc ) ;
	int r =  WINNER(t->rc ) ;  
	return ((l>r) ? l : r) ;
}
int main()
{
	wptr root = NULL ;
	cout<<"Enter value of n (no. of leaf nodes) "<<endl ;
	int n ;
	cin>> n ;
	int a[50] ;
	for(int i=0;i<n-1 ;i++)
	{
		a[i] = 0 ;
	}
	cout<<"ENter datas "<<endl ;
	for( int i=n-1 ; i<2*n-1 ; i++ )
	{
		cin>>a[i] ;
	}
	int k = 2*n ;
	root = create_WIN_TREE( root , a , 0 , k) ;
/*	cout<<"PRE_ORDER IS : "<<endl ;
	PRE(root) ; */
	// 8  3 8 1 5 7 4 9 2   //
	int max_score = 0 ;
int y = WINNER(root ) ;
	cout<<"MAximum score is : "<< y << endl;
	return 0 ;
}

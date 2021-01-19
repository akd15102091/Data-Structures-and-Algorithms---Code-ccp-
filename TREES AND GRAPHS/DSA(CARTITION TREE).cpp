#include<iostream>
using namespace std ;
struct btnode
{
	int data ;
	struct btnode *lc ;
	struct btnode *rc ;
} ;
typedef struct btnode *btptr ;
int max_index(int a[] , int i , int n)
{
	int max = i ; // here max is max-element - index //
	for(int j=i+1 ; j<=n ;j++ )
	{
		if(a[j] > a[max])
		{
			max = j ;
		}
	}
	return max ;
}
void create_tree(btptr &t , int a[] ,int i ,int n) 
{
	if(i>n) return ;
	int x = max_index(a , i , n) ;
	
	btptr temp = NULL ;
	temp = new struct btnode ;
	temp->data = a[x] ;
	temp->lc = temp->rc = NULL ;
	t = temp ;
	
	create_tree(t->lc , a ,i , x-1 ) ;
	create_tree(t->rc , a , x+1 , n) ;
}

void PRE(btptr t)
{
	if(t)
	{
		cout<<t->data <<" ";
		PRE(t->lc) ;
		PRE(t->rc) ;
	}
}
int main()
{
	btptr root = NULL ;
	int n ;
	cout<<"Enter the n" <<endl;
	cin>> n;
	int a[50] ;
	cout<<"ENter the array elements "<<endl ;
	for(int i=0 ; i<n ; i++)
	{
		cin>>a[i] ;		
	}		
	create_tree(root , a , 0 , n-1) ;
	cout<<"PRE_order is " ;
	PRE(root) ;
	return 0 ;
} 

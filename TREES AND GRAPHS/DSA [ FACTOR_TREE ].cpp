#include<iostream>
using namespace std ;
struct ftnode
{
	int data ;
	struct ftnode *lc , *rc ;
} ;
typedef struct ftnode *ftptr ;

ftptr newnode(int x)
{
	ftptr ft = new struct ftnode ;
	ft->data = x ;
	ft->lc = ft->rc = NULL ;
	return ft ;
}
ftptr create_fac_tree( ftptr &t , int n )
{
	t = newnode (n) ;
	for(int i=2 ; i<= n/2 ; i++)
	{
		if( n%i == 0)
		{
			t->lc = newnode( i ) ;
			t->rc = create_fac_tree( t->rc , n/i) ;
			break ;
		}
	}
	return t ;
}

void IN( ftptr t )
{
	if(t)
	{
		IN(t->lc) ;
		cout<< t->data <<" " ;
		IN(t->rc) ;
	}
}
int main()
{
	ftptr root = NULL ;
	int num ;
	cout<<"Enter the number "<< endl ;
	cin>> num ;
	root = create_fac_tree( root , num ) ;
	cout<<"INORDER IS "<< endl ;
	IN( root ) ;
	return 0 ;
}

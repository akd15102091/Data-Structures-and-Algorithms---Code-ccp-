#include<iostream>
#include<algorithm>
using namespace std ;
#define d 2 
struct bdnode
{
	int cnt ;
	int key[2*d] ;
	struct bdnode *ptr[2*d +1] ;
} ;
typedef struct bdnode *bdptr ;
bdptr create_node( int x )
{
	bdptr temp = new struct bdnode ;
	temp->key[0] = x ;
	temp->cnt = 1 ;
	for(int i=0 ;i<(2*d+1) ;i++ )
	{
		temp->ptr[i] = NULL ;
	}
	return temp ;
}
void IN_ORDER( bdptr t)
{
	if(t)
	{
		for(int i=0;i< t->cnt ;i++)
		{
			IN_ORDER(t->ptr[i]) ;
			cout<<t->key[i] <<" " ;
		}
		IN_ORDER(t->ptr[t->cnt]) ;
	}
}
bdptr OVERFLOW( bdptr t , int x) 
{
	int b[5] ;    // hare size should be equals to 2*d+1
	for(int i=0;i<4;i++)
	{
		b[i] = t->key[i] ;
	}
	b[4] = x ;
	sort(b , b+5) ;

	bdptr temp = create_node( b[d] ) ;
	for( int i=d ; i<2*d ;i++ )
	{
		t->key[i] = -1 ;
			
	}
	t->cnt = d ;
	bdptr r_newnode = create_node( b[d+1] ) ;
	for(int i=1;i<d ;i++)
	{
		r_newnode->key[r_newnode->cnt] = b[d+i] ;
		r_newnode->cnt ++ ;
	}
	temp->ptr[temp->cnt -1] = t ;
	temp->ptr[temp->cnt] = r_newnode ;
	IN_ORDER(temp) ;
	cout<<endl;
	return temp ;
}
void add_key( bdptr &t , int x )
{
	if( t== NULL )
	{
		t = create_node(x) ;
		return ; 
	}
	if( t->cnt < (2*d+1)-1 )
	{
		t->key[t->cnt] = x ;
		t->cnt ++ ;
		sort(t->key , t->key + t->cnt) ;
		return ;
	}
	else
	{
		t = OVERFLOW( t , x) ;
	}
	int i=0 ;
	while(i < t->cnt )
	{
		if( x < t->key[i] ) break ;
		i++ ;
	}
	add_key( t->ptr[i] , x) ;

}


int main()
{
	bdptr root = NULL ;
	cout<<"enter how many numbers , you want to enter "<<endl ;
	int n ;
	cin>> n ;
	cout<<"Enter the elements "<<endl ;
	for(int i=0 ;i<n ;i++)
	{
		int x ;
		cin>>x ;
		add_key( root , x )  ;	
	}
	cout<<"IN_ORDER IS : "<<endl ;
	IN_ORDER(root) ;
	return 0 ;	
}

#include<iostream>
using namespace std ;
struct kdnode
{
	struct kdnode *lc ;
	int data[50] ;
	struct kdnode *rc ;
} ;
typedef struct kdnode *kdptr ;
kdptr INSERT( kdptr t , int a[] , int d , int p)
{
	if(t == NULL)
	{
		kdptr temp = NULL ;
		temp = new struct kdnode ; 
		for(int i=0 ; i<d ; i++)
		{
			temp->data[i] = a[i] ;
		}
		temp->lc = temp->rc = NULL ;
		t = temp ;
	}
	else if( t->data[p%d]  > a[p%d] )
	{
		t->lc =  INSERT(t->lc , a , d , p+1) ;
	}
	else if ( t->data[p%d]  < a[p%d] )
	{
		t->rc = INSERT(t->rc , a , d , p+1) ;
	}
	
	return t ;
}

void PRE(kdptr t , int d)
{
	if(t)
	{
		for(int i=0; i<d ;i++)
		{
			cout<< t->data[i] <<" ";
		}
		cout<<endl;
		PRE(t->lc , d) ;
		PRE(t->rc , d) ;
	}
} 
bool check_arr(int p[] , int q[] , int d)
{
	for(int i=0;i<d;i++)
	{
		if(p[i] != q[i])
		{
			return false ;
		}
	}
	return true ;
}
bool KD_SEARCH( kdptr t , int d , int key[] , int i )
{
	if(t == NULL) return false ;
	if(t->data[i%d] == key[i%d])
	{
		bool x = check_arr(key , t->data , d) ;
		if(x == true) return true ;
	}
	if( t->data[i%d] > key[i%d] )
	{
		return ( KD_SEARCH( t->lc , d , key , i+1 ) ) ;
	}
	else if( t->data[i%d] < key[i%d] )
	{
		return ( KD_SEARCH( t->rc , d , key , i+1 ) ) ;
	}
	else return false ;
}
int main()
{
	kdptr root = NULL ;
	cout<<"ENter how many nodes you want to enter "<<endl;
	int n ;
	cin>> n ;
	cout<<"Enterc data size(means how many data in one node) "<<endl;
	int d ;
	cin>> d ;
	for(int i=0 ; i<n ;i++)
	{
		int a[50] ;
		cout<<"ENter d datas "<<endl ;
		for(int j=0 ; j<d ; j++)
		{
			cin>> a[j] ;
		}
		root = INSERT( root , a , d , 0)  ;
	}
	cout<<"PRE ORDER is : "<<endl ;
	PRE(root , d) ;  
	cout<<endl ;
	int c[50] ;
	cout<<"ENter the key_data which you want to search "<<endl;
	for(int j=0 ;j<d ;j++) 
	{
		cin>>c[j] ;
	}
	bool y = KD_SEARCH( root , d , c , 0 ) ;
	if( y == true ) cout<<"Searching data is in tree_datas "<<endl;
	else cout<<"Searching data is not in tree_datas" <<endl;
	return 0 ;
}


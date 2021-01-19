
#include<iostream>
#include<algorithm>
using namespace std ;
int m = 5 ;
struct mstnode
{
	int ccnt  ; 
	int key[4] ;
	struct mstnode *cptr[5] ;
} ;
typedef struct mstnode *mstptr ;

mstptr create_node( int x )
{
	mstptr temp = new struct mstnode ;
	temp->key[0] = x ;
	temp->ccnt = 1 ;
	for(int i=0 ;i<m ;i++)
	{
		temp->cptr[i] = NULL ;
	}
	return temp ;
}

void Create_MST_Tree(mstptr &t ,int x)
{
	if(t == NULL) 
	{
		t = create_node(x) ;
		return ;
	}
	if(t->ccnt < m-1)
	{
		t->key[t->ccnt] = x ;
		t->ccnt ++ ;
		sort(t->key ,t->key+t->ccnt) ;
		return ;
	}
	int i=0 ;
	while(i < t->ccnt)
	{
		if( x < t->key[i] ) break ;
		i++ ;
	}
	Create_MST_Tree( t->cptr[i] , x) ;
}

void IN_ORDER( mstptr t)
{
	if(t)
	{
		for(int i=0;i< t->ccnt ;i++)
		{
			IN_ORDER(t->cptr[i]) ;
			cout<<t->key[i] <<" " ;
		}
		IN_ORDER(t->cptr[t->ccnt]) ;
	}
}

bool search(mstptr t , int x)
{
	if(t==NULL) return false ;
	for(int i=0;i< t->ccnt;i++)
	{
		if(t->key[i] == x) return true ;
		else if(t->key[i] > x ) 
		{
			return search(t->cptr[i] ,x) ;
		}
	}
	return search(t->cptr[t->ccnt] , x) ;
//	return false ;
}
int main()
{
	mstptr root = NULL ;
	cout<<"ENter how many number , you want to enter ? "<<endl ;
	int n ;
	cin >>n ;
	cout<<"ENter how the numbers / elements  : "<<endl ;
	for(int i=0 ; i<n ; i++)
	{
		int x ;
		cin>>x ;
		Create_MST_Tree(root , x) ;
	}
	cout<<"INORDER IS : "<<endl ;
	IN_ORDER(root) ;
	cout<<"ENter element to search "<<endl ;
	int x ;
	cin>> x ;
	bool a = search(root , x ) ;
	if(a==true) cout<<"Element is there in tree data . "<<endl ;
	else cout<<"Element is not there in tree data . "<<endl ;
	return 0 ;
	
	//  12      8 15 9 18 3 7 4 19 6 2 5 10
}

#include<iostream>
#include<queue>
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

void LEVEL_ORDER( mstptr t )
{
	if( t == NULL ) return ;
	queue<mstptr> q ;
	q.push(t) ;
	while(!q.empty())
	{
		int count = q.size() ;
		while(count--)
		{
			mstptr temp = q.front() ;
			cout<<"{";
			for(int i=0 ;i<temp->ccnt ;i++)
			{
				cout<<temp->key[i] <<" " ;
			}
			cout<<"} "; 
			for(int i=0 ; i<= temp->ccnt ; i++)
			{
				if(temp->cptr[i])
				{
					q.push(temp->cptr[i]) ;
				}
			}
			q.pop() ;
		}
		cout<<endl ;
	}	
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
	cout<<endl;
	cout<<"INORDER IS : "<<endl ;
	IN_ORDER(root) ;
	cout<<endl <<endl;
	cout<<"LEVEL ORDER IS : "<<endl ;
	LEVEL_ORDER(root) ;
	return 0 ;
	
	//  12      8 15 9 18 3 7 4 19 6 2 5 10
}

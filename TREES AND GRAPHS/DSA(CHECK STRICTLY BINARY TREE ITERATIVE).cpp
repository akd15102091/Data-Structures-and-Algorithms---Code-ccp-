#include<iostream>
#include<queue>
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
/*void PRE(btptr t)
{
	if( t )
	{
		cout<<t->data <<" ";
		PRE(t->lc) ;
		PRE(t->rc) ;
	}
}*/

bool check_strictly_binary(btptr t)
{
	queue<btptr> q ;
	q.push(t) ;
	while(!q.empty())
	{
		btptr temp = q.front() ;
		q.pop() ;
		int count = 0;
		if(temp->lc ) 
		{
			q.push(temp->lc) ; count++ ;
		}
		if(temp->rc ) 
		{
			q.push(temp->rc) ; count++ ;
		}
		if(count == 1)
		{
			return false ;
		}
		
	}
	return true ;
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
//	cout<<"PRE_ORDER IS : "<<endl;
	//PRE(root) ;
	// 17  5 3 2 + + 4 + + 10 7 + + 12 + 15 + +
	//15  9 5 1 + + 8 + + 30 20 + + 40 + +
	bool x = check_strictly_binary(root) ;
	if( x == true ) cout<<" strictly binary tree _ yes" ;
	else  cout<<" strictly binary tree _ no" ;
	return 0;
}

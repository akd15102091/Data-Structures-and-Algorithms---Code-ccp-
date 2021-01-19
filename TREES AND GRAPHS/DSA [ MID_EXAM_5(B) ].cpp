#include<iostream>
#include<queue>
using namespace std ;
struct lnode
{
	int data ;
	struct lnode *next ;
} ;
typedef struct lnode *lptr ;

struct btnode
{
	int data ;
	struct btnode *lc ;
	struct btnode *rc ;
} ;
typedef struct btnode *btptr ;

lptr create_list(lptr t , int a[] , int i , int n)
{
	if( i>=n ) return t ;
	lptr temp = new struct lnode ;
	temp->data = a[i] ;
	temp->next =  NULL ;
	t = temp ;
	
	t->next = create_list( t->next , a , i+1 ,n) ;
}
btptr newBTnode(int x)
{
	btptr temp = new struct btnode ;
	temp->data = x ;
	temp->lc = temp->rc = NULL ;
	return temp ;
}
void create_complete_tree( btptr &root , lptr head )
{
	if(head == NULL) 
	{
		root = NULL ;
		return ;
	}
	root = newBTnode(head->data) ;
	queue<btptr> q ;
	q.push(root) ;
	head = head->next ;
	while(head)
	{
		btptr parent = q.front() ;
		q.pop() ;
		btptr leftchild = NULL ;
		btptr rightchild = NULL ;
		leftchild = newBTnode(head->data) ;
		q.push(leftchild) ;
		head = head->next ;
		
		if(head)
		{
			rightchild = newBTnode(head->data) ;
			q.push(rightchild) ;
			head = head->next ;
 		}
 		parent->lc = leftchild ;
 		parent->rc = rightchild ;
	}
}
void print_list(lptr L)
{
	while(L)
	{
		cout<<L->data <<" ";
		L=L->next ;
	}
}
void IN(btptr t)
{
	if(t)
	{
		IN(t->lc) ;
		cout<< t->data <<" ";
		IN(t->rc) ;
	}
}
int main()
{
	btptr root = NULL ;
	lptr L = NULL ;
	cout<<"ENter the number of nodes in linked list "<< endl ;
	int n ;
	cin>> n ;
	cout<<"ENter the elements "<<endl;
	int a[50] ;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}
	L = create_list( L , a ,0 ,n ) ;
	cout<<"LIST IS : "<<endl ;
	print_list(L) ;
	cout<<endl ;
	create_complete_tree( root , L ) ;
	cout<<"INORDER IS : "<<endl ;
	IN(root) ;
	return 0 ;
	
}

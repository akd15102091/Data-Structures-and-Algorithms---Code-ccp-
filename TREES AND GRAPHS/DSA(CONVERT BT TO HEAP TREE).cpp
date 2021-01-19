#include<iostream>
using namespace std;
struct btnode
{
	int data ;
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
		temp->data = a[i] - '0' ;
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
int IN(btptr t , int H[])
{
	static int i =0 ;
	if( t )
	{
		IN(t->lc , H) ;
		H[i] = t->data ; 
		i++  ;
		IN(t->rc , H) ;
	}
	else
	{
		return i ;
	}
	
}
void construct_heap_tree(btptr &head , int H[] , int i ,int x)
{
	if(i >= x)
	{
		return ;
	}
	btptr temp = NULL ;
	temp = new struct btnode ;
	temp->data = H[i] ; 
	temp->lc = temp->rc = NULL  ;
	head = temp ;
	
	construct_heap_tree(head->lc , H , 2*i+1 , x) ;
	construct_heap_tree(head->rc , H , 2*i+2 , x) ;
}
void PRE(btptr head)
{
	if(head)
	{
		cout<<head->data <<" ";
		PRE(head->lc) ;
		PRE(head->rc) ;
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
	int H[50] ;
	int x = IN(root , H) ;
	btptr head = NULL ;
    construct_heap_tree(head , H , 0 , x)  ;
	cout<<endl ;
	cout<<"PRE order of heap_tree"<<endl ;
	PRE(head) ;
	return 0 ;
	
	// 15   6 4 3 + + 5 + + 8 7 + + 9 + + 
}

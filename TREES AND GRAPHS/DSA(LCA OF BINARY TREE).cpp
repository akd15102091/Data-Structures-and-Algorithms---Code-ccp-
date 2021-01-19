#include<iostream>
#include<stack>
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
		temp->data = a[i] -'0' ;
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

int LCA(btptr t , int k1 ,int k2)
{
	if(t == NULL) return 0 ;
	if(t->data == k1 || t->data == k2 ) return 1 ;
	else if((LCA( t->lc , k1 , k2)) && (LCA(t->rc , k1 , k2))) return t->data ;
	else if((LCA( t->lc,k1,k2)) || (LCA(t->rc ,k1,k2))) return((LCA( t->lc,k1,k2)) + (LCA(t->rc ,k1,k2))) ;
	
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
	int k1 , k2 ;
	cout<<"ENter k1 and k2 "<<endl;
	cin>> k1 >> k2 ;

	int x = LCA(root , k1 ,k2) ;
	cout<<" LCA is : "<< x <<endl; ;
	
	return 0 ;
	
}

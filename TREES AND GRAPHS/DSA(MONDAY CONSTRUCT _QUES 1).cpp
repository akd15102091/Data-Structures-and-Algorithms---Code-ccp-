#include<iostream>
using namespace std;
struct btnode
{
	int data ;
	struct btnode *lc ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;
void create_tree( btptr &t ,int a[] ,int i ,int n)
{
	if(i >= n) return  ;
	if(i == 0 )
	{
		btptr temp = NULL ;
		temp = new struct btnode ;
		temp->data = a[i] ;
		temp->lc = temp->rc = NULL ;
		t = temp ; 	
	}	
	else
	{
		btptr temp = NULL ;
		temp = new struct btnode ;
		temp->data = a[i] ;
		temp->lc = temp->rc = NULL ;
		t = temp ;
	}
	create_tree(t->lc , a ,(2*i + 1) ,n) ;
	create_tree(t->rc , a ,(2*i + 2) ,n) ;
} 
void PRE(btptr t)
{
	if(t)
	{
		cout<< t->data <<" ";
		PRE(t->lc) ;
		PRE(t->rc) ;
	}
}
int main()
{	btptr root = NULL ;
	int n ;
	int a[50] ;
	cout<<"Enter the n "<<endl;
	cin>>n;
	cout<<"Enter the elements "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}
	 // 10   2 5 8 15 25 70 10 20 30 40 
	// int j =0 ;
	 create_tree( root ,a , 0 , n) ;

	 PRE(root) ;
	
	
}

#include<iostream>
#include<cstdlib>
using namespace std;
struct btnode
{
	int data ;
	struct btnode *lc ;
	struct btnode *rc ;
};
int sum =0 ;
typedef struct btnode *btptr ;
 btptr create_node(btptr t , char a[50] ,int i)
 {
 	if(a[i] != '+')
	{
    	btptr temp = NULL;
		temp = new struct btnode ;
		temp->data = (a[i] -'0' ) ;
	//	sum = sum + temp->data ;
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
void PRE(btptr t)
{
	if( t )
	{
		cout<<t->data <<" ";
		PRE(t->lc) ;
		PRE(t->rc) ;
	}
}
int bigger_value_path(btptr t)
{
	if(t==NULL)		return 0;
	if(t->lc == NULL && t->rc == NULL)					return t->data ;
	int x = bigger_value_path(t->lc) ;
	int y = bigger_value_path(t->rc) ;
	x>y ? t->rc = NULL : t->lc=NULL ;
	return	t->data+max(x,y) ;
	
}

int main()
{	btptr root = NULL ;
	int n ;
	char a[50] ;
	cout<<"Enter the n \t";
	cin>>n;
	cout<<"Enter the elements "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}
	 
	 int j =0 ;
	 root = create_tree( root ,a , j , n) ;
	cout<<"PRE ORDER IS : \t";
	PRE(root) ;
	cout<<endl;
//	cout<<sum ;

int x =  bigger_value_path(root ) ;
 	PRE(root) ;
	cout<<endl<<"Max sum is :" <<x;
	j =0 ;
	root = create_tree( root ,a , j , n) ;
}

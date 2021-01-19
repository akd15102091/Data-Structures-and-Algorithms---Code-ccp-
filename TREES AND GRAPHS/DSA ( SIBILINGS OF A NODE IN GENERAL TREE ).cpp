#include<iostream>
#include<queue>
using namespace std;
struct Gtree
{
	char data ;
	struct Gtree *fc ;
	struct Gtree *ns ;
};
typedef struct Gtree *gptr ;
 gptr create_node(gptr t , char a[50] ,int i)
 {
 	if(a[i] != '+')
	{
    	gptr temp = NULL;
		temp = new struct Gtree ;
		temp->data = a[i] ;
		temp->fc = NULL ;
		temp->ns = NULL ;
		return temp ;
	}
	else {	return NULL ;}
 }

gptr create_tree(gptr T , char a[50] ,int &i ,int n)
{
	if(i >= n)
	{
		return T ;
	}
	T = create_node(T , a ,i) ;
	if(T==NULL) return NULL;
	i++;
	T->fc = create_tree(T->fc , a ,i , n) ;
	i++;
	T->ns = create_tree(T->ns , a ,i ,n) ;
}
void PRE(gptr t)
{
	if( t )
	{
		cout<<t->data <<" ";
		PRE(t->fc) ;
		PRE(t->ns) ;
	}
}
void print_patternwise(gptr t , int x)
{
	if(t == NULL) return ;
	for(int i=0;i<x ;i++)
	{
		cout<<" ";
	}
	cout<<t->data <<endl ;
	print_patternwise(t->fc ,x+1) ;
	print_patternwise(t->ns ,x) ;
}


void print_sibilings(gptr t1 ,gptr t2 ,int k) 
{
	if(t1 == NULL || t2 == NULL) return ;
	if(t2->data == k)
	{
		while(t1)
		{
			cout<<t1->data <<" ";
			t1 = t1->ns ;
		}
		return  ;
	}
	print_sibilings(t1 , t2->ns , k) ;
	print_sibilings(t1->fc ,t1->fc , k) ;
}
int main()
{	gptr root = NULL ;
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
	cout<<"PRE_ORDER IS : "<<endl;
	PRE(root) ; 
	cout<<endl ;
	int x =0;
	print_patternwise(root , x) ;
	cout<<"ENter key to find it's sibilings "<<endl; 
	char key ;
	cin>>key ;
	print_sibilings(root ,root , key) ;
	return 0 ;
	
}
//   29  A M B + D Q + R + + E + + J L + + P S U + V + G + T + + +

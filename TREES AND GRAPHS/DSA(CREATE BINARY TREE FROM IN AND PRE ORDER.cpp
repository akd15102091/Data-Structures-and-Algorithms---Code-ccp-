#include<iostream>
using namespace std;
struct btnode
{
	char data ;
	struct btnode *lc ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;
 int index(char pre[] ,char in[] ,int i ,int m)
 {	   int  x = i-1;
	while(pre[x] != in[i] and i<m)
	{
		i++ ;
	}
	return i ;

 }
void create_tree(btptr &t ,char pre[] , char in[] , int i , int n )
{
	if(i >= n)
	{
		return  ;
    }
   	btptr T = NULL ;
	T = new struct btnode ;
	T->data = pre[i] ;
	T->lc = NULL ;
	T->rc = NULL ;
	t = T ;
	int x = index(pre,in , i+1 ,n) ;
    //cout<<"GO";
    //cout<<"GO";
    create_tree( t->lc , pre ,in , i+1 , x ) ; 		
    create_tree( t->rc , pre ,in , x , n ) ;	
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
int main()
{	btptr root = NULL ;
	int n ;
	char pre[50] , in[50] ;
	cout<<"Enter the n "<<endl;
	cin>>n;
	cout<<"Enter the preorder "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>pre[i] ;
	}
	cout<<"Enter the inorder "<<endl;
	for( int i=0;i<n;i++)
	{
		cin>>in[i] ;
	}
	 create_tree(root , pre ,in , 0 , n ) ;
	
	cout<<"PRE_ORDER IS : "<<endl;
	PRE(root) ;
	 
	
}

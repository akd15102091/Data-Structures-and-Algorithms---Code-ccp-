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
 {	
	for(int j=0;j<m;j++)
	{
		if(pre[i] == in[j])
		return j;
	}
 }
void create_tree(btptr &t ,char pre[] , char in[] , int i , int n ,int m ,int &j)
{
	if(i > n)
	{
		return  ;
    }
   	btptr T = NULL ;
	T = new struct btnode ;
	T->data = pre[j] ;
	T->lc = NULL ;
	T->rc = NULL ;
	t = T ;
	int x = index(pre,in , j ,m) ;
    //cout<<"GO";
  //  cout<<"GO";
  j++ ;
    create_tree( t->lc , pre ,in , i , x-1 ,m,j) ; 
//	cout<<"go1" ;		
//j++ ;
    create_tree( t->rc , pre ,in , x+1 , n ,m,j) ;	
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
void IN(btptr t)
{
	if( t )
	{
		IN(t->lc) ;
		cout<<t->data <<" ";
		IN(t->rc) ;
		
	}
}
void POST(btptr t)
{
	if( t )
	{
		POST(t->lc) ;
		POST(t->rc) ;
		cout<<t->data <<" ";
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
	int j=0;
	 create_tree(root , pre ,in , 0 , n-1 ,n-1 , j) ;
	
	cout<<"POST_ORDER IS : "<<endl;
	POST(root) ;
	cout<<endl;
	cout<<"IN_ORDER IS : "<<endl;
	IN(root) ;
	cout<<endl;
	cout<<"PRE_ORDER IS : "<<endl;
	PRE(root) ;
	return 0;
	 
	
}

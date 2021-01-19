#include<iostream>
using namespace std;
struct btnode
{
	char data ;
	int x ;
	int y ;
	struct btnode *lc ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;
int min_i = 0 ;
int max_i =0 ;
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
void level_Y(btptr t , int l)
{
	if(t== NULL)
	{
		return ;
	}
	t->y = l ;
	min_i = l ;
	cout<<min_i<<" ";
	level_Y(t->lc , l+1) ;
	level_Y(t->rc , l+1) ;
}
void depth_X(btptr t )
{
	static int d =0 ;
	if(t== NULL)
	{
		return ;
	}
	depth_X(t->lc ) ;
	max_i = d ;
	cout<<max_i<<" ";
	t->x = d++ ;
	depth_X(t->rc ) ;
}

void MATRIX_FORM( char ch[50][50] , btptr t)
{
	if(t==NULL) return ;
	ch[t->x][t->y] = t->data ;
	MATRIX_FORM(ch , t->lc) ;
	MATRIX_FORM(ch , t->rc) ;	
}
void TREE_STRUCTURE( char ch[50][50] )
{
	for(int j=0;j<=10;j++)
	
	{
		for(int i=0 ; i<= 10 ;i++)
		{
			if( ch[i][j] == ' ')
			{
				cout<<"  ";
			}
			else
			{
				cout<<ch[i][j] <<" ";
			}
		}
		cout<<endl ;
	}
	return ;
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
	level_Y(root ,0)  ;
	cout<<endl ;
	depth_X(root ) ;
	char ch[50][50] ;
	for(int i=0;i<=10;i++)
	{
		//cout<<"GO";
		for(int j=0;j<=10;j++)
		{
			ch[i][j] = ' ' ;
		}
	}
	 
	MATRIX_FORM(ch , root) ;
	cout<<"TREE STRUCTURE IS : "<<endl ;
	TREE_STRUCTURE( ch ) ;
	return 0;
}

// S M K + + L A + + B + + J + E G + D + + +   //


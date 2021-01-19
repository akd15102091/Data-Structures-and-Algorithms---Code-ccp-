#include<iostream>
using namespace std ;
struct Gtree
{
	int x ;
	int y ;
	char data ;
	int ccnt ;
	struct Gtree *cptr[50] ;
} ;
typedef struct Gtree *gptr ;

gptr newnode(char  z)
{
	gptr temp = new struct Gtree ;
	temp->data = z ;
	temp->ccnt = 0 ;
	return temp ;
}
gptr Create_General_Tree( gptr t , char c[100] , int &i , int n )
{
	if(i>=n) return NULL ;
	if(c[i++] == ')') return NULL ;
	t = newnode(c[i-1]) ;
	while( 1 )
	{
	//	cout<<"GO";
		t->cptr[(t->ccnt)] = Create_General_Tree(t->cptr[(t->ccnt)] , c , i ,n) ;
		if(t->cptr[t->ccnt]  == NULL) break ;
		t->ccnt = t->ccnt +1 ; 
	}
	return t ;
}
void print_Gtree(gptr t)
{
	if(t)
	{
		cout<<t->data <<" ";
		for(int i=0;i<(t->ccnt);i++)
		{
			print_Gtree( t->cptr[i] ) ;
		}
	}
}

void print_Gtree_INORDER(gptr t)
{
	if(t)
	{
		print_Gtree_INORDER( t->cptr[0] ) ;
		cout<<t->data <<" " ;
		for(int i=1 ; i<t->ccnt  ; i++)
		{
			print_Gtree_INORDER( t->cptr[i] ) ;
		}
	}
}
void Y_CORDINATE( gptr t , int l )
{
	if(t == NULL) return ;
	t->y = l ;
	for(int i=0 ; i<= t->ccnt ; i++)
	{
		Y_CORDINATE(t->cptr[i] , l+1) ;
	}
}
int X_CORDINATE( gptr t )
{
	static int d = 0 ;
	if(t)
	{
		X_CORDINATE( t->cptr[0] ) ;
		t->x = d++ ;
		for(int i=1 ; i<t->ccnt  ; i++)
		{
			X_CORDINATE( t->cptr[i] ) ;
		}
	}
}
void MATRIX_FORM( char ch[50][50] , gptr t)
{
	if(t==NULL) return ;
	
	ch[t->x][t->y] = t->data ;
	for(int i=0;i<(t->ccnt);i++)
	{
		MATRIX_FORM( ch , t->cptr[i] ) ;
	}
}
void TREE_STRUCTURE( char ch[50][50] )
{
	for(int j=0;j<=5;j++)
	
	{
		for(int i=0 ; i<=15 ;i++)
		{
			if( ch[i][j] == '@')
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
{
	gptr root = NULL ;
	char c[100] ;
	int n ;
	cout<<"Enter the number of elements : "<<endl ;
	cin>>n ;
	cout<<"ENter the elements : "<<endl ;
	for(int i=0 ; i<n ; i++)
	{
		cin >> c[i] ;	
	}
	int j=0 ;
	root = Create_General_Tree(root , c , j , n) ;
	cout<<endl ;
	cout<<"Print tree PRE_ORDER_WISE : "<<endl ;
	print_Gtree( root ) ;
	cout<<endl<<endl  ;
	cout<<"Print tree IN_ORDER_WISE : "<<endl ;
	print_Gtree_INORDER(root) ;
	cout<<endl ;
	Y_CORDINATE( root , 0 ) ;
	X_CORDINATE( root ) ;
	cout<<endl;	
	char ch[50][50] ;
	for(int i=0;i<=15;i++)
	{
		//cout<<"GO";
		for(int j=0;j<=5;j++)              // 5 , max_level is less than 5 for shown input below
		{								   // 15 , max width is less then or equals to 15  for shown input below
			ch[i][j] = '@' ;
		}
	}
	 
	MATRIX_FORM(ch , root) ;
	cout<<"TREE STRUCTURE IS : "<<endl ;
	TREE_STRUCTURE( ch ) ;
} 
// 29  A M B ) D Q ) R ) ) E ) ) J L ) ) P S U ) V ) G ) T ) ) )

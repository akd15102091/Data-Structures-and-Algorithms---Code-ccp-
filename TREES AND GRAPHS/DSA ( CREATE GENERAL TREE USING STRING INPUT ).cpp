#include<iostream>
using namespace std ;
struct Gtree
{
	char data ;
	int index ;
	struct Gtree *cptr[50] ;
} ;
typedef struct Gtree *gptr ;

gptr newnode(char  c)
{
	gptr temp = new struct Gtree ;
	temp->data = c ;
	temp->index = 0 ;
	return temp ;
}
gptr Create_General_Tree( gptr t , char ch[100] , int &i , int n )
{
	if(i>=n) return NULL ;
	if(ch[i++] == ')') return NULL ;
	t = newnode(ch[i-1]) ;
	while( 1 )
	{
	//	cout<<"GO";
		t->cptr[(t->index)] = Create_General_Tree(t->cptr[(t->index)] , ch , i ,n) ;
		if(t->cptr[t->index]  == NULL) break ;
		t->index = t->index +1 ; 
	}
	return t ;
}
void print_Gtree(gptr t)
{
	if(t)
	{
		cout<<t->data <<" ";
		for(int i=0;i<(t->index);i++)
		{
			print_Gtree( t->cptr[i] ) ;
		}
	}
}
int main()
{
	gptr root = NULL ;
	char ch[100] ;
	int n ;
	cout<<"Enter the number of elements : "<<endl ;
	cin>>n ;
	cout<<"ENter the elements : "<<endl ;
	for(int i=0 ; i<n ; i++)
	{
		cin >> ch[i] ;	
	}
	int j=0 ;
	root = Create_General_Tree(root , ch , j , n) ;
	print_Gtree( root ) ;	
} 
// 29  A M B ) D Q ) R ) ) E ) ) J L ) ) P S U ) V ) G ) T ) ) )
// 34  A B H N ) O ) ) I ) J ) ) C ) D ) E K P ) ) L Q ) ) ) F ) G M ) ) )  

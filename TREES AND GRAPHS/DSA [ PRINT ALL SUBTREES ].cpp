#include<iostream>
#include<queue>
using namespace std ;
struct Gtree
{
	char data ;
	int ccnt ;
	struct Gtree *cptr[50] ;
} ;
typedef struct Gtree *gptr ;

gptr newnode(char  c)
{
	gptr temp = new struct Gtree ;
	temp->data = c ;
	temp->ccnt = 0 ;
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
		t->cptr[(t->ccnt)] = Create_General_Tree(t->cptr[(t->ccnt)] , ch , i ,n) ;
		if(t->cptr[t->ccnt]  == NULL) break ;
		t->ccnt = t->ccnt +1 ; 
	}
	return t ;
}
void print_subtrees( gptr t)
{
	if( t == NULL ) return ;
	queue<gptr> q ;
	q.push(t) ;
	while(!q.empty())
	{
		int count = q.size() ;
		while(count--)
		{
			gptr temp = q.front() ;
				cout<<temp->data <<" " ;
			 
			for(int i=0 ; i<= temp->ccnt ; i++)
			{
				if(temp->cptr[i])
				{
					q.push(temp->cptr[i]) ;
				}
			}
			q.pop() ;
		}
		cout<<endl ;
	}
}
void print_Gtree(gptr t)
{
	if(t)
	{
		
		for(int i=0;i<(t->ccnt);i++)
		{
			print_Gtree( t->cptr[i] ) ;
		}
		cout<<"root is "<<t->data <<endl ;
		cout<<"subtrees are : "<<endl;
		print_subtrees(t) ;
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
// 	25 A B E ) F ) ) C G K ) L M ) ) ) H ) I ) ) D J ) )

#include<iostream>
#include<queue>
using namespace std ;
struct Gtree
{
	int flag ; 
	char data ;
	int cnt ;
	struct Gtree *cptr[50] ;
} ;
typedef struct Gtree *gptr ;

gptr newnode(char  c)
{
	gptr temp = new struct Gtree ;
	temp->data = c ;
	temp->cnt = 0 ;
	temp->flag = 0 ;
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
		t->cptr[(t->cnt)] = Create_General_Tree(t->cptr[(t->cnt)] , ch , i ,n) ;
		if(t->cptr[t->cnt]  == NULL) break ;
		t->cnt = t->cnt +1 ; 
	}
	return t ;
}

static int leaf_count = 0 ;

void print_Gtree(gptr t)
{
	
	if(t)
	{
		cout<<t->data <<" ";
		if(t->cnt == 0 ) 
		{
			leaf_count ++ ;
		}
		for(int i=0;i<(t->cnt);i++)
		{
			print_Gtree( t->cptr[i] ) ;
		}
	}
}

int check_rep(gptr g , gptr arr[] , int y )
{
	for(int i=0 ;i<y;i++)
	{
		if(g == arr[i]) return 1 ;
 	}
 	return 0 ;
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
	queue<gptr> q ;
	
	gptr arr[50] ; 
	arr[0] = root ;           // arr ,  is parent holding array
	int c = 0 , no_iter = 0 , n = 1 ;
	 
	while( c < leaf_count )
	{
		no_iter ++ ;
		for(int j=0 ;j<n ; j++)
		{
			gptr temp = find_max_count( arr[j] ) ;
			if( temp != NULL )
			{
				temp->flag = 1 ;
				if(temp->cnt == 0)
				{
					c++ ;
				}
				else
				{
					q.push(temp) ;
				}
				cout<< no_iter <<" -iteration -> "<<arr[j]->data <<endl ;
			}
		}
		while(!q.empty())
		{
			arr[n]  = q.front() ;
			q.pop() ;
			n++ ;
 		}
	}
	
	
	
	
} 
//  34  A B H N ) O ) ) I ) J ) ) C ) D ) E K P ) ) L Q ) ) ) F ) G M ) ) )   

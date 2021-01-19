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

void count_all_children( gptr z , int &sum)
{
	//if(z==NULL) return 0 ;
		
	if(z)
	{
		sum ++ ;
		for(int i=0;i< z->cnt -1 ;i++)
		{ 
			count_all_children(z->cptr[i] ,sum) ;
			//sum = sum + z->cnt ;
		}
		count_all_children(z->cptr[z->cnt -1] ,sum) ;
	}
	//return sum ;
	
}

gptr find_max_count(gptr t)
{
	int max = -1 ;
	gptr t1 = NULL ;
	for(int i=0 ;i< t->cnt ;i++ )
	{
		int sum = 0 ;
		 count_all_children(t->cptr[i] ,sum ) ;
		if( max < sum  && t->cptr[i]->flag == 0)
		{
			max = sum ;
			t1 = t->cptr[i] ;
		}
	}
	return t1 ;
}

int main()
{
	gptr root = NULL ;
	char ch[100] ;
	int n1 ;
	cout<<"Enter the number of elements : "<<endl ;
	cin>>n1 ;
	cout<<"ENter the elements : "<<endl ;
	for(int i=0 ; i<n1 ; i++)
	{
		cin >> ch[i] ;	
	}
	int j=0 ;
	root = Create_General_Tree(root , ch , j , n1) ;
	print_Gtree( root ) ;
	cout<<endl ;	
	queue<gptr> q ;
	
	gptr arr[50] ; 
	arr[0] = root ;           // arr ,  is parent holding array
	int c = 0 , no_iter = 0 ,  n = 1 ;
	 
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
				cout<< no_iter <<" -iteration -> "<<arr[j]->data  <<"  to  "<<temp->data <<endl ;
			}
		}
		cout<<endl ;
		while(!q.empty())
		{
			arr[n]  = q.front() ;
			q.pop() ;
			n++ ;
 		}
	}
	//cout<<count_all_children(root , 0) <<" : "<<count_all_children(root->cptr[0] ,0) ;
	cout<<"Total no. of iterations "<< no_iter <<endl ;
	return 0 ;
} 
//  34  A B H N ) O ) ) I ) J ) ) C ) D ) E K P ) ) L Q ) ) ) F ) G M ) ) )    , for this answer = 6 iterations

//  26  A B ) C E F G H I J ) ) ) ) ) ) ) D K ) L ) M ) ) )                 , for this answer = 7 iterations

// 46  A B E ) F ) G ) ) C H I J K L M ) ) ) ) ) ) ) D N ) O P ) Q ) R ) S ) T ) U ) V ) W ) ) ) )  , for this answer = 10 iterations

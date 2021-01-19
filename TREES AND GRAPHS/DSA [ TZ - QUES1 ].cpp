#include<iostream>
#include<stack>
using namespace std ;

int G[50][50] ;
int v , e  ;
int heap_var = 0 ;
struct heap
{
	int va ;
	int vb ;
	int weight ;
} ;
struct heap H[50] ;

void bubble_sort(struct heap H[])
{
	for(int i=0;i<e-1;i++)
	{
		for(int j=0;j<e-i-1;j++)
		{
			if(H[j].weight > H[j+1].weight)
			{
				struct heap temp ;
				temp=H[j] ;
				H[j]=H[j+1] ;
				H[j+1]=temp ;
			}
		}
	}
}

bool check(int span[50][50],int a,int b,int w,int visited[],int &cnt)
{
	visited[a]=1 ;
	if( a==b )
	{   cnt++ ;
		cout<<"LO";
		return true ;
	}
	for(int i=1;i<=v;i++)
	{
	 if(visited[i]==0 && span[a][i]>0)
		{
			check(span,i,b,w,visited,cnt) ;
		}
	}
	if(cnt==0)
	{
		return false ;
	}
	
}

void spanning_tree(int span[50][50] )
{
	while(heap_var != e)
	{
		 int a = H[heap_var].va ;
		int b = H[heap_var].vb ;
		int w = H[heap_var].weight ;
		int visited[50] ;
		int cnt=0 ;
		for(int i=1 ;i<=v;i++)
		{
			visited[i]  = 0 ;
		}
		bool x = check(span,a,b,w,visited,cnt) ;
		if(x==true)
		{
		//	cout<<"go" ;
			heap_var++ ;
		}
		else
		{
		//	cout<<heap_var<<" ";
			span[H[heap_var].va][H[heap_var].vb] = H[heap_var].weight ;
			span[H[heap_var].vb][H[heap_var].va] = H[heap_var].weight ;
			heap_var++ ;
		}
	
	}
}

int main()
{
	cout<<"Enter v and e "<<endl ;
	cin>>v>>e ;
	int span[50][50] ;
	for(int i=1;i<=v ;i++)
	{
		for(int j=1;j<=v ;j++)
		{
			G[i][j] = 0 ;
			span[i][j] = 0 ;
		}
	}
	int n=e ; // heap size = number of edges
	for(int k=1;k<=e;k++)
	{
		cout<<"Enter i and j and w "<<endl ;
		int i,j,w ;
		cin>>i>>j >>w;
		
		G[i][j] = w ;
		G[j][i] = w ;   
		H[k-1].va=i;
		H[k-1].vb=j ;
		H[k-1].weight=w ;
	}
	cout<<"After sorting struct array is : "<<endl ;
	bubble_sort(H) ;
	for(int i=0;i<e;i++)
	{
		cout<<H[i].va<<" "<<H[i].vb<<" "<<H[i].weight<<endl ;
	}
	cout<<"Adjacency matrix is : "<<endl ;
	for(int i=1;i<=v ;i++)
	{
		for(int j=1;j<=v ;j++)
		{
			cout<< G[i][j] << " "  ;
		}
		cout<<endl ;
	}
	
	spanning_tree(span) ; 
	cout<<"Spanning Adjacency matrix is : "<<endl ;
	for(int i=1;i<=v ;i++)
	{
		for(int j=1;j<=v ;j++)
		{
			cout<< span[i][j] << " "  ;
		}
		cout<<endl ;
	}
	int sum=1 ;
	for(int i=1 ;i<=v;i++)
	{
		for(int j=i;j<=v;j++)
		{
			if(span[i][j]>0)
			{
				sum=sum*span[i][j] ;
			}
		}
	}
	cout<<"Minimum spanning tree weight is : "<<sum <<endl ;
	return 0 ;

} 
/*
5 7
1 5 2 
1 2 3
5 3 6
1 3 8
1 4 5
3 4 9
2 4 7
*/


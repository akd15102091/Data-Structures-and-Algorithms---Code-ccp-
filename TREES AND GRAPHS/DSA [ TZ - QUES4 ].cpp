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
			if(H[j].weight < H[j+1].weight)
			{
				struct heap temp ;
				temp=H[j] ;
				H[j]=H[j+1] ;
				H[j+1]=temp ;
			}
		}
	}
}

void check(int span[50][50],int i,int visited[],int &cnt)
{
	visited[i]=1 ;
//	cout<<i<<" ";
	cnt++ ;
	for(int x=1;x<=v;x++)
	{
	 if(visited[x]==0 && span[i][x]>0)
		{
			check(span,x,visited,cnt) ;
		}
	}
	
}

void spanning_tree(int span[50][50] ,int z )
{
	while(heap_var != e)
	{
		if(heap_var!=z)
		{
			int a = H[heap_var].va ;
			int b = H[heap_var].vb ;
			int w = H[heap_var].weight ;
			span[a][b]=0 ;
			span[b][a]=0 ;
			int visited[50] ;
			int cnt=0 ;
			for(int i=1 ;i<=v;i++)
			{
				visited[i]  = 0 ;
			}
			check(span,1,visited,cnt) ;
			if(cnt!=v)
			{
				span[a][b]=w ;
				span[b][a]=w ;
				heap_var++ ;
			}
			else
			{
				heap_var++ ;
			}
		}
		else
		{
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
		span[i][j]=w ;
		span[j][i]=w ;
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
		cout<<"Minimum spanning tree weight ,accordingly conclude each edge  : "<<endl ;
	for(int z=1;z<=e;z++)
	{
		spanning_tree(span,z-1) ; 
		int sum=0 ;
		for(int i=1 ;i<=v;i++)
		{
			for(int j=i;j<=v;j++)
			{
				sum=sum+span[i][j] ;
			}
		}
		cout<<"("<<H[z-1].va<<","<<H[z-1].vb<<")"<<" -> "<<sum <<endl ;
		heap_var=0 ;
		for(int i=1;i<=v ;i++)
		{
			for(int j=1;j<=v ;j++)
			{
				span[i][j]=G[i][j]  ;
			}
		}
	}
	
	return 0 ;

} 
/*
7 12
1 2 2
2 5 10
5 7 6
7 6 1
3 6 5
3 1 4
1 4 1
2 4 3
4 5 7
4 7 4
4 6 8
4 3 2
*/
/*
7 12
1 4 1 
6 7 1
1 2 2
3 4 2
2 4 3
1 3 4
4 7 4
3 6 5
5 7 6
4 5 7
4 6 8
2 5 10
*/

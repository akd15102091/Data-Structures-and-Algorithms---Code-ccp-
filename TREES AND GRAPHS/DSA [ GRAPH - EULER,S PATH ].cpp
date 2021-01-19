#include<iostream>
#include<queue>
#include<stack>
using namespace std ;

void in_degree(vector<int> &ind , int G[50][50] ,int v)
{
	ind.push_back(0) ;
	for(int i=1 ;i<=v ;i++)
	{
		int cnt = 0 ;
		for(int j=1 ;j<=v ;j++)
		{
			if(G[j][i] ==1 )
			{
				cnt++ ;
			}
		}
		ind.push_back(cnt) ;
	}
	return ;
}

void DFS(int G[50][50], int i,int v ,int a[] ,int &k)
{
	cout<<i<<" ";
	for(int x=1 ;x<=v ;x++)
	{
		if(G[i][x]) 
		{
			G[i][x]=0 ;
			G[x][i]=0 ;
			DFS(G,x,v,a,k) ;
		}
	}
}


int main()
{
	int G[50][50] ;
	int v , e  ;
	cout<<"Enter v and e "<<endl ;
	cin>>v>>e ;
	for(int i=1;i<=v ;i++)
	{
		for(int j=1;j<=v ;j++)
		{
			G[i][j] = 0 ;
		}
	}
	for(int k=1;k<=e;k++)
	{
		cout<<"Enter i and j "<<endl ;
		int i,j ;
		cin>>i>>j ;
		
		G[i][j] = 1 ;
		G[j][i] = 1 ;  // un_directed graph
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
/*	int visited[50] ;
	for(int i=1;i<=v;i++)
	{
		visited[i] = 0 ;   // 1 for initialization , 2 for push ,3 for pop(visited complete)
	}*/

	/*vector <int> ind ;
	in_degree(ind , G , v) ; 
	cout<<"Indegree array is : "<<endl ; // in_degree store in an array  //
	for(int i=1;i<ind.size() ;i++)
	{
		cout<< ind[i] <<" ";
	}
	cout<<endl ;
	*/
/*	for(int i=1;i<=v;i++)
	{
		if(visited[i]==0)
		{
			DFS(G,i,visited,v,visited) ;
		}
	}
*/
	int a[50] ;
	int k=1 ;
	/*for(int i=1;i<=v;i++)
	{
		DFS(G,i,v,a,k) ;
	}*/
	DFS(G,1,v,a,k) ;
	
} 
/*
7 12
1 2
1 4
2 4
2 5
2 3
4 5
4 6
3 5
3 6
3 7
6 7
5 6
*/

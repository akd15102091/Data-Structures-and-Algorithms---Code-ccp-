#include<iostream>
#include<queue>
using namespace std ;

void DFS(int G[50][50] , int v,int e,int visited[] ,int i)
{
	visited[i]=1 ;
	for(int x=1 ; x<=v ; x++)
	{
		if(G[i][x]>0 && visited[x]==0)
		{
			DFS(G,v,e,visited,x) ;
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
	int visited[50] ;
	for(int i=1;i<=v;i++)
	{
		visited[i] = 0 ;   
	}
	int count = 0 ; // count is the number of friend circles
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==0)
		{
			count++ ;
			DFS(G,v,e,visited,i) ;
		}
	}
	
	cout<<"Total number of friend circles are : "<<count <<endl ;
	return 0;
} 
/*
12 9
1 2
1 3
2 4
5 6
6 7
8 9
9 10
10 8
11 12
*/

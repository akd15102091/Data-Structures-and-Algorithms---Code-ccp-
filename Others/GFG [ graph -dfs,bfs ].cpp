#include<iostream>
#include<queue>
using namespace std ;

void DFS(int G[50][50],int v,int e,int i,int visited[])
{
	visited[i] = 1 ;
	cout<<i<<" ";
	for(int x=1;x<=v;x++)
	{
		if(visited[x]==0 && G[i][x]==1)
		{
			DFS(G,v,e,x,visited) ;
		}
	}
}

void BFS(int G[50][50],int v,int e,int visited[])
{
	if(v==0) return ;
	
	queue<int> q ;
	q.push(1) ;
	visited[1] = 1 ;
	while(!q.empty())
	{
		int temp = q.front() ;
		q.pop() ;
		cout<<temp<<" " ;
		
		for(int x=1;x<=v;x++)
		{
			if(visited[x]==0 && G[temp][x]==1)
			{
				q.push(x) ;
				visited[x]=1 ;
			}
		}
	}
	return ;
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
		cout<<"Enter i and j : "<<endl ;
		int i,j ;
		cin>>i>>j;
		
		G[i][j] = 1 ;
		G[j][i] = 1 ;   
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

	int visited[50]={0} ;
	
	cout<<"DFS is : ";
	DFS(G,v,e,1,visited) ;
	cout<<endl;
	for(int i=1;i<=v;i++) visited[i]=0 ;
	cout<<"BFS is : ";
	BFS(G,v,e,visited) ;
	
	return 0;
} 
/*
7 9
1 2
1 3
2 4
3 4
4 5
3 5
4 6
6 7
3 7
*/


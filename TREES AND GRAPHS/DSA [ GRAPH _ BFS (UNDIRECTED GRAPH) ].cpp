#include<iostream>
#include<queue>
using namespace std ;

void BFS(int G[50][50] ,int v, int visited[] ,int i_ver )
{
	queue<int> q ;
	q.push(i_ver) ;
	visited[i_ver] = 2 ;
	while(!q.empty())
	{
		int temp = q.front() ;
		cout<<temp<<" -> " ;
		for(int j=1;j<=v;j++)
		{
			if(G[temp][j] ==1 && visited[j] ==1)
			{
				q.push(j) ;
				visited[j] = 2 ;
			}
		}
		q.pop() ;
		visited[temp] = 3 ;
	}
	cout<<"END" ;
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
		visited[i] = 1 ;   // 1 for initialization , 2 for enque ,3 for deque(visited complete)
	}
	cout<<"Enter initial vertax to traversal : "<<endl ;
	int i_ver ;
	cin>>i_ver ;
	cout<<"Breadth first search" <<endl ;
	BFS(G,v,visited ,i_ver) ;
	return 0;
} 
/*
6 8
1 2 
1 3 
1 5
2 4
2 6
4 5
5 6
3 5
*/

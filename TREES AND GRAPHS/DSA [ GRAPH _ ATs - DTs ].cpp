#include<iostream>
#include<queue>
#include<stack>
using namespace std ;


void DFS(int G[50][50], int s,int visited[],int v ,int l[] ,int r[] ,int &k)
{
	l[s]=k++;
	visited[s]=1 ;
	for(int i=0 ;i<v ;i++)
	{
	if(G[s][i]>0 && visited[i]==0)
		{
			DFS(G,i,visited,v,l,r,k) ;
		}
	}
	r[s]=k++;
}


int main()
{
	int G[50][50] ;
	int v , e  ;
	cout<<"Enter v and e "<<endl ;
	cin>>v>>e ;
	for(int i=0;i<v ;i++)
	{
		for(int j=0;j<v ;j++)
		{
			G[i][j] = 0 ;
		}
	}
	for(int k=0;k<e;k++)
	{
		cout<<"Enter i and j "<<endl ;
		int i,j ;
		cin>>i>>j ;
		
		G[i][j] = 1 ;
		//G[j][i] = 1 ;  // un_directed graph
	}
	cout<<"Adjacency matrix is : "<<endl ;
	for(int i=0;i<v ;i++)
	{
		for(int j=0;j<v ;j++)
		{
			cout<< G[i][j] << " "  ;
		}
		cout<<endl ;
	}
	int visited[50] ;
	for(int i=0;i<v;i++)
	{
		visited[i] = 0 ;   // 1 for initialization , 2 for push ,3 for pop(visited complete)
	}


	int l[50] ;
	int r[50] ;
	for(int i=0;i<v;i++)
	{
		l[i]=0 ;
		r[i] = 0 ;
	}
	int k=0;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==0)
		{
			DFS(G,i,visited,v,l,r,k) ;
		}
	}

	cout<<endl ;
	for(int i=0;i<v;i++)
	{
		cout<<i<<" -> {"<<l[i]<<" , "<<r[i]<<"}"<<endl ;
	}
	return 0;
} 
/*
8 8
0 1
0 2
2 3
2 4
4 5
3 5
6 7
3 1
*/

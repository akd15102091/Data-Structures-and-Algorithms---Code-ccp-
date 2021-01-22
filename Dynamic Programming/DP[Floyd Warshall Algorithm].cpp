// Floyd Warshall Algorithm

#include<iostream>
#define INF 99999  
using namespace std ;

void printAllShortestPathDistance(int dist[500][500],int v)
{
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
		//	cout<<"distance between" <<i<<" and "<<j<<" is : " ;
			if(dist[i][j]!=INF) cout<<dist[i][j] <<"    " ;
			else cout<<"INF"<<" ";
		}
		cout<<endl ;
	}
}

void Floyd_Warshall(int G[500][500],int v)
{
	int dist[500][500] ;
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			dist[i][j] = G[i][j] ;
		}
	}
	
	for(int k=1;k<=v;k++)
	{
		for(int i=1;i<=v;i++)
		{
			for(int j=1;j<=v;j++)
			{
				if(dist[i][j] > (dist[i][k] + dist[k][j]))
				{
					dist[i][j] = (dist[i][k] + dist[k][j]) ;
				}
			}
			for(int x=1;x<=v;x++)
			{
				for(int y=1;y<=v;y++)
				{
					cout<<dist[x][y]<<"  ";
				}
				cout<<endl;
			}
			cout<<"-----------------------------------"<<endl;
		}
	}
	cout<<"__________________"<<"final"<<endl;
	printAllShortestPathDistance(dist,v) ; 
}

int main()
{
	int v,e ;
	int G[500][500] ;
	cout<<"Enter the number of vertices and edges : "<<endl;
	cin>>v>>e ;
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			G[i][j]=INF ;
		}
	}
	for(int i=1;i<=v;i++)
	{
		G[i][i]=0 ;
	}
	// let us create following weighted directed graph
	for(int k=1;k<=e;k++)
	{
		int i,j,w ;
		cout<<"Enter i , j , w : "<<endl;
		cin>>i>>j>>w ;
		G[i][j]=w ;
		G[j][i]=w ;
	}

	Floyd_Warshall(G,v) ;
	return 0;
}
/*
4 4
1 2 5
2 3 3
3 4 1
1 4 10
*/

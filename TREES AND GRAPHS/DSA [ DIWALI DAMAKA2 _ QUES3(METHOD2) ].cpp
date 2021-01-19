#include<iostream>
#include<vector>
#include<cstring>
using namespace std ;

void pairOfK(int G[50][50],int i,int k,int v,int x,int y,vector<int>visited )
{
	visited[i]=1 ;
	if(k==0)
	{
		cout<<"("<<x<<" , "<<y<<")"<<endl ;
	}
	for(int l=1;l<=v;l++)
	{
		if(G[i][l]==1 && visited[l]==0)
		{
			y=l ;
			pairOfK(G,l,k-1,v,x,y,visited) ;
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
	cout<<"Enter length : "<<endl ;
	int k ;
	cin>> k ;
	vector <int> visited ;
	for(int i=0;i<=v;i++)
	{
		visited.push_back(0) ;
	}
//	pairOfK(G,v,k,visited) ;
	for(int i=1;i<=v;i++)
	{
		int x,y ;
		x=i ;
		pairOfK(G,i,k,v,x,y,visited) ;
	}
	return 0 ;
}


/*
8 7
1 2
1 5
2 4
5 8
5 6
6 7
4 3

*/

#include<iostream>
using namespace std ;

void in_degree(int ind[] , int G[50][50] ,int v)
{
	int k= 1 ;
	for(int i=1 ;i<=v ;i++)
	{
		int cnt = 0 ;
		for(int j=1 ;j<=v ;j++)
		{
			if(G[j][i] ==1)
			{
				cnt++ ;
			}
		}
		ind[k] = cnt ;
		k++ ;
	}
	return ;
}

void print_sequence(int G[50][50],int ind[] ,int v )
{
	int cnt = 0 ;
	for(int i=1;i<=v ;i++)
	{
		if(ind[i] <= 0)
		{
			cnt++ ;
		}
	}
	if(cnt == v) return ;
	
	for(int i=1 ;i<= v ;i++)
	{
		if(ind[i]==0)
		{
			cout<<i <<" " ;
			for(int k=1;k<=v;k++)
			{
				if(G[i][k] == 1)
				{
					ind[i] = ind[i] -1 ;
					ind[k] = ind[k] -1 ;
				}
			} 
		}
	}
	print_sequence(G, ind , v ) ;
	
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
	//	G[j][i] = 1 ;   directed graph
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
	int ind[50] ;
	in_degree(ind , G , v) ;  // in_degree store in an array  //
	cout<<"Indegree array : " ;
	for(int i=1;i<=v;i++)
	{
		cout<<ind[i] <<" ";
	}
	cout<<endl ;
	print_sequence(G , ind , v) ;
} 
/*
9 10
1 5
5 6
6 7
2 5
2 8
8 6
3 4
3 9
4 7
9 7
*/

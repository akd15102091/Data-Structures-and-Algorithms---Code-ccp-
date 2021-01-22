#include<iostream>
#include<queue>
using namespace std ;

void countPath(int G[50][50],int v,int e,int i,int b,int &cnt)
{
	if(i==b)
	{
		cnt++ ;
	}
	else
	{
		for(int x=1;x<=v;x++)
		{
			if( G[i][x]==1)
			{
				countPath(G,v,e,x,b,cnt) ;
			}
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
		cout<<"Enter i and j : "<<endl ;
		int i,j ;
		cin>>i>>j;
		
		G[i][j] = 1 ;  
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
	
	cout<<"Enter two vertixs : ";
	int a,b ;
	cin>>a>>b;
	int cnt=0 ;
	countPath(G,v,e,a,b,cnt) ;
	cout<<"Number of path between given vertax a and b is : "<<cnt ;
	
	return 0;
} 
/*
5 7
1 2
2 5
1 5
2 4
1 3
4 3
3 5
*/


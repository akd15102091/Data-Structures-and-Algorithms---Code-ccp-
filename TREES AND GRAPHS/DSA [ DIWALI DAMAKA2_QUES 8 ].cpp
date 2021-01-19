#include<iostream>
#include<vector>
#include<cstring>
using namespace std ;
int mps=0 ;
void maxPathSum(int G[50][50],int i,int v,vector<int>visited,int sum, int &max,int k,int weight[])
{
	visited[i]=1 ;
	if(max<k)
	{
		max=k ;
		mps=sum ;
	}
	for(int x=1 ;x<=v;x++)
	{
		if(G[i][x]==1 && visited[x]==0)
		{
			sum=sum+weight[x] ;
			//max=max+1 ;
			maxPathSum(G,x,v,visited,sum,max,k+1,weight) ;
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
	int weight[50] ;
	cout<<"ENter the weighted of vertexs i=1 to i= v  : "<<endl ;
	for(int i=1 ;i<=v ;i++)
	{
		int x ;
		cin>>x ;
		weight[i] = x ;
	}
	int max = 0 ; // max is max path length
	int sum =0 ;
	int k=0 ;
	vector <int> visited ;
	for(int i=0;i<=v;i++)
	{
		visited.push_back(0) ;
	}
	for(int i=1;i<=v;i++)
	{
		sum=weight[i] ;
		maxPathSum(G,i,v,visited,sum,max,k,weight) ;
	}
	cout<<mps ;
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
/*
10 9
1 2
2 5
2 6
2 7
1 3
3 8
1 4
4 9
4 10
7 2 5 3 6 15 9 7 10 11
*/

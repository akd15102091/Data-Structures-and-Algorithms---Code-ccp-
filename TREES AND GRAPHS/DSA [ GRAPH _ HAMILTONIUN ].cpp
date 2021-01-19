#include<iostream>
#include<queue>
using namespace std ;
int n=0 ;
void permutation(int ver[] ,int l,int r,int G[50][50])
{
	if(l==r)
	{
		int cnt=0 ;
		for(int x=1;x<r;x++)
		{
			if(G[ver[x]][ver[x+1]]==0)
			{
				cnt++ ;
			}
		}
		if(cnt==0)
		{
			for(int x=1;x<=r;x++)
			{
				cout<<ver[x] <<" ";
			}
			n++ ;
			cout<<endl ;
		}
		
		return ;
		
	}
	for(int i=l;i<=r;i++)
	{
		swap(ver[l],ver[i]) ;
		permutation(ver,l+1,r,G) ;
		swap(ver[l],ver[i]) ;
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
	cout<<"Enter vertex array : "<<endl ;
	int ver[50] ;
	for(int i=1 ;i<=v;i++)
	{
		cin>>ver[i] ;
	}
	cout<<"All hamiltonion paths are : "<<endl ;
	permutation(ver,1,v,G) ;
	cout<<endl<<n ;
	return 0;
} 
/*
4 4 
1 2
2 3
3 4
4 2
*/

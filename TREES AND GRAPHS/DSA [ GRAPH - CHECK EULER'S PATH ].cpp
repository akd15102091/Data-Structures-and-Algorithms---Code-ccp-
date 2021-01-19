#include<iostream>
#include<vector> 
using namespace std ;
void in_degree(int ind[] , int G[50][50] ,int v,int &k)
{
	for(int i=1 ;i<=v ;i++)
	{
		int cnt = 0 ;
		for(int j=1 ;j<=v ;j++)
		{
			if(G[j][i] ==1 || G[i][j])
			{
				cnt++ ;
			}
		}
		ind[k++]=cnt ;
	}
	return ;
}

void splice_arr(int G[50][50] , int v ,int s, int i,vector<int> &v1,int ind[])
{
	v1.push_back(i) ;
	for(int x=1;x<=v;x++)
	{
		if(ind[s]==0)
		{
			break ;
		}
		if(G[i][x]==1)
		{
			//v1.push_back(x) 
			G[i][x]=-1 ;
			G[x][i]=-1 ;
			ind[i]=ind[i]-1 ;
			ind[x]=ind[x]-1 ;
			splice_arr(G,v,s,x,v1,ind) ;
		}
	}
}
void splice(vector<int>v1 , vector<int>v2 , vector<int> &v3)
{
	int d= v2[0] ;
	int i=0 ;
	while(v1[i] !=d)
	{
		v3.push_back(v1[i]) ;
		i++ ;
	}
	for(int j=0;j<v2.size();j++)
	{
		v3.push_back(v2[j]) ;
	}
	for(int k=i+1;k<v1.size();k++)
	{
		v3.push_back(v1[k]) ;
	}
	return ;
}

void EulerPath( int G[50][50],int v,int ind[] , vector<int>&v1 ,vector<int>&v2)
{
	int cnt=0 ;
	for(int l=1;l<=v;l++)
	{
		if(ind[l]==0) cnt++ ;
	}
	if(cnt==v) 
	{
		for(int i=0;i<v1.size() ;i++)
		{
			cout<<v1[i]<<" ";
		}
		return ;	
	}
	int d ;
	for(int z=0; z<v1.size() ;z++ )
	{
		if(ind[v1[z]]!=0)
		{
			d=v1[z] ;
			break ;	
		}	
	}
	splice_arr(G,v,d,d,v2,ind) ;
	vector<int>v3 ;
	splice(v1,v2,v3) ;
	v2.clear() ;
	EulerPath(G,v,ind,v3,v2) ;
	
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
	int ind[50] ;
	int k=1 ;
	in_degree(ind , G , v,k) ; 
	int n=0 ;
	cout<<"Indegree array is : "<<endl ; // in_degree store in an array  //
	for(int i=1;i<k ;i++)
	{
		cout<< ind[i] <<" ";
	}
	cout<<endl ;
	int s=1 ; // source vertex= 1
	vector<int>v1 ;
	//v1.push_back(0) ;
	vector<int>v2 ;
	splice_arr(G,v,s,s,v1,ind) ;
	cout<<"Euler's path for given graph : "<<endl ;
	EulerPath(G,v,ind,v1,v2) ;
	
	return 0;
} 
/*
 12 21
 1 3
 1 4
 2 3
 2 8
 8 9
 3 6
 6 9
 3 9
 3 7
 7 9
 4 7
 7 10
 9 12
 12 10
 4 10
 3 4
 4 5
 10 11
 4 11
 5 10
 9 10
 
*/

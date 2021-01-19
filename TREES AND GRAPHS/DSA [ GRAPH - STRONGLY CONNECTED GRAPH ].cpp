#include<iostream>
using namespace std ;

void AT_DT(int G[50][50], int s,int visited[],int v ,int l[] ,int r[] ,int &k)
{
	l[s]=k++;
	visited[s]=1 ;
	for(int i=1 ;i<=v ;i++)
	{
	if(G[s][i]>0 && visited[i]==0)
		{
			AT_DT(G,i,visited,v,l,r,k) ;
		}
	}
	r[s]=k++;
}

int no_visit(int visited[],int v)
{
	int cnt=0 ;
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==1)
		{
			cnt++ ;
		}
	}
	return cnt ;
}

void DFS(int rev_mat[50][50],int v,int e,int visited[],int pt,int r[])
{
	visited[pt] = 1 ;
	cout<<pt<<" " ;
	for(int j=1;j<=v;j++)
	{
		if(visited[j]==1)
		{
			int max=0 ; 
		    int z ;
			for(int i=1;i<=v;i++)
			{
				if(max<r[i] && visited[i]==0 && rev_mat[pt][i]==1)
				{
					max=r[i] ;
					z = i ;
				}
			}
			
			DFS(rev_mat,v,e,visited,z,r) ;
		}
	}
}

int main()
{
	int G[50][50] ;
	int rev_mat[50][50] ;
	int v , e  ;
	cout<<"Enter v and e "<<endl ;
	cin>>v>>e ;
	for(int i=1;i<=v ;i++)
	{
		for(int j=1;j<=v ;j++)
		{
			G[i][j] = 0 ;
			rev_mat[50][50] = 0 ;
		}
	}
	for(int k=1;k<=e;k++)
	{
		cout<<"Enter i and j "<<endl ;
		int i,j ;
		cin>>i>>j ;
		
		G[i][j] = 1 ;
		//G[j][i] = 1 ;  // un_directed graph
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
		visited[i] = 0 ;  
	}


	int l[50] ;
	int r[50] ;
	for(int i=1;i<=v;i++)
	{
		l[i]=0 ;
		r[i] = 0 ;
	}
	int k=0;
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==0)
		{
			AT_DT(G,i,visited,v,l,r,k) ;
		}
	}

	cout<<endl ;
	for(int i=1;i<=v;i++)
	{
		cout<<i<<" -> {"<<l[i]<<" , "<<r[i]<<"}"<<endl ;
	}

	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			if(G[i][j]==1)
			{
				rev_mat[j][i] = 1 ;
			}
		}
	}
	for(int i=1;i<=v;i++)
	{
		visited[i] = 0 ;  
	}
	while(no_visit(visited,v)!=v)
	{
		int	max=0 ;
		int pt ;
		for(int i=1;i<=v;i++)
		{
			if(max<r[i] && visited[i]==0)
			{
				max=r[i] ;
				pt = i ;
			}
		}
		DFS(rev_mat,v,e,visited,pt,r) ;
		cout<<endl ;
		break ;
	}
	return 0;
} 
/*
10 15
1 2
2 3
3 1
1 4
3 4
3 5
4 5
2 6
6 3
7 6
8 6
7 8
8 10
9 8
10 9
*/

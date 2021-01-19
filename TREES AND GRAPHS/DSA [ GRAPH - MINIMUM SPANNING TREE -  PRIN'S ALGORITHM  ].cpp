#include<iostream>
#include<stack>
using namespace std ;
int no_visit(int visited[] ,int v)
{
	int x =0;
	for(int i=1;i<=v;i++)
	{
		if(visited[i]==1)
		{
			x++ ;
		}
	}
	return x ;
}


void min_span_tree(int G[50][50] ,int visited[]  ,int v )
{
	int min=10000 ,t,p ;
	int sum=0 ;
	visited[1]=1;
	while(no_visit(visited,v) !=v)
	{
		for(int j=1 ;j<=v;j++)
		{
			if(visited[j])
			{
				for(int m=1;m<=v;m++)
				{
					if(G[j][m]>0 && !visited[m])
					{
						if(min>G[j][m])
						{
							t=m ;
							p=j ;
							min=G[j][m] ;
						}
					}
					
				}
							
			}		
		}
		visited[t] =1 ;
		sum+=min ;
		cout<<p<<" to "<<t<<endl ;
		min=10000 ;
	}
	cout<<sum<<endl; 
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
		cout<<"Enter i and j and w "<<endl ;
		int i,j,w ;
		cin>>i>>j >>w;
		
		G[i][j] = w ;
		G[j][i] = w ;   
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
	for(int i=1 ;i<=v;i++)
	{
		visited[i]  = 0 ;
	}
	min_span_tree(G ,visited ,v ) ;

} 
/*
7 12
1 2 2
2 5 10
5 7 6
7 6 1
3 6 5
3 1 4
1 4 1
2 4 3
4 5 7
4 7 4
4 6 8
4 3 2
*/

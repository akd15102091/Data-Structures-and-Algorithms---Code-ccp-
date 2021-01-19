#include<iostream>
#include<stack>
#include<algorithm>
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


int min_span_tree(int G[50][50] ,int visited[]  ,int v ,int z)
{
	int min=10000 ,t,p ;
	int sum=0 ;
	visited[z]=1;            
	int a=0,b1=0,b2=0;
	for(int i=1;i<=v;i++)
	{
		if(G[z][i]>0 && min>G[z][i])
		{
			min= G[z][i] ;
			a=z;
			b1=i ;
		}
	}
	
	int min2=10000 ;
	for(int i=1;i<=v;i++)
	{
		if(G[z][i]>0 && min2>G[z][i] && min<G[z][i] )
		{
			if(min2>min)
			{
				min2= G[z][i] ;
				a=z;
				b2=i ;
			}
			
		}
	}
//	cout<<a<<b1<<b2 ;
	int cnt=0 ;
	int arr[50] ;
	
	while(no_visit(visited,v) !=v)
	{
		for(int j=1 ;j<=v;j++)
		{   //cnt++ ;
			if(visited[j])
			{
				for(int m=1;m<=v;m++)
				{
					if(cnt==0)
					{
						min=min2 ;
						p=a;
						t=b2 ;
						break ;
					}
					if(G[j][m]>0 && !visited[m] &&cnt!=0 && !(j==a && m==b1) && !(j==b1 && m==a) )
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
	//	cout<<p<<" to "<<t<<endl ;
		min=10000 ;
		cnt++ ;
	}
	//cout<<sum<<endl; 
	return sum ;
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
	int span2=100000 ;
	for(int z=1;z<=v;z++)
	{
		int val = min_span_tree(G ,visited ,v ,z) ;
		if(span2>val)
		{
			span2=val ;
		}
		for(int i=1 ;i<=v;i++)
		{
			visited[i]  = 0 ;
		}
	}
	
	cout<<"Second best minimum spanning tree weight is : "<< span2<<" ";
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
for this graph 1st min spanning tree weight=16
and for 2nd min spanning tree weight = 17
*/

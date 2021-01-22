#include<iostream>
#include<vector>
#include<stack>
using namespace std ;
int min(vector<int> visited ,vector<int> d ,int v)
{
	int m = 10000  ,t ;
	for(int i=1;i<=v;i++)
	{
		if(m>d[i] && visited[i]==0)
		{
			t= i ;
			m = d[i] ;
		}
	}
	return t ;
}
int shortest_path(int G[50][50] ,vector<int> visited ,vector<int> d ,int pv[] ,int cv ,int x ,int y ,int v )
{
	int i=x ;
	d[i]=0 ;
	while(i !=y)
	{
		for(int j=1 ;j<=v;j++)
		{
			if(G[i][j]>0  && visited[i]==0)
			{
				if(d[j] > d[i]+G[i][j] )
				{
					d[j] = d[i]+G[i][j]  ;
					pv[j] = i ;
				}
			}
				
		}
		visited[i] =1 ;
		int new_i = min(visited,d,v) ;
		i = new_i ;
	}
	stack<int> s ;
	int dis=0 ;
	while(i!=x)
	{
		dis++ ;
		s.push(i) ;
		i = pv[i] ;
	}
	s.push(i);
	
	return dis ;
	
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
	int x1,x2,x3 ;
	cout<<"Enter three sets  vertex "<<endl ;
	cin>>x1>>x2>>x3 ;
	vector<int> visited ;
	vector<int> d;
	int pv[50] ;
	for(int i=0 ;i<=v;i++)
	{
		d.push_back(10000) ;
		visited.push_back(0) ;
	}
	int dis[50][50] ;
	
	int cv ;// cv is current vertax
	for(int j=1;j<=3;j++)
	{
		int x ;
		if(j==1) x=x1 ; if(j==2) x=x2 ;	if(j==3) x=x3 ;
		
		for(int i=1;i<=v;i++)
		{
			if(i==x)
			{
				dis[j][i]=0 ;
			}
			else
			{
				int c =shortest_path(G ,visited ,d ,pv ,cv ,x ,i ,v ) ;
				dis[j][i]=c ;
	
			}
		}
	}
	
	for(int i=1;i<=v;i++)
	{
		if(dis[1][i]<=3 && dis[2][i]<=3 && dis[3][i]<=3)
		{
			cout<<i<<" " ;
		}
	}
	
} 
/*
10 9 
1 10 1
2 3 1
4 5 1
10 3 1
3 5 1
10 8 1
3 6 1
3 7 1
5 9 1
*/

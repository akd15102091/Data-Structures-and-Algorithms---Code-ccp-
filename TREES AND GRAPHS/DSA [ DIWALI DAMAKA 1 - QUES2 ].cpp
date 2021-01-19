
#include<iostream>
#include<stack>
using namespace std ;
int min(int visited[] ,int d[] ,int v)
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
void shortest_path(int G[50][50] ,int visited[] ,int d[] ,int pv[] ,int cv ,int x ,int y ,int v ,int weighted[] )
{
	int i=x ;
	d[i]=0 ;
	while(i !=y)
	{
		for(int j=1 ;j<=v;j++)
		{
			if(G[i][j]>0  && visited[i]==0)
			{
				if(d[j] > d[i]+weighted[j] )
				{
					d[j] = d[i]+weighted[j]  ;
					pv[j] = i ;
				}
			}
				
		}
		visited[i] =1 ;
		int new_i = min(visited,d,v) ;
		i = new_i ;
	}
	stack<int> s ;
	while(i!=x)
	{
		s.push(i) ;
		i = pv[i] ;
	}
	s.push(i);
	cout<<"Shortest path from source 'x' to destination 'y' is : " ;
	while(!s.empty())
	{
		if(s.size()==1)
		cout<<"V"<<s.top();
		else
		cout<<"V"<<s.top()<<" -> ";
		s.pop();
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
		cout<<"Enter i and j  "<<endl ;
		int i,j;
		cin>>i>>j ;
		
		G[i][j] = 1;
	//	G[j][i] = 1 ;   // directed graph
	}
	int weighted[50] ;
	for(int i=1;i<=v;i++)
	{
		cout<<"Enter the weight of V"<<i<<endl ;
		int w ;
		cin>>w ;
		weighted[i]=w ;
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
	int x,y ;
	cout<<"Enter starting and ending vertex "<<endl ;
	cin>>x>>y ;
	int visited[50] ;
	int d[50] ;
	int pv[50] ;
	for(int i=1 ;i<=v;i++)
	{
		d[i] = 100000 ;
		visited[i]  = 0 ;// very big number
	}
	int cv = x ; // cv is current vertax
	shortest_path(G ,visited ,d ,pv ,cv ,x ,y ,v , weighted ) ;

} 
/*
7 12
1 2 
2 5 
5 7 
7 6 
3 6 
3 1 
1 4 
2 4 
4 5 
4 7 
4 6 
4 3 

4 2 7 1 10 5 6


*/

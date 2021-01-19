#include<iostream>
#include<stack>
using namespace std ;
int min(int visited[] ,int d[] ,int v)
{
	int m = 10000  ,t ;
	for(int i=1;i<=v;i++)
	{
		if(m>d[i] && visited[i]==0  )
		{
			t= i ;
			m = d[i] ;
		}
	}
	return t ;
}

void shortest_path(int G[50][50] ,int visited[] ,int d[] ,int pv[] ,int cv ,int x ,int y ,int v ,int visited_edge[50][50] )
{
	
	int i=x ;
	d[i]=0 ;
	while(i !=y)
	{
		for(int j=1 ;j<=v;j++)
		{
			if(G[i][j]>0  && visited[i]==0 && visited_edge[i][j]==0 )
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
	while(i!=x)
	{
		s.push(i) ;
		i = pv[i] ;
	}
	s.push(i);
	int k=0 ;
	int b[50] ;
	//cout<<"Shortest path from source 'x' to destination 'y' is : " ;
	while(!s.empty())
	{
		cout<<"V"<<s.top()<<" ";
		b[k]=s.top() ;k++ ;
		s.pop() ;
	}
	for(int l=0;l<k-1 ;l++)
	{
		visited_edge[b[l]][b[l+1]] = 1 ;
	}
	
}



int main()
{
	int G[50][50] ;
	int visited_edge[50][50] ;
	int v , e  ;
	cout<<"Enter v and e "<<endl ;
	cin>>v>>e ;
	for(int i=1;i<=v ;i++)
	{
		for(int j=1;j<=v ;j++)
		{
			G[i][j] = 0 ;
			visited_edge[i][j]=0 ;
		}
	}
	for(int k=1;k<=e;k++)
	{
		cout<<"Enter i and j and w "<<endl ;
		int i,j,w ;
		cin>>i>>j >>w;
		
		G[i][j] = w ;
		//G[j][i] = 1 ;   
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
	cout<<"Shortest path from source 'x' to destination 'y' is : " ;
	shortest_path(G ,visited ,d ,pv ,cv ,x ,y ,v , visited_edge ) ;
	for(int i=1 ;i<=v;i++)
	{
		d[i] = 100000 ;
		visited[i]  = 0 ;// very big number
	}
	cout<<endl ;
	cout<<"Shortest path from source 'y' to destination 'x' is : " ;
	cv=y ;
//	cout<<"Enter ending and starting vertex "<<endl ;
	shortest_path(G ,visited ,d ,pv ,cv ,y ,x ,v , visited_edge ) ;
	return 0 ;

} 

/*
7 12
1 2 2
2 5 10
5 7 6
7 6 1
6 3 5
3 1 4
1 4 1
2 4 3
4 5 2
4 7 4
4 6 8
4 3 2
*/

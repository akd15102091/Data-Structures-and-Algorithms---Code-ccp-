#include<iostream>
#include<queue>
using namespace std ;

struct state
{
	int a ;
	int b ;
} ;
void WATER_JUG( int G[50][50] ,queue<struct state> q ,int x,int y ,int z)
{
	struct state H ;
	H.a = 0 ;
	H.b = 0 ;
	q.push(H) ;
	
	while(!q.empty())
	{
		struct state temp = q.front() ;
		cout<<"("<<temp.a <<","<<temp.b<<")" ;
		if(temp.a == z || temp.b == z)
		{
			return ;
		}
		
		if( temp.a ==0 && temp.b==0 )
		{
			struct state t ;
			t.a = x ;
			t.b = 0 ;
			if(G[t.a][t.b]==0)
			{
				G[t.a][t.b] = 1 ;
				q.push(t) ;
			}
			
			struct state t2 ;
			t2.a = 0 ;
			t2.b = y ;
			if(G[t2.a][t2.b]==0)
			{
				G[t2.a][t2.b] = 1 ;
				q.push(t) ;
			} 
			
		}	
		 else
		 {
			if( temp.a != 0 || temp.b !=0 )
			{
				struct state t ;
				t.a = temp.a ;
				t.b = 0 ;
				if(G[t.a][t.b]==0)
				{
					G[t.a][t.b] = 1 ;
					q.push(t) ;
				}
				struct state t2 ;
				t2.a = 0 ;
				t2.b = temp.b ;
				if(G[t2.a][t2.b]==0)
				{
					G[t2.a][t2.b] = 1 ;
					q.push(t) ;
				} 
			}
			if( temp.a != 0 || temp.b !=0 )
			
				struct state t2 = temp ;
				struct state t ;
				while(temp.b<y || temp.a>0)
				{
						temp.a-- ;
						temp.b ++ ;
					
				}
				t.a = temp.a  ;
				t.b = temp.b ;
				if(G[t.a][t.b] ==0)
				{
					G[t.a][t.b] = 1 ;	
					q.push(t) ;
				}
				while(t2.b>0 || t2.a<x)
				{
					t2.a ++ ;
					t2.b -- ;
				}
				t.a = t2.a  ;
				t.b = t2.b ;
				if(G[t.a][t.b] ==0)
				{
					G[t.a][t.b]=1 ;
					q.push(t) ;
				}
			 }
		 }
		q.pop() ;
	}
}

int main()
{
	int x , y ;
	int G[50][50] ;
	cout<<"Enter two litres ( X > Y ) : "<<endl ;
	cin>>x>>y ;
	for(int i=0;i<=x;i++)
	{
		for(int j=0 ;j<=x ;j++)
		{
			G[i][j] = 0 ; 
		}
	}
	cout<<"Which litre you want : "<<endl ;
	int z ;
	cin>>z ;
	queue<struct state> q ;

	WATER_JUG( G ,q, x, y ,z ) ;
}

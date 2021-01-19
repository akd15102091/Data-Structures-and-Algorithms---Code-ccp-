#include<iostream>
#include<vector>
#include<queue>
using namespace std ;
struct element
{
	vector<int>vec ;
	int len ;
} ;

void kLengthPath(struct element st, int G[50][50],int v,int e,int s,int d ,int k)
{
	queue<struct element> q ;
	q.push(st) ;
	while(!q.empty()) 
	{
		struct element var = q.front() ;
		q.pop() ;
		if( var.vec[0]==s && var.vec.back()==d)
		{
			for(int i=0;i<var.vec.size() ;i++)
			{
				cout<<var.vec[i]<<" "; 
			}
			cout<<endl ;
		}
		int x = var.vec.back() ;
		int z = var.len-1 ;
		for(int i=1;i<=v;i++)
		{
			
			if(G[x][i]==1)
			{
				//var.vec.push_back(i) ;
				struct element temp ;
				temp.vec = var.vec ;
				temp.vec.push_back(i) ;
				temp.len = z ;
				q.push(temp) ; 
			}
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
	//	G[j][i] = 1 ;  // un_directed graph
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

	cout<<"Enter the source , destination and path length : "<<endl ;
	int s,d,k ;
	cin>>s>>d>>k ;
	vector<int> vt ;
	vt.push_back(s) ;
	struct element st ;
	st.len=k ;
	st.vec=vt ;
	cout<<"All paths of length k , from source s to destination d are : "<<endl ;
	kLengthPath(st,G,v,e,s,d,k) ;
	return 0;
} 
/*
8 12
4 1
4 6
7 6
1 6
1 2
1 5
6 5
5 2
2 3
5 3
5 8
3 8
*/

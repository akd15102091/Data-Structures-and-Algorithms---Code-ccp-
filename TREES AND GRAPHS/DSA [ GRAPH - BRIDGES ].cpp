#include<iostream>
#include<vector>
#include<stack>
using namespace std ;
void in_degree(vector<int> &ind , int G[50][50] ,int v)
{
	ind.push_back(0) ;
	for(int i=1 ;i<=v ;i++)
	{
		int cnt = 0 ;
		for(int j=1 ;j<=v ;j++)
		{
			if(G[j][i] ==1 || G[i][j]==1)
			{
				cnt++ ;
			}
		}
		ind.push_back(cnt) ;
	}
	return ;
}
int av[50] ;
int cuts[50] ;
int var=1 ;
void DFS(int G[50][50],int s,int v,int e,stack<int>stk,int arr[],int &d,int visited[],int num[], int l[],int &k)
{
	visited[s]=1 ;
	num[s]=k ;
	av[s]=k ;
	l[s]=k++ ;
	arr[d]=s ;
	d++ ;
	for(int i=1;i<d-1;i++)
	{
		if(G[s][arr[i]]>0 && visited[i]==1 && arr[i]!=stk.top())
		{
			if(l[s]>num[arr[i]])
			{
				l[s]=num[arr[i]] ;
			}
		}
	}
	stk.push(s) ;
	for(int x=1;x<=v;x++)
	{
		if(G[s][x]>0 && visited[x]==0)
		{
			DFS(G,x,v,e,stk,arr,d,visited,num,l,k) ;
			if(l[s]>l[x])
			{
				l[s]=l[x] ;
				
			}
			if(l[x]>=num[s] && s!=1)
			{
				cuts[var]=s ;
				var++ ;
				cout<<s<<endl ;
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
	int visited[50] ;
	for(int i=1;i<=v;i++)
	{
		visited[i] = 0 ;   // 1 for initialization , 2 for push ,3 for pop(visited complete)
	}
	
	vector <int> ind ;
	in_degree(ind , G , v) ; 

	int l[50] ;
	for(int i=1;i<=v;i++)
	{
		l[i]=0 ;
	}
	stack<int> stk ;
	stk.push(0) ;
	int d=1 ,k=1;
	int num[50] ;
	int arr[50];
	DFS(G,1,v,e,stk,arr,d,visited,num,l,k) ;
	cout<<endl ;
	
	for(int i=1;i<var;i++)
	{
		for(int j=1;j<=v;j++)
		{
			if(G[cuts[i]][j]>0 && ind[j]==1)
			{
				cout<<cuts[i]<<"-"<<j <<endl ;
			}
		}
		for(int j=1;j<var;j++)
		{
			if(G[cuts[i]][cuts[j]]>0 && cuts[i]!=cuts[j])
			{
				G[cuts[i]][cuts[j]]=0 ;
				G[cuts[j]][cuts[i]]=0 ;
				cout<<cuts[i]<<"-"<<cuts[j]<<endl ;
			}
		}
	}
	
}
/*
7 8 
1 2
2 3
3 4
4 1
4 6
4 5
5 6
3 7
*/
/*
8 11
1 2
1 3
2 3
2 4
2 5
4 5
5 6
6 4
6 8
8 7
7 6
*/
/*
8 12
1 2
1 3
2 3
2 4
2 5
4 5
5 6
6 4
6 8
8 7
7 6
2 6
*/
/*
5 5
1 2
2 5
1 5
3 5
3 4
*/

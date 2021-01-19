#include<iostream>
#include<vector>
#include<cstring>
using namespace std ;
int n=0 ;
void Print_All_DFS(int G[50][50], int i_ver, string str,vector<int>visited ,int v)
{
	if(str.length() == v)
	{
		cout<<str<<endl ;
		n++ ;
	}
	visited[i_ver]=2 ;
	
	for(int x=1; x<=v; x++)
	{
        if(visited[x] == 1 && G[i_ver][x] ==1)
		{
            char ch = '0'+x ;
            Print_All_DFS(G ,x , str+ch , visited , v);
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
	vector<int> visited ;
	visited.push_back(0) ;
	for(int i=1;i<=v;i++)
	{
		visited.push_back(1)  ;   // 1 for initialization , 2 for push ,3 for pop(visited complete)
	}
	cout<<"Enter initial vertax to traversal : "<<endl ;
	int i_ver ;
	cin>>i_ver ;
	cout<<"Depth first search" <<endl ;
	string str ="" ;
	char ch = '0'+i_ver ;
	str = str+ch ;
	Print_All_DFS(G,i_ver,str,visited,v) ;
	cout<<"Total DFS counting is : "<<n ;
	return 0;
} 
/*
5 7
1 2
1 3
2 4
2 5
3 4
3 5
4 5

*/

/* 
6 9
1 2
1 6
1 3
2 4
2 5
3 5
3 4
4 6
3 6

*/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std ;

void print_cycles( int G[50][50] ,vector<bool> VISITED ,int i ,int v ,string str="")
{
	if(VISITED[i] == true)
	{
		if(str.substr(0,1) == str.substr(str.length()-1 ,str.length()) )
		{
			cout<<str <<endl ;
		}
		return ;
	}
	VISITED[i] = true ;
	for(int x=1 ;x<=v ;x++)
	{
		char ch = '0'+x ;
		if(G[i][x] == 1)
		{
			print_cycles( G , VISITED ,x ,v , str+ch) ;
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
	vector<bool> VISITED ;
	VISITED.push_back( false ) ;
	for(int i=1;i<=v;i++)
	{
		VISITED.push_back( false ) ;
	}
	for(int i=1 ;i<=v ;i++)
	{
		char ch = '0' +i ;
		string str = "" ;
		print_cycles(G,VISITED ,i ,v , str+ch) ;
	}

}

/*
5 7
1 2
2 3
3 4
4 1
1 3
2 5
4 5
*/

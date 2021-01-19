#include<iostream>
#include<vector>
#include<cstring>
using namespace std ;

void in_degree(vector<int> &ind , int G[50][50] ,int v)
{
	ind.push_back(0) ;
	for(int i=1 ;i<=v ;i++)
	{
		int cnt = 0 ;
		for(int j=1 ;j<=v ;j++)
		{
			if(G[j][i] ==1)
			{
				cnt++ ;
			}
		}
		ind.push_back(cnt) ;
	}
	return ;
}
int n =0 ;
void printAll( int G[50][50] , vector<int> ind , int i ,int v , string str="")
{
	if( str.length() == v) 
	{
		cout<<str<<endl ;
		n++ ;	
		return ;
	}
	ind[i] = -1 ;
	for(int j=1; j<=v; j++)
	{
        if(G[i][j])
		{
            ind[j]--;
        }
    }
    for(int x=1; x<=v; x++)
	{
        if(ind[x] == 0)
		{
            char ch = '0'+x ;
            printAll(G ,ind, x, v , str + ch);
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
	vector <int> ind ;
	in_degree(ind , G , v) ; 
	cout<<"Indegree array is : "<<endl ; // in_degree store in an array  //
	for(int i=1;i<ind.size() ;i++)
	{
		cout<< ind[i] <<" ";
	}
	cout<<endl ;
	cout<<"All possible sequences are : "<<endl ;
	for(int i=1; i<=v; i++)
	{	if(ind[i] == 0)
		{
            string str = "";
            char ch = '0'+i;
            str += ch;
            printAll(G ,ind, i,v , str ) ;
        }
    }
    cout<<" All possible sequences counting is : "<< n;
}

/*
9 10
1 5
5 6
6 7
2 5
2 8
8 6
3 4
3 9
4 7
9 7
*/

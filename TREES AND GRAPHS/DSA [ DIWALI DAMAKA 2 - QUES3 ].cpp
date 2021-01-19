#include<iostream>
#include<queue>
using namespace std ;
void matrix_multiplication(int a[50][50] , int b[50][50] , int C[50][50] ,int v )
{
	//	int c[m][q];
    for(int i= 1;i<=v;i++)
    {
        for(int j = 1;j<=v;j++)
        {
            int sum  = 0;
                for(int e=1;e<=v;e++)
                {
                   //for(int f = 0;f< p;f++)
                    {
                        sum += (a[i][e])*(b[e][j]);
                    }
                 }
            C[i][j] = sum;
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
	// here we find G*G , and which of it,s index has value k , that length of i to j will be equal to k
	int C[50][50]; // c is G*G
	matrix_multiplication(G,G,C,v) ;
	matrix_multiplication(G,C,C,v) ;
	int sum=0 ;
	for(int i=1;i<=v;i++)
	{
		sum=sum+C[i][i] ;
	}
	cout<<"Number of triangles in given graph : "<<sum/6 <<endl ;
	return 0;
} 

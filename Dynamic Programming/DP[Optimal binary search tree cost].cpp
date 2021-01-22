#include<iostream>
using namespace std ;

int n;
int m=  n+1 ;
//calP[n+1][n+1]
float OBST(float calP[500][500],int i,int j)
{
	float e[n+1][n+1] ;
	for(int i=1;i<=n;i++)
	{
		e[i][i-1]=0 ;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			e[i][j]=INT_MAX ;
		}
	}
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i<=(n-l+1);i++)
		{
			int j = i+l-1 ;
			for(int k=i;k<=j;k++)
			{
				float t = e[i][k-1] + e[k+1][j] + calP[i][j] ;
				if(t<e[i][j])
				{
					e[i][j] =t ;
				}
			}
		}
	}
	return e[1][n] ;
}

int main()
{
	float calP[500][500] ;
	cout<<"Enter the number of keys : "<<endl;
	cin>>n ;
	float K[n+1] ;
	float P[n+1] ;
	cout<<"Enter the key value : "<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>K[i] ;
	}
	cout<<"Enter the corresponding probability value : "<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>P[i] ;
	}
	// calP[i][j] = sum of P[i] + P[i+1]+....+ P[j]
	for(int i=1;i<=n;i++)
	{
		calP[i][i]=P[i] ; 
	}
	for(int i=1;i<=(n-1);i++)
	{
		int j=i+1 ;
		calP[i][j] = calP[i][j-1] + calP[i+1][j] ;
	}
	for(int l=3;l<=n;l++)
	{
		for(int i=1;i<=(n-l+1);i++)
		{
			int j=i+l-1 ;
			calP[i][j] = calP[i][j-1] + calP[i+1][j] -calP[i+1][j-1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<calP[i][j]<<" 		 ";
		}
		cout<<endl;
	}
	cout<<endl ;
	float minCost = OBST(calP,1,n) ; 
	cout<<"Min search cost is : "<<minCost<<endl ;
}

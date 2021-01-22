#include<iostream>
using namespace std ;

int MinNumberOfCoins(int coin[],int n,int sum)
{
	int T[500][500] ;
	for(int i=0;i<=n;i++)
	{
		T[i][0]=0 ;
	}
	int m =sum ;
	for(int j=1;j<=m;j++)
	{
		T[0][j]=INT_MAX ;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(j>=coin[i-1])
			{
				T[i][j]=min(T[i-1][j],1+ T[i][j-coin[i-1]])	;
			}	
			else
			{
				T[i][j]=T[i-1][j] ;
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout<<T[i][j]<<"   ";
		}
		cout<<endl ;
	}
	return T[n][m] ;
}

int main()
{
	int n,sum ;
	int coin[500] ;
	cout<<"enter n : "<<endl;
	cin>>n ;
	cout<<"Enter the elements of array coin : "<<endl ;
	for(int i=0;i<n;i++)
	{
		cin>>coin[i] ;
	}
	cout<<"Enter sum : "<<endl ;
	cin>>sum ;
	int x = MinNumberOfCoins(coin,n,sum) ;
	cout<<"min number of coins : "<<x<<endl ;
}

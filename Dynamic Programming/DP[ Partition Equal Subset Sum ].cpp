#include<iostream>
using namespace std ;

bool equalPartitionSum(int n,int arr[],int s)
{
	bool T[500][500] ;
	int m=s ;//n*m matrix
	for(int i=0;i<=m;i++)
	{
		if(i==0 || arr[0]==i)
		{
			T[0][i]=true ;
		}
		else T[0][i]=false ;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(j<arr[i])
			{
				T[i][j]=T[i-1][j] ;
			}
			else 
			{
				T[i][j]=(T[i-1][j])||(T[i-1][j-arr[i]]) ;
			}
		}
	}

	return T[n-1][m] ;
}

int main()
{
	int n;
	cout<<"Enter n : ";
	cin>>n ;
	int arr[500] ;
	cout<<"Enter elements : "<<endl ;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i] ;
	}
	int sum=0 ;
	for(int i=0;i<n;i++)
	{
		sum=sum+arr[i] ;
	}
	if(sum%2==1)
	{
		cout<<"false"; return 0 ;
	}
	bool x = equalPartitionSum(n,arr,sum/2) ;
	if(x==true) cout<<"TRUE" ;
	else cout<<"False" ;
	return 0 ;
}

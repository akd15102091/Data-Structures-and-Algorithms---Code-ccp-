#include<iostream>
using namespace std ;

void countingSort(int a[],int n)
{
	int k = INT_MIN ;
	for(int i=0;i<n;i++)
	{
		if(a[i]>k) k = a[i] ;
		
	}
	int count[k+1] ={0} ;
	for(int i=0;i<n;i++)
	{
		count[a[i]] ++ ;

	}	

	// update count array 
	for(int i=1;i<=k;i++)
	{
		count[i]= count[i] +count[i-1] ;
	}		

	int B[500] ;
	for(int i=n-1;i>=0;i--)
	{
		
		int x = count[a[i]] -1;
		B[x] = a[i] ;
		count[a[i]] -- ;
	}	
	
	for(int i=0;i<n;i++)
	{
		cout<<B[i]<<" ";
	}
	
}

int main()
{
	int n ;
	cin>>n ;
	int a[500] ;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}
	countingSort(a,n) ;
	return 0 ;
}
/*
17
2 1 1 0 2 5 4 0 2 8 7 7 9 2 0 1 9 
*/

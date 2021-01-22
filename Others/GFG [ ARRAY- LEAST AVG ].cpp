#include<iostream>
using namespace std ;

void leastAvgSubarray(int a[],int n,int k)
{
	if(n<k)
	{
		cout<<"No subarray ...!!" ;
		return ;
	}
	int l,r ;
	float least ;
	least = INT_MAX ;
	
	int i=0 ;
	float sum=0 ;
	while(i<k)
	{
		sum = sum+a[i] ;
		i++ ;
	}
	float avg ;
	avg = sum/k ;
	if(least > avg)
	{
		least = avg ;
		l=0 ;
		r=k-1 ;
	}
	
	while(i<n)
	{
		avg = avg*k ;
		avg = avg-a[i-k]+a[i] ;
		avg = avg/k ;
		
		if(least>avg)
		{
			least = avg ;
			l = i-k+1 ;
			r = i ;
		}
		i++ ;
	}
	
	cout<<"Least average : "<<least<<endl;
	cout<<"that subarray is : "<<l<<" to "<<r<<endl;
	
}

int main()
{
	int n , k ; 
	cout<<"Enter n : "<<endl;
	cin>>n ;
	int a[n] ;
	cout<<"Enter the elements : "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}
	cout<<"Enter k : "<<endl ;
	cin>>k ;
	leastAvgSubarray(a,n,k) ;
}

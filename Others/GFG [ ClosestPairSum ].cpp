#include<iostream>
#include<algorithm>
using namespace std ;

void closestPairSum(int a[],int l,int r,int &x,int &y,int key)
{
	int minDiff = INT_MAX ;
	int i=l ;
	int j=r ;
	while(l<=r)
	{
		if(abs(a[l] +a[r] -key) < minDiff)
		{
			x = a[l] ;
			y = a[r] ;
			minDiff = abs(a[l] +a[r] -key) ;
		}
		if((a[l]+a[r])<key)
		{
			l++ ;
		}
		else if((a[l]+a[r])>key)
		{
			r-- ;
		}
		else break ; // if minDiff==0
	}	
}

int main()
{
	int n; ;
	int a[500] ;
	cin>>n ;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}
	int key ;
	cin>>key ;
	int x=0,y=0 ;
	closestPairSum(a,0,n-1,x,y,key) ;
	cout<<"Closest Pair Sum is : "<<x<<" , "<<y<<endl ;
	return 0 ;
}

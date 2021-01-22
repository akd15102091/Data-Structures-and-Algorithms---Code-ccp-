#include<iostream>
#include<climits>
#include<algorithm>
using namespace std ;
int randomPartition(int arr[], int l, int r); 
void swap(int &a,int &b)
{
	int temp = a ;
	a=b ;
	b=temp ;
}

int Partition(int a[],int l,int r)
{
	int x = a[r] ;
	int i=l-1 ;
	for(int j=l;j<=r-1;j++)
	{
		if(a[j]<=x)
		{
			i++ ;
			swap(a[j],a[i]) ;
		}
	}
	swap(a[i+1],a[r]) ;
	return (i+1) ;
}
int randomPartition(int arr[], int l, int r) 
{ 
    int n = r-l+1; 
    int pivot = rand() % n; 
    swap(arr[l + pivot], arr[r]); 
    return Partition(arr, l, r); 
} 
int KthSmallestElement(int a[],int l,int r,int k)
{
	if(k>0 && k<=(r-l+1))
	{
		int pos = randomPartition(a,l,r) ;
		if(pos-l == k-1)
		{
			return a[pos] ;
		}
		else if(pos-l > k-1)
		{
			return KthSmallestElement(a,l,pos-1,k) ;
		}
		else
		{
			return KthSmallestElement(a,pos+1,r,k-pos+l-1) ;
		}	
	}
	return INT_MAX ;// return if k is greater than no of elements
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
	int k ;
	cin>>k ;
	int x = KthSmallestElement(a,0,n-1,k) ;
	cout<<"Kth smallest element is : "<<x<<endl;
}

#include<iostream>
using namespace std ;

int maxSubArraySum(int nums[],int n) 
{
    int meh = 0 ;
    int msf = INT_MIN ;
    
    for(int i=0;i<n;i++)
    {
       meh = meh+nums[i] ;
        if(meh < nums[i]) meh = nums[i] ;
        if(msf<meh) msf = meh ;
    }
    return msf ;
}

int main()
{
	int n; 
	cout<<"Enter n : "<<endl ;
	cin>>n ;
	int arr[n] ;
	cout<<"Enter the elements : "<<endl ;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i] ;
	}
	int x =  maxSubArraySum(arr,n) ;
	cout<<"Max contigous subarray sum : "<<x << endl;
	return 0;
}

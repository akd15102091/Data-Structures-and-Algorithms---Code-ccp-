#include<iostream>
#include<cmath>
using namespace std ;

void segment_tree_array( int ip[] , int st[] , int low , int high , int pos )
{
	if(low == high)
	{
		st[pos] = ip[low]  ;
		return ;
	}
	int mid = (low + high) / 2  ;
	segment_tree_array( ip , st , low , mid , 2*pos +1 ) ;
	segment_tree_array( ip , st , mid+1 , high , 2*pos +2 ) ;
	st[pos] = ( st[2*pos +1] ) + ( st[2*pos +2] ) ;
	 
}
int sum_range_quary( int st[] , int qlow , int qhigh , int low , int high ,int pos )
{
	if( qlow<=low && qhigh >= high)
	{
		return st[pos] ;
	}
	if( low>qhigh  ||  high<qlow )
	{
		return 0 ;  //very big number  	
	}	

	int mid = (low + high) / 2   ;
	return ((sum_range_quary(st , qlow , qhigh , low , mid , 2*pos +1)) + (sum_range_quary(st , qlow , qhigh , mid+1 , high , 2*pos +2)) ) ;
}

int main()
{
	int n ;
	cout<<" ENter no. of inputs : "<<endl ;
	cin>> n ;
	cout<<"Enter elements of input array : "<<endl ;
	int ip[50] ;  // input array //
	for(int i=0 ; i<n; i++)
	{
		cin>> ip[i] ;
	}
	int temp ;
	int cnt =0;
	for(int i=0;i<100;i++)
	{
		int y = pow(2,i) ;
		if(n == y)
		{cnt++ ;
			break ;
		}
	}
	if(cnt==1) temp = n ;
//	else cout << "NOt p"
	else
	{
		temp = pow( 2,(int(log2(n)))+1 )  ;
		for(int i=n;i<temp;i++)
		{
			ip[i] = 0;
		}
	}

	int x ;

	x = 2*temp-1 ;
	
	int st[x] ;  
	segment_tree_array(ip ,st , 0 , temp-1 , 0) ;
	for(int i=0;i<x;i++)
	{
		cout<<st[i]<<"  ";
	}
	cout<<endl ;
	cout<<"Enter the range : (qlow  and   qhigh ) "<<endl ;
	int qlow , qhigh ;
	cin>> qlow >> qhigh ;
	int sum_value = sum_range_quary( st , qlow , qhigh , 0 , temp-1 , 0 )  ;
	
	cout<<"In given range , sum_value is : "<< sum_value <<endl ;
	return 0 ;
}
// 7    //  -2 3 -4 -3 0 2 1
// 9 //  -4 3 -7 0 4 6 5 -1 -2



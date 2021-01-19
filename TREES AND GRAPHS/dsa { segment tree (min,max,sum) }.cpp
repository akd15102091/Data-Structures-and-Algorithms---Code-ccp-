#include<iostream>
#include<cmath>
using namespace std ;
int z ;
struct segment 
{
	int gcd ;
	int max ;
	int min ;
	int sum ;
}  st[50] ;

int gcd(int a ,int b)
{
	for(int i=a;i>=1 ;i--)
	{
		if(a%i ==0  && b%i == 0)
		{
			return i ;	
		}	
	}	
}

void segment_tree_array( int ip[] , struct segment st[] , int low , int high , int pos )
{
	if(low == high)
	{
		if(ip[low] == -1)
		{
			st[pos].gcd = z ;
			st[pos].max= 0  ;
			st[pos].min = 10000 ;
			st[pos].sum = 0 ;
			return;
		}
		st[pos].gcd = ip[low] ;
		st[pos].max= ip[low]  ;
		st[pos].min = ip[low] ;
		st[pos].sum = ip[low] ;
		return ;
	}
	int mid = (low + high) / 2  ;
	segment_tree_array( ip , st , low , mid , 2*pos +1 ) ;
	segment_tree_array( ip , st , mid+1 , high , 2*pos +2 ) ;
	st[pos].sum = ( st[2*pos +1].sum ) + ( st[2*pos +2].sum ) ;
	st[pos].min = min(( st[2*pos +1].min ) , ( st[2*pos +2].min ) );
	st[pos].max = max(( st[2*pos +1].max ) , ( st[2*pos +2].max ) );
	st[pos].gcd = gcd( ( st[2*pos +1].gcd ) , ( st[2*pos +2].gcd ) ) ;
	 
}
struct segment  sum_range_quary( struct segment st[] , int qlow , int qhigh , int low , int high ,int pos )
{
	if( qlow<=low && qhigh >= high)
	{
		return st[pos] ;
	}
	if( low>qhigh  ||  high<qlow )
	{
		struct segment s ;
		s.gcd = z ;
		s.max = 0;
		s.sum =0 ;
		s.min = 10000 ;
		return s  ;  //very big number  	
	}	

	int mid = (low + high) / 2   ;
	struct segment result ;
	result.sum = (sum_range_quary(st , qlow , qhigh , low , mid , 2*pos +1)).sum + (sum_range_quary(st , qlow , qhigh , mid+1 , high , 2*pos +2)).sum ;
	result.min =min( (sum_range_quary(st , qlow , qhigh , low , mid , 2*pos +1)).min ,  (sum_range_quary(st , qlow , qhigh , mid+1 , high , 2*pos +2)).min ) ;
	result.max = max((sum_range_quary(st , qlow , qhigh , low , mid , 2*pos +1)).max , (sum_range_quary(st , qlow , qhigh , mid+1 , high , 2*pos +2)).max ) ;
	result.gcd = gcd( (sum_range_quary(st , qlow , qhigh , low , mid , 2*pos +1)).gcd , (sum_range_quary(st , qlow , qhigh , mid+1 , high , 2*pos +2)).gcd) ;
	return ( result ) ;
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
	z = ip[n-1] ;
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
			ip[i] = -1;
		}
	}

	int x ;

	x = 2*temp-1 ;
	
	//int st[x] ;  
	segment_tree_array(ip ,st , 0 , temp-1 , 0) ;
	for(int i=0;i<x;i++)
	{
		cout<<st[i].max<<"  "<<st[i].min <<" "<<st[i].sum <<" "<<st[i].gcd<<" @@@ ";
	}
	cout<<endl ;
	cout<<"Enter the range : (qlow  and   qhigh ) "<<endl ;
	int qlow , qhigh ;
	cin>> qlow >> qhigh ;
	struct segment values = sum_range_quary( st , qlow , qhigh , 0 , temp-1 , 0 )  ;
	
	cout<<"In given range , sum_value is : "<< values.sum <<endl ;
	cout<<"In given range , min_value is : "<< values.min <<endl ;
	cout<<"In given range , max_value is : "<< values.max <<endl ;
	cout<<"In given range , gcd_value is : "<< values.gcd <<endl ;
	return 0 ;
}
// 7    //  -2 3 -4 -3 0 2 1
// 9 //  -4 3 -7 0 4 6 5 -1 -2



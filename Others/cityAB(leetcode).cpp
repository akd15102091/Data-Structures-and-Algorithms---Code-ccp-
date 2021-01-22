#include<iostream>
#include<cmath>
using namespace std ;
struct ABcity
{
	int ca ;// cost for city A
	int cb ;// cost for city B
	
} arr[500] ;
int main()
{
	int n ;
	cin>>n ;
	int k = 2*n ;
	for(int i=0;i<k;i++)
	{
		cin>>arr[i].ca >>arr[i].cb ;
	}
	
	// now we will sort this array of structure using difference  ( absolute(a-b) )
	
	for(int i=0;i<k-1;i++)
	{
		for(int j=0;j<k-i-1;j++)
		{
			if((abs(arr[j].ca - arr[j].cb)) > (abs(arr[j+1].ca - arr[j+1].cb)))
			{
				struct ABcity temp ;
				temp = arr[j] ;
				arr[j] = arr[j+1] ;
				arr[j+1] = temp ;
			}
		}
	}
	
	int cnta=0 ; // count in city A
	int cntb=0 ; // count in city B
	int minCost = 0 ; // required minimum cost
	int i=k-1 ; // iterate sorted structre from last
	int c=0;
	while(i>=0)
	{ c++ ;
		if((arr[i].ca > arr[i].cb) && cntb<n)
		{
			minCost += arr[i].cb ;
			cntb++ ;
		}
		else if(cntb>=n && cnta<n)
		{
			minCost += arr[i].ca ;
			cnta++ ;
		}
		
		if((arr[i].ca < arr[i].cb) && cnta<n)
		{
			minCost += arr[i].ca ;
			cnta++ ;	
		}
		else if(cnta>=n && cntb<n)
		{
			minCost += arr[i].cb ;
			cntb++ ;
		}
		i-- ;
	}
	cout<<minCost<<endl;
	cout<<cnta<<" "<<cntb<<endl;
	return 0 ;
	
	 
}
/*
2
10 20
30 200
400 50
30 20

ans:: 110
*/

/*
3
10 20
30 200
400 50
30 20
20 40
40 50

ans:: 180
*/

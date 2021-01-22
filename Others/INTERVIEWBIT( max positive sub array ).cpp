#include<iostream>
#include<vector>
#include<utility>
using namespace std ;

void maxSet(vector<int> A)
{
	int n = A.size() ;
	vector<pair<int,int> > vec ;
	int i=0;
	while(A[i]<0) i++ ;
	while(i<n)
	{
		int j=i+1;

		while(j<n && A[j]>0)
		{
			j++ ; 
		}
		vec.push_back(make_pair(i,j-1)) ;
		while(A[j]<0) j++ ;
		i=j ;
	}
	int m = vec.size() ;
	
	for(int k=0;k<m;k++)
	{
		cout<<vec[k].first <<" "<<vec[k].second <<endl;
	}
	vector<int> sum ;
	for(int k=0;k<m;k++)
	{
		int x = vec[k].first ;
		int y = vec[k].second ;
		
		int val=0 ;
		for(int z=x;z<=y;z++)
		{
			val +=A[z] ;
		}
		sum.push_back(val) ;
	}
	
	int sl,el,maxSum ;
	sl=vec[0].first ;
	el=vec[0].second ;
	maxSum=sum[0] ;
	
	for(int k=1;k<m;k++)
	{
		if(sum[k] > maxSum)
		{
			sl=vec[k].first ;
			el=vec[k].second ;
			maxSum = sum[k] ;
		}
		else if(sum[k] == maxSum)
		{
			if((vec[k].second - vec[k].first +1) > (el-sl+1))
			{
				sl=vec[k].first ;
				el=vec[k].second ;
				maxSum = sum[k] ;
			}
		}
	}
//	cout<<sl<<" "<<el<<endl;
	// Answers
	cout<<"max sum of non-negative subarray : "<<maxSum <<endl;
	cout<<"That subarray is : ";
	for(int k=sl;k<=el;k++)
	{
		cout<<A[k]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n ;
	vector<int> vec ;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x ;
		cin>>x ;
		vec.push_back(x) ;
	}
	
	maxSet(vec) ;
	
}
/*
6
-54961 3510 -50805 -82137 -39096 -47421
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
//int perfectSum(int a[],int i,int sum)
//{
//	if(sum==0)
//	{	
//		return 1 ;
//	}
//	if(sum<0)
//	{
//		return 0 ;
//	}
//	if(i<0) return 0 ;
//	
//	
//	if(a[i] > sum)
//	{
//		return perfectSum(a,i-1,sum) ;
//	}
//	else return (perfectSum(a,i-1,sum-a[i]) + perfectSum(a,i-1,sum) ) ;
//}

int perfectSum(int a[],int n,int sum)
{
//	int dp[n+1][sum+1] ;
	vector<vector<int> > dp ;
	for(int i=0;i<=n;i++)
	{
		vector<int> v ;
		for(int j=0;j<=sum;j++)
		{
			v.push_back(0) ;
		}
		dp.push_back(v) ;
	}
	for(int i=0;i<=sum;i++)
	{
		dp[0][i] = 0 ;
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][0] = 1 ;
	}
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			
			if(j<a[i-1])
			{
				dp[i][j] = dp[i-1][j] ;
			}
			else
			{
				dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]] ;
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
	}
	
	return dp[n][sum] ;
	
}

int main()
{
	int t ;
	cin>>t ;
	while(t--)
	{
		int n ;
		cin>>n ;
		int a[n] ;
		for(int i=0;i<n;i++)
		{
			cin>>a[i] ;
		}
		
		int sum ;
		cin>>sum ;
		sort(a,a+n) ;
		int cnt=0 ;
		cnt = perfectSum(a,n,sum) ;
		cout<<cnt<<endl ;
	}
}
/*
1
6
2 3 5 6 8 10
10
*/


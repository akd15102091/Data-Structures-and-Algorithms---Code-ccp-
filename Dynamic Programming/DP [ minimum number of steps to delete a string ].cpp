
// problem  : Minimum steps to delete a string after repeated deletion of palindrome substrings

#include<iostream>
#include<cstring>
using namespace std ;

int minSteps(string str,int n)
{
	int dp[n+1][n+1] ;

	for(int i=0;i<=n;i++) 
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j] = 0 ;
		}
	}
	
	for(int len=1 ;len<=n;len++)
	{
		// loop with two variables i and j, denoting 
        // starting and ending of substrings 
		for(int i=0,j=len-1;j<n;j++,i++)
		{
			if(len==1) dp[i][j]=1 ;
			else
			{
				dp[i][j] = 1+dp[i+1][j] ;
				if(str[i]==str[i+1])
				{
					dp[i][j] = min(1+dp[i+2][j],dp[i][j]) ;
				}
				for(int k=i+2;k<=j;k++)
				{
					if(str[i]==str[k])
					{
						dp[i][j] = min(dp[i+1][k-1]+dp[k+1][j], dp[i][j]) ;
					}
				}
			}
		}
	}
	return dp[0][n-1] ;
}

int main()
{
	string str ;
	cin>>str ;
	int n = str.length() ;
	int x = minSteps(str,n) ;
	cout<<"minimum number of steps to delete a string : "<<x<<endl;
	return 0;
}

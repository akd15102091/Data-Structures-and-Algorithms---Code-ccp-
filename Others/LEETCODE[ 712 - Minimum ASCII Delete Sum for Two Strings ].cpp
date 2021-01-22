#include<iostream>
using namespace std ;

int minimumDeleteSum(string s1, string s2) 
    {
        int n1 = s1.length() ;
        int n2 = s2.length() ;
        int dp[n1+1][n2+1] ;
        dp[0][0] = 0 ;
        for(int i=1;i<=n1;i++)
        {
            dp[i][0] = dp[i-1][0] + s1[i-1] - 0 ;
        }
        for(int j=1;j<=n2;j++)
        {
            dp[0][j] = dp[0][j-1] + s2[j-1] - 0 ;
        }
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] ;
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j]+s1[i-1]-0 ,dp[i][j-1]+s2[j-1]-0) ;
                }
            }
        }
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                cout<<dp[i][j]<<"  ";
            }
            cout<<endl;
        }
        
        cout<<endl;
        
        return dp[n1][n2] ;
    }

int main()
{
	string s1,s2 ;
	cin>>s1 ;
	cin>>s2 ;
	int ans = minimumDeleteSum(s1,s2);
	cout<<ans;
	
	return 0;
}

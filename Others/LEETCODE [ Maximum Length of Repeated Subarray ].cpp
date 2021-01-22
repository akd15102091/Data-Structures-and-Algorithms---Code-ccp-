#include<iostream>
#include<vector>
using namespace std ;

int findLength(vector<int>& A, vector<int>& B) 
    {
        int n1 = A.size() ;
        int n2 = B.size() ;
        int dp[n1+1][n2+1] ;
        for(int i=0;i<=n1;i++)
        {
            dp[i][0] = 0 ;
        }
        for(int i=0;i<=n2;i++)
        {
            dp[0][i] = 0 ;
        }
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                dp[i][j] = 0 ;
            }
        }
        int ans=0;
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(A[i-1]==B[j-1]) dp[i][j] = dp[i-1][j-1] + 1 ;
                if(ans<dp[i][j]) ans = dp[i][j] ;            
            }
        }
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                cout<<dp[i][j]<<"  ";
            }
            cout<<endl;
        }
        return ans  ;
    }

int main()
{
	vector<int> A,B ;
	int n1,n2 ;
	cin>>n1>>n2 ;
	
	for(int i=0;i<n1;i++)
	{
		int x ;
		cin>>x ;
		A.push_back(x) ;
	}
	for(int i=0;i<n2;i++)
	{
		int x ;
		cin>>x ;
		B.push_back(x) ;
	}
	
	int ans = findLength(A,B) ;
	cout<<endl<<ans;
	
	return 0;
}

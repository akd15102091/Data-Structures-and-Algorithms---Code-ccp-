#include<iostream>
#include<cstring>
using namespace std ;

int countNoOfAllPalindromicSubstring(string str,int n)
{
	bool T[n][n] ;
	memset(T, false , sizeof(T));
	int dp[n][n] ;
	memset(dp, 0 , sizeof(dp));

	for(int i=0;i<n;i++) 
	{
		T[i][i] = true ;
	}
	// for length 2
	for(int i=0;i<n-1;i++)
	{
		if(str[i]==str[i+1])
		{
			T[i][i+1] = true ;
			dp[i][i+1] = 1 ;
		}
	}
	// for length > 2
	 for (int k=2 ; k<n; k++) 
    { 
        for (int i=0; i<n-k; i++) 
        {  // Set ending point 
            int j = k + i; 
  
            // If current string is palindrome 
            if (str[i] == str[j] && T[i+1][j-1] ) 
                T[i][j] = true; 
  
            // Add current Palindrome substring ( + 1) 
            // and rest Palindrome substring (dT[i][j-1] + dT[i+1][j]) 
            // remove common Palindrome substrings (- dT[i+1][j-1]) 
            if (T[i][j] == true) 
                dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1 - dp[i+1][j-1]; 
            else
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]; 
        } 
    } 
	return ( n + dp[0][n-1] );
}

int main()
{
	string str ;
	cin>>str ;
	int n = str.length() ;
	int x = countNoOfAllPalindromicSubstring(str,n) ;
	cout<<"Total number of palindrome substring in a string : "<<x<<endl;
	return 0;
}

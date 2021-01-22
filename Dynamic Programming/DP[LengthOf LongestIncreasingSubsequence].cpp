#include<iostream>

using namespace std ;
int main()
{
	int n ;
	cin>>n ;
	int a[500] ,T[500];
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
		T[i] = 1 ;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{
				int a = T[j]+1 ;
				int b=T[i] ;
				
				T[i]=(a>b ? a:b) ;
			}
		}
	}
	int value=0 ;
	for(int i=0;i<n;i++)
	{
		if(value<T[i]) value = T[i] ;
	}
	cout<<"Length of Longest increasing subsequence : "<<value<<endl; 
	return 0 ;
}
/*
Longest common subsequence

int longestCommonSubsequence(string text1, string text2) 
    {
        int c=0;
        int k = 0 ;
        while(text1[k]!='\0')
        {
            k++ ;
            c++ ;
        }
        int len1 = k  ;
         c=0;
         k = 0 ;
        while(text2[k]!='\0')
        {
            k++ ;
            c++ ;
        }
       // int len2 = strlen(len2) ;
        int len2 = k ;
        int lcs[len1+1][len2+1], i, j;
        for (i = 0; i <= len1; i++)
        {
            for (j = 0; j <= len2; j++)
            {
                if (i == 0 || j == 0)
                    lcs[i][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                else
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }

        }
            return lcs[len1][len2] ;
        }
*/

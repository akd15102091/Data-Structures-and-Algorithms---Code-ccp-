#include<iostream>
#include<cstring>
using namespace std ;

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
       
       cout<<"Commom subsequence : "<<endl ;
      int p=len1,q = len2 ;
	while(p!=0 && q!=0)
	{
		if(lcs[p][q]==lcs[p][q-1]) q = q-1 ;
		else if(lcs[p][q]==lcs[p-1][q]) p = p-1 ;
		else
		{
			cout<<text2[q-1]<<" ";
			p-- ;
			q-- ;
		}
	}
       
       
            return lcs[len1][len2] ;
}

int main()
{
	string str1,str2 ;
	cout<<"Enter string 1 : "<<endl;
	cin>>str1 ;
	cout<<"Enter string 2 : "<<endl ;
	cin>>str2 ;
	int x = longestCommonSubsequence(str1,str2) ;
	cout<<endl ;
	cout<<"LEngth is : "<<x<<endl ;
	
}


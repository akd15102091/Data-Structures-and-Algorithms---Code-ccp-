#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std ;
bool palindrome(string str)
{
    int i = 0 ;
    int j = str.length()-1 ;
    while(i<=j)
    {
        if(str[i] != str[j])
        {
            return false ;
        }
        i++;
        j--;
    }
    return true ;
}
int solve(string A) 
{
    int n = A.length() ;
    int cnt=0 ;
    
    bool x = palindrome(A) ;
    
    if(x==true) return 0 ;
    reverse(A.begin(),A.end()) ;
    
    int ind=0 ;
    while(ind<n-1)
    {
        A +=A[ind] ;
       // cout<<A<<endl;
        cnt++ ;
        if(palindrome(A))
        {
            break ;
        }
        ind++ ;
    }
    return cnt ;
}

int main()
{
	string str;
	cin>>str ;
	int val = solve(str) ;
	cout<<val;
}

#include <iostream>
#include<algorithm>
using namespace std;

int main() 
{
    int t ;
    cin>>t ;
    while(t--)
    {
        int n ;
        cin>> n;
        int a[n] ;
        for(int i=0;i<n;i++)
        {
            cin>>a[i] ;
        }
        
        sort(a,a+n) ;
        
        int i = n-1 ;
        int s1=0 ;
        int s2=0 ;
        
        s1 = s1+ a[i] ;
        i-- ;
        
        while(i>=0)
        {
            while(s2<s1 && i>=0)
            {
                s2 = s2+a[i] ;
                i-- ;
            }
            while(s2>=s1 && i>=0)
            {
                s1 = s1+a[i] ;
                i-- ;
            }
        }
        cout<<abs(s1-s2) <<endl;
        
    }
    	
	return 0;
}

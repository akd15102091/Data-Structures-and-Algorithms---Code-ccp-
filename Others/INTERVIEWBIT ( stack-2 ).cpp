#include<iostream>
#include<stack>
#include<cstring>
using namespace std ;
int main()
{
	string A ;
	cin>> A ;
	int cnt1 = 0 ;
    int cnt2 = 0 ;
    if((A[0]=='(' || A[2]==')' )&& A.length()==3) cout<<"0" ;
    int i=0 ;
    stack<int> s ;
    while(i<A.length())
    {
        int x=0 ;
        while(A[i]=='(')
        {
            s.push(A[i]) ;
            x++ ;
            i++ ;
        }
        if(x>=2) cnt1=x ;
        
        int y=0 ;
        while(A[i]==')')
        {
            s.pop() ;
            y++ ;
            i++ ;
        }
        if(y>=2) cnt2=y ;
        else i++ ;
        
    }cout<<"@";
    cout<<cnt1<<" "<<cnt2<<endl;
    if(cnt1!=0 && cnt2!=0 && cnt1==cnt2)
    {
        cout<<"1";
    }
    else cout<<"0" ;
}

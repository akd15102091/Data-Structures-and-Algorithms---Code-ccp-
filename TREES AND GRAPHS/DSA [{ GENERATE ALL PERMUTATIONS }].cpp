#include<iostream>
#include<string>
using namespace std ;

void permutations( string s , int l ,int r)
{
	if(l==r) cout<<s<<endl ;
	else
	{
		for(int i=l ;i<=r ;i++)
		{
			swap(s[l] , s[i]) ;
			permutations( s, l+1 ,r) ;
			swap( s[l] , s[i]) ;
		}
	}
}

int main()
{
	string str ;
	cin>>str ;
	int n = str.length() ;
	cout<<"All permutations are : "<<endl ;
	permutations(str,0,n-7) ;
}

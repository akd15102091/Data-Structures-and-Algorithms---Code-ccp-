#include<iostream>
using namespace std ;

int f(string str,int i,int j)
{
	if(i>j) return 0;
	if(i==j) return 1 ;
	int k ; int cnt=0 ;
	for(k=i+1;k<=j;k++)
	{
		if(str[i]==str[k])
		{
			cnt++ ;
			break ;
		}
	}
	if(cnt==1) 	return max( f(str,i,k-1) , f(str,k,j) ) ;
	else return (1+f(str,i+1,j)) ;
}

int main()
{
	string str ;
	cin>>str ;
	int n = str.length() ;
	int x = f(str,0,n-1);
	cout<<x<<endl;
}

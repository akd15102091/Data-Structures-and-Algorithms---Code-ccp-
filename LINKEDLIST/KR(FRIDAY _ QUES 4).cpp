#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int a[50] ;
	int i=0,n;
	cout<<"Enter the value of n : "<<endl;
	cin>>n ;
	cout<<"Enter the elements : "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}
	int k;
	cout<<"Enter the value of K "<<endl;
	cin>>k ;
	stack<int> s;
	int p=0 ;
	for(int j =0 ; j<n-k+1 ;j++)
	{
		p=j ;
	for(int i=p ; i< k+p ;i++)
	{
		s.push(a[i]) ;
	}
	int x = s.top() ;
	s.pop() ;
	while(!s.empty())
	{
		if(x > s.top())
		{
			s.pop() ;
		}
		else
		{
			x=s.top() ;
			s.pop() ;
		}
	}
	cout<< x ;
	}
	
}

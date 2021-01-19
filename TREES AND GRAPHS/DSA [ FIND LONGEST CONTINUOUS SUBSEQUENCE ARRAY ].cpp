#include<iostream>
using namespace std ;
int main()
{
	cout<<"enter lagest number in set "<<endl ;
	int t ;
	cin>> t;
	int a[t] ;
	for(int i=0 ;i<t;i++)
	{
		a[1] = 0 ;
	}
	cout<<"Enter how many numbers you want to enter "<<endl ;
	int n;
	cin>>n;
	cout<<"enter elements : "<<endl ;
	for(int i=0;i<n;i++)
	{
		int x ;
		cin>> x ;
		a[x] = 1 ;
	}
	int max =0  ;
	for(int i=0;i<t;i++)
	{
		int count = 0 ;
		if(a[i] == 1)
		{
			while(a[i]==1)
			{
				count++ ;
				i++ ;
			}
			if(count>max) max = count ;
		}
	}
	cout<<" longest continuous subsequeence array length "<<max ;
	return 0 ;
}
// 45 // 11 // 1 21 3 8 7 4 45 5 9 2 20

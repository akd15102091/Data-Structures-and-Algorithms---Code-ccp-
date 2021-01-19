#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int lmin ;
	int data ;
	int rmax ;
};


 
int main()
{	queue<node> q;
    struct node s  ;
	int a[50] ,n ;
	cout<<"Enter the number of elements / (nodes) "<<endl;
	cin>>n;
	cout<<"ENter the elements "<<endl;
	for(int i=0 ; i<n ; i++)
	{
		cin>>a[i] ;
	}
	 s.lmin = 0 ;
    s.rmax =1000 ;
	s.data = a[0] ;
	q.push(s) ;
	int j=1;
	while( !q.empty() )
	{	node temp = q.front() ;
	    cout<<temp.lmin<<" "<<temp.data<<" "<<temp.rmax <<endl;//this line will give the range of each node data//
		q.pop() ;
		if(a[j] < temp.data && a[j] >= temp.lmin )
		{	
			node t  ;
			t.data = a[j] ;
			t.lmin = temp.lmin ;
			t.rmax = (temp.data) - 1 ;
			q.push(t) ;
			j++ ;
		}
		
		if(a[j] > temp.data && a[j] <= temp.rmax )
		{	
			node t  ;
			t.data = a[j] ;
			t.lmin = (temp.data) + 1 ;
			t.rmax = temp.rmax ;
			q.push(t) ;
			j++ ;
		}
	}
	if(j==n) cout<<"Yes" ;
	else cout<<"no" ;
	
	return 0;
}

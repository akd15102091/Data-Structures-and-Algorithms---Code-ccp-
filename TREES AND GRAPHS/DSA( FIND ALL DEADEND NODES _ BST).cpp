#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int lmin ;
	int data ;
	int rmax ;
};

/*bool check_bst(int a[] ,int i ,int n , int &min ,int &max)
{	if(i == n-1) return true;

	if(!(a[i] >min) || !(a[i]<max))
	{
		return false ;
	}
	if(a[i+1] < a[i])
	{
		max = a[i] - 1 ;
		return (check_bst(a , i+1 ,n, min ,max)) ;
	}
	if(a[i+1] > a[i])
	{
		min = a[i] +1 ;
		return (check_bst(a,i+1 , n , min , max)) ;
	}
}*/
 
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
	cout<<"Dead end nodes elements : ";
	while( !q.empty() )
	{	node temp = q.front() ;
	    if(((temp.rmax) - (temp.lmin))<=1)
	    {
	    	cout<<temp.data<<" " ;
		}
	    //cout<<temp.lmin<<" "<<temp.data<<" "<<temp.rmax <<endl;//this line will give the range of each node data//
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
	cout<<endl;
	if(j==n) cout<<"Yes" ;
	else cout<<"no" ;
	
	
}

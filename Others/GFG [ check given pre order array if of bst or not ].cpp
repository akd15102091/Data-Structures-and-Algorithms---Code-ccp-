#include<iostream>
#include<stack>
using namespace std;


bool checkPreOfBst(int pre[],int n)
{
	if(n==0) return true ;
	stack<int> s ;
	int root = INT_MIN ;
	for(int i=0;i<n;i++)
	{
		if(root>pre[i]) return false ;
		while(!s.empty() && s.top()<pre[i])
		{
			root = s.top() ;
			s.pop() ;
		}
		s.push(pre[i]) ;
	}
	return true ;
}

int main()
{   
    int n ;
    int pre[500] ;
	cout<<"ENter how many number in pre order array : "<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cin>>pre[i] ;
	}
	bool x = checkPreOfBst(pre,n) ;
	if(x==true) cout<<"Correct"<<endl; 
	else cout<<"Incorrect"<<endl ;
    return 0;  
}
		


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
vector<int> function(vector<int> A) 
{
    int n = A.size() ;
    vector<int> B ;
    for(int i=0;i<n;i++)
    {
        B.push_back(A[i]) ;
    }
    if(n==1)
    {
        vector<int> vec ;
        vec.push_back(-1) ;
        return vec ;
    }
    sort(B.begin(),B.end()) ;
    
    int l=0 ;
    int r=n-1 ;
    int le=0,cntl=0;
    int re=0 ,cntr=0;
    while(A[l]==B[l] && l<n)
    {
    	l++ ;
    }
    while(A[r]==B[r] && r>=0)
    {
    	r-- ;
    }
    le=l ;
    re=r ;
    vector<int> result ;
    if(re-le<1)
    {
        result.push_back(-1) ;
        return result ;
    }
    else
    {
        result.push_back(le) ;
        result.push_back(re) ;
        return result ;
    }
    
    
}


int main()
{
	int n ;
	vector<int> vec ;
	
	cin>> n;
	for(int i=0;i<n;i++)
	{
		int x ;
		cin>>x ;
		vec.push_back(x) ;
	}
vector<int> rs =	function(vec) ;
cout<<endl;
	for(int i=0;i<rs.size();i++)
	{
		cout<<rs[i]<<" ";
	}

}
/*
14
3 3 4 5 5 9 11 13 14 15 15 16 15 20 16
*/

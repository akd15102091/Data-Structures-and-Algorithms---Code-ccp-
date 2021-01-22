#include<iostream>
#include<cstring>
#include<vector>
using namespace std ;
int func(string A)
{
	int n = A.length() ;
    if(n==0 || n==1) return 1 ;
    vector<char> vec ;
    vec.clear() ;
  cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
        if((A[i]>=65 && A[i]<=90)|| (A[i]>=48 && A[i]<=57)||(A[i]>=97 && A[i]<=122))
        {
            vec.push_back(A[i]) ;
        }
    }
    int x = 0 ;
    int y = vec.size() -1 ;
    for(int i=0;i<=y;i++)
    {
       cout<<vec[i]<<" ";
    }
    while(x<y)
    {
    	if(vec[x] != vec[y]) return 0 ;
    	x++ ;y-- ;
	}
	return 1 ;
}
int main()
{
	string str="A man, a plan, a canal: Panama" ;
	int x = func(str) ;
	cout<<x ;
}

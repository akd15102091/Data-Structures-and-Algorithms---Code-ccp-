#include<iostream>
#include<map>
#include<utility>
#include<vector>
using namespace std ;
bool funct(vector<int> arrive,vector<int> depart ,int K)
{
	int n = arrive.size() ;
	map<int,int> mp ;
	for(int i=0;i<n;i++)
    {
        mp[arrive[i]] += 1 ; 
        mp[depart[i]] -= 1 ;
    }
    map<int,int> :: iterator itr ;
    vector<pair<int,int> >vec ;
    for(itr=mp.begin() ;itr!=mp.end() ;itr++)
    {
    	vec.push_back({itr->first,itr->second}) ;
	}
//	 for(itr=mp.begin() ;itr!=mp.end() ;itr++)
//    {
//    	cout<<itr->first <<" "<<itr->second<<endl ;
//	}
	int m = vec.size() ;
	vector<int>result ;
	for(int i=0;i<m;i++)
	{
		result.push_back(0) ;
	}
	result[0] = vec[0].second ;
	
    for(int i=1;i<m;i++)
    {
        result[i] = result[i-1] + vec[i].second  ;
    }
    int cnt=0 ;
    for(int i=0;i<m;i++)
    {
        if(result[i] >K)
        {
            cnt++ ;
        }
    }
    if(cnt==0) return true ;
    else return false ;
}
int main()
{
	int n;
	cin>>n;
	vector<int> vec1,vec2 ;
	for(int i=0;i<n;i++)
	{
		int x ;
		cin>>x ;
		vec1.push_back(x) ;
	}
	for(int i=0;i<n;i++)
	{
		int x ;
		cin>>x ;
		vec2.push_back(x) ;
	}
	int k ;
	cin>>k ;
	bool y = funct(vec1,vec2,k) ;
	cout<<endl;
	if(y==true) cout<<"true" ;
	else cout<<"false" ;
	
}

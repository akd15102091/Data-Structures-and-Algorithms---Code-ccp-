#include<iostream>
#include<vector>
#include<map>
#include<iterator>

using namespace std ;

void pairWithEqualSum(vector<int>arr,int n)
{
	map<int,vector<pair<int,int> > > mp ;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			pair<int,int> p = make_pair(arr[i],arr[j]) ;
			if((mp[arr[i] + arr[j]]).size() ==0)
			{
				(mp[arr[i] + arr[j]]).push_back(p) ;

			}
			else if((mp[arr[i] + arr[j]])[(mp[arr[i] + arr[j]]).size()-1] !=p )
			{
							(mp[arr[i] + arr[j]]).push_back(p) ;

			}
		}
	}
	
	map<int,vector<pair<int,int> > > :: iterator itr ;
	for(itr=mp.begin();itr!=mp.end();itr++)
	{
		if(itr->second.size() >1)
		{
			for(int i=0;i<itr->second.size();i++)
			{
				cout<<"{ "<<itr->second[i].first<<","<<itr->second[i].second<<" }"<<"  ";
			}
			cout<<" with sum "<<itr->first <<endl;
		}
	}
}

int main()
{
	vector<int> arr  ;
	int n ;
	cout<<"Enter n : "<<endl ;
	cin>>n ;
	int x ;
	cout<<"enter the elements : "<<endl; 
   for(int i=0;i<n;i++)
   {
   	cin>>x ;
   	arr.push_back(x) ;
   }
  
    pairWithEqualSum(arr, n); 
    return 0 ;
}

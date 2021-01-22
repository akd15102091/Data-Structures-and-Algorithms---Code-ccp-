#include<iostream>
#include<iterator>
#include<map>
using namespace std ;

void Function(int A[],int B[],int n,int m)
{
	map<int,int> mp ;
	for(int i=0;i<n;i++)
	{
		mp[A[i]]++ ;
	}
	map<int,int> :: iterator itr ;
	for(int i=0;i<m;i++)
	{
		if(mp.find(B[i]) != mp.end())
		{
			itr = mp.find(B[i]) ;
			for(int j=0;j< itr->second;j++)
			{
				cout<<itr->first <<" ";
			}
			mp.erase(B[i]) ;
		}
	}
	 for (itr = mp.begin(); itr != mp.end(); itr++) 
	{ 
        for (int j = 0; j < itr->second; j++) 
            cout << itr->first << " "; 
    } 
  
    cout << endl; 
}

int main()
{
	int n ;// length of A array
	int m ;// length of B array
	cout<<"Enter n,m"<<endl;
	cin>>n>>m ;
	int A[500],B[500] ;
	cout<<"Enter elements od A array : "<<endl ;
	for(int i=0;i<n;i++)
	{
		cin>>A[i] ;
	}
	cout<<"Enter elements od B array : "<<endl ;
	for(int i=0;i<m;i++)
	{
		cin>>B[i] ;
	}
	
	Function(A,B,n,m) ;
	
}

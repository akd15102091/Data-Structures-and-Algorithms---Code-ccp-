#include<iostream>
#include<vector>
#include<map>
#include<iterator>

using namespace std ;

void countingSort(vector<int>arr,int n)
{
	map<int,int> freqMap ;
	map<int,int> :: iterator it ;
	for(int i=0;i<n;i++)
	{
		freqMap[arr[i]]++ ;
	}
	int i=0 ;

	//for every element of the map
	it=freqMap.begin() ; 
	while(it!=freqMap.end())
	{
		int val = it->first ;
		int freq = it->second ;
		cout<<val<<" "<<freq <<endl;

		for(int j=0;j<freq;j++)
		{
		
			arr[i] = val  ;
			i++ ;
		}
		it++;
	}
	// sorted array
	for(int k=0;k<n;k++)
	{
		cout<<arr[k]<<" ";
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
   // int n = arr.size(); 
   for(int i=0;i<n;i++)
   {
   	cin>>x ;
   	arr.push_back(x) ;
   }
  
    countingSort(arr, n); 
    return 0 ;
}

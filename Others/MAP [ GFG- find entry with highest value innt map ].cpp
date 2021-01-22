#include<iostream>
#include<map>
#include<utility>
using namespace std ;

pair<int,int> findEntryWithHighestValue(map<int,int>sampleMap)
{
	pair<int,int> p(0,0) ;
	int x,y=0;
	map<int,int> :: iterator it ;
	for(it=sampleMap.begin();it!=sampleMap.end();it++)
	{
		if(it->second >y)
		{
			x = it->first ;
			y=it->second ;
 		}
	}
	return (make_pair(x,y)) ;
}

int main()
{
	map<int, int> sampleMap; 
    sampleMap.insert(pair<int, int>(1, 40)); 
    sampleMap.insert(pair<int, int>(2, 30)); 
    sampleMap.insert(pair<int, int>(3, 60)); 
    
    pair<int,int> result = findEntryWithHighestValue(sampleMap) ;
    cout<<result.first<<"  "<<result.second<<endl ;
    return 0;
	
}

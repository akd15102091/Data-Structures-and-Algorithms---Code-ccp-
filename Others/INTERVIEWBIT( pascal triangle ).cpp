#include<iostream>
#include<vector>
using namespace std ;

vector<vector<int> > pascalTriangle(int n)
{
	vector<vector<int> > result1 ,result ;
	if(n==0) return result ;
	if(n==1)
	{
		vector<int> vec;
		vec.push_back(1) ;
		result1.push_back(vec) ;
		return result1;
	}
	if(n==2)
	{
		vector<int> vec1,vec2;
		vec1.push_back(1) ;
		result1.push_back(vec1) ;
		vec2.push_back(1) ;
		vec2.push_back(1) ;
		result1.push_back(vec2) ;
		return result1 ;
	}
	vector<int> vec1,vec2;
	vec1.push_back(1) ;
	result.push_back(vec1) ;
	vec2.push_back(1) ;
	vec2.push_back(1) ;
	result.push_back(vec2) ;
	
	int i=2;
	while(i<n)
	{
		vector<int> vec ;
		int j=i-1 ;
		int s=0;
		int e=result[j].size() -1 ;
		vec.push_back(result[j][0]) ;
		for(int k=0;k<= e-1;k++)
		{
			vec.push_back(result[j][k] + result[j][k+1]) ;
		}
		vec.push_back(result[j][e]) ;
		result.push_back(vec) ;
		i++;
	}
	return result ;
	
	
}

int main()
{
	int n ;
	cin>>n ;
	vector<vector<int> > vec = pascalTriangle(n) ;
	for(int i=0;i<vec.size();i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			cout<<vec[i][j]<<"  ";
		}
		cout<<endl;
	}
}

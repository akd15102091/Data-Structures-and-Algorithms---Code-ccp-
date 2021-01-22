#include<iostream>
#include<cstring>
using namespace std ;

int EditDistance(string str1,string str2,int n1,int n2)
{
	int T[500][500] ;
	// matrix n1*n2 ;
	for(int i=0;i<=n2;i++)
	{
		T[0][i]=i;
	}
	for(int i=0;i<=n1;i++)
	{
		T[i][0]=i;
	}
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				T[i][j]=T[i-1][j-1] ;
			}
			else
			{
				T[i][j]=min(min(T[i-1][j],T[i][j-1]),T[i-1][j-1]) +1 ;
			}
		}
	}
	return T[n1][n2] ;
}

int main()
{
	string str1,str2 ;
	cout<<"Enter string 1 : "<<endl; 
	getline(cin,str1) ;
	cout<<"Enter string 2 : "<<endl; 
	getline(cin,str2) ;
	int len1 = str1.length() ;
	int len2 = str2.length();
	int x = EditDistance(str1,str2,len1,len2) ;
	cout<<"min number of changes [ EditDistance ] : "<<x<<endl;
	return 0;
	
	
}

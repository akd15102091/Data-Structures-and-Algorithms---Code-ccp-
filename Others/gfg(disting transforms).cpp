#include<iostream>
#include<cstring>
using namespace std ;

int distTrans(string A,string B,string str,int i,int n )
{
	if(str==B) 
	{ return 1 ;}
	if(i>=n) return 0 ;
	
	return ( distTrans(A,B,str+A.substr(i,1),i+1,n) + distTrans(A,B,str,i+1,n) ) ;
}

int main()
{
	string A ;
	string B ;
	cout<<"Enter string 1 : "<<endl;
	cin>>A ;
	cout<<"Enter sting 2 : "<<endl;
	cin>>B ;
	
	int cnt=0 ;
	string str="" ;
	int i=0 ;
	int n = A.length() ;
	cnt = distTrans(A,B,str,i,n) ;
	cout<<"Answer is : "<<cnt<<endl;
	return 0;
}

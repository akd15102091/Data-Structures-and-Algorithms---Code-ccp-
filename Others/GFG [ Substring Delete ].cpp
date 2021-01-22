#include<iostream>
#include<algorithm>
using namespace std ;

bool checkDelete(string st , string sbst)
{	
	if(sbst.length()==0) return 0 ;
	int b = sbst.length() ;
	int a = st.length() ;
	
	while(a>0)
	{
		int x = st.find(sbst) ;
		if(x!=-1)
		{
			st.erase(x,b) ;
			a=a-b ;
		}
		else return false ;
	}
	return true ;
}

int main()
{
	string str ;
	string sub_str ;
	cin>>str ;
	cin>>sub_str ;
	
	bool x = checkDelete(str,sub_str) ;
	if(x) cout<<"TRUE" ;
	else cout<<"FALSE" ;
}


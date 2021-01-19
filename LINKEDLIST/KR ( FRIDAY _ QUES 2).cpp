#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char ch[50] ;
	cout<<"Enter the string : "<<endl ;
	cin.getline(ch , 50) ;
	int length = strlen(ch) ;
	int i=0 ;
	while(i<=length)
	{
	 
		 if(isalpha(ch[i]) && i<length)
		{
			cout<<ch[i] <<endl ;
			i++ ;
		}
		else if( ch[i] == '{' )
		{
			while(ch[i] !='}' && i<length)
			{
				cout<<ch[i] ;
				i++ ;
			}
			if( ch[i] == '}')
			{
				cout << "}";
				i++;
			}
			/*if(i<length)
			{
				cout<<ch[i] <<endl ;
				i++ ;
			}*/
			if(i == length) break;
			
		}
	}
	return 0;
}


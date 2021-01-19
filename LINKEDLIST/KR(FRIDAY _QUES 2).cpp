#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char ch[50] ;
	cout<<"Enter the string "<<endl;
	cin.getline(ch,50) ;
	int len = strlen(ch) ;
	int i=1 ;
	
	while(i<len-1)
	{ int count=0 ;
		if(isalpha(ch[i]))
		{
			cout<<ch[i]<<endl ;
			i++ ;
		}
		
		else if(ch[i] = '{')
		{
			while(ch[i] != '}')
			{   if(ch[i] == '{')
			  {
				count++;
			  }
			  
			  	cout<<ch[i] ;
				i++ ;
			  }
				
			}
			while(count)
			  {
			  	if(ch[i] =='}')
			  	{
			  		count--;
				  }
			cout<<ch[i] ;
			i++ ;
	     	}
	     	cout<<endl;
		}
	}


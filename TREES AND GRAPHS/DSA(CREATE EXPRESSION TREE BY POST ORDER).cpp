#include<iostream>
#include<stack> 
using namespace std;
struct Etree
{
	char data ;
	struct Etree *lc ;
	struct Etree *rc ;
};
typedef struct Etree *etptr ;
etptr create_node( char x)
{
	etptr T = NULL ;
	T= new struct Etree ;
	T->data = x ;
	T->lc = T->rc = NULL ;
	return T ;
}
etptr create_Etree(etptr t , char ch[] ,int n)
{
	stack<etptr> s ;
	int i = 0 ;
	while(i<n)
	{
		while(isdigit(ch[i]))
		{
			etptr temp = create_node(ch[i]) ;
			s.push(temp) ;
			i++ ;
		}
		if(!(isdigit(ch[i])))
		{
			t = create_node(ch[i]) ;
			t->rc = s.top() ;
			s.pop() ;
			t->lc = s.top() ;
			s.pop() ;
			s.push(t) ;
			i++ ;
			
		}
	}
		return t ;
}
void IN(etptr t )
{
	if(t)
	{
		IN(t->lc) ;
		cout<<t->data ;
		IN(t->rc) ;
	}
}

int eval(int a ,int b ,char c)
{
	switch(c)
	{
		case '+' : return (a+b) ;
		case '-' : return (a-b) ;
		case '*' : return (a*b) ;
		case '/' : return (a/b) ;
	}
}
int value_Etree( etptr t )
{
	
	if(!(t->lc) && !(t->rc))
	{
		return ((t->data) -'0') ;
	}
	int a = value_Etree(t->lc) ;
	int b = value_Etree(t->rc) ;
	char x = eval(a , b ,t->data) + '0' ;
	return (x - '0') ;
} 

int main() 
{
	etptr root = NULL ;
	char ch[50] ;
	cout<<"Enter the n"<<endl;
	int n;
	cin>>n ;
	cout<<"Enter the post order array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>ch[i] ;
	}
	root = create_Etree(root ,ch , n) ;
	
	cout<<"IN order is "<<endl;
	IN(root) ;
	cout<<endl ;
	int x = value_Etree( root ) ;
	cout<<"Value of expresion tree "<<x<<endl;
	return 0;
}

#include<iostream>
using namespace std ;
struct mlist
{
	char data ;
	struct mlist *next ;
	struct mlist *dlink ;
};
typedef struct mlist *mlptr ;

mlptr create_list(mlptr t , char ch[] , int &i ,int n)
{
	if(i>=n) return t ; 
	
	mlptr temp = new struct mlist ;
	temp->data = ch[i] ;
	temp->next = NULL ;
	temp->dlink = NULL ;
	t = temp  ;	
	
	if(ch[i] == '{')
	{
		i++ ;
		t->dlink = create_list(t->dlink ,ch ,i , n) ;
		i++ ;
		t->next = create_list(t->next , ch ,i , n) ;
	}
	if(ch[i] == '}')
	{
		return t ;
	}
	i++ ;
	t->next = create_list(t->next , ch ,i , n) ;
}
void PRE(mlptr t)
{
	if(t)
	{
		cout<<t->data ;
		PRE(t->dlink) ;
		PRE(t->next)  ;
	}
}
int main()
{
	mlptr root = NULL ;
	char ch[50] ;
	cout<<"ENter number of elements "<<endl;
	int n ;
	cin>> n;
	cout<<"ENter elements : "<<endl ;
	for(int i=0;i<n;i++)
	{
		cin>> ch[i] ;
	}
	int j=1 ;
	root = create_list(root , ch , j ,n) ;
	cout<<" RESULT IS "<<endl;
	cout<<"{";
	PRE(root) ;
	cout<<"}" ;
	cout<<endl;
	return 0 ;
	
	// 21   { A B { C D E } F { G { H I J } K } L M }
}



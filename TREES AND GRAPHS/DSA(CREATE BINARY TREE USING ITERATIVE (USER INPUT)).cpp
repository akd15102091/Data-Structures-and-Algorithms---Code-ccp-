#include<iostream>
#include<stack>
using namespace std;
struct btnode
{
	char data ;
	struct btnode *lc ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;
btptr create_node(char x)
{
	btptr t = NULL ;
	t = new struct btnode ;
	t->data = x ;
	t->lc = NULL ;
	t->rc = NULL ;
	return t ;
}
void PRE(btptr t)
{
	if( t )
	{  
		cout<<t->data <<" ";
		PRE(t->lc) ;
		PRE(t->rc) ;
	}
}
int main()
{
	btptr T = NULL ;
	stack<btptr> s;
	cout<<"Enter the first node value "<<endl ;
	char x ;
	cin>>x ;
	T = create_node( x) ;
	s.push(T) ;
	while(!s.empty())
	{
		btptr temp = s.top() ;
		cout<<"leftchild yes or no"<<endl;
		char c ;
		cin>>c ;// c should be either y or n //
		if(c == 'y')
		{
			cout<<"Enter left_data"<<endl;
			char  num ;
			cin>>num ;
			temp->lc = create_node(num) ;
			s.push(temp->lc) ;
		}
		else
		{
			cout<<"rightchild yes or no"<<endl;
			cin>>c ;
			if(c == 'y')
			{
				cout<<"Enter right_data"<<endl;
				char  num ;
				cin>>num ;
				temp->rc = create_node(num) ;
				s.push(temp->rc) ;
			}
			else
			{
				s.pop() ;
			}
		}
 	}
 	PRE(T) ;
	
}

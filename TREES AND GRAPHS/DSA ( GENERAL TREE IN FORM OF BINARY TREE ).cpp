#include<iostream>
#include<queue> 
using namespace std ;
struct Gtree
{
	char data ;
	struct Gtree *fc , *ns ;
} ;
typedef struct Gtree *gptr ;
gptr newnode( char c)
{
	gptr temp = new struct Gtree ;
	temp->data = c ;
	temp->fc = temp->ns = NULL ;
	return temp ;
}
void Create_General_tree( gptr &t )
{
	cout<<"ENter the  root value : "<<endl ;
	char ch ;
	cin>> ch ;
	t = newnode(ch) ;
	queue<gptr> q ;
	q.push(t) ;
	while(!q.empty())
	{
		gptr temp = q.front() ;
	
		cout<<"IS there first child(enter y or n) "<<endl ;
		char x ;
		cin>> x ;
		if(x=='y')
		{
			cout<<"ENter first child data "<<endl ;
			cin>>ch ;
			temp->fc = newnode(ch) ;
			q.push(temp->fc) ;
		}
		else if(x=='n')
		{
			cout<<"IS there right sibiling (enter y or n) "<<endl ;
			char z ;
			cin>> z ;
			if(z=='y')
			{
				cout<<"ENter right sibling data "<<endl;
				cin>>ch ;
				temp->ns = newnode(ch) ;
				q.push(temp->ns) ;
			}
			else if(z=='n')
			{
				q.pop() ;
			}
		}
	}
}
void print_Gtree( gptr t )
{
	if(t)
	{
		cout<<t->data<<" ";
		print_Gtree(t->fc) ;
		print_Gtree(t->ns) ;
	}
}
int main()
{
	gptr root = NULL ;
	Create_General_tree( root ) ;
	print_Gtree(root) ;	
}

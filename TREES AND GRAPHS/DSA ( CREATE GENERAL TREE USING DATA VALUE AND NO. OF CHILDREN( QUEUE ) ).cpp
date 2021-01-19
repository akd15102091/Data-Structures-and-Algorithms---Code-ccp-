#include<iostream>
#include<queue>
using namespace std ;
struct Gtree
{
	char data ;
	int ccnt ;
	struct Gtree *cptr[50] ;
};
typedef struct Gtree *gptr ;
gptr newnode( char x )
{
	gptr temp = new struct Gtree ;
	temp ->data = x ;
	for(int i=0 ;i<50 ;i++)
	{
		temp->cptr[i] = NULL ;
	}
	return temp ;
}

void Create_GENARAL_Tree( gptr &t )
{
	cout<<"Enter data value  " <<endl;
	char ch ;
	cin>>ch  ;
	t = newnode( ch) ;
	queue<gptr> q ;
	q.push(t) ;
	while(!q.empty())
	{
		gptr temp = q.front() ;
		q.pop() ;
		cout<<"HOw many children you want "<<endl ;
		int n ;
		cin>> n;
		temp->ccnt = n ;
		for(int i=0;i<n ;i++)
		{
			cout<<"ENter data" <<endl ;
			cin>>ch ;
			temp->cptr[i] = newnode( ch ) ;
			q.push( temp->cptr[i] ) ;
		}
	}
}
void print_Gtree(gptr t)
{
	if(t)
	{
		cout<<t->data <<" ";
		for(int i=0;i<(t->ccnt);i++)
		{
			print_Gtree( t->cptr[i] ) ;
		}
	}
}
int main()
{
	gptr root = NULL ;
	
/*	cout<<"ENter root value "<<endl ;
	char x ;
	cin>> x ;*/
	Create_GENARAL_Tree(root ) ;
	print_Gtree(root) ;
}

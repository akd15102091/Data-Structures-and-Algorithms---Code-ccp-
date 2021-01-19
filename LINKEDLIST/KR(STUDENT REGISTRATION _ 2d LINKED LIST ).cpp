#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct rnode *rptr ;

union u
{
	int roll ;
	char sn ;
	struct rnode *dlink ;
};

struct rnode
{
	int flag ;
	struct rnode *next ;
	union u a;
};

rptr s = new struct rnode[10] ;
rptr c = new struct rnode[10] ;
void addrnode(rptr &s ,rptr &c,int roll ,char z ,int i, int j)
{
	rptr T = NULL ;
	T = new struct rnode ;
	T->next = NULL ;
	(T->a).dlink = NULL;
	if(s->flag == 1) (T->a).roll = roll ;
	else if(c->flag == 2) (T->a).sn = z ;

	else
	{
    	while((c)->a.dlink)
    	{
    		c = (c)->a.dlink ;
    	}
       	(c)->a.dlink = T;
	}
		while((s)->next )
	{
		(s) = (s)->next ;
	}
	(s)->next = T ;

	
	
}
int main()
{  int n,m ;
	cout<<"enter the number of students "<<endl;
	cin>>n;
	cout<<"enter the number os subject"<<endl;
	cin>>m;
	cout<<"enter the roll numbers"<<endl;
	 (s[])->flag =1 ;
	for(int i=0;i<n;i++)
	{   int x;
		if(s->flag == 1)
		(s+i)->a.roll = x ;
	}
	cout<<"enter the subjects"<<endl;
	c->flag=2;
	for(int j=0;j<m;j++)
	{
		char ch;
		if(c->flag ==2 )
		(c+j)->a.sn = ch ;
	}
	cout<<"Enter the subject corresponding to student" <<endl;
	for(int i=0 ;i<n;i++)
	{   cout<<"ENter the student rool number"<<endl;
		int y ;
		cin>>y ;
		cout<<"Enter how many subject to student["<<i<<"]"<<endl;
		int l;
		for(int j=0;j<l;j++)
		{
			char z;
			cin>>c;
			addrnode(s[i] ,c[i] ,y,z ,i ,j) ;
		}
	}
}

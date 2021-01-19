#include<iostream>
using namespace std ;
union u
{
	int x ;
	char ch ; 
} ;
struct data_value
{
	int flag ;
	union u  un ;
} ;
struct kdnode
{
	struct kdnode *lc ;
	struct data_value data[50] ;
	struct kdnode *rc ;
} ;
typedef struct kdnode *kdptr ;
kdptr INSERT( kdptr t , struct data_value a[] , int d , int p)
{
	if(t == NULL)
	{
		kdptr temp = NULL ;
		temp = new struct kdnode ; 
		for(int i=0 ; i<d ; i++)
		{
			if(a[i].flag == 1)
			{
				temp->data[i].flag = 1 ;
				//cout<<"G"<< a[i].un.x <<endl;
				temp->data[i].un.x = a[i].un.x ;
			//	cout<<"G"<<temp->data[i].un.x <<endl ;
			}
			else if(a[i].flag == 0)
			{
				temp->data[i].flag = 0 ;
			//	cout<<"L"<< a[i].un.ch <<endl;
				temp->data[i].un.ch = a[i].un.ch;
			//	cout<<"L"<< temp->data[i].un.ch<<endl ;
			}
		}
		temp->lc = temp->rc = NULL ;
		t = temp ;
	}
	if( a[p%d].flag == 1)
	{
		 if( t->data[p%d].un.x  > a[p%d].un.x )
			{
			t->lc =  INSERT(t->lc , a , d , p+1) ;
			}
		 else if ( t->data[p%d].un.x  < a[p%d].un.x )
			{
				t->rc = INSERT(t->rc , a , d , p+1) ;
			}
	}
	else if(a[p%d].flag == 0)
	{
		if( t->data[p%d].un.ch  > a[p%d].un.ch )
			{
			t->lc =  INSERT(t->lc , a , d , p+1) ;
			}
		 else if ( t->data[p%d].un.ch  < a[p%d].un.ch )
			{
				t->rc = INSERT(t->rc , a , d , p+1) ;
			}
	}

	return t ;
}
void PRE(kdptr t , int d)
{
	if(t)
	{
		for(int i=0; i<d ;i++)
		{
			if(t->data[i].flag == 1)
			{
				cout<< t->data[i].un.x <<" ";
			}
			else if(t->data[i].flag == 0)
			{
				cout<< t->data[i].un.ch <<" ";
			}
		}
		cout<<endl;
		PRE(t->lc , d) ;
		PRE(t->rc , d) ;
	}
} 
int main()
{
	kdptr root = NULL ;
	cout<<"ENter how many nodes you want to enter "<<endl ;
	int n ;
	cin>> n ;
	cout<<"Enterc data size(means how many data in one node) "<<endl;
	int d ;
	cin>> d ;
	for(int i=0 ; i<n ;i++)
	{
		struct data_value a[50] ;
		cout<<"ENter d datas "<<endl ;
		for(int j=0 ; j<d ; j++)
		{
			int f ;
			cout<<"enter flag  " ;
			cin>>f ;
			if(f ==1) 
			{
				a[j].flag = 1 ;
				int p ;
				cin>> p ;
				a[j].un.x = p ;	
			}
			else if(f == 0)
			{
				a[j].flag = 0 ;
				char c ;
				cin>> c ;
				a[j].un.ch = c ;
			}
		}
		root = INSERT( root , a , d , 0)  ;
	}
	cout<<"PRE ORDER is : "<<endl ;
	PRE(root , d) ;  
	cout<<endl ;
/*	1
	7
	0
	b
	1
	20
	1
	25
	0
	a
	1
	15
	1
	372
	0
	i
	1
	9
	1
	18
	0
	m
	1
	2   */
}

#include<iostream>
using namespace std;
struct btnode
{
	int level ;
	char data ;
	struct btnode *lc ;
	struct btnode *rc ;
	struct btnode *next ;
};
typedef struct btnode *btptr ;
int height = 0 ;
 btptr create_node(btptr t , char a[50] ,int i ,int l )
 {
 	if(a[i] != '+')
	{
	
		btptr temp = NULL;
		temp = new struct btnode ;
		temp->level = l ;
		if(temp->level > height )  height = temp->level ;
		temp->data = a[i] ;
		temp->lc = NULL ;
		temp->rc = NULL ;
		temp->next = NULL ;
		return temp ;
	}
	else {	return NULL ;}
 }

btptr create_tree(btptr T , char a[50] ,int &i ,int n ,int l)
{
	if(i >= n)
	{
		return T ;
	}
	T = create_node(T , a ,i , l) ;
	if(T==NULL) return NULL;
	i++;
	T->lc = create_tree(T->lc , a ,i , n ,l+1 ) ;
	i++;
	T->rc = create_tree(T->rc , a ,i ,n ,l+1 ) ;
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

void connect(btptr t, int x ,btptr &temp)
{
	if(t == NULL) return ;
	if(t->level == x)
	{
		if(temp == NULL){
		temp = t ;
		}
		else
		{
			temp->next = t ;
			temp = temp->next ;
		}	
	}
	connect(t->lc ,x ,temp) ;
	connect(t->rc ,x,temp) ;
}

void print_tree( btptr t )
{
	if(t)
	{
		btptr temp = t ;
		while(temp)
		{
			cout<<temp->data <<" ";
			temp = temp->next ;
		}
		cout<<endl ;
		print_tree( t->lc ) ;
		print_tree( t->rc ) ;
	}
}

int main()
{	btptr root = NULL ;
	int n ;
	char a[50] ;
	cout<<"Enter the n "<<endl;
	cin>>n;
	cout<<"Enter the elements "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}
	 
	 int j =0 ;
	 root = create_tree( root ,a , j , n ,0 ) ;
	cout<<"PRE_ORDER IS : "<<endl;
	PRE(root) ;
	cout<<endl ;
	for(int i=0;i<=height ;i++)
	{
		btptr temp = NULL ;
		connect(root , i ,temp ) ;
	}
	cout<<"After connect : "<<endl ;
	print_tree( root ) ;
	return 0 ;
}
// 15   a  b d + + e + + c f + + g + + 


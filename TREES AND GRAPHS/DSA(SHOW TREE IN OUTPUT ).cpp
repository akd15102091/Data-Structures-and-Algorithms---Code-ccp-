#include<iostream>
#include<queue>
using namespace std;
struct btnode
{
	char data ;
	int x ;
	int y ;
	struct btnode *lc ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;

btptr create_node(btptr t , char a[50] ,int i)
 {
 	if(a[i] != '+')
	{
    	btptr temp = NULL;
		temp = new struct btnode ;
		temp->data = a[i] ;
		temp->lc = NULL ;
		temp->rc = NULL ;
		return temp ;
	}
	else {	return NULL ;}
 }

btptr create_tree(btptr T , char a[50] ,int &i ,int n)
{
	if(i >= n)
	{
		return T ;
	}
	T = create_node(T , a ,i) ;
	if(T==NULL) return NULL;
	i++;
	T->lc = create_tree(T->lc , a ,i , n) ;
	i++;
	T->rc = create_tree(T->rc , a ,i ,n) ;
}
void level_Y(btptr t , int l)
{
	if(t== NULL)
	{
		return ;
	}
	t->y = l ;
	level_Y(t->lc , l+1) ;
	level_Y(t->rc , l+1) ;
}
void depth_X(btptr t ,int d)
{
	if(t== NULL)
	{
		return ;
	}
	depth_X(t->lc , d) ;
	t->x = d++ ;
	depth_X(t->rc , d) ;
}
// S M K + + L A + + B + + J + E G + D + + +   //
/*void image_tree(btptr t)
{
	if(t==NULL) return ;
	queue<btptr> q ;
	q.push(t);
	while(!q.empty())
	{
		btptr temp=q.front();
		q.pop() ;
		for(int i=0;i< temp->x ;i++)
		{
			cout<<" ";
		}
		cout<<temp->data <<" ";
		if(temp->lc!=NULL) q.push(temp->lc);
		if(temp->rc!=NULL) q.push(temp->rc);
		
		//q.pop();
	}
}*/
void left_view(btptr t , int l )
{
	static int max =0 ;
	if(t == NULL)
	{
		return ;
	}
	if( l>max)
	{
		cout<<t->data <<" ";
		max = l ;
	}
	left_view(t->lc , l+1 ) ;
	left_view(t->rc , l+1 ) ;
}

void right_view(btptr t ,int l )
{
	static int max =0 ;
	if(t == NULL)
	{
		return ;
	}
	if( l>max)
	{
		cout<<t->data <<" ";
		max = l ;
	}
	right_view(t->rc , l+1 ) ;
	right_view(t->lc , l+1 ) ;
	
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
	 root = create_tree( root ,a , j , n) ;
	 level_Y(root ,1) ;
	 depth_X(root , 1) ;
	 left_view(root , 1 ) ;
	 cout<<endl ;
	 right_view(root , 1) ;
	 //image_tree(root) ;
//	cout<<"PRE_ORDER IS : "<<endl;
//	PRE(root) ;
//	print_serialization(root) ;	
}


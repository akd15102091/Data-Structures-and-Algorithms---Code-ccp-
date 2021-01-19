#include<iostream>
#include<queue>
using namespace std;
struct btnode
{
	int data ;
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
		temp->data = a[i] -'0' ;
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
queue<int> q1,q2 ;

void select( int &max , int sum )
{
	if(sum > max) 
	{
		max = sum ;
		while(!q2.empty())
		{
			q2.pop() ;
		}
		while(!q1.empty())
		{
			q2.push(q1.front()) ;
			q1.pop() ;
		}
	}
	return ;
}
void max_path(btptr t , int &max , int &sum)
{
	if(!(t->lc) && !(t->rc))
	{
		sum = sum + t->data ;
		q1.push(t->data) ;
		select(max , sum ) ;
	}
	q1.push(t->data) ;
	sum = sum + t->data ;
	max_path(t->lc ,max , sum) ;
	max_path(t->rc ,max , sum) ;
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
	int max = 0 , sum =0 ;
	max_path(root , max , sum) ;
	cout<<"MAx sum is "<<max<<endl;
	cout<<"MAx_sum_path is :  ";
	while(!q2.empty())
	{
		cout<< q2.front() <<" ";
		q2.pop() ;
	}
	return 0 ;
	// 17     5 3 2 + + 4 + + 9 7 6 + + 8 + + + 
	
}

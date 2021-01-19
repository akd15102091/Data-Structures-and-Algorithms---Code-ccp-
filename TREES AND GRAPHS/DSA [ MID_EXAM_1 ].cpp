#include<iostream>
#include<stack>
using namespace std;
struct btnode
{
	char data ;
	int val ;  // index_value //
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
void index_value( btptr t , int k)
{
	if(t == NULL) return ;
	t->val = k ;
	index_value(t->lc , k+1) ;
	index_value(t->rc , k+1) ;
}
int height(btptr t)
{
	if(t == NULL) return -1 ;
	if(t->lc == NULL && t->rc == NULL) return 0 ;
	int l = height(t->lc) ;
	int r = height(t->rc) ;
	return (1+((l>r)?l:r)) ;
}

void spiral_order(btptr t , int x , stack<char> &s)
{
	if(t==NULL) return ;
	
	if(t->val == x ) 
	{
		s.push(t->data) ;
	}
	spiral_order( t->lc , x ,  s) ;
	spiral_order( t->rc , x ,  s) ;
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
	int H = height(root) ;
	//cout<<H <<endl;
	// 19  A B D + + E + + C F H + + I + + G + +
	index_value(root , 0) ;
	int count = 0 ;
	stack<char> s1 ,s2 ;
	for(int i=0 ; i<=(H+1)/2 ; i++)
	{
		spiral_order(root , i , s1) ;
		while(!s1.empty())
		{
			s2.push(s1.top()) ;
			s1.pop() ;
		}
		while(!s2.empty())
		{
			cout<< s2.top() <<" ";
			s2.pop() ;
		}
		cout<<endl ;
		spiral_order(root ,  H-i , s1) ;
		while(!s1.empty())
		{
			cout<<s1.top() <<" ";
			s1.pop() ;
		}
		cout<<endl ;
	}
	return 0 ;
}

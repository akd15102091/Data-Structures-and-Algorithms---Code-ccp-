#include<iostream>
#include<queue>
using namespace std;
struct btnode
{
	int data ;
	struct btnode *lc ;
	struct btnode *rc ;
	int val ;
};
typedef struct btnode *btptr ;
int l =0 ;
 btptr create_node(btptr t , char a[50] ,int i)
 {
 	if(a[i] != '+')
	{
		l++ ;
    	btptr temp = NULL;
		temp = new struct btnode ;
		temp->data = a[i] - '0' ;
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

void value(btptr t , int x )
{
	if(t == NULL) return ;
	t->val = x ;
	value(t->lc , 2*x+1) ;
	value(t->rc , 2*x+2) ;
}
bool check_complete_binarytree(btptr t ,int n)
{
	queue<btptr> q ;
	q.push(t) ;
	while(!q.empty())
	{
		btptr temp = q.front() ;
		q.pop() ;
		int c = 0; 
		if(temp->lc) q.push(temp->lc) ;
		if(temp->rc) q.push(temp->rc) ;
		if(temp->val >= n) return false ;
		if(!(temp->lc)  &&  !(temp->rc))
		{
			break ;
		}
	}
	int count = 0 ;
	while(!q.empty())
	{
		btptr p = q .front()  ;
		q.pop() ;
		if(p->val >= n) return false ;
		if(p->lc || p->rc)
		{
			count ++ ;
		}
	}
	if(count == 0) return true ;
	else return false ;
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
	 value(root , 0) ;
	bool x = check_complete_binarytree(root , l) ;
	if(x == true) cout<<"Tree is a complete binary tree "<<endl;
	else cout<<"Tree is not acomplete binary tree "<<endl;
	return 0;
	// 15   6 4 3 + + 5 + + 8 7 + + 9 + +
	//13   6 4 3 + + 5 + + 8 + 9 + +
}

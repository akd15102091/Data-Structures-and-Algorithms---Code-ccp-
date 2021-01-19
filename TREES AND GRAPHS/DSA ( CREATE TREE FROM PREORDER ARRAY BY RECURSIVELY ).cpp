#include<iostream>
using namespace std ;
struct bstnode
{
	int data ;
	struct bstnode *lc ;
	struct bstnode *rc ;
};
typedef struct bstnode *bstptr ;
/*bstptr creatr_node(int data)
{
	
	return T ; 
} */
int index(int a[] ,int i ,int n )
{   int  x = i-1;
	while(a[x] > a[i] and i<n)
	{
		i++ ;
	}
	return i ;
}
void create_bst_tree(bstptr &t ,int a[] ,int i ,int n) 
{
	if(i >= n)
	{
		return  ;
    }
   	bstptr T = NULL ;
	T = new struct bstnode ;
	T->data = a[i] ;
	T->lc = NULL ;
	T->rc = NULL ;
	t = T ;
	int x = index(a , i+1 ,n) ;
    //cout<<"GO";
    create_bst_tree( t->lc , a , i+1 , x) ; 		
    create_bst_tree( t->rc , a , x , n) ;	 
	
}
void PRE(bstptr t)
{
	if(t)
	{
		cout<<t->data <<" ";
		
		PRE(t->lc) ;
		PRE(t->rc);
	}
}
int main()
{
	bstptr root = NULL ;
	int a[50] , n;
	cout<<"Enter the number of elements "<<endl;
	cin>>n;
	cout<<"Enter elements "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}
	root = new struct bstnode ;
	root->data = a[0] ;
	root->lc = root->rc = NULL ;
	create_bst_tree(root , a ,0 ,n) ;
	PRE(root) ;
}

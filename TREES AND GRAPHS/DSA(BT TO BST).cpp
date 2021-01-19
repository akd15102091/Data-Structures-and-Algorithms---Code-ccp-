#include<iostream>
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
void IN_b(btptr t , int b[50] , int &i)
{
	if(t)
	{
		IN_b(t->lc , b , i) ;
		b[i] = t->data ;
		i++ ;
		IN_b(t->rc , b , i) ;
	}
}
void IN_convert_bst(btptr t ,int b[] ,int len ,int &i)
{
	if(t == NULL) return ;
	if(i == len) return ;
	IN_convert_bst(t->lc , b , len , i) ;
	t->data = b[i] ;
	i++ ;
	IN_convert_bst(t->rc , b , len ,i) ;
}
void IN_ORDER(btptr t)
{
	if(t)
	{
		IN_ORDER(t->lc) ;
		cout<< t->data <<" ";
		IN_ORDER(t->rc) ; 
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
	 root = create_tree( root ,a , j , n) ;
	int b[50] ;
	int i = 0 ;
	IN_b(root , b ,i) ;
	int len = i ;
	for(int k=0;k<len;k++)
	{
		cout<<b[k] ;
	}
	cout<<endl;
for(int i=0;i<len;i++)
	{
		for(int j=0;j<len-i-1;j++)
		{
			if(b[j] > b[j+1])
			{
				int temp ;
				temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
			}
		}
	}
	for(int k= 0 ;k<len;k++)
	{
		cout<<b[k] ;
	}
	cout<<endl ;
	i = 0 ;
	IN_convert_bst(root , b , len , i) ;
	cout<<"IN Order after converting bt to bst"<<endl ;
	IN_ORDER(root) ;
	//  1 2 3 + 0 + + 4 + + 5 6 + + 7 9 + + +   //
	 return 0 ;
}


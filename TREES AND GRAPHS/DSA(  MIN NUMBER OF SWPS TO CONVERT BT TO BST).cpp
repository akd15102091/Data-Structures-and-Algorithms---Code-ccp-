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
int IN_ORDER_ARRAY( btptr t , int b[] )
{
	static int i =0 ;
	if(t)
	{
		IN_ORDER_ARRAY(t->lc , b) ;
		b[i++] = t->data ;
		IN_ORDER_ARRAY(t->rc , b) ;
	}
	return i ;
}

/*void in(btptr T)
{
	if(T)
	{
		in(T->lc);
		cout << T->data << " ";
		in(T->rc);
	}
}*/

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
	 int count = 0;
	int j =0 ;
	root = create_tree( root ,a , j , n) ;
	int b[50] ;
	int len = IN_ORDER_ARRAY( root , b ) ;
	int flag = 0 ;

	//  in(root);
	for(int i=0 ;i <len-1 ;i++)
	{
		//cout <<"~"<< b[i] << " ";
		int min = b[i] ;
		int loc = i ;
		count = 0 ;
		for(int j = i+1 ; j<len ; j++)
		{
			
			if(b[j] < min)
			{
				count ++ ;
				min = b[j] ;
				loc = j ;
			}
		}
		if(count) cout << b[i] << " is swapped with " << b[loc] << endl;
		if(count != 0)
		{
			int temp = b[i] ;
			b[i] = b[loc] ;
			b[loc] = temp ;
			flag ++ ;
		}
		
	}
	cout<<flag <<endl ;
	return 0 ;
	////   15   5 3 2 + + 1 + + 4 7 + + 9 + + 
}

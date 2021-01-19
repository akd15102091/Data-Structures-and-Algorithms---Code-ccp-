#include<iostream>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;
stack<int> s ;
struct btnode
{
	int data ;
	struct btnode *lc ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;
int  NuMbeR_inT( string str)
{
	int x = 0;
	for(int i=0 ; i<str.length() ; i++)
	{
			x = x*10+str[i]-'0';
	}	
	return x ;
} 
 btptr create_node(btptr t , string a[50] ,int i)
 {
 	if(a[i] !="+" )
	{
    	btptr temp = NULL;
		temp = new struct btnode ;
		temp->data = NuMbeR_inT(a[i]) ;
		temp->lc = NULL ;
		temp->rc = NULL ;
		return temp ;
	}
	else {	return NULL ;}
 }

btptr create_tree(btptr T , string a[50] ,int &i ,int n)
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
void IN_ORDER_push(btptr t)
{
	if(t)
	{
		IN_ORDER_push(t->lc) ;
		s.push(t->data) ;
		IN_ORDER_push(t->rc) ;
	}
}
void REQUIRED_SUM_PAIRS(btptr t ,int k,int &n)
{
	if( !s.empty()&&--n)
	{
			if(t->lc)
			{
				REQUIRED_SUM_PAIRS( t->lc , k,n) ;
			}
		
			while(s.size()&&((s.top()) + t->data ) > k )
			{
				s.pop() ;
			}   
			if(s.size()&&((s.top()) + t->data ) == k)
			{
				cout<< s.top() <<" "<<t->data <<endl ;
				s.pop() ;

			}  
		if(t->rc)
			{
				
				REQUIRED_SUM_PAIRS( t->rc , k,n) ;
			}
	}	
} 
int main()
{	btptr root1 = NULL ;
	btptr root2 = NULL ;	
	int n1 , n2 ;
	string a[50] , b[50] = "";
	cout<<"Enter the n1 "<<endl;
	cin>>n1;
	cout<<"Enter the elements "<<endl;
	for(int i=0;i<n1;i++)
	{
		cin>>a[i] ;
	}
	int j =0 ;
	root1 = create_tree( root1 ,a , j , n1) ;
	cout<<"Enter the n2 "<<endl;
	cin>>n2;
	cout<<"Enter the elements "<<endl;
	for(int i=0;i<n2;i++)
	{
		cin>>b[i] ;
	}
	j =0 ;
	root2 = create_tree( root2 ,b , j , n2) ;
	IN_ORDER_push(root1) ;
	cout<<"ENter the key for sum"<<endl;
	int k ;
	cin>>k ;
	REQUIRED_SUM_PAIRS( root2 ,k ,n2 ) ;
	return 0;
	// 17 5 3 2 + + 4 + + 10 7 + + 12 + 15 + +         15 9 5 1 + + 8 + + 30 20 + + 40 + +  //
}

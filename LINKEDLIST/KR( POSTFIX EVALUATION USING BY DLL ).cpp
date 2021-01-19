#include<iostream>
#include<cstdlib>
using namespace std;
struct dlnode
{
	struct dlnode *left ; 
	char data ;
	struct dlnode *right ;
};
typedef struct dlnode *dptr ;
dptr createlist(dptr D , char x )
{	dptr temp = D ;
	dptr T= NULL ;
	T = new struct dlnode ;
	
	if( D == NULL )
	{ 
		T->data = x ;
		T->left = NULL ;
		T->right = NULL ;
		D = T ;
		return D;
	}
	else
	{
		while(D->right != NULL)
		{
        	D=D->right;
		}
		T->data=x;
		T->right=NULL;
		T->left = D ;
		D->right=T;
        return temp;
	}
}

void printlist( dptr D )
{  
	if(D == NULL ) cout<<"List is empty "<<endl;
	else
	{
		while( D != NULL)
		{ 
			cout<< D->data <<" ";
			D = D->right ;
		}
	}
}
float eval(int n ,int m ,char c)
{
	if(c == '+') return (n+m) ;
	if(c == '-') return (n-m) ;
	if(c == '*') return (n*m) ;
	if(c == '/') return (n/m) ;
}
int main()
{
	dptr D = NULL ;
	cout<<"enter the number of elements " <<endl ;
	int n,a[50] ;
	cin>> n ;
	cout<<"enter the elements of doubly linked list "<<endl;
	for(int i=0;i<n;i++)
	{
		char x;
		cin>>x ;
		D = createlist( D , x) ;
	}
    char y;
	printlist( D ) ;
	cout<<endl;
   while(D)
   {
   	if(D->data == '+' || D->data == '-' || D->data == '*' || D->data == '/' )
    {
    	int op1 = (D->left->data) - '0';
    	int op2 = (D->left->left->data ) - '0';
    	char ch = D->data ;
		 y = eval(op2 ,op1 ,ch) + '0';
		D->data=y ;
		if(D->left->left->left != NULL)
		{
			dptr temp = D->left->left->left ;
			temp->right = D ;
			D->left = temp ;	
	    } 
	    else
	    {
	    	dptr temp =D->left ;
	    	temp =NULL ;
	    	D->left = NULL ;
		}
    }
    if(D->right == NULL) cout<<(y - '0') ;
    D=D->right ;
  
   }
    return 0;
}


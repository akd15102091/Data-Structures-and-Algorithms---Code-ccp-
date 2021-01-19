#include<iostream>
#include<cstdlib>
using namespace std;
struct dlnode
{
	struct dlnode *left ; 
	int data ;
	struct dlnode *right ;
};
typedef struct dlnode *dptr ;
dptr createlist(dptr D , int x )
{	dptr temp = D ;
	dptr T= NULL ;
	T = new struct dlnode ;
	T->left = NULL;
	T->right = NULL;
	
	if( D == NULL )
	{ 
		T->data = x ;
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
		{ // cout<<"go";
			cout<< D->data <<" ";
			D = D->right ;
		}
	}
}
void reverse_doublylinkedlist(dptr &D,dptr &ref )
{    
		if(D->right == NULL) 
		{
				dptr t = NULL;
				D->right =D->left;
				D->left= NULL;
				ref = D;
				return ;
		}
		if(D -> right !=NULL)
		{
			dptr t = NULL;
			t = D->right;
			if(D->left == NULL) 		D->right = NULL;
			else
	 		D->right = D->left;
			D->left = t;
		 	reverse_doublylinkedlist(t,ref) ;
		}
 } 
int main()
{
	dptr D = NULL,ref=NULL ;
	ref = new(dlnode);
	cout<<"enter the number of elements " <<endl ;
	int n,a[50] ;
	cin>> n ;
	cout<<"enter the elements of doubly linked list "<<endl;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x ;
		D = createlist( D , x) ;
	}
	printlist( D ) ;
	cout<<endl;
	cout<<"Reversly linked list : "<<endl ; 
    reverse_doublylinkedlist( D,ref ) ;
    printlist( ref ) ;
    

}


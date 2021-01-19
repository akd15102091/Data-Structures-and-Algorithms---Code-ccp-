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
		{ // cout<<"go";
			cout<< D->data <<" ";
			D = D->right ;
		}
	}
}
void reverse_doublylinkedlist(dptr D )
{
	if(D -> right !=NULL)
	{
	 reverse_doublylinkedlist(D->right) ;
	}
	cout<< D->data <<" " ;
//	D = D->left ;
	/*if(D -> left !=NULL)
	{
	reverse_doublylinkedlist(D->left ) ;
	}*/
	
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
		int x;
		cin>>x ;
		D = createlist( D , x) ;
	}
	printlist( D ) ;
	cout<<endl;
	cout<<"Reversly linked list : "<<endl ; 
    reverse_doublylinkedlist( D ) ;

}


#include<iostream>
#include<cstdlib>
using namespace std;
struct dlnode
{
	struct dlnode *left ; 
	int data ;
	struct dlnode *right ;
};
struct queue
{
	struct dlnode *front = NULL ;
	struct dlnode *rear =NULL ;
	int size ; 
};
typedef struct dlnode *dptr ;
 queue q;
dptr ENQUE(dptr D , int x , int &size )
{	
	q.size= q.size + 1 ;
	dptr temp = D ;
	dptr T= NULL ;
	T = new struct dlnode ;
	
	if( D == NULL )
	{   
		T->data = x ;
		T->left = NULL ;
		T->right = NULL ;
		D = T ;
		q.front = D ;
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
		q.rear=T;
		D->right=T;
        return temp;
	}
}
void DEQUE(dptr &D , int &size)
{   cout<<"dequed element "<< D->data <<endl;
	D = D->right ;
	q.front = D ;
	q.size = q.size -1 ;
	
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


int main()
{
	
	dptr D = NULL ;
	cout<<"enter the number of elements " <<endl ;
	int n,a[50] ;
	cin>> n ;
	q.size=0;
	cout<<"enter the elements of doubly linked list "<<endl;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x ;
		D = ENQUE( D , x , q.size) ;
	}
	printlist( D ) ;
	cout<<endl;
//	ENQUE( q , 15 , q.size) ;
	cout<<q.size <<endl;
	D = ENQUE(D , 20 ,q.size );
	printlist( D ) ;
	cout<<endl;
	cout<<q.size<<endl;
	DEQUE(D , q.size) ;
	DEQUE(D , q.size) ;
	cout<<"Now size is "<<q.size ;
    return 0;
 

}


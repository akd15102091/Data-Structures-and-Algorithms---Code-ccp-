#include<iostream>
#include<cstdlib>
#include<windows.h>
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
/*void print_triplets(dptr x , dptr y, dptr z ,int k)
{
	Sleep(500);
	cout<< "\nNeglectMe" <<x->data <<" "<< y->data <<" "<< z->data <<endl;
	if(z->right != NULL)
	{
		if((x->data)+(y->data)+(z->data) == k)
		{
		cout<< x->data <<" "<< y->data <<" "<< z->data <<endl;
	    }
	    print_triplets(x->right , y->right , z->right, k);
	    print_triplets(x , y->right , z->right, k);
		print_triplets(x , y , z->right , k) ;
    	
   		
	}
}*/
int main()
{
	dptr D = NULL ;
	cout<<"enter the number of elements " <<endl ;
	int n;
	cin>> n ;
	cout<<"enter the elements of doubly linked list "<<endl;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x ;
		D = createlist( D , x) ;
	}
	int k ;
	cout<<"enter the sum"<<endl;
	cin>>k ;
//	cout <<  D->data << "\n";
//	print_triplets( D , D->right ,D->right->right ,k) ;
     dptr x = D ;
     dptr y =NULL ;
     dptr z = NULL ; 
    for(int i=0;i<n;i++)
    {
    		y = x->right ;
    	while(y->right)
    	{
    		z = y->right ; 
    		while(z)
    		{
    			
    				if((x->data)+(y->data)+(z->data) == k)
	               	{
	              	cout<< x->data <<" "<< y->data <<" "<< z->data <<endl;
	                }
	                //if(z->right != NULL)
	                z=z->right ;
			}
			y=y->right ;
		}
		x=x->right ;
	}
	cout<<endl;
	return 0;
}


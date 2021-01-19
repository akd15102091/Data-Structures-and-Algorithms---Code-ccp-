#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
typedef struct node *lptr ;

lptr createlist(lptr L , int a[], int i ,int n)
{
	if(i==n) {  return L ;  }
	else
	{
		lptr T = NULL ;
		T = new struct node ;
		T->data = a[i] ;
		T->next = NULL ;
	    L = T ;
	    L->next = createlist(L->next , a ,i+1 , n) ;
	}
}
void printlist( lptr L )
{   static int c = 0;
	if(L != NULL)
	{   c++;
		cout<< L->data <<" ";
		printlist(L->next) ;
	}
	else if(c == 0)
	{
		cout<<"List is empty "<<endl;
	}
	
}
int main()
{
	lptr L = NULL ;
	
	cout<<"Enter number of elements : "<<endl;
	int n;
	cin>>n;
	int a[50];
	cout<<"Enter the elements of linked list : "<<endl;
	for(int i=0 ; i<n ; i++)
	{
		cin>>a[i] ;
	}
	
	L = createlist( L , a ,0 ,n) ;
	printlist(L);
	lptr P = L ;
	for(int i=0;i<n/2 ;i++)
	{
		lptr t1 = P ;
		lptr Q = t1 ;
		lptr R = t1;
		while(Q->next)
		{
			Q = Q->next ;
		}
		while(R->next != Q)
		{
			R =R->next ;
		}
		R->next = NULL ;
		P =P->next ;
		t1->next = Q ;
		Q->next = P ;
	
	}
	cout<<endl;
	printlist(L);
	
}

#include<iostream>
#include<queue>
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
lptr addend(lptr L,int x)
{
	lptr temp=L;
     lptr T;
	T=new (struct node);
	if(L==NULL)
	{
		
		T->data=x;
		T->next=NULL;
		L=T;
		return L;
	}
	else
	{
		while(L->next != NULL)
		{	
        	L=L->next;
		}
		T->data=x;
		T->next=NULL;
		L->next=T;
        return temp;
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
lptr L ;
lptr reverselinkedlist(lptr prev , lptr curr )
{	if(curr)
	{
		reverselinkedlist(curr , curr->next) ;
		curr -> next = prev ;	
	}	
	else
	{
		L=prev ;
	} 
	return L ;
}
lptr LL ;
lptr addnumber_oflist(lptr t1 , lptr t2 ,int carry)
{
	if(t1 == NULL && t2==NULL)
	{
		if(carry == 0) return LL ;
		else {
				LL = addend(LL , carry) ;
				return LL ;			
		     }
	}
	else
	{
		int a= t1->data ;
		int b= t2->data ;
		if((a+b+carry)>=10) 
		{
			LL = addend( LL , (a+b+carry)%10) ;
			return (addnumber_oflist( t1->next ,  t2->next ,1)) ;
		}
		else
		{
			LL = addend( LL , (a+b+carry)%10) ;
			return (addnumber_oflist( t1->next ,  t2->next ,0)) ;

		}
	}
}
int main()
{
	lptr L1 = NULL ;
	lptr L2 = NULL ;
	cout<<"Enter number of elements : "<<endl;
	int n;
	cin>>n;
	int a[50] , b[50];
	cout<<"Enter the elements of linked list 1 : "<<endl;
	for(int i=0 ; i<n ; i++)
	{
		cin>>a[i] ;
	}
	cout<<"Enter the elements of linked list 2 : "<<endl;
	for(int i=0 ; i<n ; i++)
	{
		cin>>b[i] ;
	}
	L1 = createlist( L1 , a ,0 ,n) ;
	L2 = createlist( L2 , b ,0 ,n)  ;
//	printlist(L1) ;
//	printlist(L2) ;
    lptr t1 = reverselinkedlist(NULL , L1) ;
    lptr t2 = reverselinkedlist(NULL , L2) ;
   // printlist(t1) ;
    cout<<endl;
   // printlist(t2) ;
	lptr newll ;
	newll = addnumber_oflist(t1 , t2 , 0); 
	lptr LL3 =   reverselinkedlist(NULL , newll) ;
	printlist(LL3) ;
}

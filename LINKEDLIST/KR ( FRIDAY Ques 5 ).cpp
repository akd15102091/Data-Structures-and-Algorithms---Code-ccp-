#include<iostream>
#include<stack>
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
	stack<int> s ; 
	cout<<"Enter number of elements : "<<endl;
	int n;
	cin>>n;
	int a[50];
	cout<<"Enter the elements of linked list : "<<endl;
	for(int i=0 ; i<n ; i++)
	{
		cin>>a[i] ;
	}
	int k ;
	cout<<"Enter the value of k "<<endl;
	cin>>k ;
	L = createlist( L , a ,0 ,n) ;
	printlist(L);
	cout<<endl;
	lptr temp = L ;
	
	for(int i=0;i<=(n/k) ; i++)
	{
		lptr t = temp ;
		for(int j=0 ;j<k ;j++)
		{
			if(temp != NULL)
	    	{
			s.push(temp->data) ;
			temp = temp->next ;
		    }	
		}
		while(!s.empty())
		{
			t->data = s.top() ;
			s.pop() ;
			t = t->next ;
		}
	
	}
	
	
	printlist( L );
	return 0;
}

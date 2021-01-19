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
lptr print_intersection_value( lptr L , lptr t )
{   //cout<<"go";
	if(L->data == t->data)
	{
		return t ;
	}
	else return(print_intersection_value( L->next , t->next )) ;
}
lptr checkloop_presence(lptr s , lptr f , int flag)
{
	if( f == NULL)
	{
		cout<<" Loop is not in linked list "<<endl;
		return NULL ;
	}
	if(flag !=0 && s == f )
	{
	
		cout<<" Loop has formed "<<endl;
		return s;
	
	}

	else {  
	         if(f->next !=NULL && f->next->next != NULL)
			 return (checkloop_presence(s->next , f->next->next, flag+1))  ; }
}
int looplength(lptr s, lptr f,int l)
{
	if(s == f) return l;
	else return(looplength( s,  f->next, l+1)) ;
}
lptr remove_loop(lptr L ,lptr b, lptr c)
{
	while(b->next != c)
	{
		b=b->next ;
	}
	b->next = NULL ;
	return L;
	
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
	cout<<endl;
	lptr temp = L ;
	while(temp->next != NULL )
	{
		temp = temp->next ;
	}
	temp->next = L->next->next->next->next ;  // Here loop is formed

	lptr b = NULL ;
	b =checkloop_presence( L,L ,0) ;
	//cout<<b->data ;
	lptr c = NULL ; 
	c = print_intersection_value( L ,b  )  ;
	cout<<"Intersection value is : "<< c->data <<endl;
	int l = looplength(b,b->next,1);
	cout<<"length is "<<l<<endl;
	lptr R = NULL ;
	R = remove_loop( L , b , c ); 
	printlist(R) ;
	
	
	
}

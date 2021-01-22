#include<iostream>
using namespace std ;

struct lnode
{
	int data ;
	struct lnode *next ;
} ;
typedef struct lnode *lptr ;

lptr createList(lptr t,int a[],int i,int n)
{
	if(i>=n) return t ;
	else
	{
		lptr temp = new struct lnode ;
		temp->data = a[i] ;
		temp->next = NULL ;
		t=temp ;
		t->next = createList(t->next,a,i+1,n) ;
	}
}
void printList(lptr t)
{
	if(t)
	{
		cout<<t->data<<" " ;
		printList(t->next) ;
	}
}

void FrontBackSplit(lptr source,lptr &frontRef,lptr &backRef)
{
	lptr slow = NULL ;
	lptr fast = NULL ;
	
	slow = source ; 
	fast = source->next ;
	
	while(fast != NULL)
	{
		fast = fast->next ;
		if(fast!=NULL)
		{
			slow = slow->next ;
			fast = fast->next ;
		}
	}
	
	frontRef = source ;
	backRef = slow->next ;
	slow->next = NULL ;
	
}

lptr SortedMerge(lptr a,lptr b)
{
	lptr result = NULL; 

    if (a == NULL) return (b); 
    else if (b == NULL) return (a); 
  
    if (a->data <= b->data) 
	{ 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else 
	{ 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
 }

void MergeSort(lptr &headRef)
{
	lptr head = headRef ;
	lptr a = NULL ;
	lptr b = NULL ;
	
	if((head == NULL) || (head->next == NULL)) 
	{ 
		return; 
    } 
    
	FrontBackSplit(head,a,b) ;
	
	MergeSort(a) ;
	MergeSort(b) ;
	
	headRef = SortedMerge(a,b) ;
	
}

int main()
{
	lptr head = NULL ;
	int n ;
	int a[500] ;
	cout<<"Enter the number of the elements : "<<endl ;
	cin>>n ;
	cout<<"Enter the elements of linked list : "<<endl ;
	for(int i=0;i<n;i++)
	{
		cin>>a[i] ;
	}
	int i=0 ;
	head = createList(head,a,i,n) ; 
	cout<<"Unsorted linked list : "<<endl ;
	printList(head) ;
	cout<<endl <<endl;;
	
	MergeSort(head) ;
	cout<<"Sorted linked list : "<<endl ;
	printList(head) ;
	return 0;
	
}

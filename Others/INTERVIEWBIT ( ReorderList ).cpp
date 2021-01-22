#include<iostream>
using namespace std;
struct ListNode
{
	int data;
	struct ListNode *next;
};
//typedef struct node *lptr ;

ListNode* createlist(ListNode* L , int a[], int i ,int n)
{
	if(i==n) {  return L ;  }
	else
	{
		ListNode* T = NULL ;
		T = new struct ListNode ;
		T->data = a[i] ;
		T->next = NULL ;
	    L = T ;
	    L->next = createlist(L->next , a ,i+1 , n) ;
	}
}

 ListNode* reverselinkedlist(ListNode* curr )
{
	ListNode* prev = NULL ;
	ListNode* nextnode = NULL ;
	while(curr)
	{
		nextnode = curr -> next ;
		curr -> next = prev ;
		prev = curr ;
		curr = nextnode ;
	}
	return prev ;
}
ListNode* reorderList(ListNode* A) 
{
    if(A==NULL)
    {
        return A ;
    }
    if(A->next==NULL) return A ;
    ListNode* h1=A ;
    int n=0 ;
    ListNode* count =NULL ;
    count = A ;
    while(count!=NULL)
    {
        n++ ;
        count= count->next ;
    }
    int k = n/2 ;
    int x=0 ;
    ListNode* temp1 = A ;
    while(x<k-1 && temp1!=NULL)
    {
        temp1=temp1->next ;
        x++ ;
    }
    ListNode* h2 = temp1->next ;
//    cout<<h1->data <<" "<<h2->data<<endl;
    temp1->next=NULL ;
    h2 = reverselinkedlist(h2) ;
   // cout<<h1->data <<" "<<h2->data<<endl;
    ListNode* head =h1 ;
    ListNode* ref = head ;
    h1=h1->next ; 
    for(int i=0;i<n;i++)
    {
    
        if(i%2==0 && h2!=NULL)
        {
            head->next=h2 ;
            h2=h2->next ;
            head=head->next ;
        }
        else if(i%2==1 && h1!=NULL)
        {
            head->next=h1 ;
            h1=h1->next ;
            head=head->next ;
        }
	}
        
	return ref ;
}

int main()
{
	ListNode* L = NULL ;
	
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

	ListNode* temp = NULL ;
	temp = reorderList(L) ; 
	cout<<endl ;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->next ;
	}
	return 0;
}

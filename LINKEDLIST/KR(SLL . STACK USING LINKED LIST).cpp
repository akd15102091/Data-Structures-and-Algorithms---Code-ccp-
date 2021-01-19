#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct stack
{
	int size;
	struct node *L;
	
};
typedef struct node *lptr;
stack s;

void PUSH(stack &s,int x)
{   s.size += 1 ;
	lptr ref=s.L;
     lptr T;

		T=new (struct node);
		T->data = x;
		T->next = NULL;
	if(ref==NULL)
	{
		s.L=T;
	}
	else if(ref->next == NULL)
	{
		ref->next = T;
		s.L=ref;
	}
	else
	{
		while(ref->next != NULL)
		{	
        	ref = ref->next;
		}
		ref->next=T;
	}
}
void printl(stack s)
{
	
	if(s.L==NULL)
	{
		cout<<"LL is empty"<<endl;
	}
	else{
		  while(s.L != NULL){
			cout<<(s.L)->data<<" ";
			s.L=(s.L)->next;
		}
		cout<<endl;
	}
}
void POP(stack *s)
{   lptr ref=(*s).L ;
	if((*s).L==NULL)
	{
		cout<<"Stack is empty"<<endl;	
	}	
	else
	{
		while(ref->next->next !=NULL)
		{
			ref=ref->next;
		}
		lptr t=ref->next;
		free(t);
		ref->next=NULL;
		(*s).size=(*s).size-1 ;
	}
	
}

int main()
{
//	lptr L=NULL;
	int n;
	cout<<"Enter how many numbers in linked list"<<endl;
	cin>>n;
	cout<<"enter elements "<<endl;
	 s.size=0;
	 s.L = NULL;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		 PUSH(s,x);
	}
	printl(s);
	cout<<endl;
	cout<<"Now size os stack : "<<s.size<<endl;
	
//	push(&L,9);
	POP(&s);
	printl(s);
	cout<<"Now size os stack : "<<s.size<<endl;
	
	return 0;
}

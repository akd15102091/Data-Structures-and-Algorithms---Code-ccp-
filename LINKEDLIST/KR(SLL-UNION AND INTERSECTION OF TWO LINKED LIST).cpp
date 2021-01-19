#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
typedef struct node *lptr;
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
void printl(lptr L){
	
	if(L==NULL){
		cout<<"LL is empty"<<endl;
	}
	else{
		while(L != NULL){
			cout<<L->data<<" ";
			L=L->next;
		}
		cout<<endl;
	}
}
lptr addtwolist(lptr L1 , lptr L2)
{
	lptr temp=NULL;
	temp=L1;
	while(L1->next !=NULL)
	{
		L1=L1->next;
	}
	L1->next=L2;
	return temp;
}
lptr uniontwolist(lptr L)
{
	lptr t1=L;
	lptr cse=NULL;
	while(t1 != NULL)
	{ 
		lptr t2=t1->next;
		
		int c=0;
		while(t2 != NULL)
		{
			if(t1->data == t2->data)
			{
				c++;
			}
			t2=t2->next;
		}
		if(c==0)
		{
			cse = addend(cse,t1->data)  ;
		}
		t1=t1->next;
	}
	return cse;
}
lptr intersectiontwolist(lptr L)
{
	lptr t1=L;
	lptr cse=NULL;
	while(t1 != NULL&&t1->next != NULL)
	{
		lptr t2=t1->next;
		int c=0;
		while(t2 != NULL)
		{
			if(t1->data == t2->data)
			{
				c++;
			}
			t2=t2->next;
		}
		if(c==1)
		{
			cse = addend(cse,t1->data)  ;
		}
		t1=t1->next;
	}
	return cse;
}

int main()
{
	lptr L1=NULL, L2=NULL , L3=NULL , L4=NULL;
//	L3=L1 U L2  , L4= intersection of L1 and L2;
	int n1,n2;
	cout<<"Enter how many numbers in linked list 1"<<endl;
	cin>>n1;
	cout<<"enter elements of linked list 1 "<<endl;
	for(int i=0;i<n1;i++)
	{
		int x;
		cin>>x;
		L1 = addend(L1,x);
    }
    printl(L1);
    cout<<"Enter how many numbers in linked list 2"<<endl;
	cin>>n2;
	cout<<"enter elements of linked list 2 "<<endl;
	for(int i=0;i<n2;i++)
	{
		int x;
		cin>>x;
		L2= addend(L2,x);
    }
    
	printl(L2);
	
	
	lptr L;
	L=addtwolist(L1,L2);
	printl(L);
	L3=uniontwolist(L);
	printl(L3);
	L4=intersectiontwolist(L);
printl(L4);
	return 0;
    
}

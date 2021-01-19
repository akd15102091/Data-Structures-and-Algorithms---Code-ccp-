#include<iostream>
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
lptr addfront(lptr L,int y)
{
	lptr T;
    T= new(node);
    T->data=y;
    T->next=NULL;
	if((L)==NULL)
	{
		(L)=T;
	}

	else
	{
		T->next=(L);
		(L)=T;
	}
	//(*L)=ref;
	
}
lptr addbefore(lptr L,int y,int x)
{   
    lptr temp=L;
    lptr T;
    T= new(node);
    T->data=y;
    T->next=NULL;
    int k=1;
    if((L)==NULL)
    {
    	cout<<"Linked list is empty ,so we can't add elements "<<endl;
	}


	
	while(L)
	{
		if(L->next->data == x)
		{
			T->next=L->next;
			L->next=T;
		/*	lptr khem = NULL;
			khem = new(node);
			khem->data = y;
			khem->next = L->next;
			L->next = khem; */
			k=0;
			break;
		  }  
	       L=L->next;
	}

	if(k)
	cout << "Element not found in LL";
	return temp;
	
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

int main()
{
	lptr L=NULL;
	int n;
	cout<<"Enter how many numbers in linked list"<<endl;
	cin>>n;
	cout<<"enter elements "<<endl;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		L = addend(L,x);
	}
	printl(L);
		cout<<endl;
	cout<<"enter the value for add in the front of sll : "<<endl;
	int y;
	cin>>y;
	L=addfront(L,y);
	printl(L);
	cout<<"Enter element which you want to enter and before which element "<<endl;
	int a,b;
	cin>>a>>b;
    L=addbefore(L,a,b);
	printl(L);

	return 0;
}

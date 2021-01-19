#include<iostream>
using namespace std;
struct lnode
{
	int data;
	struct lnode *next;
};
typedef struct lnode *lptr;
void addend(lptr *L,int x)
{   
    lptr T,ref=*L;
    T= new(lnode);
    T->data=x;
    T->next=NULL;
	if((*L)==NULL)
	{
		(*L)=T;
	}
	else
	{
		while((*L)->next !=NULL)
		{
			(*L)=(*L)->next;
		}
		(*L)->next=T;
		
	}
	*L = ref;
}

void printlist(lptr L)
{
	if((L)==NULL)
	{
		return;
	}
	else
	{
		while((L) !=NULL)
		{
			cout<<(L)->data <<" ";
			(L)=(L)->next;
		}
	}
}
void addfront(lptr *L,int y)
{
	lptr T,ref=*L;
    T= new(lnode);
    T->data=y;
    T->next=NULL;
	if((*L)==NULL)
	{
		(*L)=T;
	}

	else
	{
		T->next=(*L);
		(*L)=T;
	}
	//(*L)=ref;
	
}
void addbefore(lptr *L,int y,int x)
{   lptr T,ref=*L;
    T= new(lnode);
    T->data=y;
    T->next=NULL;
    int k=1;
    if((*L)==NULL)
    {
    	cout<<"Linked list is empty ,so we can't add elements "<<endl;
	}
	
	while((*L)->next->data !=x)
	{  if((*L)->next->data == x)
	       {k++;}}
		T->next=(*L)->next ;
		(*L)->next=T;
	
	if(k==1)
	{
		cout<<"Elements is not in linked list,so we can't add elements"<<endl;
	}
	(*L)=ref;
	
}
int main()
{
	lptr L = NULL;
	//L = new(lnode);
	lptr temp=L;
	cout<<"Enter the numbet of nodes "<<endl;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		addend(&L,x);
	}
	printlist(L);
	cout<<endl;
	cout<<"enter the value for add in the front of sll : "<<endl;
	int y;
	cin>>y;
	addfront(&L,y);
	printlist(L);
	cout<<"Enter element which you want to enter and before which element "<<endl;
	int a,b;
	cin>>a>>b;
	addbefore(&L,a,b);
	printlist(L);
	return 0;

}

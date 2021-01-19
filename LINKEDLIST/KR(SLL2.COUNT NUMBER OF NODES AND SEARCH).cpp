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
int  countnodes(lptr L )
{
	if(L==NULL)
	{
		return 0;
	}
	else
	return (1+countnodes(L->next));
}
void search(lptr L , int num)
{
	if(L !=NULL )
	{
		if(L->data == num)
		{
			cout<<"Element is found"<<endl;
		}	
		search(L->next , num);	
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
	int y=countnodes(L);
	cout<<"Number of nodes : "<<y<<endl;
	cout<<"enter value which you want to search "<<endl;
	int num;
	cin>>num;
	search(L,num);

	return 0;
}

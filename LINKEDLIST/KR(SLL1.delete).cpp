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
lptr deletefront(lptr L)
{
	lptr temp=L;
	L=L->next;
	free(temp);
	return L;
}
lptr deleteend(lptr L)
{
	lptr temp=L;
	while((L->next->next)!=NULL)
	{
		L=L->next;
	}
	lptr t;
	t=L->next;
	L->next=NULL;
	free(t);
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
lptr delthatelement(lptr L,int x)
{
	lptr temp=L;
	while(L->next->data !=x)
	{
		L=L->next;
	}
	lptr t;
	t=L->next;
	L->next=L->next->next;
	free(t);
	return temp;	
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
    L=deletefront(L);
    printl(L);
    L=deleteend(L);
    printl(L);
    cout<<"Which no. you want to delete"<<endl;
    int z;
    cin>>z;
    L=delthatelement(L,z);
    printl(L);
	return 0;
}

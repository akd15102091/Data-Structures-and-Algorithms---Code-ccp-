#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int c;   // c is coefficient
	int p;   // p is power
	struct node* next;
};
typedef struct node * lptr;
lptr addend(lptr L,int x,int y)
{
	lptr temp=L;
     lptr T;
	T=new (struct node);
	if(L==NULL)
	{
		T->c=x;
		T->p=y;
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
	    T->c=x;
		T->p=y;
		T->next=NULL;
		L->next=T;
        return temp;
	}
}
void printl(lptr L)
{   if(L==NULL)
    {
		cout<<"LL is empty"<<endl;
	}
	else
	{
		while(L != NULL)
		{
			cout<< L->c <<" "<< L->p <<endl;
			L=L->next;
		}
		cout<<endl;
	}
}
lptr addexpressionlist(lptr L1, lptr L2)
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
lptr sumofexpression(lptr L)
{
	lptr t1=L;
	lptr cse=NULL;
	while(t1 != NULL)
	{
		lptr t2=t1->next;
		int c=0;
		while(t2 != NULL)
		{
			if(t1->p == t2->p)
			{
				c++;
				t2->c = (t2->c)+(t1->c);
			}
			t2=t2->next;
		}
		if(c==0)
		{
			cse = addend(cse,t1->c,t1->p)  ;
		}
		t1=t1->next;
	}
	return cse;

}
int main()
{
	lptr e1=NULL,e2=NULL; // e1 and e2 are expresions
	int n1,n2;
	cout<<"Enter number of terms in expression 1"<<endl;
	cin>>n1;
	cout<<"enter coefficient and power of terms "<<endl;
	for(int i=0;i<n1;i++)
	{
		int x,y;
		cin>>x>>y;
		e1=addend(e1,x,y);
	}
//	printl(e1);
	cout<<"Enter number of terms in expression 2"<<endl;
	cin>>n2;
	cout<<"enter coefficient and power of terms "<<endl;
	for(int i=0;i<n2;i++)
	{
		int x,y;
		cin>>x>>y;
		e2=addend(e2,x,y);
	}
	//printl(e2);
	lptr e=NULL;
	e=addexpressionlist(e1,e2);
	//printl(e);
    lptr sum=NULL;
    sum=sumofexpression(e);
    cout<<"Sum of expressions is "<<endl;
    printl(sum);
    
	return 0;	
}

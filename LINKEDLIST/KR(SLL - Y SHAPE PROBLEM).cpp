#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;
typedef struct node* lptr;
struct node
{
	int data;
	struct node* next;
};
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
int intersection_element(lptr L1, lptr L2)
{
	stack<int>s1,s2;
	while(L1 !=NULL)
	{
		s1.push(L1->data);
		L1=L1->next;
	}
	while(L2 !=NULL)
	{
		s2.push(L2->data);
		L2=L2->next;
	}
	while(! s1.empty()  &&(! s2.empty() ) )
	{  
	     int a=s1.top();
	    int b=s2.top();
	    s1.pop();
		s2.pop();
	     if((a==b) && (s1.top() !=s2.top()))
	     {
	     	return a;
		 }
	/*	if(s1.top() == s2.top())
		{
			s1.pop();
			s2.pop();
		}
		else
		{
			return s1.top();
		}*/
		
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
    int y= intersection_element(L1,L2);
    cout<<"Intersection point is : "<<y<<endl;
	return 0;
}

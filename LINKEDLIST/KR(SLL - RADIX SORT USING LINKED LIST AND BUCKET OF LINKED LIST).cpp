#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct queue
{   int size;
int unit;
	struct node *front=NULL;
	struct node *rear=NULL;
	struct node *L;
	struct queue *agla = NULL;
};

typedef struct node *lptr;
queue q;
//q.front= NULL,q.rear=NULL;
typedef struct node *lptr;
void ENQUE(queue &q,int x)
{
     q.size += 1 ;
	 lptr ref=q.L;
     lptr T;
	T=new (struct node);
	T->data = x;
	//cout<<x<<" ";
	T->next = NULL;
	if(ref==NULL)
	{   q.front = T;
		q.rear = T;
		q.L=T;
		
	}
	else if(ref->next == NULL)
	{
		ref->next = T;
		q.rear = T;
		q.L=ref;
		
	}
	else
	{
		while(ref->next != NULL)
		{	
        	ref = ref->next;
		}
		q.rear = T;
		ref->next=T;
	}
}
void printl(lptr L)
{
	

	if(L !=NULL){
		  while(L != NULL){
			cout<<L->data<<" ";
			L=L->next;
		}
		cout<<endl;
	}
}
int DEQUE(queue *q)
{  
        lptr t = ((*q).front) ;
	    int a=t->data;
	    ((*q).front) = ((*q).front) ->next;
	    (*q).L=(*q).L -> next ;
		free(t);
	//	ref->next=NULL;
		(*q).size=(*q).size-1 ;
		return a;
//	}
	
}
int main()
{
	//queue<int>q[10];
	int a[50],n;
	cout<<"Enter the number of elements : "<<endl;
	cin>>n;
	cout<<"Enter the elements : "<<endl;
	queue *Q = NULL;
	queue *P = NULL;
	
	Q = new(queue);
	P = Q;
	for(int s=0;s<10;s++)
	{
		queue *T = NULL;
		T = new(queue);
		T->unit = s;
		T->agla = NULL;
		Q->agla = T;
		Q = Q->agla;
		//Q->agla = NULL;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter the maximum no. of digits : "<<endl;
	int x;
	cin>>x;
	for(int i=1;i<=x;i++)   // x is the largest digit
	{
	//	int y=pow(10,x);
    	int y=10;
		int z=pow(10,i-1);
		for(int j=0;j<n;j++)
		{
		  if((a[j]/z ) % y ==0) ENQUE(Q,a[j]) ; 
		  if((a[j]/z ) % y ==1) ENQUE(Q->agla,a[j]) ;
		  if((a[j]/z ) % y ==2) ENQUE(Q->agla->agla,a[j]) ;
		  if((a[j]/z ) % y ==3) ENQUE(Q->agla->agla->agla,a[j]) ;
		  if((a[j]/z ) % y ==4) ENQUE(Q->agla->agla->agla->agla,a[j]) ;
		  if((a[j]/z ) % y ==5) ENQUE(Q->agla->agla->agla->agla->agla,a[j]) ;
		  if((a[j]/z ) % y ==6) ENQUE(Q->agla->agla->agla->agla->agla->agla,a[j]) ;
		  if((a[j]/z ) % y ==7) ENQUE(Q->agla->agla->agla->agla->agla->agla->agla,a[j]) ;
		  if((a[j]/z ) % y ==8) ENQUE(Q->agla->agla->agla->agla->agla->agla->agla->agla,a[j]) ;
		  if((a[j]/z ) % y ==9) ENQUE(Q->agla->agla->agla->agla->agla->agla->agla->agla->agla,a[j]) ;
		  
		}
	
		int l=0,m=0;
		for(l=0;l<10;l++)
		{   
		    int c=0;
		    while(c!=l)
		    {   c++;
		    	Q=Q->agla;
			}
			while((Q.size) != 0)
			{
			//	a[m]=q[l].front();
			//	q[l].pop();
			a[m]=DEQUE(&Q);
				m++;
				
			}
	    }
    } 
    cout<<"Sorted array is : "<<endl;
    for(int i=0;i<n;i++)
    {
    	cout<<a[i]<<" ";
	}
	Q = P;
	while(Q)
	{
		cout << Q->unit;
		Q= Q->agla;
	}
	return 0;
}


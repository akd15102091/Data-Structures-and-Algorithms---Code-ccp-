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
	struct node *front=NULL;
	struct node *rear=NULL;
	struct node *L;
};
typedef struct node *lptr;
queue q[10];
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
		  if((a[j]/z ) % y ==0) ENQUE(q[0],a[j]) ; 
		  if((a[j]/z ) % y ==1) ENQUE(q[1],a[j]) ;
		  if((a[j]/z ) % y ==2) ENQUE(q[2],a[j]) ;
		  if((a[j]/z ) % y ==3) ENQUE(q[3],a[j]) ;
		  if((a[j]/z ) % y ==4) ENQUE(q[4],a[j]) ;
		  if((a[j]/z ) % y ==5) ENQUE(q[5],a[j]) ;
		  if((a[j]/z ) % y ==6) ENQUE(q[6],a[j]) ;
		  if((a[j]/z ) % y ==7) ENQUE(q[7],a[j]) ;
		  if((a[j]/z ) % y ==8) ENQUE(q[8],a[j]) ;
		  if((a[j]/z ) % y ==9) ENQUE(q[9],a[j]) ;
		  
		}
	
		int l=0,m=0;
		for(l=0;l<10;l++)
		{
			while((q[l].size) != 0)
			{
			//	a[m]=q[l].front();
			//	q[l].pop();
			a[m]=DEQUE(&q[l]);
				m++;
				
			}
	    }
    } 
    cout<<"Sorted array is : "<<endl;
    for(int i=0;i<n;i++)
    {
    	cout<<a[i]<<" ";
	}
	return 0;
}


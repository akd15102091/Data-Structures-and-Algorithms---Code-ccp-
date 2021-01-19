#include<iostream>
using namespace std;
typedef struct node
{
	int b_val ;
	char data;
	int freq;

	node *lchild;
	node *rchild;
}
*NPTR;
NPTR H[3000];
void PerculateUp(NPTR H[],int n,NPTR T)
{
  int j,k=n-1;
  H[n-1]=T;
  j=(k-1)/2;
  while( H[k]->freq < H[j]->freq  &&  n!=0)
  {
  swap(H[k],H[j]);
  k=j;
  j=(k-1)/2;
  }
}
void bubble_sort(int n)
{
	int temp , i ,j ;
	for( i=0;i<n;i++)
	{
		for(j=0 ;j<n-i-1 ;j++ )
		{
			if(H[j]->freq > H[j+1]->freq)
			{
				swap(H[j] , H[j+1]) ;
			}
		}
	}
}
void HuffmanCode(int n)
{
	while(n>1)
	{
		NPTR K=new node();
		K->data='.';
		K->freq=H[0]->freq+H[1]->freq;
		K->lchild=H[0];
		K->rchild=H[1];
		H[0]=K;
		for(int i=2;i<n;i++)
		H[i-1]=H[i];
		--n;
		bubble_sort(n);
	}
}

void bit_value(NPTR t , int x)
{
	if(t== NULL ) return ;
	t->b_val = x ;
	bit_value(t->lchild , 0) ;
	bit_value(t->rchild , 1) ;
}
void printarr(int a[] ,int i ,char c)
{  cout<<c <<" : ";
	for(int k=0;k<i ;k++)
	{
		cout<<a[k]<<" ";
	}
	cout<<endl;
}
void print_result(NPTR t, int i ,int a[])
{
	
	if(t->lchild==NULL && t->rchild == NULL)
	{
			a[i] = t->b_val;
			char ch = t->data ;
			printarr(a,i+1 ,ch) ;
	}
	else
	{
		a[i] = t->b_val ;
		++i;
		if(t->lchild != NULL)
		print_result(t->lchild ,i ,a) ;
		if(t->rchild != NULL)
		print_result(t->rchild ,i ,a) ;
	}

	
}

int main()
{
	int y,k=0,n,f,a[100];
	char c;
	cout<<"Enter the no. of characters : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the character : ";
		cin>>c;
		cout<<"Enter its frequency : ";
		cin>>f;
		NPTR P=new node();
		P->data=c;
		P->freq=f;
		P->lchild=NULL;
		P->rchild=NULL;
		++k ; 
		if(k==1)
		H[0]=P;
		else
		PerculateUp(H,k,P);
		
	}
	HuffmanCode(n);
	
	bit_value(H[0] , 0) ;
	print_result(H[0] ,0 ,a) ;
	return 0;
}


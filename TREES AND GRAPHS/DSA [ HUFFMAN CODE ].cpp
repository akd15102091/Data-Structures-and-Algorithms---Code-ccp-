#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node
{
	int b_val ;
	char data;
	int freq;
	string st;
	node *lchild;
	node *rchild;
}
*NPTR;
NPTR H[3000];
void PerculateUp(NPTR H[],int n,int key,NPTR T)
{
  int j,k=n;
  H[n]=T;
  j=(k-1)/2;
  while(H[k]->freq<H[j]->freq && n!=0)
  {
  swap(H[k],H[j]);
  k=j;
  j=(k-1)/2;
  }
}
void PerculateDown(int n)
{
  int j=0,c;
  while((H[j]->freq>H[(2*j)+1]->freq || H[j]->freq>H[(2*j)+2]->freq) && (2*j)+1<n && (2*j)+2<n)
  {
  if(H[j]->freq>H[(2*j)+1]->freq && H[j]->freq>H[(2*j)+2]->freq)
  {
  c=min(H[(2*j)+1]->freq,H[(2*j)+2]->freq);
  if(c==H[(2*j)+1]->freq)
  {
  swap(H[j],H[(2*j)+1]);
  j=(2*j)+1;
  }
  else
  {
	  swap(H[j],H[(2*j)+2]);
	  j=(2*j)+2;
  }
}
else if(H[j]->freq>H[(2*j)+1]->freq && H[j]->freq<H[(2*j)+2]->freq)
  {
	swap(H[j],H[(2*j)+1]);
	  j=(2*j)+1;
  }
else if(H[j]->freq<H[(2*j)+1]->freq && H[j]->freq>H[(2*j)+2]->freq)
  { 
	swap(H[j],H[(2*j)+2]);
	  j=(2*j)+2;
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
		PerculateDown(n);
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
		i++;
		if(t->lchild)
		print_result(t->lchild ,i ,a) ;
		if(t->rchild)
		print_result(t->rchild ,i ,a) ;
	}

	
}
void IN(NPTR t)
{
	if(t)
	{
		IN(t->lchild) ;
		cout<<t->data <<" ";
		IN(t->rchild)  ;
	//	cout<<t->freq <<" ";
			
	}
}
int main()
{
	int y,k=0,n,f;
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
		if(k==0)
		H[0]=P;
		else
		PerculateUp(H,k,P->freq,P);
		++k;
	}
	HuffmanCode(n);
	
	bit_value(H[0] , 0) ;
	IN(H[0]) ;

	int a[50] ;
	print_result(H[0] ,0 ,a) ;
	return 0;
}


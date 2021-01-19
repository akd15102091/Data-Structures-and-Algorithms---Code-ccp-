#include<iostream>
using namespace std;
typedef struct fibonode
{
int data;
fibonode *lc;
fibonode *rc;
}
*TPTR;
TPTR T;
TPTR Create1()
{
	TPTR P=new fibonode();
	P->data=1;
	P->lc=NULL;
	P->rc=NULL;
	return P;
}
TPTR Create2()
{
	TPTR P=new fibonode();
	P->lc=Create1();
	P->rc=Create1();
	P->data=P->lc->data+P->rc->data;
	return P;
}
TPTR Create(TPTR K,int x,int j)
{
	if(x==1)
	{
		K=Create1();
		return K;
	}
	else if(x==2)
	{
		K=Create2();
		return K;
	}
	else
	{
		if(x==j)
		return K;
		else if(K==NULL)
		{
			TPTR P=new fibonode();
			P->lc=Create2();
			P->rc=Create1();
			P->data=P->lc->data+P->rc->data;
			K=Create(P,x,++j);
		}
		else
		{
			TPTR L=new fibonode();
			L->lc=K;
			L->rc=K->lc;
			L->data=L->lc->data+L->rc->data;
			K=Create(L,x,++j);
		}
		return K;
	}
}
void Preorder(TPTR K)
{
	if(K)
	{
		cout<<K->data<<" ";
		Preorder(K->lc);
		Preorder(K->rc);
	}
}
int main()
{
	T=NULL;
	int a,i=2;
	cout<<"Enter the required level : ";
	cin>>a;
	T=Create(T,a,i);
	cout<<"Preorder of fibonacci tree is : ";
	Preorder(T);
	return 0;
}

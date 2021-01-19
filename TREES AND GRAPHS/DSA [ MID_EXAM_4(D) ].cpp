#include<iostream>
#include<cmath>
using namespace std;
typedef class wnode *wptr;
int a[] = {1,6 ,5,2,3,7,4,9} ;
int i=0;
int k=log2((sizeof(a)/sizeof(a[0])));

class wnode{
public:
int data;
wnode *lc=NULL,*rc = NULL;
wnode(int key)
{
data = key;
lc = NULL;
rc = NULL;
}
};

int create(wptr T,int a[],int k)
{
if(k==0)
{
T->lc = new wnode(a[i++]);
T->rc = new wnode(a[i++]);
T->data = max(T->lc->data,T->rc->data);
return T->data;
}
T->lc = new wnode(0);
T->rc = new wnode(0);
int c = create(T->lc,a,k-1);
int b = create(T->rc,a,k-1);
T->data = max(c,b);
return T->data;
}

void find_n_replace(wptr T,int n)
{
if(T)
{
if(T->data == n) T->data = -1;
find_n_replace(T->lc,n);
find_n_replace(T->rc,n);
}
}

int give_max(wptr T)
{
if(T)
{
if(T->lc==NULL && T->rc == NULL) return T->data;
else {
T->data = max(give_max(T->lc),give_max(T->rc));
return T->data;
}
}
}

int main()
{
wptr khem = new wnode(0);
int x = create(khem,a,k);
cout << "Winnner is " << x;
for(int i=0;i<2;i++)
{
find_n_replace(khem,x);
x = give_max(khem);
}
cout << "\nThird winner is " << x;
return 0;
}



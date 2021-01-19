#include<iostream>
#include<queue>
using namespace std;
typedef struct gnode *gptr; 
typedef struct bdnode *bptr;

struct gnode{
	int data;
	char ch;
	gptr cptr[10];
	int cnt = 0;
};

struct bdnode{
	char data;
	bptr lc = NULL,rc = NULL;
};

gptr tempGen(char key)
{
	gptr temp = NULL;
	temp = new(gnode);
	temp->ch = key;
	temp->data = 0;
	for(int i=0;i<10;i++)
	temp->cptr[i] = NULL;
	return temp; 
}

bptr new_bdnode(char ch)
{
	bptr temp = NULL;
	temp = new(bdnode);
	temp->data = ch;
	temp->lc = NULL;
	temp->rc = NULL;
	return temp;
}

gptr create(gptr t,char ch[],int n,int &i)
{
	if(i>=n)	return NULL;
	if(ch[i++]==')')	return NULL;
	t = tempGen(ch[i-1]);
	while(1)
	{
		t->cptr[(t->data)] = create(t->cptr[(t->data)],ch,n,i);
		if(t->cptr[t->data] == NULL)	break;
		t->data = t->data + 1;
	}
	return t;
}

void printlevel(queue<bptr> &q){
  if(q.size() == 1) return ;
  bptr t = q.front();q.pop();
  if(t == NULL){
    cout << endl;
    q.push(NULL);
    printlevel(q);
  }
  
  else{
  	cout << t->data << " ";
  	if(t->lc)	q.push(t->lc);
  	if(t->rc)	q.push(t->rc);
	printlevel(q);
  }
}

void in(bptr t)
{
	if(t==NULL)	return;
	in(t->lc);
	cout << t->data << " ";
	in(t->rc);
}

int print(gptr t,bptr &tp,gptr kh)
{
	if(t == NULL)	return 0;
	tp = new_bdnode(t->ch);
	int a=0,b=0,k=0;
	for ( int i = 0 ; i < t->data ; i++ )
	{
		if(t->cptr[i])
		{
			if(k == 0)  
			{
				a = print(t->cptr[i],tp->lc,kh);
				if(a == 0)
				{
					t->cptr[i] = NULL;
				}
			}
			if(k == 1)
			{
				b = print(t->cptr[i],tp->rc,kh);
				if(b == 0)
				t->cptr[i] = NULL;
			}	
			k++;
		}
	}
	if((k > 2) || a || b)	return 1;
	
	return 0;
}
/* abd)e)f))cm)n)o)p)q)))*/

int main()
{
	char ch[50];
	cin.getline(ch,50);
	gptr khem = NULL;
	cout << "\nSize ";
	int n;
	cin >> n;
	int k =0;
	khem = create(khem,ch,n,k);
	
	bptr km = NULL;
	queue<bptr> ksm ;
	int z=1,y=0;
	while(z)
	{
		z = print(khem,km,khem);
		ksm.push(km);
		km = NULL;
	}
	while(ksm.size()){
	cout << "\nLevel order " << ksm.size() << endl;
	queue<bptr> q;
 	q.push(ksm.front());q.push(NULL);
  	cout << "\n\tLevel :  ";
  	printlevel(q);
  	ksm.pop();	
  }
  	//0print(khem);
	return 0;
	}


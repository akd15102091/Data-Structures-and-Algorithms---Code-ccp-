#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct bdnode* bdptr;
#define d 2

struct bdnode {
int flag = 0;
int cnt = 0;
int key[2 * d+1];
bdptr ptr[2 * d + 2];
bdptr parent;
};

void inorder(bdptr t)
{
	if(t == NULL) return;
	for(int i=0;i<t->cnt;i++)
	{
		inorder(t->ptr[i]);
		if(t->key[i] == -1) break;
		cout<<t->key[i] <<" " ;
		// cout << t->key[i] << "(" << t->flag << ") ";
	}
	inorder(t->ptr[t->cnt]);
}

int find_id(int a[],int n,int key) //returns the index of newly added node
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==key)
		return i;
	}
	return -1;
}

void printlevel(queue<bdptr> &q){
  if(q.size() == 1) return;
  bdptr t = q.front();q.pop();
  if(t == NULL){
    cout << endl;
    q.push(NULL);
    printlevel(q);
  }

  else{
    int i=0;
    cout << "{" ;
    while(i<t->cnt){
      if(t->ptr[i]) q.push(t->ptr[i]);
      cout << t->key[i] << " , ";
      i++;
    }
    cout << "}\t" ;
    if(t->ptr[i]) q.push(t->ptr[i]);
  }
  printlevel(q);
}

void tempGen(int data, bdptr ance,bdptr &node)
{
	bdptr temp = NULL;
	temp = new(bdnode);
	for (int i = 0; i <= 2 * d; i++)
	{
		temp->ptr[i] = NULL ;
	}
	for (int i = 0; i < 2 * d; i++)
	{
		temp->key[i] = -1;	
	}
	temp->flag = 0;
	temp->key[0] = data;
	temp->cnt = 1;
	temp->parent = ance;
	node = temp;
}

void modify_parent(bdptr &par,int median,bdptr head,bdptr r_newnode,bdptr &root)
{
	if(par == NULL)
	{
		bdptr one ;
		tempGen(median,NULL,one);
		one->ptr[0] = head;
		one->ptr[1] = r_newnode ;
		one->flag = 1;
		one->ptr[0]->parent = one ;
		one->ptr[1]->parent = one ;
		root = one ;
		par  = one ;
	}
	else{
		par->flag = 1 ;
		par->key[par->cnt] = median ;
		par->cnt++;
		sort(par->key, par->key + par->cnt) ;
		int id = find_id(par->key,par->cnt,median) ;
		if(par->cnt > id+1)
		{
			for(int i=par->cnt;i>=id+2;i--)
			{
				par->ptr[i] = par->ptr[i-1];
				par->ptr[i]->parent = par->ptr[0]->parent;
			}
		}
		par->ptr[id+1] = r_newnode ;
		par->ptr[id+1]->parent = par->ptr[0]->parent;
		
		if(par->cnt == 2*d+1)
		{
			par->cnt--;
			int medi = par->key[d];
			par->key[d] = -1;
			par->cnt--;
			bdptr fre = NULL;
			tempGen(par->key[d + 1], NULL,fre);
			fre->flag = par->flag;
			par->key[d+1] = -1;
			for (int i = 1; i < d; i++)
			{
				fre-> key[i] = par->key[d + i + 1];
				par->key[d + i + 1] = -1;
				fre->cnt++;
				par->cnt--;
			}
			for(int i=0;i<=d;i++)
			{
				fre->ptr[i] = par->ptr[d+i+1];
				fre->ptr[i]->parent = par->ptr[d+i+1]->parent;
			}
			modify_parent(par->parent,medi,par,fre,root);
			return;
		}
	}
}


void create(bdptr &head, int data, bdptr par,bdptr &root,int idx = 0)
{
	if (head == NULL) {
	tempGen(data,par,head);
	//cout << "Parent is " << head->parent->key[0];
	root = head;
	return;
	}
	if(head->flag == 0){
	head->key[head->cnt++] = data;
	sort(head->key, head->key + head->cnt);
	if (head->cnt == 2 * d+1)
	{
//	cout << "idx " << idx;
	if(idx > 0 && par->ptr[idx-1]->cnt < 2*d)
	{
//	cout << "idx gt 0";
	create(par->ptr[idx-1],par->key[idx-1],par,root,idx-1);
	par->key[idx-1] = head->key[0];
	for(int i=0;i<2*d;i++)
	{
	head->key[i] = head->key[i+1];
	}
	head->cnt--;
	return;
	}
	else if(par && (idx < par->cnt && par->ptr[idx+1]->cnt < 2*d))
	{
	cout << idx << head->cnt ;
	create(par->ptr[idx+1],par->key[idx],par,root,idx+1);
	head->cnt--;
	par->key[idx] = head->key[head->cnt];
	return;
	}
//	cout << "no";
	head->cnt--;
	int median = head->key[d];
	head->key[d] = -1;
	head->cnt--;
	bdptr r_newnode;
	tempGen(head->key[d + 1], par,r_newnode);
	r_newnode->flag = head->flag;
	for (int i = 1; i < d; i++)
	{
	r_newnode->key[i] = head->key[d + i + 1];
	head->key[d + i + 1] = -1;
	r_newnode->cnt++;
	head->cnt--;
	}
	modify_parent(par,median,head,r_newnode,root);
	head->parent = par;
	return;
	}
	//cout << " " << head->cnt << endl;
	}
	else{
	int c=0;
	for(int i=0;i<head->cnt;i++)
	{
	if(data < head->key[i])
	{
	create(head->ptr[i],data,head,root,i);
	return;
	}
	}
	create(head->ptr[head->cnt],data,head,root,head->cnt);
	}
}




int main()
{
	int n,key;
	cout << "Enter the number of entries ";
	cin >> n;
	bdptr head = NULL, parent = NULL,root = NULL;
	for (int i = 1; i <= n; i++)
	{
		int x ;
		cin >>x ;
		create(head, x , parent,root);
		head = root;
	}
  queue<bdptr> q;
  q.push(root);q.push(NULL);
  cout << "\n\tLevel :  ";
  printlevel(q);
	cout<<endl<<endl<<endl ;
	inorder(root);
	return 0;
}

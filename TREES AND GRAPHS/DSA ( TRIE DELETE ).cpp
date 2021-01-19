#include<iostream>
#include<cstring>
using namespace std;
typedef struct tnode *tptr;

union un{
	tptr child[27];
	char ch[20];
};

struct tnode{
	int data;
	union un da;
};

tptr leafGen(char ch[20])
{
	tptr temp = NULL;
	temp = new(tnode);
	temp->data = 0;
	int l = strlen(ch);
	strcpy(temp->da.ch,ch);
	return temp;
}

tptr tempGen()
{
	tptr temp = NULL;
	temp = new(tnode);
	temp->data = 1;
	for(int i=0;i<27;i++)
	{
		temp->da.child[i] = NULL;
	}
	return temp;
}


void create(tptr t,char ch[20])
{
	tptr ref = t;
	for(int i=0;i<strlen(ch);i++)
	{
		int id = ch[i]-'a';
		if(ref->da.child[id]==NULL)
		{
			ref->da.child[id] = leafGen(ch);
			return;
		}
		else if(ref->da.child[id]->data == 0)
		{
			char arr[20];
			strcpy(arr,ref->da.child[id]->da.ch);
			ref->da.child[id] = tempGen();
			ref->da.child[id]->da.child[(arr[i]-'a')] = leafGen(arr);
		}
		ref = ref->da.child[id];
	}
	ref->da.child[26] = leafGen(ch);
	
}

void del_trie( tptr t ,char ch[20]  )
{
	if( t == NULL) return ;
	static int i =0 ;
	int id = ch[i] -'a' ;
	i++ ;
	if(t->da.child[id]->data == 0 &&  strcmp(ch ,t->da.ch) ==1 )
	{
		t->da.child[id] = NULL ;
		return ;
	}
	else
	{
		
		del_trie(t->da.child[id] ,ch ) ;
		return ;
	}
}

void print(tptr t)
{
	if(t == NULL )	return ;
	if(t->data == 0) 
	{
		cout << t->da.ch << endl ;
		return;
	}
	for(int i=0;i<27;i++)
	{
		if(t->da.child[i]!=NULL)
		print(t->da.child[i]);
	}
}

int main()
{
	tptr root = tempGen();
	int n;
	cout << "Enter the number of entries ";
	cin >> n;
	char ch[20];
	cin.ignore();	
	for(int i=0;i<n;i++)
	{
	cin.getline(ch,20);
	create(root,ch);
	}
	cout << "\nData entered by user \n";
	print(root);
	cout<<endl<<endl ;
	cout<<"Enter string to delete : "<<endl;
	cin.getline(ch ,20) ;
	del_trie(root , ch) ;
	cout<<"After deleting , Data's  are : "<<endl ;
	print(root) ;
}
/*
7
cat
mat
bat
atm
cam
abc
tab */







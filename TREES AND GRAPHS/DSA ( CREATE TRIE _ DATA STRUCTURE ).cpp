#include<iostream>
#include<cstring>
using namespace std;
typedef struct tnode *tptr;

struct tnode{
	tptr child[26];
	bool end;
};

tptr tempGen()
{
	tptr temp = NULL;
	temp = new(tnode);
	temp->end = false;
	for(int i=0;i<26;i++)
	{
		temp->child[i] = NULL;
	}
	return temp;
}

void create(tptr t,string str)
{
	tptr ref = t;
	for(int i=0;i<str.length();i++)
	{
		int id = str[i]-'a';
		if(ref->child[id]==NULL)	ref->child[id] = tempGen();
		ref = ref->child[id];
	}
	ref->end = true;
}

bool search(tptr t,string str)
{
	tptr temp = t;
	string find = str;
	for(int i=0;i<str.length();i++)
	{
		int id = str[i]-'a';
		if(temp->child[id]==NULL)	return false;
		temp = temp->child[id];
	}
	return temp && temp->end ;
}


int main()
{
	int n;
	cout << "Enter the number of entries ";
	cin >> n;
	tptr str = tempGen() ;
	for(int i=0;i<n;i++)
	{
	string find ;
	cin >> find;
	create(str,find);
	}
	cout << "Enter the number of cases ";
	cin >> n;
	for(int i=0;i<n;i++)
	{
	string find ;
	cin >> find;
	if(search(str,find))	cout << "\nFound"<<endl ;
	
	else cout<<"not found " ;
	}
	
}

